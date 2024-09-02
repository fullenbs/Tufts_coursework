% -------------------------------------------------------------------------
% This implements the Jacobi iteration method to solve a linear system
% Ax = b
% -------------------------------------------------------------------------
function [x,error] = jacobi(A,b,tol)
    % Initialize the solution
    n = length(A);
    x = zeros(n,1);
    % Diagonal part of A
    d = diag(A);
    % Iteration counter
    it = 1;
    error = [ ];
    % Jacobi algorithm
    while norm(A*x-b)>tol
        x = (b - A*x + d.*x)./d;
        error = [error norm(A*x-b)];
        it = it+1;
    end
    error = [error norm(A*x-b)];
    % Plot residual error vs iteration
    figure
    semilogy(1:it,error,'r', 'LineWidth',2)
    xlabel('Iteration number = k','FontSize',15)
    ylabel('$||Ax-b||$','interpreter','latex','FontSize',15)
    title('Covergence of Jacobi iteration')
    grid on
    %saveas(1,'Jacobi_convergence','png')
end

