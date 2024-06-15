
#include <Eigen/Dense>

class Controller {
    private:
         Eigen::MatrixXd K;

    public:
     // Constructor
     Controller();

     ~Controller();

     // Function to compute control force based on current state
    double computeControlForce(const Eigen::VectorXd& state) const;


};
 