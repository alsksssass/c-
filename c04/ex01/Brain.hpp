#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <string>
#include <iostream>
class Brain {
private:
	std::string *ideas;
public:
	Brain();
	~Brain();
	Brain(const Brain &a);
	Brain &operator=(const Brain &a);
};

#endif // BRAIN_HPP