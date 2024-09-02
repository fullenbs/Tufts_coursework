import numpy as np
import math

f = lambda x: (math.e)**x - np.sin(x) #Function

def bisection(a, b, epsilon):
    c1 = 0
    iter = 0
    while f(a)*f(b) < 0: 
        c = (a+b)/2 #New point
        if (abs(c-c1) < epsilon): #If below error bound we are done
            break
        c1 = c #Temp var to see how close we are to convergence
        if f(c)*f(a) < 0: #Update value
            b = c
        elif f(c)*f(b) < 0: #Update value
            a = c
        elif f(c) == 0: #If we're at the root
            break
        print(iter, "|", c)
        iter += 1
    return c

a = -4 #Starting point
b = -1
epsilon = 0.000001 #Error bound

print("iteration | midpoint")
print(bisection(a, b, epsilon))
