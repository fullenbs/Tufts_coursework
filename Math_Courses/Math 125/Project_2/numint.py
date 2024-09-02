import numpy as np
import math

f = lambda x : np.sqrt(1-(5/9)*(np.sin(x)**2)) #function

#Trapezoid method with k^2 = 5/9 as b=2, a=3
a = 0
b = math.pi/2
size = 10**6
x = np.linspace(a, b, size)

h = (b-a)/size #interval size
y = f(x)

int = 0 #Does numerical integration following the trapezoid method
for i in range(1, size): 
    int += 2*y[i]
int = 12*((int + y[0]+y[99])*h/2)
print(int)

h = 1/25 #All other methods of ellipse perimeter
print(2*math.pi*np.sqrt((2**2+3**2)/2), 'method 1')
print(math.pi*(3*(5)-np.sqrt((3*3+2)*(3+3*2))), 'ramanujan 1')
print(math.pi*5*(1+(3*h)/(10+np.sqrt(4+3*h))), 'ramanujan 2')
#d) Perimeter of ellipse 
# I pulled approximations from:https://www.youtube.com/watch?v=5nW3nJhBHL0&t=1058s


