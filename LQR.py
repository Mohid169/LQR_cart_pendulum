import numpy as np
import control 


# Define the parameters
cartMass = 1.0
pendulumMass = 0.1
pendulumLength = .5
g = 9.81  

#TODO: fill in A/B matrices (based on linearized equations)
A = np.array([
    [0, 0, 1, 0],
    [0, 0, 0, 1],
    [0, pendulumMass * g / cartMass, 0, 0],
    [0, (pendulumMass + cartMass) * g / (cartMass * pendulumLength), 0, 0]

])

B = np.array([
    [0],
    [0],
    [1 / cartMass],
    [1 / (cartMass * pendulumLength)]
])

#Define the weighing matrices
Q = np.diag([1, 1, 10, 10])
R = np.array([[0.1]]) # I care about smooth control inputs

K = control.lqr(A,B, Q,R) 
print("Gain matrix: ")
print(K)
