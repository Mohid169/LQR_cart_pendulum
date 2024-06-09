import numpy as np
import control 


# Define the parameters
cartMass = 1.0
pendulumMass = 0.1
pendulumLength = .5
g = 9.81  

#TODO: fill in A/B matrices (based on linearized equations)
A = np.array([ ] )
B = np.array([ ] )

#Define the weighing matrices
Q = np.array([ ] )
R = np.array([ ] )

K = control.lqr(A,B, Q,R) 
print("Gain matrix: ")
print(K)
