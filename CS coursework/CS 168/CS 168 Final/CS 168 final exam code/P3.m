load('P3_Parameters.mat', 'A');
load('P3_Parameters.mat', 'c');
load('P3_Parameters.mat', 'b');
%All parameters can be loaded in for file
max_iter = 10000; %To make graphs set max_iter=100
eps = 10e-8;
eps_feas = 10e-8;
alpha = 0.01;
beta = 0.5;
mu = 10;
m = 50;
x = ones(200, 1);
l = ones(200, 1);
nu = zeros(m, 1);
vals = zeros(100, 1);
etas = zeros(100, 1);
steps = zeros(100, 1);
r_feas = zeros(100, 1);
iter = 1;
while (norm(A*x-b) > eps_feas && norm(c - sum(l)+A'*nu) > eps_feas && nu > eps)
   if iter > max_iter %If it really doesn't ever stop for some reason
       break; end
   vals(iter, 1) = c'*x;
   eta = -sum(l);
   etas(iter, 1) = eta;
   
   t = eta/mu*200;
   b1 = [zeros(200, 200), -eye(200), A'; diag(l), diag(x), zeros(200,50); A, zeros(50, 250)];
   b2 = [c - sum(l)+A'*nu; diag(l)*x - t*ones(200,1); b - A*x];
   sol = -mldivide(b1,b2);
   
   if (norm(A*x-b) < eps_feas && norm(c - sum(l)+A'*nu) < eps_feas && nu < eps)
       break; 
   end
   
   dx = sol(1:200);
   dl = sol(201:400);
   dnu = sol(401:450);
   
   s = .99*min(1, max(-dl./l));
   while (min(x + s*dx) < 0)
       s = beta*s;
   end
   xtemp = x +s*dx; %Temporary updates
   ltemp = l + s*dl;
   nutemp = nu + s*dnu;
   rup = [c - sum(ltemp) + A'*nu; diag(ltemp)*xtemp - t*ones(200,1); b - A*xtemp];
   while(norm(rup) > (1-alpha*s)*norm(b2))
        s = s*beta;
        xtemp = x +s*dx;
        ltemp = l + s*dl;
        nutemp = nu + s*dnu;
        rup = [c - sum(ltemp) + A'*nu; diag(ltemp)*xtemp - t*ones(200,1); b - A*xtemp];
   end
   steps(iter, 1) = s;
   x = xtemp;
   l = ltemp;
   nu = nutemp;
   r_feas(iter, 1) = sqrt(norm(c - sum(ltemp) + A'*nu)^2 + norm(A*x - b)^2);
   iter = iter + 1;
end

% subplot(1, 2, 1);
% title('Objective function values'); hold on
% plot(vals);
% subplot(1, 2, 2);
% title('Step size'); hold on
% plot(steps);
% title('Surrogate duality gap'); hold on
% plot(etas);
% xlabel('iteration');
% ylabel('duality gap');
title('Feasibility gap'); hold on
plot(r_feas);
xlabel('iteration');
ylabel('Feasibility gap');
