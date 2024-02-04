#include "cart_pendulum.hpp"
#include <iostream>
#include <cmath> 

//Constants
const double g=9.81;
const double dt=.01;


//Constructor for CartPendulum class
CartPendulum::CartPendulum(const double cartMass, const double pendulumMass, const double pendulumLength)
    : M(cartMass), m(pendulumMass), l(pendulumLength),
      x(0.0), z(pendulumLength), theta(0.1), x_dot(0.0), z_dot(0.0), theta_dot(0.0) {}

void CartPendulum::update(double dt, double controlForce,
                          double k1_x_dot, double k2_x_dot, double k3_x_dot, double k4_x_dot,
                          double k1_theta_dot, double k2_theta_dot, double k3_theta_dot, double k4_theta_dot) {
    // Step 1
    double x_dot_avg = (k1_x_dot + 2.0 * k2_x_dot + 2.0 * k3_x_dot + k4_x_dot) / 6.0;
    double theta_dot_avg = (k1_theta_dot + 2.0 * k2_theta_dot + 2.0 * k3_theta_dot + k4_theta_dot) / 6.0;

    // Update position and velocity
    x_dot += x_dot_avg * dt;
    x += x_dot * dt;

    // Equations of motion for the pendulum
    double pendulumForce = -m * l * theta_dot_avg * theta_dot_avg * sin(theta);
    z_dot += (pendulumForce * cos(theta) / m) * dt;
    z += z_dot * dt;

    // Update angular velocity and position
    double torque = -m * l * g * sin(theta); // Torque due to gravity
    double theta_accel = (m * l * theta_dot_avg * theta_dot_avg * cos(theta) - pendulumForce) / (m * l);
    theta_dot += theta_accel * dt;
    theta += theta_dot * dt;
}

// Getter implementations
double CartPendulum::getThetaDot() const {
    return theta_dot;
}

double CartPendulum::getCartVelocity() const {
    return x_dot;
}


double CartPendulum::getCartPosition() const {
    return x;
}

double CartPendulum::getPendulumAngle() const{
    return theta;
}

double CartPendulum::calculateCartAcceleration(double controlForce, double theta, double theta_dot, double x, double x_dot) const {
    return  (controlForce + m * l * theta_dot * theta_dot * sin(theta)) / (M + m); 
}

double CartPendulum::calculateThetaAcceleration(double theta, double theta_dot, double x_double_dot) const {
    // Update the dynamics based on the provided equation
    return (x_double_dot * cos(theta) + g * sin(theta)) / l;
}


// Setter implementations
void CartPendulum::setX(double value) {
    x = value;
}

void CartPendulum::setZ(double value) {
    z = value;
}

void CartPendulum::setTheta(double value) {
    theta = value;
}

void CartPendulum::setXDot(double value) {
    x_dot = value;
}

void CartPendulum::setZDot(double value) {
    z_dot = value;
}

void CartPendulum::setThetaDot(double value) {
    theta_dot = value;
}