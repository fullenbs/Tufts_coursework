% -------------------------------------------------------------------------
% This script does Lagrange interpolation given a set of nodes x0,..,xn
% and values y0,...,yn. 
% Inputs
% x is a column vector of the nodes
% y is a column vector of the values
% z is a row vector where the interpolant is going to evaluated
% Example
% x = [0;1;2];
% y = [2;4;8];
% z = [3 4 7];
% -------------------------------------------------------------------------
function values  = lagrange_interpolant(x,y,z)
% Number of points: n+1
n = length(x)-1;
% Number of input data points to evaluate i.e. length of z
m = length(z);
% Define l0(x), l1(x)...,ln(x)
% Precompute denominators
% Example: (x0-x1)*(x0-x2)*...(x0-xn)
denom = zeros(n+1,1);
for i = 0:n
   xi_minus_x = x(i+1)-x;
   denom(i+1)= prod(xi_minus_x(xi_minus_x~=0));
end
% Compute numerators and combine the Lagrange polynomials
values = zeros(1,m);
for j = 0:n
    zminusx= z-x;
    zminusx(j+1,:) = 1;
    zx = prod(zminusx);
    values = values+ (y(j+1).*zx)/denom(j+1);
end
end