#include <iostream>
#include "massive.hpp"

int
main()
{
	double array[5] ;
	for (int i = 0; i < 5; i++) {
		array[i] = 0;
	}
	array[4] = 7;
	array[1] = 5;
	massive A(array, 5);
	std::cout << A ;
	double ar[4];
	for (int i = 0; i < 4; i++) {
		ar[i] = 0;
	}
	ar[3] = 1;
	ar[1] = 3;
	massive B(ar, 4);
	std::cout << B ;

	B >> 3;
	std::cout << B ;

	B = A - B;
	std::cout << B ;

	std::cout << "Hello, World!" << std::endl;
	return 0;
}