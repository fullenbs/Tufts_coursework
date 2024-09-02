% -------------------------------------------------------------------------
% This script illustrates the Runge phenomenon can be avoided by
% using Chebyshev nodes
% Plots error
% -------------------------------------------------------------------------
% Define Runge function
runge_fun = @(x) 1./(1+25*x.^2);
% Plot Lagrange interpolant for n = 4, 8, 16 and 32
% n = 4;
n = 4;
a = [0:1:n]';
x = cos(((2*a+1)*pi)./(2*n+2));
y = runge_fun(x);
% Uniform grid for plotting
z = -1:0.01:1;
values = lagrange_interpolant(x,y,z);
subplot(2,2,1)
plot(z,abs(values-runge_fun(z)))
title('Chebyshev interpolant error n = 4')
% n = 8
n = 8;
a = [0:1:n]';
x = cos(((2*a+1)*pi)./(2*n+2));
y = runge_fun(x);
% Uniform grid for plotting
z = -1:0.01:1;
values = lagrange_interpolant(x,y,z);
subplot(2,2,2)
plot(z,abs(values-runge_fun(z)))
title('Chebyshev interpolant error n = 8')
% n = 16
n = 16;
a = [0:1:n]';
x = cos(((2*a+1)*pi)./(2*n+2));
y = runge_fun(x);
% Uniform grid for plotting
z = -1:0.01:1;
values = lagrange_interpolant(x,y,z);
subplot(2,2,3)
plot(z,abs(values-runge_fun(z)))
title('Chebyshev interpolant error n = 16')
% n= 32
n = 32;
a = [0:1:n]';
x = cos(((2*a+1)*pi)./(2*n+2));
y = runge_fun(x);
% Uniform grid for plotting
z = -1:0.01:1;
values = lagrange_interpolant(x,y,z);
subplot(2,2,4)
plot(z,abs(values-runge_fun(z)))
title('Chebyshev interpolant error n = 32')



