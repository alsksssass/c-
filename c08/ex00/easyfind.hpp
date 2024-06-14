#pragma once
#include <algorithm>
#include <exception>
#include <iostream>
template<typename T>
typename T::iterator easyfind (T &p, const int num){
	typename T::iterator it = std::find(p.begin(),p.end(),num);
	if(it == p.end())
		throw std::range_error("error range");
	return it;
};
template<typename T>
typename T::const_iterator easyfind (const T &p, const int num){
	std::cout << "const " <<std::endl;
	typename T::const_iterator it = std::find(p.begin(),p.end(),num);
	if(it == p.end())
		throw std::range_error("error range");
	return it;
};