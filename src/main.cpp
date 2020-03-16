#include <iostream>
#include <vector>
#include "etmatrix.hpp"
#include "cpp20matrix.hpp"
// #include <exceptional/ranges>

int main(int argc, char *argv[])
{
	std::cout << "C++ version\nBuilt on Version: 201703\nCurrent Version\t: " << __cplusplus << std::endl;

	lib::etmatrix<float> e_mat({{-1, 2, 3, 7.5}, {3, 4, 12, (float)17 / 3}});
	lib::etmatrix<float> e_mat_1({{2, 4, 6, -18}, {3.2, (float)4 / 7, 16, 17}});
	lib::etmatrix<float> e;
	e = (e_mat + e_mat_1);
	std::cout << e_mat << "\n"
			  << e_mat_1 << "\n"
			  << e;
}
