#pragma once

#include <iostream>


class ScalarConverter {
	private:
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(ScalarConverter const &a);
	ScalarConverter& operator=(ScalarConverter const &a);
	public:
		static void convert(std::string str);
};