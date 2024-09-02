%--------------------------------------------------------------------------
% This script implements the solution to the weighted least squares
% problem: A^T W^T W A x = A^T W^T W b
% -------------------------------------------------------------------------
% The matrix A, the weight matrix W and the vector b
A = [1 0 ; 1 1; 1 2];
W = [1 0 0; 0 2 0; 0 0 1];
b = [0;1;1];
% Compute the solution x
x = (A'*W'*W*A)\(A'*W'*W*b);
% Plot the data and the least-squares fit on a graph.
% Plot data: x1 is the x-coordinates and y1 is the y-coordinates
x1 = [0 ; 1 ; 2];
y1 = [0 ; 1;  1];
figure;
sz = 50;
scatter(x1,y1,sz,'filled','r')
least_squares_x = 0:0.1:2;
least_squares_y = x(2)*least_squares_x+x(1);
hold on
plot(least_squares_x,least_squares_y,'LineWidth',2)
grid on
title('Data points and least squares fit')
legend('Data points','Least squares fit','Location','northwest')
saveas(1,'data_fitting','png')