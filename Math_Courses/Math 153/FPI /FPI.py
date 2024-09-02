import math
import matplotlib.pyplot as plt
plt.style.use('seaborn-whitegrid')
import numpy as np


fig = plt.figure()
ax = plt.axes()
x = np.linspace(0, 500, 1000)

def h(a, x):
    return a*x*(1-x)
a_chosen = False
x_chosen = False

while a_chosen == False:
    a = input("Pick coefficient of function: ")
    try:
        a = float(a)
        a_chosen = True
    except ValueError:
        print("Please enter a valid number")
        
while x_chosen == False:
    x_0 = input("Enter a starting point for the algorithm: ") 
    try:
        x_0 = float(x_0)
        if x_0 < 0 or x_0 > 1:
            print("Number must be between 0 and 1. Please try again: ")
        else:
            x_chosen = True
    except ValueError:
        print("Must enter a number. Please try again")
    

plt.xlabel("kth iteration")
plt.ylabel("X(k)")

i = 0
tol = 0.000000000001
while i < 500:
    x_1 = h(a, x_0)
    print("Coefficient: " + str(a), "Iteration: " + str(i+1), "Value: " + str(x_0))
    plt.scatter(i, h(a,x_0), c = 'blue', edgecolors='none')
    if np.abs(x_0 - x_1) < tol:
        break
    x_0 = x_1
    i += 1

plt.show()

