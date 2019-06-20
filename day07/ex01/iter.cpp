#include "iter.hpp"

int main()
{

    int array1[] = {12, 5, 11};
    char array2[] = {'a', 'd', 's'};

    ::iter(array1, 3, ::output);
    ::iter(array2, 3, ::output);

	return (0);
}