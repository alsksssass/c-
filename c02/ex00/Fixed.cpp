#include "Fixed.hpp"
Fixed::Fixed(){ 
	fix_point = 0;
	std::cout << "Default constructor called" << std::endl;}
Fixed::Fixed(const Fixed &s){
	std::cout << "Copy constructor called" << std::endl;
	this->fix_point = s.getRawBits();
}
Fixed& Fixed::operator=(const Fixed &s){
	std::cout << "Copy assignment operator called" << std::endl;
	if(this != &s)
	{
		this->fix_point = s.getRawBits();
	}
	return *this;
}
Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}
int Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called" << std::endl;
	return fix_point;
}
void Fixed::setRawBits(int const raw){
	fix_point = raw;
}

