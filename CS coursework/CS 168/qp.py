import cvxpy as cp
import numpy as np

delta_1 = 0
delta_2 = 0
P = np.array([[2, -1], [-1, 4]])
A = np.array([[1, 2], [1, -4], [5, 76]])
b = np.array([-2 + delta_1, -3 + delta_2, 1])
q = np.array([-1, 0])

# Define and solve the CVXPY problem.
x = cp.Variable(2)
prob = cp.Problem(cp.Minimize((1/2)*cp.quad_form(x, P) + q @ x),
                 [A @ x <= b])

prob.solve()

# Print result.
print("\nThe optimal value is", prob.value)
print("The solution* x is")
print(x.value)
print("The dual solution corresponding to the inequality constraints is")
print(prob.constraints[0].dual_value)