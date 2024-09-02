% -------------------------------------------------------------------------
% This script finds the linear and quadratic fit for the least squares
% problem
% -------------------------------------------------------------------------
% Load data
load('least_squares_data.mat');
% m = number of data points
m = length(data);
% -------------------------------------------------------------------------
% Linear fit
% Set up the system A'*A*x = A'*b
% Set up A
A = [ones(m,1) data(:,1)];
b = data(:,2);
x = (A'*A)\(A'*b);
% Plot original data along with linear fit
figure
scatter(data(:,1),data(:,2),'r*')
hold on
plot(data(:,1),x(1)+x(2)*data(:,1),'b','LineWidth',3)
% -------------------------------------------------------------------------
% Quadratic fit
% Set up the system A'*A*x = A'*b
% Set up A
A = [ones(m,1) data(:,1) data(:,1).^2];
b = data(:,2);
z = (A'*A)\(A'*b);
% Plot original data along with quadratic fit
figure
scatter(data(:,1),data(:,2),'r*')
hold on
plot(data(:,1),z(1)+z(2)*data(:,1)+z(3)*data(:,1).^2,'b','LineWidth',3)
