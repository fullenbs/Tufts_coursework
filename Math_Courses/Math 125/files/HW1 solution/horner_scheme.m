% -------------------------------------------------------------------------
% This code implements Horner's method for evaluating a polynomial of
% degree n: p(x) = a_0 + a_1*x + a_2*x^2 + ... + a_n*x^n
% Inputs
% x0 
% array of coefficients: a = [a0 a1 a2 ...an]
% degree of polynomial: n
% Output
% p(x0)
% ------------------------------------------------------------------------
function y = horner_scheme(n,x0,a)
y = a(n+1);
for i = n:-1:1
    y =   y*x0+a(i);
end
end