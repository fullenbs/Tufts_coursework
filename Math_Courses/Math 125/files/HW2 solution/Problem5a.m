% -------------------------------------------------------------------------
% This code solves problem 5a
% -------------------------------------------------------------------------
tol = 1e-5;
% 5(a)
f = @(x) x^5+ x-1;
f_der = @(x) 4*x^3 + 1;
x0 = 2;
root1 = newton_raphson(f,f_der,tol,x0);
% 5(b)
f = @(x) sin(x)-6*x-5;
f_der = @(x) cos(x)-6;
x0 = -2;
% root2 = newton_raphson(f,f_der,tol,x0);
% 5(c)
f = @(x) log(x)+x^2-3;
f_der = @(x) 1/x+2*x;
x0 = 3;
% root3 = newton_raphson(f,f_der,tol,x0);

