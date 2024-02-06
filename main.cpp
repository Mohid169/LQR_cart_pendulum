#include "cart_pendulum.hpp"
#include "rk4_integrator.hpp"

#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

void drawWheels(double cartPosition) {
    // Draw wheels
    plt::plot({cartPosition - 0.1, cartPosition + 0.1}, {0, 0}, "ko");  // Wheels
}



int main() {
    // System parameters
    const double cartMass = 1.0;
    const double pendulumMass = 0.1;
    const double pendulumLength = .5;

    // Create CartPendulum instance
    CartPendulum system(cartMass, pendulumMass, pendulumLength);

    // Simulation parameters
    double controlForce = 100;
    const double dt = 0.01;
    const double simulationTime = 2.0;

    // Number of steps
    int numSteps = static_cast<int>(simulationTime / dt);

    // Set up plot
    plt::figure_size(600, 600);
   // plt::ion();  // Turn on interactive mode
 // Set plot limits
         plt::axis("equal");

 const double minY = -1.5;
 const double maxY =1.5;

    plt::ylim(minY, maxY);


    // Animation loop

    for (int i = 0; i < numSteps; ++i) {
        // Run RK4 integration
        runRK4(system, controlForce);

        // Clear the previous plot
        plt::clf();

        // Plot the cart
        double cartWidth = 0.5; // Adjust the width of the rectangle as needed
        double cartHeight = 0.1; // Adjust the height of the rectangle as needed
        double cartLeft = system.getCartPosition() - cartWidth / 2;
        double cartRight = system.getCartPosition() + cartWidth / 2;
        plt::plot({cartLeft, cartRight, cartRight, cartLeft, cartLeft},
                  {0, 0, cartHeight, cartHeight, 0}, "b-");

        //add a string 
        double pendulumX = system.getCartPosition();
        double pendulumY = 0.0;
        double pendulumStringX = pendulumX + pendulumLength * sin(system.getPendulumAngle());
        double pendulumStringY = pendulumY - pendulumLength * cos(system.getPendulumAngle());
        plt::plot({pendulumX, pendulumStringX}, {pendulumY, pendulumStringY}, "k-");

        // Plot the pendulum
        double pendulumTopX = pendulumX + pendulumLength * sin(system.getPendulumAngle());
        double pendulumTopY = pendulumY - pendulumLength * cos(system.getPendulumAngle());
        plt::plot({pendulumX, pendulumTopX}, {pendulumY, pendulumTopY}, "ro");

        // Draw wheels
        drawWheels(system.getCartPosition());

       
        // Add labels and title
        plt::title("Cart-Pendulum Animation");
        plt::xlabel("Cart Position");
        plt::ylabel("Pendulum Height");
          plt::xlim(system.getCartPosition() - 1.5, system.getCartPosition() + 1.5);

        //std::cout << "Pendulum Length at Step " << i << ": " << pendulumLength << std::endl;

        // Pause to create animation effect
              plt::ylim(minY, maxY);
                    


        plt::pause(0.01);
              plt::ylim(minY, maxY);


    }
    plt::show();

    return 0;
}