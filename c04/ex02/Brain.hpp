#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <string>
#include <iostream>
class Brain {
private:
	std::string ideas[100];
public:
	Brain();
	~Brain();
	Brain(const Brain &a);
	Brain &operator=(const Brain &a);
	void setBrain(int idx, const std::string memory);
	std::string getBrain(int idx);
};

#endif // BRAIN_HPP