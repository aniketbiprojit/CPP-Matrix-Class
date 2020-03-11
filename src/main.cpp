#include <iostream>
#include "etmatrix.hpp"

int main(int argc, char *argv[])
{
	std::cout << "C++ version: " << __cplusplus << std::endl;
	lib::etmatrix<int> e({1, 2, 3}, 3);

	std::cout << e;
}
