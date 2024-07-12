#pragma once
#include <stack>
#include <cctype>
#include <iostream>
#include <exception>
class RPN {
	private:
		std::stack <long> st;
		RPN(RPN const &a);
		RPN &operator=(RPN const &a);
	public:
		RPN();
		~RPN();
		void push(std::string &a);
};