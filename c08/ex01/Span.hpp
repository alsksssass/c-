#pragma once
#include <vector>
#include <exception>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
class Span {
	private:
	std::vector<int> arr;
	unsigned int idx;
	unsigned int cnt;
	Span();
	public:
	Span(const int _idx);
	~Span();
	Span(Span const &a);
	Span& operator=(Span const &a);
	template<typename iterator>
	void rangeAdd(iterator st, iterator ed){
		if(st == ed)	return;
		for(iterator it = st; it !=ed; it++)
			addNumber(*it);
	}
	void addNumber(const int);
	long long shortestSpan() const;
	long long longestSpan() const;
};