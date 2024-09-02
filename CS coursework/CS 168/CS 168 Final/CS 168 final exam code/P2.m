%Load in and initialization
%Just comment in/out Newton's method/Gradient descents
load('P2_Parameters.mat', 'A')
load('P2_Parameters.mat', 'b')
alpha = 0.1;
beta = 0.5;
maxiters = 2000;
x = zeros(10,1);

m = 84; %84 or 142 depending on a/B, change accordingly
vals = zeros(1,m); %Fix number of trials for display purposes
grads = zeros(1,m);
steps = zeros(1,m);

 k = 1;
 while (norm(x + A'*(1./(b-A*x))) > 1e-5)
     f = 0.5*x'*x - sum(log(b-A*x));  
     vals(k) = f;
     grad = x + A'*(1./(b-A*x));
     grads(k) = norm(grad);
     v = -grad; %Gradient descent
     fprime = grad'*v;
     t = 1;
     dx = -(A*v)./(b-A*x);
     
     %Line search, first verify that we are in the domain of the objective
     while (min(1+t*dx) < 0)
         t = beta*t;
     end
     
     %Once we're in the domain, we can do the backwards line search
     while (f + t*x'*v - sum(log(1+t*dx)) > f + t*alpha*fprime)
         t = beta*t;
     end
     steps(k) = t;
     x =  x+t*v;
     k = k + 1;
 end

% sgtitle('Objective function vs iteration/step size \alpha = 0.03, \beta=0.3')
% subplot(1, 2, 1);
% title('Objective vs iteration number'); hold on
% plot(vals, 'b');
% xlabel('iteration');
% ylabel('Objective function');
% xlim([0 140]);
% subplot(1, 2, 2);
% title('Step size vs iteration number'); hold on
% plot(steps, 'b');
% xlabel('iteration');
% ylabel('Objective function');
% xlim([0 140]);

opt = 39.943;
test = vals - opt;
set(gca, 'YScale', 'log');
title('Norm of gradient vs iteration \alpha=0.1, \beta=0.5'); hold on
plot(grads, 'b');
ylabel('Norm of gradient in log scale');
xlabel('Iteration');
plot(test, 'r');
legend('\nabla f(x)', '(f-p^*)');
xlim([0,m-1]);

%Gradient descent above
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%Newton's method below

% n = 9;
% load('P2_Parameters.mat', 'A')
% load('P2_Parameters.mat', 'b')
% vals = zeros(1,n); %From testing it takes 9 iterations either way
% grads = zeros(1,n);
% steps = zeros(1,n);
% 
% x = zeros(10, 1);
% k = 1;
% 
% dec = 1;
% decs = zeros(1,n);
% while (dec > 2e-12)
%     y = b-A*x;
%     f = x'*x - sum(log(y));  
%     vals(k) = f;
%     grad = x + A'*(1./y); %Gradient and Hessian
%     hess = ones(10, 10) + A'*diag(1./(y.^2))*A;
%     v = -hess\grad; 
%     dec = -grad'*v;
%     decs(k) = dec;
%     if (dec < 2e-12) %Break condition
%         break; end
%     fprime = grad'*v;
%     t = 1;
%     dx = -(A*v)./y;
%     dc = x'*v;
%     
%     %Makes sure we are in the domain of the function
%     while (min(1+t*dx) < 0)
%         t = beta*t;
%     end
%     
%     %Backwards line search in action
%     while (f + t*x'*v - sum(log(1+t*dx)) > f + t*alpha*fprime)
%          t = beta*t;
%     end
%     steps(k) = t;
%     x =  x+t*v;
%     k = k + 1;
% end

%All the plots included:
% sgtitle('Objective function vs iteration/step size \alpha = 0.03, \beta=0.3')
% subplot(1, 2, 1);
% title('Objective vs iteration number'); hold on
% plot(linspace(0, 9, 9), vals, 'b');
% xlabel('iteration');
% ylabel('Objective function');
% xlim([0 n]);
% subplot(1, 2, 2);
% title('Step size vs iteration number'); hold on
% plot(linspace(0, 9, 9), steps, 'b');
% xlabel('iteration');
% ylabel('Objective function');
% xlim([0 n]);

% opt = 39.9898;
% %test = log(abs(vals - opt + 1e-6));
% test = vals - opt;
% set(gca, 'YScale', 'log')
% title('Norm of gradient vs iteration \alpha=0.03, \beta=0.3'); hold on
% plot(linspace(0, 9, 9), decs, 'b');
% ylabel('Norm of gradient in log scale');
% xlabel('Iteration');
% plot(linspace(0, 9, 9), test, 'r');
% legend('\lambda^2', 'log(f-p^*)');
% xlim([0,n-1]);
% disp('x');
