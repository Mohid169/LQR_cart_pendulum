#include "cart.hpp"


Cart::Cart(double mass, double position, double velocity)
    : mass(mass), position(position), velocity(velocity) {}

void Cart::update(double force) {
    double acceleration = force / mass;
    velocity += acceleration * dt;
    position += velocity * dt;
}

double Cart::getPosition() const {
    return position;
}
