#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <cmath>
#include <iostream>
#include <list>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

class PmergeMe{
private:
    std::list< std::list<int> > dataList;
    std::vector< std::vector<int> > dataVector;

    int getJacobsthal(int k);
    int getSizeList();
    int getSizeVector();
    int binarySearchList(int val, int left, int right);
    int binarySearchVector(int val, int left, int right);
    void mergeElementList(int idx1, int idx2);
    void mergeElementVector(int idx1, int idx2);
    void insertList(int idx, int insertIdx);
    void insertVector(int idx, int insertIdx);
    void lastSortList(int idx);
    void lastSortVector(int idx);

	std::list< std::list<int> >::iterator getIterL(int idx);
    std::list<int>::iterator getIterLL(int idx1, int idx2);

public:
    PmergeMe();
    PmergeMe(int argc, char **argv);
    PmergeMe(const PmergeMe &obj);
    ~PmergeMe();
    PmergeMe &operator=(const PmergeMe &obj);

	int getElementSize();
    void sortList();
    void sortVector();

    std::list<int> getResultList();
    std::vector<int> getResultVector();

	class PmergeException: public std::exception{
	public:
		virtual const char *what() const throw();
	};
};

#endif
