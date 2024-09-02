import numpy as np
import math


f = lambda x : np.exp(-x**2)

roots_2 = np.array([-np.sqrt(1/3), np.sqrt(1/3)])
roots_3 = np.array([-np.sqrt(3/5), 0, np.sqrt(3/5)])
roots_4 = np.array([-0.86113631159405, 0.86113631159405, -0.33998104358486, 0.33998104358486])

def interpolate(x, y, domain):
    prod = 1
    sum = np.zeros(len(domain))
    #Generates each component of sum individually, adding them iteratively
    #Follows Lagrange interpolation formula
    for i in range(0, len(x)): 
        for j in range(0, len(x)):
            if i != j:
                prod = (domain - x[j])/(x[i]-x[j])*prod
        prod = prod*y[i]
        sum = sum + prod
        prod = 1
    return sum

x = np.linspace(-1, 1, 100)
b = .02
res = interpolate(roots_4, f(roots_4), x)
int = 0
for i in range(0, len(roots_2)):
    for j in range(1, 99):
        int += 2*res[j]
    int = f(roots_2[i])*(int + res[0]+res[99])*b
print(int)