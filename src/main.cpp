#include <iostream>
#include <vector>
#include "cpp20matrix.hpp"
//#include "etmatrix.hpp"
// #include <exceptional/ranges>

template <typename T>
auto operator+(const lib::cpp20matrix<T>& left,const lib::cpp20matrix<T>& right){
    auto sum = ranges::views::zip_with(std::plus{},left.vec,right.vec);
    return sum;
}

int main(int argc, char *argv[])
{
	std::cout << "C++ version\nBuilt on Version: 201703\nCurrent Version\t: " << __cplusplus << std::endl;

//	lib::etmatrix<float> e_mat({{-1, 2, 3, 7.5}, {3, 4, 12, (float)17 / 3}});
//	lib::etmatrix<float> e_mat_1({{2, 4, 6, -18}, {3.2, (float)4 / 7, 16, 17}});
//	lib::etmatrix<float> e;
//	e = (e_mat + e_mat_1);
//	std::cout << e_mat << "\n"
//			  << e_mat_1 << "\n"
//			  << e;
    
    lib::cpp20matrix <float> cpp_mat({{-1, 2, 3, 7.5}, {3, 4, 12, (float)17 / 3}});
    lib::cpp20matrix <float> cpp_mat_1({{2, 4, 6, -18}, {3.2, (float)4 / 7, 16, 17}});
    auto c = cpp_mat+cpp_mat_1;
    
    for(int i=0;i<c.size();i++)
        std::cout << c[i] << " " ;
}
