% -------------------------------------------------------------------------
% This applies Simpson's method of integration to find the arc length of
% a curve with x(t) = a*cos(t) and y(t) = b*sin(t). The arc-length is
% (4a)*int_{0}^{pi/2}  sqrt(1-k^2*sin^2(t)) dt where k^2 = 1-b^2/a^2
% Let f(t) = sqrt(1-k^2*sin^2(t))
% -------------------------------------------------------------------------
% specify a and b
a = 3;
b = 2;
% specify k^2
K = 1-(b^2/a^2);
% specify number of sub-intervals
m  = 1465;
% specify h
h = (pi/2)/m;
% define function
f = @(t) sqrt(1-K*(sin(t)).^2);
% define the grid
g = linspace(0,pi/2.0,m+1);
% Trapezoid method
integral = h/2*(f(g(1))+f(g(m+1))+2*sum(f(g(2:m))));
% Ramanujan estimate
lam = (a-b)/(a+b);
r_estimate = pi*(a+b)*(1+(3*lam^2)/(10+sqrt(4-3*lam^2)));