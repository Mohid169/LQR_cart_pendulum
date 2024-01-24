#include "cart_pendulum.hpp"
#include <iostream>
#include <cmath> 

//Constants
const double g=9.81;
const double dt=.01;

// Default constructor with default initial conditions
CartPendulum::CartPendulum()
    : M(5.0), m(1.0), l(1.0),
      x(0.0), z(1.0), theta(0.1), x_dot(0.0), z_dot(0.0), theta_dot(0.0) {}

//Constructor for CartPendulum class
CartPendulum::CartPendulum(double cartMass, double pendulumMass, double pendulumLength)
    : M(cartMass), m(pendulumMass), l(pendulumLength),
      x(0.0), z(pendulumLength), theta(0.1), x_dot(0.0), z_dot(0.0), theta_dot(0.0) {}

void CartPendulum::update(double controlForce){
    //Equations of motion for the cart
    double cartAcceleration = (controlForce + m * l * theta_dot * theta_dot * sin(theta)) / (M + m);
    x_dot += cartAcceleration * dt; //cart accel forward integrated into time is cart velocity
    x += x_dot * dt; //cart velocity forward integrated into time is cart pos

    //Equations of motions for the pendulum
    double pendulumForce = -m * l * theta_dot * theta_dot * sin(theta); 
    z_dot += (pendulumForce * cos(theta) / m ) * dt;
    z += z_dot * dt;

    // Update angular velocity and position
    double torque = -m * l * g * sin(theta); // Torque due to gravity
    double theta_accel = (m * l * theta_dot * theta_dot * cos(theta) - pendulumForce) / (m * l);
    theta_dot += theta_accel * dt;
    theta += theta_dot * dt;
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