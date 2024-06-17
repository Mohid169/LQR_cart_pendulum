#include "controller.hpp"

// Define the specific value of K here
static const Eigen::MatrixXd K_value = [] (){
    Eigen::MatrixXd K(1,4);
    K << -3.16227766, 54.83770148, -6.19654141, 15.57851760;

   // K << -10.00000000, 136.73940808, -18.88850316, 43.45512349;

  //  K << -3.16227766, 62.12032081, -6.56446997, 19.50071771;

  //  K << 2.23606798, 18.39136499, 4.27826100, 7.64654265;

   // K << -2.23606798, 46.43423141, -4.60964924, 13.33053083;

    //K << -1.00000000, 31.69839389, -2.29400646, 7.58504594;

    //K <<-0.31622777, 25.77917966, -1.03261577,  5.67829062;
    // -0.1 , 23.70458528,  -0.52275607,  5.1262609;
    
    //-1, 38.87629279, -3.96558315 , 9.11555351;
   // -3.16227766,  78.90677196, -11.99644004,  20.22234155;
    return K;
}();
//Constructor
Controller::Controller() {
    K = K_value;
};

//Destructor
Controller::~Controller() {};

//Function to compute control force based on current state
double Controller::computeControlForce(const Eigen::VectorXd& state) const {
    if (state.size()!=4){
        throw std::invalid_argument("State vector must have 4 elements");
    }
    return (-1.0*K*state)(0,0);
}