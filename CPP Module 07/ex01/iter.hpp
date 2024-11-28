#ifndef ITER_HPP
# define ITER_HPP

template<typename T1>

void iter(T1 *array, size_t arr_len, void (*foo)(T1&)){
	if(array == NULL || foo == NULL)
		return;
	for(size_t i = 0; i < arr_len; i++)
		foo(array[i]);
}

template<typename T2>
void iter(const T2 *array, size_t arr_len, void (*foo)(const T2&)){
	if(array == NULL || foo == NULL)
		return;
	for(size_t i = 0; i < arr_len; i++)
		foo(array[i]);
}

#endif
