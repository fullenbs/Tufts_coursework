% -------------------------------------------------------------------------
% This code implements Newton's method
% -------------------------------------------------------------------------
function root = newton_raphson(f,f_der,tol,x0)
% Newton method 
x = x0;
while 1
    x = x - (f(x))/f_der(x);
    fprintf("%.8f\n",x) 
    if abs(f(x))<tol
        break
    end
end
root= x;
end