#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <string>
class AMateria;

class ICharacter
{
public:
virtual ~ICharacter() {}
virtual std::string const & getName() const = 0;
virtual void equip(AMateria* m) = 0;
virtual void unequip(int idx) = 0;
virtual void use(int idx, ICharacter& target) = 0;
};
#endif // ICHARACTER_HPP

/*
Character 클래스는 4개의 빈 인벤토리를 가지며 Materia를 슬롯 0~3 순서로 장착한다. 
인벤토리가 가득 찼을 때 속성을 추가하거나 없는 Materias를 사용/해제하려고 했다면 아무런 동작도 하지 않는다.
(당연하지만 버그는 금지됨)
unequip 함수는 절대 Materias를 delete 하지 않는다.
(캐릭터가 unequip 하고 사용하지 않는 Materias는 알아서 처리하되 메모리 릭이 있으면 안 됨)
use 함수는 slot [idx]의 Materias를 사용하며 target은 AMateria의 use에 인자로 넘긴다.
당연히 캐릭터의 인벤토리는 어떤 Materias도 담을 수 있어야 한다.
캐릭터 클래스는 name을 인자로 받는 생성자가 있어야 하며, 대입/복사 연산은 당연히 깊은 복사여야 함.
복사 중에는 이전에 보유한 속성은 delete 되어야 하고, 소멸자 역시 당연히 그렇게 되어야 함.
아래와 같은 IMateriaSource 인터페이스 클래스를 구현하라.
*/