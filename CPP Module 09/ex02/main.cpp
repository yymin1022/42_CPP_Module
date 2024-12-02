#include <iostream>
#include <sys/time.h>

#include "PmergeMe.hpp"

int getTime(struct timeval from, struct timeval to);
void printList(std::list<int> l);
void printVector(std::vector<int> v);

int main(int argc, char **argv){
	try{
		if(argc == 1)
			throw std::string("too few argument");

		PmergeMe pmerge(argc, argv);

		std::cout << "Before: ";
		printVector(pmerge.getResultVector());

		struct timeval startVector, endVector;
		gettimeofday(&startVector, 0);
		pmerge.sortVector();
		gettimeofday(&endVector, 0);
		std::cout << "After:  ";
		printVector(pmerge.getResultVector());

		struct timeval startList, endList;
		gettimeofday(&startList, 0);
		pmerge.sortList();
		gettimeofday(&endList, 0);

		std::cout << "Time to process a range of   " << pmerge.getElementSize()
			<< " elements with std::vector : " << getTime(startVector, endVector) << " us" << std::endl
			<< "Time to process a range of   " << pmerge.getElementSize()
			<< " elements with std::list :   " << getTime(startList, endList) << " us" << std::endl;
	}catch(const std::string& e){
		std::cerr << e << std::endl;
		return (1);
	}catch(const PmergeMe::PmergeException& e){
		std::cerr << e.what() << std::endl;
		return (1);
	}

	return (0);
}

int getTime(struct timeval from, struct timeval to){
	int sec = to.tv_sec - from.tv_sec;
	int usec = to.tv_usec - from.tv_usec;

	if (usec < 0){
		sec--;
		usec += 1000000;
	}

	return (sec * 1000000 + usec);
}

void printList(std::list<int> l){
	for(std::list<int>::iterator iter = l.begin(); iter != l.end(); iter++)
		std::cout << *(iter) << " ";
	std::cout << std::endl;
}

void printVector(std::vector<int> v){
	for(int i = 0; i < static_cast<int>(v.size()); i++)
		std::cout << v[i] << " ";
	std::cout << std::endl;
}
