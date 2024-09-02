#Secant method in python

f = lambda x: x**3+x-1 #Function
def secant(x0, x1, epsilon): 
    dummy = 0
    for i in range(1000):
        print(dummy,"| " ,x1)
        dummy = x1
        if abs(f(x1)-f(x0)) < epsilon: #If in epsilon bound, end
            break
        x1 = x1 - f(x1)*(x1-x0)/(f(x1)-f(x0)) #Updates new point
        x0 = dummy   
    return x1

x0 = 0 #Starting value
x1 = 1
epsilon = 0.0000000000001 #Error bound

print("iteration| x0 | x1")
print("final value:", secant(x0, x1, epsilon))