#include "Fixed.hpp"
#include <cmath>
Fixed::Fixed(){ 
	std::cout << "Default constructor called" << std::endl;
	fix_point = 0;}
Fixed::Fixed(const int num){ 
	std::cout << "Int constructor called" << std::endl;
	fix_point = num << bit;}
Fixed::Fixed(const float num){ 
	std::cout << "Float constructor called" << std::endl;
	fix_point = roundf(num * (1<< bit));}
	

Fixed::Fixed(const Fixed &s){
	std::cout << "Copy constructor called" << std::endl;
	*this = s;
}
int Fixed::toInt() const {
	return fix_point>> bit;
}
float Fixed::toFlot(void) const{
	return (float)fix_point/(1 << bit);
}
Fixed& Fixed::operator=(const Fixed &s){
	std::cout << "Copy assignment operator called" << std::endl;
	if(this != &s)
	{
		this->fix_point = s.fix_point;
	}
	return *this;
}
std::ostream& operator << (std::ostream &stream, const Fixed &a){
	stream << a.toFlot();
	return stream;
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

