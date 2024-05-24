#include "Fixed.hpp"
#include <cmath>
Fixed::Fixed(){ 
	fix_point = 0;}
Fixed::Fixed(const int num){ 
	fix_point = num << bit;}
Fixed::Fixed(const float num){ 
	fix_point = roundf(num * (1 << bit));}

Fixed::Fixed(const Fixed &s){
	*this = s;
}
int Fixed::toInt() const {
	return fix_point>> bit;
}
float Fixed::toFlot(void) const{
	return (float)fix_point/(1 << bit);
}
Fixed& Fixed::operator=(const Fixed &s){
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
}
int Fixed::getRawBits(void) const{
	return fix_point;
}
void Fixed::setRawBits(int const raw){
	fix_point = raw;
}

bool operator > (const Fixed &a, const Fixed &b) {return a.getRawBits() > b.getRawBits() ? true : false;}
bool operator < (const Fixed &a, const Fixed &b) {return a.getRawBits() < b.getRawBits() ? true : false;}
bool operator == (const Fixed &a, const Fixed &b) {return a.getRawBits() == b.getRawBits()? true : false;}
bool operator != (const Fixed &a, const Fixed &b) {return a.getRawBits() != b.getRawBits()? true : false;}
bool operator >= (const Fixed &a, const Fixed &b) {return a.getRawBits() >= b.getRawBits()? true : false;}
bool operator <= (const Fixed &a, const Fixed &b) {return a.getRawBits() <= b.getRawBits()? true : false;}
Fixed operator + (const Fixed &a, const Fixed &b)
{
	Fixed ret(a.toFlot() + b.toFlot());
	return ret;
}
Fixed operator - (const Fixed &a, const Fixed &b)
{
	Fixed ret(a.toFlot() - b.toFlot());
	return ret;
}
Fixed operator * (const Fixed &a, const Fixed &b)
{
	Fixed ret(a.toFlot() * b.toFlot());
	return ret;
}
Fixed operator / (const Fixed &a, const Fixed &b)
{
	Fixed ret(a.toFlot() / b.toFlot());
	return ret;
}
Fixed& Fixed::operator ++ ()
{
	this->fix_point++;
	return *this;
}
const Fixed Fixed::operator++(int)
{
	Fixed const ret (*this);
	this->fix_point++;
	return ret;
}
Fixed& Fixed::operator--()
{
	this->fix_point--;
	return *this;
}
const Fixed Fixed::operator -- (int)
{
	Fixed const ret (*this);
	this->fix_point--;
	return ret;
}

Fixed& Fixed::min(Fixed &a, Fixed &b){return a < b ? a : b;}
const Fixed& Fixed::min(const Fixed &a, const Fixed &b){return a < b ? a : b;}
Fixed& Fixed::max(Fixed &a, Fixed &b){return a > b ? a : b;}
const Fixed& Fixed::max(const Fixed &a, const Fixed &b){return a > b ? a : b;}
