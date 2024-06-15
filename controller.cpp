#include "controller.hpp"

// Define the specific value of K here
static const Eigen::MatrixXd K_value = [] (){
    Eigen::MatrixXd K(1,4);
    K << -3.16227766,  78.90677196, -11.99644004,  20.22234155;
    return K;
}();
//Constructor
Controller::Controller() {
    K = K_value;
};

//Destructor
Controller::~Controller() {};

//Function to compute control force based on current state
double Controller::computeControlForce(const Eigen::Vector)