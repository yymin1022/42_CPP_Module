#include "Serializer.hpp"

Serializer::Serializer(){}

Serializer::Serializer(const Serializer &other){
	static_cast<void>(other);
}

Serializer::~Serializer(){}

Serializer &Serializer::operator=(const Serializer &other){
	static_cast<void>(other);
	return *this;
}

uintptr_t Serializer::serialize(Data* ptr){
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw){
	return reinterpret_cast<Data*>(raw);
}
