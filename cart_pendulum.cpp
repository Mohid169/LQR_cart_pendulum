#include "cart_pendulum.hpp"
#include <iostream>
#include <cmath> 

//Constants
const double g=9.81;
// TO DO LIST: ii
// (1) Refactor CODE - change function calls, remove z parameters
// (2) Re-derive math 

//Constructor for CartPendulum class
CartPendulum::CartPendulum(const double cartMass, const double pendulumMass, const double pendulumLength)
    : M(cartMass), m(pendulumMass), l(pendulumLength),
      x(0.0), z(pendulumLength), theta(M_PI/2), x_dot(0.0), z_dot(0.0), theta_dot(0.0) {}

//delete 'z' parameter, not used for anything
 
 void CartPendulum::update(double controlForce, double dt){
    double x_double_dot =  calculateCartAcceleration(controlForce, theta, theta_dot, x, x_dot); 
    //Change function signature to be not shit
    double theta_double_dot = calculateThetaAcceleration(controlForce, theta,  theta_dot, x_double_dot);

     // Update velocities using Euler integration
    x_dot += x_double_dot * dt;
    theta_dot += theta_double_dot * dt;

    // Update positions using Euler integration
    x += x_dot * dt;
    theta += theta_dot * dt;


 };



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
    // Calculate cart acceleration (x_double_dot)
    double numerator = controlForce + m*g*sin(theta)*cos(theta)-m*l*sin(theta)*pow(theta_dot,2);

    double denominator = M - m* (pow(sin(theta), 2));
    std::cout<<"x_accel: ";
    std::cout<<numerator/denominator<<std::endl;
    return numerator / denominator;
}

double CartPendulum::calculateThetaAcceleration(double controlForce, double theta, double theta_dot, double x_double_dot) const {
    // Update the dynamics based on the provided equation
    double numerator = 1.0*controlForce*cos(theta) - m*l*pow(theta_dot,2 )*cos(theta)*sin(theta) + (M+m)*g*sin(theta);
    double denominator = (M - m * pow(sin(theta), 2)) * l;
    std::cout<<"theta accel";
    std::cout<<numerator/denominator<<std::endl;
    return numerator / denominator;
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



// void CartPendulum::RK_4update(double dt, double controlForce,
//                           double k1_x_dot, double k2_x_dot, double k3_x_dot, double k4_x_dot,
//                           double k1_theta_dot, double k2_theta_dot, double k3_theta_dot, double k4_theta_dot) {
//     // Step 1
//     double x_dot_avg = (k1_x_dot + 2.0 * k2_x_dot + 2.0 * k3_x_dot + k4_x_dot) / 6.0;
//     double theta_dot_avg = (k1_theta_dot + 2.0 * k2_theta_dot + 2.0 * k3_theta_dot + k4_theta_dot) / 6.0;

//       // Update position and velocity of the cart
//     x_dot += x_dot_avg * dt;
//     x += x_dot * dt;
//     // Equations of motion for the pendulum
//     //double pendulumForce = -m * l * theta_dot_avg * theta_dot_avg * sin(theta);
//     theta_dot += theta_dot_avg * dt;  // Update angular velocity
//     theta += theta_dot * dt;  // Update angle

//     std::cout<<theta<<std::endl;
//     std::cout<<x<<std::endl;
// }