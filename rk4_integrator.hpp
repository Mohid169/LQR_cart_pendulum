#pragma once

#include "cart_pendulum.hpp"
#include <cmath>


// Function to perform RK4 integration for the CartPendulum system
void runRK4(CartPendulum& system, double controlForce);
