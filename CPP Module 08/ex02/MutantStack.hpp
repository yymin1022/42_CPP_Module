#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

template<typename T>
class MutantStack: public std::stack<T>
{
public:
    MutantStack();
    MutantStack(const MutantStack& copy);
    ~MutantStack();
    MutantStack& operator=(const MutantStack& copy);

    typedef typename std::deque<T>::iterator iterator;

    iterator begin();
    iterator end();
    const iterator begin() const;
    const iterator end() const;
};

template<typename T>
MutantStack<T>::MutantStack()
	: std::stack<T>(){}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack& copy)
	: std::stack<T>(copy){}

template<typename T>
MutantStack<T>::~MutantStack(){}

template<typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& copy){
    if (this != &copy)
        std::stack<T>::operator=(copy);
    return *this;
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(){
    return this->c.begin();
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(){
    return this->c.end();
}

template<typename T>
const typename MutantStack<T>::iterator MutantStack<T>::begin() const{
    return this->c.begin();
}

template<typename T>
const typename MutantStack<T>::iterator MutantStack<T>::end() const{
    return this->c.end();
}

#endif
