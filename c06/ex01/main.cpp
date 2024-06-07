#include "Serializer.hpp"

int main()
{
	Data *a = new Data();
	a->num = 99;

	std::cout << a << std::endl;
	std::cout << a->num << std::endl;

	uintptr_t b =  Serializer::serialize(a);
	std::cout << std::hex << b << std::endl;
	Data *ret = Serializer::deserialize(b);
	std::cout << ret << std::endl;
	std::cout << std::dec <<ret->num << std::endl;
	return 0;
}