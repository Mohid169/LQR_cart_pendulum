// File RK4_integrator.cpp


// File RK4_integrator.cpp


#include "rk4_integrator.hpp"
#include <cmath>

const double dt = .01;


// void runRK4(CartPendulum& system, double controlForce) {

// // Step 1
// double k1_theta_dot = system.getThetaDot();
// double k1_theta_accel = system.calculateThetaAcceleration(system.getPendulumAngle(), k1_theta_dot, system.calculateCartAcceleration(controlForce, system.getPendulumAngle(), k1_theta_dot, system.getCartPosition(), system.getCartVelocity()));
// double k1_x_dot = system.calculateCartAcceleration(controlForce, system.getPendulumAngle(), k1_theta_dot, system.getCartPosition(), system.getCartVelocity());
// double k1_x_accel = system.calculateCartAcceleration(controlForce, system.getPendulumAngle(), k1_theta_dot, system.getCartPosition(), system.getCartVelocity());

// // Step 2
// double k2_theta_dot = system.getThetaDot() + k1_theta_accel * dt / 2.0;
// double k2_theta_accel = system.calculateThetaAcceleration(system.getPendulumAngle() + k1_theta_dot * dt / 2.0, system.getThetaDot() + k1_theta_accel * dt / 2.0, system.calculateCartAcceleration(controlForce, system.getPendulumAngle() + k1_theta_dot * dt / 2.0, system.getThetaDot() + k1_theta_accel * dt / 2.0, system.getCartPosition() + k1_x_dot * dt / 2.0, system.getCartVelocity() + k1_x_accel * dt / 2.0));
// double k2_x_dot = system.calculateCartAcceleration(controlForce, system.getPendulumAngle() + k1_theta_dot * dt / 2.0, system.getThetaDot() + k1_theta_accel * dt / 2.0, system.getCartPosition() + k1_x_dot * dt / 2.0, system.getCartVelocity() + k1_x_accel * dt / 2.0);
// double k2_x_accel = system.calculateCartAcceleration(controlForce, system.getPendulumAngle() + k1_theta_dot * dt / 2.0, system.getThetaDot() + k1_theta_accel * dt / 2.0, system.getCartPosition() + k1_x_dot * dt / 2.0, system.getCartVelocity() + k1_x_accel * dt / 2.0);

// // Step 3
// double k3_theta_dot = system.getThetaDot() + k2_theta_accel * dt / 2.0;
// double k3_theta_accel = system.calculateThetaAcceleration(system.getPendulumAngle() + k2_theta_dot * dt / 2.0, system.getThetaDot() + k2_theta_accel * dt / 2.0, system.calculateCartAcceleration(controlForce, system.getPendulumAngle() + k2_theta_dot * dt / 2.0, system.getThetaDot() + k2_theta_accel * dt / 2.0, system.getCartPosition() + k2_x_dot * dt / 2.0, system.getCartVelocity() + k2_x_accel * dt / 2.0));
// double k3_x_dot = system.calculateCartAcceleration(controlForce, system.getPendulumAngle() + k2_theta_dot * dt / 2.0, system.getThetaDot() + k2_theta_accel * dt / 2.0, system.getCartPosition() + k2_x_dot * dt / 2.0, system.getCartVelocity() + k2_x_accel * dt / 2.0);
// double k3_x_accel = system.calculateCartAcceleration(controlForce, system.getPendulumAngle() + k2_theta_dot * dt / 2.0, system.getThetaDot() + k2_theta_accel * dt / 2.0, system.getCartPosition() + k2_x_dot * dt / 2.0, system.getCartVelocity() + k2_x_accel * dt / 2.0);

// // Step 4
// double k4_theta_dot = system.getThetaDot() + k3_theta_accel * dt;
// double k4_theta_accel = system.calculateThetaAcceleration(system.getPendulumAngle() + k3_theta_dot * dt, system.getThetaDot() + k3_theta_accel * dt, system.calculateCartAcceleration(controlForce, system.getPendulumAngle() + k3_theta_dot * dt, system.getThetaDot() + k3_theta_accel * dt, system.getCartPosition() + k3_x_dot * dt, system.getCartVelocity() + k3_x_accel * dt));
// double k4_x_dot = system.calculateCartAcceleration(controlForce, system.getPendulumAngle() + k3_theta_dot * dt, system.getThetaDot() + k3_theta_accel * dt, system.getCartPosition() + k3_x_dot * dt, system.getCartVelocity() + k3_x_accel * dt);
// double k4_x_accel = system.calculateCartAcceleration(controlForce, system.getPendulumAngle() + k3_theta_dot * dt, system.getThetaDot() + k3_theta_accel * dt, system.getCartPosition() + k3_x_dot * dt, system.getCartVelocity() + k3_x_accel * dt);

 
// system.update(dt, controlForce,
//                   k1_x_dot, k2_x_dot, k3_x_dot, k4_x_dot,
//                   k1_theta_dot, k2_theta_dot, k3_theta_dot, k4_theta_dot);



// }
        
