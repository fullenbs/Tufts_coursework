import numpy as np
import matplotlib.pyplot as plt

#Function and derivative for q2 part a
f = lambda x: np.log(np.exp(x)+np.exp(-x))
df = lambda x : (np.exp(x) - np.exp(-x))/(np.exp(x) + np.exp(-x))
d2f = lambda x: 4*np.exp(2*x)/(np.exp(2*x)+1)**2

#Function and derivative for q2 part b
g = lambda x: -np.log(x) + x
dg = lambda x: -1/x+1
d2g = lambda x: 1/(x**2)

#Objective function for question 3
def h(x, A):
    sum1 = 0
    for i in range(0, A.shape[0]):
        print(A.shape)
        print(A[i:,])
        print(A[i:,].shape)
        sum1 += np.log(1-np.matmul(A[i:,], x))
    sum1 = -1*sum1
    
    sum2 = 0 
    for i in x:
        sum2 += np.log(1-i**2)
    return sum1 - sum2

grad_test = lambda x, A: A.T/(1-np.matmul(A,x)) - 1/(1+x) - 1/(1-x)

#Newton's method function
#Inputs: x0: starting point, epsilon: tolerance, t: step size
#Returns: Final x value
#Note: Change function to be the one given in problem
def newton(x0, epsilon, t): #Newton's method
    x1 = x0
    x = x1 #Variable stuff
    iter = 0
    while (df(x)**2/d2f(x) > 2*epsilon): #Have error to not let it run for too long
        x = x1
        x1 = x1 - t*df(x1)*(d2f(x1)**(-1)) #Updates new point with function f
        print("       ", iter, "|", x1, "|", df(x1)) #Display
        iter += 1
    return(x1)    

def newton_vec(x0, epsilon, t):
    x = x0
    iter = 100
    for i in range(iter):
        t = 1
        hess_inv = np.linalg.inv(d2f(x))
        if (np.matmul(np.matmul(df(x).T, hess_inv), df(x)) < np.sqrt(epsilon)):
            break 
        
        while(np.max(f(x)))
        x = x - t*np.matmul(hess_inv, df(x))





           

def newt_infeasible(x0, epsilon, a, B):
    max_iter = 100
    for i in range(max_iter):
        r = ValueError
        Dx = ValueError
        if (np.linalg.norm(r) < epsilon):
            break
        t = 1
        while (np.min(x + t*Dx) <= 0):
            t = B*t
        x = x + t*Dx

#Gradient descent function: 
#Inputs: x0: starting point, epsilon: tolerance, a: alpha parameter in line search,
#B: beta parameter in line search
#Returns: Final x value
#Note: Change function to be whatever problem requires
def grad_descent(x0, epsilon, a, B, mat): #Gradient descent
    max_iter = 500
    x = x0
    A = mat
    for iter in range(0, max_iter):

        val = h(x, A)
        print(val)
        if (np.linalg.norm(grad_test(x, mat)) <= epsilon):
            break 
        v = -grad_test(x, mat)
        fup = -(grad_test(x, mat)**2)
        t = 1
        while ((np.max(np.matmul(A, x + t*v)) >= 1)):
            t = B*t
        while (-np.sum(np.log(1-np.matmul(A, x + t*v))) - np.sum(np.log(1-(x+t*v)^2))
               > val + a*t*fup):
            t = B*t
        x = x + t*v

        while (grad_test(x + t*fup, ) > g(x) + a*t*dg(x)*fup):
            t = B*t
        x = x + t*v
    return(x)

#A = np.random.normal(0, 1, (200, 100))
# A = np.random.normal(0, 1, (30, 100))
# x = np.random.uniform(0, 1, 100)
# b = np.matmul(A, x)
#A = np.load('mat.npy')

x = 1 #Starting point
epsilon = .000001 #Error to end algorithm
print("Iteration |", "x |", "f(x)")
#x = np.ones(100)

#print("Final value:", grad_descent(x, epsilon, 0.05, 0.1, A))
print("Final value:", newton(x, epsilon, 1))


exit()
x = np.linspace(0, 10, 1000)
plt.plot(x, g(x), label = 'f(x)')
plt.plot(x, dg(x), label = 'f\'(x)')
plt.ylim(-20, 10)
legend = plt.legend(loc='upper center')
plt.title('Part b graph')
plt.grid()
plt.show()