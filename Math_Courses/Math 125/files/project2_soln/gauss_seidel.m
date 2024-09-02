% -------------------------------------------------------------------------
% This implements the Gauss Seidel method to solve a linear system Ax = b
% -------------------------------------------------------------------------
function [x,error] = gauss_seidel(A,b,tol)
    % Initialize the solution
    n = length(A);
    x = zeros(n,1);
    x_new = x;
    % Iteration counter
    it = 1;
    error = [ ];    
    % Gauss Seidel algorithm
    while norm(A*x_new-b)>tol
        for i = 1:n
            x_new(i) = (b(i) - A(i,1:i-1)*x_new(1:i-1)-A(i,i+1:n)*x(i+1:n))/A(i,i);            
        end
        error = [error norm(A*x_new-b)];
        it = it+1;
        x = x_new;
    end
    error = [error norm(A*x-b)];
    % Plot residual error vs iteration
    figure
    semilogy(1:it,error,'r', 'LineWidth',2)
    xlabel('Iteration number = k','FontSize',15)
    ylabel('$||Ax-b||$','interpreter','latex','FontSize',15)
    title('Covergence of Gauss Seidel iteration')
    grid on
    %saveas(1,'Gauss_Seidel_convergence','png')
end

