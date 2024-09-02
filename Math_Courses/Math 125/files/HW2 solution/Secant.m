% -------------------------------------------------------------------------
% This code implements secant's method
% -------------------------------------------------------------------------
function root = Secant(f,tol,x0,x1)
% Secant method 
xn1 = x0;
xn = x1;
while 1
    x = xn - (f(xn)*(xn-xn1)/(f(xn)-f(xn1)));
    fprintf("%.8f\n",x) 
    xn1 = xn;
    xn = x;
    if abs(f(x))<tol
        break
    end
end
root= x;
end