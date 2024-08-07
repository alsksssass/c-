#include "RPN.hpp"
RPN::RPN(){}
RPN::~RPN(){}
bool operator_check(int a)
{
	if(a == '+' || a == '-' || a == '*' || a == '/')
		return true;
	return false;
}

long calcule(long a, long b, int c)
{
	if(c == '+')
		return a + b;
	else if(c == '-')
		return a - b;
	else if(c == '*')
		return a * b;
	else if(c == '/')
	{
		if(b == 0)
			throw std::invalid_argument("Error : Divide by zero");
		return  a / b;
	}
	else
		throw std::invalid_argument("Error : calculator");
}
void RPN::push(std::string &a){
	for(int i = 0; i < (int)a.size(); i++)
	{
		if(a[i] == ' ')
			continue;
		if(std::isdigit(a[i]) == false && operator_check(a[i]) == false)
			throw std::invalid_argument("Error syntax digit");
		if(operator_check(a[i]) == true)
		{
			if(st.size() < 2)
				throw std::invalid_argument("Error syntax argument");
			long c = st.top(); st.pop();
			long b = st.top(); st.pop();
			st.push(calcule(b,c,a[i]));
		}
		else
			st.push(a[i] - '0');
	}
	if(st.size()!= 1)
		throw std::invalid_argument("Error syntax size");
	std::cout << st.top() << std::endl;
}