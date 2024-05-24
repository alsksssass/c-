#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include <string>

class AMateria;

class IMateriaSource
{
public:
virtual ~IMateriaSource() {}
virtual void learnMateria(AMateria*) = 0;
virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif // IMATERIASOURCE_HPP

/*
learnMateria에서는 인자로 들어온 속성을 복사하여, 이후에 사용할 수 있도록 메모리에 저장한다.
캐릭터에서 구현한 것과 비슷하게 MateriaSource는 4개만 보유할 수 있다. 반드시 고유성을 지닐 필요는 없다.
createMateria에서는 이전에 학습한 MateriaSource를 반환한다. 
인자에 들어온 string 값에 해당하는 MateriaSource를 모를 경우 0을 반환한다.
핵심만 말하면 MateriaSource의 템플릿을 학습한 다음 필요할 때마다 생성해낼 수 있어야 한다. 
그러면 새로운 Materia를 string 만으로 구별하여 생성해낼 수 있다.*/