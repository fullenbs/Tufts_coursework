import numpy as np
import csv

M = np.zeros((100, 100))

col = 0
count = 0
with open('stochastic_matrix.csv') as csv_file: #Reads in file
    csv_reader = csv.reader(csv_file, delimiter=',')
    for row in csv_reader:
        for i in range(0, len(row)):
            M[col, i] = float(row[i])
        col += 1

x = np.random.uniform(0, 5, 100) #Generates random vector
def power(M, x): #Does power iteration
    x_k = x
    for i in range(0, 100):
        x_k1 = np.matmul(M, x_k)
        x_k = x_k1/np.linalg.norm(x_k1)
    return x_k

res = power(M, x) #eigenvector
res = res/np.sum(res)
quot = np.matmul(np.matmul(res.T, M), res)/(np.matmul(res.T, res)) #eigenvalue
print(res, np.sum(res), quot)