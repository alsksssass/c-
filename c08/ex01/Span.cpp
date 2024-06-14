#include "Span.hpp"

Span::Span(const int _idx) : idx(_idx) , cnt(0){
} 
Span::~Span(){
	arr.clear();
}
Span::Span(Span const &a) : idx(a.idx){
	cnt = a.cnt;
	for(unsigned int i = 0; i < a.arr.size(); i++)
		arr[i] = a.arr[i];
}
Span& Span::operator=(Span const &a){
	if(this == &a) return *this;
	arr.clear();
	cnt = a.cnt;
	for(unsigned int i = 0; i < a.arr.size(); i++)
	{
		arr[i] = a.arr[i];
	}
	return *this;
}
void Span::addNumber(const int a){
	if(cnt == idx)
		throw std::out_of_range("out_of_range");
	arr.push_back(a);
	cnt++;
}

long long Span::shortestSpan() const{
	if(cnt < 2)
		throw std::range_error("range_error");
	std::vector<int> temp(arr.begin(),arr.end());
	std::sort(temp.begin(),temp.end());
	long long pre = 0;
	long long ret_num = *(temp.end() -1);
	for (unsigned int i = 0; i < cnt; i ++)
	{
		if(i > 0)
			ret_num = std::min(temp[i] - pre,ret_num);
		pre = temp[i];
	}
	return ret_num;
}
long long Span::longestSpan() const{
	if(cnt < 2)
		throw std::range_error("range_error");
	std::vector<long long> temp(arr.begin(),arr.end());
	std::sort(temp.begin(),temp.end());	
	return (*(temp.end() -1)) - *(temp.begin());
}
