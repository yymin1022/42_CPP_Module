#pragma once

#include <algorithm>
#include <exception>
#include <iostream>
#include <vector>

class Span{
private:
	std::vector<int> storage;
	unsigned int maxSize;
	unsigned int lSpan;
	unsigned int sSpan;
	Span();

public:
	Span(unsigned int N);
	Span(const Span &src);
	~Span();
	Span &operator=(const Span &src);

	void addNumber(int num);
	void addNumber(int num, unsigned int length);
	unsigned int shortestSpan()const;
	unsigned int longestSpan()const;

	void printData() const;

	class ArrayFullException: public std::exception{
	public:
		virtual const char *what() const throw();
	};

	class InvalidArgumentException: public std::exception{
	public:
		virtual const char *what() const throw();
	};

	class ComparisonInvalidException: public std::exception{
	public:
		virtual const char *what() const throw();
	};
};
