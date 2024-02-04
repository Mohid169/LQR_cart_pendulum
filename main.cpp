#include "cart_pendulum.hpp"
#include "rk4_integrator.hpp"

int main() {
    // Instantiate your CartPendulum and set initial conditions
    double cartMass = 5.0;
    double pendulumMass = 1.0;
    double pendulumLength = 1.0;
    CartPendulum system(cartMass, pendulumMass, pendulumLength);

    // Set control force and run RK4
    double controlForce = 0.0;
    runRK4(system, controlForce);

    return 0;
}