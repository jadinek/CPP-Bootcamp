#include <iostream>

template <class T>
void swap(T &one, T &two){
	T temp = one;

	one = two;
	two = temp;
}

template <class T>
T min(T one, T two){
    if (one < two)
        return one;
    else
        return two;
}

template <class T>
T max(T one, T two){
    if (one >= two)
        return one;
    else
        return two;
}