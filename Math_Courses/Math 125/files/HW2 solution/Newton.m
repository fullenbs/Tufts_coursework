% -------------------------------------------------------------------------
% This code implements Newton's method
% -------------------------------------------------------------------------
function root = newton_raphson(@f,@f_der,tol,x0)
% Newton method 
while 1
    x = x - f(x)/f_der(x);
    if f(x)<tol
        break
    end
end