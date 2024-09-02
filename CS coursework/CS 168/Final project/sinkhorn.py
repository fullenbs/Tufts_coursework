import torch
from keras.datasets import mnist
import matplotlib.pyplot as plt
import numpy as np
import ot
#import tensorflow as tf
import time

#Parameters: 
# mu: first distribution
# nu: second distribution
# M: Cost matrix
# reg: entropic regularizer, lambda in analysis
# maxiter: maximum number of iterations
# tol: difference between updates before breaking
#Note: Assumption is inputs are probability distributions
def sinkhorn(mu, nu, M, reg, maxiter=50, tol=1e-5):
    #Converts inputs to tensors
    mu = torch.tensor(mu)
    nu = torch.tensor(nu)
    M = torch.tensor(M)

    #Dimension parsing, done so looking at correct dimensions
    mu = torch.transpose(mu.unsqueeze(0), 0, 1) 
    nu = torch.transpose(nu.unsqueeze(0), 0, 1)

    #Gibbs Kernel and it's transpose. Calculating Kt here saves a couple of 
    #calculations.
    K = (-reg*M).exp() 
    Kt = torch.transpose(K, 0, 1)

    #Initial scaling vector of u, set so it's a uniform
    u = (torch.ones(mu.size(0))/(mu.size(0))).unsqueeze(0) 
    u = torch.transpose(u, 0, 1)

    #Sinkhorn's Algorithm
    for i in range(maxiter):
        u_old = u #Save old variable

        #The matrix scaling process outlined in the paper, can combine into
        #one step, so we don't need to be keeping track of u and v the entire 
        #time. 
        u = mu/torch.mm(K, nu/torch.mm(Kt, u_old)) 

        #Here is the break condition. We could calculate it every step, since
        #maximum iter is small, we do it every 5 to save a little on run time.
        if i % 5 == 0:
            if torch.norm(u - u_old) < tol: 
                break
    
    #This calculates v, as we need it at the end.
    v = (nu/torch.mm(Kt, u)) 

    #Last step is getting the distance, so just taking the Frobenius norm with
    #respect to the distance
    return torch.sum(torch.mm(u*(K*M), v))

#Test that compares speed of calculating EMD and Sinkhorn
# Input: Output file, entropic regularizer
def speed_compare(file, lamba):
    start = time.time()

    #Sizes of histograms, number of trials, and creates arrays for results
    size = np.array((64, 128, 256, 512, 1024, 2048, 4096))
    trials = 1000
    results_sink = np.zeros(len(size)*trials)
    results_emd = np.zeros(len(size)*trials)

    #keeping track of time through update, and marker is for counting 
    update = time.time()
    marker = 0

    #Outer for loop goes for size of histogram, and inner for loop goes through
    #all possible trials.
    for i in size:
        for j in range(0, trials):
            #Generates mu and nu, and also normalizes them. 
            #This also creates the cost function
            mu = np.random.uniform(1, 2, i)
            nu = np.random.uniform(1, 2, i)
            mu = mu/np.sum(mu)
            nu = nu/np.sum(nu)
            M = ot.dist(mu.reshape((i, 1)), nu.reshape((i,1)), metric='euclidean')
            
            #Calculates EMD and the time it takes to run 
            #For this experiment, we don't care about run time.
            update = time.time()
            dist = ot.emd2(mu, nu, M)
            curr = time.time()
            results_emd[marker*trials + j] = curr - update
            
            #Calculates sinkhorn distances, and the the run time of the process.
            #Again, we don't care about the actual distance calculated. 
            update = time.time()
            dist = sinkhorn(mu, nu, M, lamba)
            curr = time.time()
            results_sink[marker*trials + j] = curr - update

        #Updates
        print('trial complete: ', marker)
        marker += 1

    #Writes results to file w/ each line as: emd_distance,sinkhorn_distance
    #Can be easily accessed as a CSV file
    with open(file, 'x') as file:
        for i in range(0, len(size)*trials):
            file.write(str(results_emd[i]) + ',' +  str(results_sink[i]) + '\n')

    print('program run time: ', time.time() - start)


#Runs the comparison test of accuracy between Sinkhorn and EMD
def accuracy_compare():
    #Only use train_x, but function call requires this form
    (train_x, train_y), (test_x, test_y) = mnist.load_data()
    lambdas = [1, 2, 4, 8, 12, 16, 24, 32, 48, 64]
    #lambdas = [128, 256, 512, 1024] #For res2.txt only
    
    #Variable initialization 
    trials = 1000
    dist1 = np.zeros(trials*len(lambdas))
    dist2 = np.zeros(trials*len(lambdas))
    marker = 0

    #Procedural loop
    for i in lambdas:
        for j in range(trials):
            #Pick two random images from MNIST training set
            rand_x = np.random.randint(0, 60000, 1)
            rand_y = np.random.randint(0, 60000, 1)
            img_x = train_x[rand_x]
            img_y = train_x[rand_y]

            #Reshaping procedure for both images, does the following steps:
            # 1.) Converts 2D array into 1D array
            # 2.) Pads data to avoid divide by 0 errors, doesn't effect outcome
            # 3.) Divide by sum of components so vector is distribution
            x = (img_x.reshape(img_x.shape[0]*img_x.shape[1], -1))
            x = x.reshape(-1)
            x = x + 5
            x = x/np.sum(x)

            #Same procedure, just for y
            y = img_y.reshape(img_y.shape[0]*img_y.shape[1], -1)
            y = y.reshape(-1)
            y = y + 5
            y = y/np.sum(y)

            #Cost matrix generation
            M = ot.dist(x.reshape((len(x), 1)), y.reshape((len(y),1)))
            M /= (M.max() * 0.1)

            #Earth mover's distance
            dist1[marker*trials+j] = ot.emd2(x,y, M)

            #Sinkhorn distance 
            dist2[marker*trials+j] = sinkhorn(x, y, M, i)
        print('trial complete: ', marker)
        marker += 1

    #Saves results in file in form of:  EMD, Sinkhorn, Relative error
    with open('res.txt', 'x') as file:
        for i in range(trials*len(lambdas)):
            file.write(str(dist1[i]) + ',' + str(dist2[i]) + ',' + 
                       str((dist2[i]-dist1[i])/dist1[i]) + '\n')

    
#Main function
if __name__ == '__main__':
    #Avoids type issues
    torch.set_default_dtype(torch.float64) 
    #accuracy_compare()
   