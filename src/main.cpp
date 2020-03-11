#include <iostream>
#include "etmatrix.hpp"

int main(int argc, char *argv[])
{
	std::cout << "C++ version\nBuilt on Version: 201703\nCurrent Version\t: " << __cplusplus << std::endl;
	std::endl(std::cout);
	
	lib::etmatrix<int> e_arr({1, 2, 3}, 3);
	e(2)=20;
	std::cout << e;	
}
