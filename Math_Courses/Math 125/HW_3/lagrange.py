import numpy as np
import matplotlib.pyplot as plt

n = 8 #Degree of polynomial
f = lambda x: 1/(1+25*(x**2)) #True function 

def cheby(n): #Calculates Chebyshev nodes for given degree
    x = np.zeros(n)
    for i in range(0, n):
        temp = (2*(i+1)-1)/(2*n)
        x[i] = np.cos(temp*np.pi)
    return x

#Does Lagrange interpolation
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

x = np.zeros(n+1)
y = np.zeros(n+1)
for i in range(0,n+1): #For non-Chebyshev nodes, makes domain and range
    x[i] = (2*i)/n-1
    y[i] = f(x[i])

x_2 = cheby(n)
y_2 = f(x)
domain = np.linspace(-1, 1, 100) #Graphing domain
#res = interpolate(x, y, domain) This line is uniform nodes
res = interpolate(x_2, y_2, domain) #This line is Chebyshev nodes
#Comment out the line you don't want

#Graph display, just change name between different graph
plt.title('Interpolant with Chebyshev nodes of degree ' + str(n))
plt.plot(domain, res, color='blue',label='Interpolant')
plt.plot(domain, f(domain), color='red', label= 'True function')
plt.plot(domain, f(domain) - res, color = 'magenta', label ='Error')
plt.legend(loc=1)
plt.show()
