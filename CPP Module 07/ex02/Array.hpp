#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <exception>

template<typename T>
class Array {
private:
    T* arr;
    int _size;

public:
    Array(): _size(0){
        this->arr = new T[this->_size];
    }

    Array(unsigned int N): _size(N){
        this->arr = new T[this->_size];
    }

    Array(const Array& src): _size(src.size()){
        this->arr = new T[src.size()];
        for(int i = 0; i < src.size(); i++)
            this->arr[i] = src.arr[i];
    }

    ~Array(){
		if(arr != NULL)
	        delete[] this->arr;
    }

    Array& operator=(const Array& src){
        if(this != &src){
			if(arr != NULL)
	            delete[] this->arr;
            this->_size = src.size();
            this->arr = new T[this->_size];
            for(int i = 0; i < this->_size; i++)
                this->arr[i] = src.arr[i];
        }
        return *this;
    }

    T& operator[](int index){
        if(index >= this->_size || index < 0){
            throw Array<T>::OutOfIndexException();
        }
        return this->arr[index];
    }

    const T& operator[](int index) const{
        if(index >= this->_size || index < 0){
            throw Array<T>::OutOfIndexException();
        }
        return this->arr[index];
    }

    int size() const{
        return this->_size;
    }

    class OutOfIndexException: public std::exception{
    public:
        virtual const char* what() const throw();
    };
};

template<typename T>

const char	*Array<T>::OutOfIndexException::what() const throw(){
	return ("Error: Invalid index");
}

#endif
