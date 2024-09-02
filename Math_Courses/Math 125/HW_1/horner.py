#This function implements Horner's method
def horner(coeff, x):
    result = coeff[0]
    for i in range(1, len(coeff)): 
        result = result*x+coeff[i] 
    return result

#p(x) = 7x^3 -11x^2 +12x + 5 is polynomial in question
#Horners method means p(x) = 5 + x(12 + x(-11+7x)))

coeff = [7, -11, 12, 5] #Coefficients of p(x) for use
x = 100 #Initial value
print(horner(coeff, x)) #Prints result