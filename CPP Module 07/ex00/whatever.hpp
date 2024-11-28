#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template<typename T1>

const T1 &max(const T1 &x ,const T1 &y){
	return (x >= y ? x : y);
}

template<typename T2>

const T2 &min(const T2 &x ,const T2 &y){
	return (x <= y ? x : y);
}

template<typename T3>

void swap(T3 &x, T3 &y){
	T3 tmp = x;
	x = y;
	y = tmp;
}

#endif
