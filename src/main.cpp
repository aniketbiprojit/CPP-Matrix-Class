#include <iostream>
#include <vector>
// #include <experimental/ranges/ranges>
#include "etmatrix.hpp"

template <typename T>
class cpp20matrix
{
public:
std::vector<std::vector<T>> vec;
cpp20matrix(std::initializer_list<std::initializer_list<T>> l){
	values.clear();
	for(auto it=l.begin();iv<l.end();it++){
		for(auto inner_it=it->begin();inner_it<it->end();inner_it++)
			vec.push_back(*inner_it);
	}


}

};

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
