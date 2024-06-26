#include "MateriaSource.hpp"
MateriaSource::MateriaSource(){
	std::cout << "MateriaSource Construct Call" << std::endl;
	for(int i = 0; i < 4; i++)
		memory[i] = 0;
}
MateriaSource::~MateriaSource(){
	std::cout << "MateriaSource Destruct Call" << std::endl;
	for(int i = 0; i < 4; i++)
		delete memory[i];
}
MateriaSource::MateriaSource(const MateriaSource &a){
	std::cout << "MateriaSource Copy Construct Call" << std::endl;
	for(int i =0; i < 4; i++)
	{
		if(a.memory[i] != NULL)
			memory[i] = a.memory[i]->clone();
		else
			memory[i] = 0;
	}
}
MateriaSource& MateriaSource::operator=(const MateriaSource &a){
	std::cout << "MateriaSource assignment operator Call" << std::endl;
	if (this != &a)
	{
		for (int i = 0; i < 4; i++)
		{
			if (memory[i] != NULL)
			{
				delete memory[i];
				memory[i] = 0;
			}
			if(a.memory[i] != NULL)
				memory[i] = a.memory[i]->clone();
		}
	}
	return *this;
}
AMateria* MateriaSource::createMateria(std::string const & type){
	for(int i = 0; i < 4; i++)
	{
		if(memory[i] && memory[i]->getType() == type)
			return memory[i]->clone();
	}
	return NULL;
}
void MateriaSource::learnMateria(AMateria* a){
	for(int i = 0; i < 4; i++)
	{
		if(memory[i] == NULL)
		{
			memory[i] = a;
			return;
		}
	}
	delete a;
}