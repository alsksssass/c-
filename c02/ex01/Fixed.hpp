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
};

	std::ostream &operator << (std::ostream &stream, const Fixed &a);
#endif