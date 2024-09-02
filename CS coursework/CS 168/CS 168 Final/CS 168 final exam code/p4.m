%Initialization and variable stuff
%Note I've commented out part a stuff for now, 
randn('seed', 1); 
T = 96; % 15 minute intervals in a 24 hour period
t = (1:T)'; 
p = exp(-cos((t-15)*2*pi/T)+0.01*randn(T,1)); 
u = 2*exp(-0.6*cos((t+40)*pi/T) -0.7*cos(t*4*pi/T)+0.01*randn(T,1));
Q = 35;
C = 3; 
D = 3;

% Part a convex problem
% cvx_quiet(true);
% cvx_begin
%     variables q(T,1) c(T,1); 
%     minimize(p'*(u+c));
%     subject to
%     c <= C;
%     c >= -D;
%     q <= Q;
%     q >= 0;
%     q(2:T) == q(1:T-1) + c(1:T-1); 
%     q(1) == q(T) + c(T);
%     u+c >= 0;
% cvx_end

%Makes the four graphs displayed in my submission for 4a
% figure; 
% ts = (1:T)/4;
% subplot(4,1,1);
% plot(ts,u); hold on
% xlabel('t');
% ylabel('u_t');
% subplot(4,1,2);
% plot(ts, c);
% xlabel('t');
% ylabel('c_t');
% subplot(4,1,3);
% plot(ts, p);
% ylabel('p_t');
% xlabel('t');
% subplot(4,1,4);
% plot(ts,q);
% ylabel('q_t');
% xlabel('t');
%To run part a code, just uncomment the code, and probably comment out the
%part below
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%Variable initialization, I chose between 0 and 100 just because
Q = linspace(0, 100);

%Variables storing results of
Q_res = zeros(T, 100);
C_res = zeros(T, 100);
c_res = zeros(T, 1);
cvx_quiet(true);

%Loops through and does problem 100 times for C,D=3 case
for i = 1:100
    cvx_begin
        Q_curr = Q(i);
        variables q(T,1) c(T,1); 
        minimize(p'*(u+c));
        c <= C; %Not sure what to use instead of <= but this works
        c >= -D;
        q <= Q_curr;
        q >= 0;
        q(2:T) == q(1:T-1) + c(1:T-1); 
        q(1) == q(T) + c(T);
        u+c >= 0;
    cvx_end
    Q_res(:,i) = q; %Saves results just in case
    C_res(:,i) = c;
    c_res(i) = cvx_optval;
end

%Now does the case for C,D=1
C = 1;
D = 1;
Q_2 = linspace(0, 100);
c_res_2 = zeros(T, 1);
cvx_quiet(true);
for i = 1:100
    cvx_begin
        Q_curr = Q_2(i);
        variables q(T,1) c(T,1); minimize(p'*(u+c));
        c <= C;
        c >= -D;
        q <= Q_curr;
        q >= 0;
        q(2:T) == q(1:T-1) + c(1:T-1); 
        q(1) == q(T) + c(T);
        u+c >= 0;
    cvx_end
    c_res_2(i) = cvx_optval; %Saves optimal value for graph
end

%Now that both have run, generate plots and compare
plot(Q, c_res, 'b'); hold on
plot(Q, c_res_2, 'r');
legend('C,D=3', 'C,D=1');
xlabel('Q');
ylabel('cost');