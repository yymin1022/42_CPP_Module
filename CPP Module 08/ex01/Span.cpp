#include "Span.hpp"

Span::Span()
	: maxSize(0), lSpan(0), sSpan(0){}

Span::Span(unsigned int N)
	: maxSize(N), lSpan(0), sSpan(0){}

Span::Span(const Span &src)
	: storage(src.storage), maxSize(src.maxSize), lSpan(src.lSpan), sSpan(src.sSpan){}

Span::~Span(){}

Span &Span::operator=(const Span &src){
	if(this != &src){
		this->storage = src.storage;
		this->maxSize = src.maxSize;
		this->lSpan = src.lSpan;
		this->sSpan = src.sSpan;
	}
	return *this;
}

void Span::addNumber(int num){
	unsigned int curSize = storage.size();

	if(curSize == maxSize)
		throw ArrayFullException();
	else if(curSize > 1){
		unsigned int span;
		unsigned int lastNum = static_cast<unsigned int>(storage.back());
		unsigned int targetNum = static_cast<unsigned int>(num);

		if(targetNum > lastNum)
			span = targetNum - lastNum;
		else
			span = lastNum - targetNum;

		if(curSize == 2){
			sSpan = span;
			lSpan = span;
		}else{
			sSpan = std::min(sSpan, span);
			lSpan = std::max(lSpan, span);
		}
	}

	storage.push_back(num);
}

void Span::addNumber(int num, unsigned int length){
	if(length == 0)
		throw InvalidArgumentException();
	else if(length > maxSize - storage.size())
		throw ArrayFullException();

	addNumber(num);
	length--;

	if(length > 0){
		sSpan = 0;
		if(storage.size() == 1)
			lSpan = 0;
		storage.insert(storage.end(), length, num);
	}
}

unsigned int Span::longestSpan(void)const{
	if(storage.size() < 2)
		throw ComparisonInvalidException();
	return (lSpan);
}

unsigned int Span::shortestSpan(void) const{
	if(storage.size() < 2)
		throw ComparisonInvalidException();
	return (sSpan);
}

void Span::printData() const{
	for(unsigned int i = 0; i < storage.size(); i++){
		std::cout << storage[i] << " ";
	}
	std::cout << std::endl;
}

const char *Span::ArrayFullException::what() const throw(){
	return ("Error: Array is full");
}

const char *Span::InvalidArgumentException::what() const throw(){
	return ("Error: Invalid Argument");
}

const char *Span::ComparisonInvalidException::what() const throw(){
	return ("Error: more than two element in vector needed to be compared");
}
