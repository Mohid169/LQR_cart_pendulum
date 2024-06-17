# Cart-Pendulum Simulation with LQR Controller

This project simulates a cart-pendulum system using a Linear Quadratic Regulator (LQR) controller. The simulation is visualized using `matplotlib` in C++.

## Table of Contents
- [Introduction](#introduction)
- [Installation](#installation)
- [Usage](#usage)
- [Files](#files)
- [License](#license)

## Introduction
The cart-pendulum system is a classic problem in control theory and dynamics. This project demonstrates how to use an LQR controller to stabilize an inverted pendulum mounted on a cart.

## Installation

### Prerequisites
- C++17 or higher
- Eigen library
- matplotlib-cpp library
- CMake

### Steps
1. Clone the repository:
    ```sh
    git clone https://github.com/yourusername/cart-pendulum-simulation.git
    cd cart-pendulum-simulation
    ```
2. Install Eigen:
    ```sh
    sudo apt-get install libeigen3-dev
    ```

3. Set up `matplotlib-cpp`:
    ```sh
    git clone https://github.com/lava/matplotlib-cpp.git
    cd matplotlib-cpp
    mkdir build && cd build
    cmake ..
    sudo make install
    ```

4. Build the project:
    ```sh
    mkdir build
    cd build
    cmake ..
    make
    ```

## Usage
1. Run the executable:
    ```sh
    ./cart_pendulum_simulation
    ```

2. The simulation will display the cart-pendulum system in a window, showing the cart's movement and the pendulum's angle over time.

## Files
- `main.cpp`: Main entry point for the simulation.
- `cart_pendulum.hpp` and `cart_pendulum.cpp`: Defines the `CartPendulum` class that models the dynamics of the system.
- `controller.hpp` and `controller.cpp`: Defines the `Controller` class that implements the LQR controller.
- `CMakeLists.txt`: CMake build configuration file.

### main.cpp
This file contains the main loop of the simulation, setting up the system parameters and the animation using `matplotlibcpp`.

### cart_pendulum.hpp & cart_pendulum.cpp
These files implement the dynamics of the cart-pendulum system, including methods for updating the state of the system.

### controller.hpp & controller.cpp
These files implement the LQR controller used to stabilize the pendulum.

### CMakeLists.txt
This file contains the build configuration for CMake.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.
