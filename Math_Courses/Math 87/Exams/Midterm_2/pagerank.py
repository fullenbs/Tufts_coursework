import numpy as np
 

def make_transition(A,p):
    (n,m) = A.shape
    T = np.zeros((n, n))

    for i in range(0, n): #creates transition matrix
        ones_count = 0
        for j in range(0, n): #finds number of ones in a column
            if A[j, i] == 1:
                ones_count = ones_count + 1
        if ones_count == 0: #if no ones, replace the column with 1/n
            T[:,i] = np.ones((1, n))/n
        else:
            T[:,i] = np.copy(A[:,i]/ones_count) 
    ones_mat = np.ones((n, n))*p/n
    return (1-p)*T + ones_mat #complete equation

float_formatter = "{:.5f}".format
np.set_printoptions(formatter={'float_kind':float_formatter})



A = np.array([[0, 0, 0, 0, 0], 
            [1, 0, 0, 0, 0], 
            [1, 1, 0, 0, 0], 
            [1, 0, 1, 0, 0], 
            [0, 1, 0, 1, 0]])
B = np.array([[0, 1, 1, 1, 1], 
             [1, 0, 0, 0, 0], 
             [1, 1, 0, 0, 0], 
             [1, 0, 1, 0, 0], 
             [0, 1, 0, 1, 0]])
(n, m) = A.shape
C = make_transition(B, p = 0.4)
print(C)

e_val, e_vec = np.linalg.eig(C)
v = e_vec[:,0]
w = (1/sum(v,0))*v
print(w)
B = np.linalg.matrix_power(C, 5)
print(B)