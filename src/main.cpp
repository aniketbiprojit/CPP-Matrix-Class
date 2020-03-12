#include <iostream>
#include "etmatrix.hpp"

int main(int argc, char *argv[])
{
	std::cout << "C++ version\nBuilt on Version: 201703\nCurrent Version\t: " << __cplusplus << std::endl;
	std::endl(std::cout);

	lib::etmatrix<int> e_mat({{1, 2, 3, 15}, {3, 4, 12, 17}});
	lib::etmatrix<int> e_mat_1({{2, 4, 6, 18}, {3, 4, 16, 17}});
	lib::etmatrix<int> e({{1, 2, 3, 5}, {3, 4, 6, 7}});
	e = (e_mat + e_mat_1);
	std::cout << e_mat << "\n"
			  << e_mat_1 << "\n"
			  << e;
}
