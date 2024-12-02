#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe& obj){
	(void)obj;
}

PmergeMe PmergeMe::operator=(const PmergeMe& obj){
	if(this != &obj){
		*this = obj;
	}
	return (*this);
}

PmergeMe::~PmergeMe(){}
