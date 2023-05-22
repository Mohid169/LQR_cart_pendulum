#include idndef CART_HPP
#define CART_HPP

class Cart {
private:
		double mass;
		double posistion; 
		double velocity; 

public:

	Cart(double mass, double posistion, velocity);

	void update(force);

	double getPosition() const;

}; 

#endif 