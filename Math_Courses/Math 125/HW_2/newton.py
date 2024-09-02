import numpy as np

#Function and derivative for part 1
f = lambda x : np.log(x)+x**2 - 3
df = lambda x: 1/x +2*x

#Function and derivative for part 2
g = lambda x: x**5+x-1
dg = lambda x: 5*x**4+1

#Function and derivative for part 3
h = lambda x: np.sin(x)-6*x-5
dh = lambda x: np.cos(x) - 6

def newton(x0, epsilon): #Newton's method
    x1 = x0
    x = x1 + 50*epsilon #Just guarantees runs first iteration
    iter = 0
    while (abs(x1-x) > epsilon): #Have error to not let it run for too long
        x = x1
        x1 = x1 - h(x1)/dh(x1) #Updates new point with function f
        print("       ", iter, "|", x1, "|", h(x1)) #Display
        iter += 1
    return(x1)    

x = 3 #Starting point
epsilon = .000001 #Error to end algorithm
print("Iteration |", "x |", "h(x)")
print("Final value:", newton(x, epsilon))