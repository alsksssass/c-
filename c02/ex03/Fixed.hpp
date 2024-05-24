#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
class Fixed {
private:
	int fix_point;
	static const int bit = 8;
public:
	Fixed();
	Fixed(const int num);
	Fixed(const float num);
	Fixed(const Fixed &s);
	Fixed &operator=(const Fixed &s);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);
	int toInt(void) const;
	float toFlot(void) const;
	Fixed& operator ++ ();
	const Fixed operator ++ (int);
	Fixed& operator -- ();
	const Fixed operator -- (int);
	static Fixed& min(Fixed &a, Fixed &b);
	static const Fixed& min(const Fixed &a, const Fixed &b);
	static Fixed& max(Fixed &a, Fixed &b);
	static const Fixed& max(const Fixed &a, const Fixed &b);

};
std::ostream &operator << (std::ostream &stream, const Fixed &a);
bool operator > (const Fixed &a, const Fixed &b);
bool operator < (const Fixed &a, const Fixed &b);
bool operator == (const Fixed &a, const Fixed &b);
bool operator != (const Fixed &a, const Fixed &b);
bool operator >= (const Fixed &a, const Fixed &b);
bool operator <= (const Fixed &a, const Fixed &b);
Fixed operator + (const Fixed &a, const Fixed &b);
Fixed operator - (const Fixed &a, const Fixed &b);
Fixed operator * (const Fixed &a, const Fixed &b);
Fixed operator / (const Fixed &a, const Fixed &b);
#endif