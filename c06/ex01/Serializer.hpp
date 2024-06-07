#pragma once
#include <iostream>
#include <cstdint>

struct Data{
	int num;
};
class Serializer{
	private:
	Serializer();
	~Serializer();
	Serializer(Serializer const &a);
	Serializer& operator=(Serializer const &a);
	public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};