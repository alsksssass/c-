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
	void addNumber(const int a);
	void rangeAdd();
	long long shortestSpan() const;
	long long longestSpan() const;
};