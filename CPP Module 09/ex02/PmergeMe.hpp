#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <list>
#include <string>
#include <vector>

class PmergeMe{
private:
public:
	PmergeMe();
	PmergeMe(const PmergeMe& obj);
	PmergeMe operator=(const PmergeMe& obj);
	~PmergeMe();
};

#endif
