#include <iostream>

#include "Serializer.hpp"

int main(){
	Data data;
	data.data = 42;

	std::cout << "Data ptr: " << &data << std::endl;
	std::cout << "Data data: " << data.data << std::endl;

	uintptr_t serialized = Serializer::serialize(&data);
	std::cout << "Serialized: " << serialized << std::endl;
	Data* deserialized = Serializer::deserialize(serialized);

	std::cout << "Deserialized data ptr: " << deserialized << std::endl;
	std::cout << "Deserialized data: " << deserialized->data << std::endl;

	return 0;
}
