% -------------------------------------------------------------------------
% This script illustrates the Runge phenomenon using Lagrange interpolant
% on uniformly spaced nodes in [-1,1]
% Plots the error
% -------------------------------------------------------------------------
% Define Runge function
runge_fun = @(x) 1./(1+25*x.^2);
% Plot Lagrange interpolant for n = 4, 8, 16 and 32
% n = 4;
n = 4;
x = [-1:2/n:1]';
y = runge_fun(x);
% Uniform grid for plotting
z = -1:0.01:1;
values = lagrange_interpolant(x,y,z);
subplot(2,2,1)
plot(z,abs(values-runge_fun(z)))
title('Lagrange interpolant error n = 4')
% n = 8
n = 8;
x = [-1:2/n:1]';
y = runge_fun(x);
% Uniform grid for plotting
z = -1:0.01:1;
values = lagrange_interpolant(x,y,z);
subplot(2,2,2)
plot(z,abs(values-runge_fun(z)))
title('Lagrange interpolant error n = 8')
% n = 16
n = 16;
x = [-1:2/n:1]';
y = runge_fun(x);
% Uniform grid for plotting
z = -1:0.01:1;
values = lagrange_interpolant(x,y,z);
subplot(2,2,3)
plot(z,abs(values-runge_fun(z)))
title('Lagrange interpolant error n = 16')
% n= 32
n = 32;
x = [-1:2/n:1]';
y = runge_fun(x);
% Uniform grid for plotting
z = -1:0.01:1;
values = lagrange_interpolant(x,y,z);
subplot(2,2,4)
plot(z,abs(values-runge_fun(z)))
title('Lagrange interpolant error n = 32')


