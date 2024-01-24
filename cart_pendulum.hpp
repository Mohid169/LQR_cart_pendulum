#inndef CART_PENDULUM_HPP
#define CART_PENDULUM_HPP

/**
 * @brief Represents a cart-pendulum system.
 *
 * This class models the dynamics of an inverted pendulum mounted on a cart.
 * The equations of motion are simulated to analyze the behavior of the system.
 */

class CartPendulum {
private:
    double M; // Mass of the cart.
    double m; // Mass of the pendulum.
    double I; // Moment of inertia of the pendulum.
    double l; // Length of the pendulum.
    double x; // Position of the cart along the x-axis.
    double z; // Vertical position of the pendulum's center of mass.
    double theta; // < Angle of the pendulum.
    double x_dot; // Velocity of the cart.
    double z_dot; // Velocity of the pendulum's center of mass.
    double theta_dot; //< Angular velocity of the pendulum.

public:
    /**
     * @brief Constructor for the CartPendulum class.
     *
     * @param cartMass Mass of the cart.
     * @param pendulumMass Mass of the pendulum.
     * @param pendulumLength Length of the pendulum.
     */
    CartPendulum(double cartMass, double pendulumMass, double pendulumLength);

    /**
     * @brief Update the state of the system based on a control force.
     *
     * @param controlForce The force applied to the cart.
     */
    void update(double controlForce);

    /**
     * @brief Get the position of the cart along the x-axis.
     *
     * @return The position of the cart.
     */
    double getCartPosition() const;

    /**
     * @brief Get the angle of the pendulum.
     *
     * @return The angle of the pendulum.
     */
    double getPendulumAngle() const;

     // Setters for initial conditions
    void setX(double value);
    void setZ(double value);
    void setTheta(double value);
    void setXDot(double value);
    void setZDot(double value);
    void setThetaDot(double value);
};

#endif // CART_PENDULUM_HPP
