import math

class CartPendulum:
    def __init__(self, cart_mass, pendulum_mass, pendulum_length, g):
        self.cart_mass = cart_mass  # Mass of the cart
        self.pendulum_mass = pendulum_mass  # Mass of the pendulum
        self.pendulum_length = pendulum_length  # Length of the pendulum
        self.g = g  # Acceleration due to gravity

    def calculate_cart_acceleration(self, control_force, theta, theta_dot, x, x_dot):
        # Calculate cart acceleration (x_double_dot)
        numerator = control_force + self.pendulum_mass * self.g * math.sin(theta) * math.cos(theta) - self.pendulum_mass * self.pendulum_length * math.sin(theta) * math.pow(theta_dot, 2)
        denominator = self.cart_mass + self.pendulum_mass * (math.pow(math.sin(theta), 2))
        x_accel = numerator / denominator
        print("x_accel:", x_accel)
        return x_accel

    def calculate_theta_acceleration(self, control_force, theta, theta_dot, x_double_dot):
        # Update the dynamics based on the provided equation
        numerator = control_force * math.cos(theta) - self.pendulum_mass * self.pendulum_length * math.pow(theta_dot, 2) * math.cos(theta) * math.sin(theta) + (self.cart_mass + self.pendulum_mass) * self.g * math.sin(theta)
        denominator = (self.cart_mass + self.pendulum_mass * math.pow(math.sin(theta), 2)) * self.pendulum_length
        theta_accel = numerator / denominator
        print("theta_accel:", theta_accel)
        return theta_accel

cart_mass = 1.0  # Mass of the cart
pendulum_mass = 0.1  # Mass of the pendulum
pendulum_length = 0.5  # Length of the pendulum
g = 9.81  # Acceleration due to gravity

cart_pendulum = CartPendulum(cart_mass, pendulum_mass, pendulum_length, g)

control_force = 0.0891425
theta = -0.0108084
theta_dot = 0.0
x = -0.42297
x_dot = 0.0

x_double_dot = cart_pendulum.calculate_cart_acceleration(control_force, theta, theta_dot, x, x_dot)
theta_double_dot = cart_pendulum.calculate_theta_acceleration(control_force, theta, theta_dot, x_double_dot)
