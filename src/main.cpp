#include <iostream>
#include "etmatrix.hpp"

int main(int argc, char *argv[])
{
	std::cout << "C++ version\nBuilt on Version: 201703\nCurrent Version\t: " << __cplusplus << std::endl;
	std::endl(std::cout);

	lib::etmatrix<int> e_mat({{1, 2, 3, 5}, {3, 4, 6, 7}});
	lib::etmatrix<int> e_mat_1({{1, 2, 3, 5}, {3, 4, 6, 7}});
	lib::etmatrix<int> e({1,2,3});
	std::cout << (e_mat+e_mat_1)(1,2);
	// std::cout << e;
}
