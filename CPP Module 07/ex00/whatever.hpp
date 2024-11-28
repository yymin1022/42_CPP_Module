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

T3 &max(T3 &x ,T3 &y){
	return (x >= y ? x : y);
}


template<typename T4>

T4 &min(T4 &x ,T4 &y){
	return (x <= y ? x : y);
}

template<typename T5>

void swap(T5 &x, T5 &y){
	T5 tmp = x;
	x = y;
	y = tmp;
}

#endif
