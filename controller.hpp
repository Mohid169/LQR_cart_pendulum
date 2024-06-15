#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <Eigen/Dense>

class Controller {
    private:
         Eigen::MatrixXd;

    public:
     // Constructor
     Controller();

     ~Controller();

     // Function to compute control force based on current state
    double computeControlForce(const Eigen::VectorXd& state) const;

    // Function to set the LQR gain matrix K
    void setLQRGainMatrix(const Eigen::MatrixXd& gainMatrix);
};
 