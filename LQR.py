import numpy as np
import control 


# Define the parameters
cartMass = 1.0
pendulumMass = 0.1
pendulumLength = .5
g = 9.81  

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
Q = np.diag([1, 10, 1, 10])
R = np.array([[.1]]) # I care about smooth control inputs

K, _, _ = control.lqr(A,B, Q,R) 
print("Gain matrix: ")
print("K << ", end="")
for i in range(K.shape[0]):
    for j in range(K.shape[1]):
        print(f"{K[i, j]:.8f}", end="")
        if i == K.shape[0] - 1 and j == K.shape[1] - 1:
            print(";", end="")
        else:
            print(", ", end="")
print()