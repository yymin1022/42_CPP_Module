#ifndef ARRAY_HPP
# define ARRAY_HPP

template<typename T>

class Array{
private:
	T *_array;
	size_t _size;

public:
	Array(): _size(0){
		std::cout << "Default Constructor called: created empty Array of size 0" << std::endl;
		this->_array = new T[this->_size];
	}

	Array(size_t size): _size(size){
		std::cout << "Constructor for an Array of size " << size << " called" << std::endl;
		this->_array = new T[this->_size];
	}

	Array(const Array &src): _size(src.size()){
		std::cout << "Copy Constuctor called" << std::endl;
		this->_array = new T[src._size];
		this->_size = src._size;

		for(size_t i = 0; i < src._size; i++)
			this->_array[i] = src._array[i];
	}

	~Array(){
		if(this->_array != NULL)
			delete[] this->_array;
	}

	Array& operator=(const Array &src){
		if(this != src){
			if(this->_array != NULL)
				delete[] this->_array;
			this->_size = src.size();
			this->_array = new T[this->_size];
			for(size_t i = 0; i < this->size(); i++)
				this->_array[i] = src._array[i];
		}
		return (*this);
	}

	T& operator[](size_t index){
		if(index >= this->_size || this->_array == NULL){
			std::cout << "index: " << index << std::endl;
			throw Array<T>::OutOfIndexException();
		}
		return (this->_array[index]);
	}

	const T& operator[](size_t index) const{
		if(index >= this->_size || this->_array == NULL){
			std::cout << "index: " << index << std::endl;
			throw Array<T>::OutOfIndexException();
		}
		return (this->_array[index]);
	}

	class OutOfIndexException: public std::exception{
	public:
		virtual const char	*what() const throw();
	};

	size_t size() const{
		return (this->_size);
	}
};

template<typename T>

const char	*Array<T>::OutOfIndexException::what() const throw(){
	return ("Error: Invalid index");
}

#endif
