#pragma once

#ifndef RK4_INTEGRATOR_HPP
#include <cmath>
#include "cart_pendulum.hpp"



// Function to perform RK4 integration for the CartPendulum system
void runRK4(CartPendulum& system, double controlForce);
#endif // RK4_INTEGRATOR_HPP
