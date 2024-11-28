#pragma once

#include <algorithm>
#include <climits>
#include <exception>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

class Span{
private:
	std::vector<int> storage;
	unsigned int size;
	unsigned int pos;
	Span();

public:
	Span(unsigned int N);
	Span(const Span &src);
	~Span();
	Span &operator=(const Span &src);

	void addNumber(int number);
	void addNumber(unsigned int range, time_t seed);
	unsigned int shortestSpan()const;
	unsigned int longestSpan()const;

	unsigned int getSize()const;
	unsigned int getPos()const;

	class VectorInvalidException: public std::exception{
	public:
		virtual const char *what() const throw();
	};

	class ArrayFullException: public std::exception{
	public:
		virtual const char *what() const throw();
	};

	class ComparisonInvalidException: public std::exception{
	public:
		virtual const char *what() const throw();
	};
};
