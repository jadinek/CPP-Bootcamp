#include <iostream>

template <class T>
void output(T element)
{
	std::cout << element << std::endl;
}

template <class T>
void iter(T *array, size_t length, void f(T))
{
    for (size_t i = 0; i < length; i++)
        f(array[i]);
		
}