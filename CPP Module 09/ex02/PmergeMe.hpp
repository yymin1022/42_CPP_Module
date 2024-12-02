#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cmath>
#include <iostream>
#include <list>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

class PmergeMe {
private:
    std::vector<std::vector<int>> v;
    std::list<std::list<int>> l;

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

public:
    PmergeMe();
    PmergeMe(int argc, char **argv);
    PmergeMe(const PmergeMe &obj);
    ~PmergeMe();
    PmergeMe &operator=(const PmergeMe &obj);

    std::list<int> getResultList();
    std::vector<int> getResultVector();
    void sortList();
    void sortVector();
};

#endif
