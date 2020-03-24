#include <iostream>
#include <vector>
#include "etmatrix.hpp"
#include "cpp20matrix.hpp"
#include "time.hpp"
#include "data.hpp"

int main(int argc, char *argv[])
{
    std::cout << "C++ version\nBuilt on Version: 201709\nCurrent Version\t: " << __cplusplus << std::endl;
    lib::data_generate d(100);
    lib::etmatrix<float> e_mat(d.s1);
    lib::etmatrix<float> e_mat_1(d.s2);
    lib::etmatrix<float> e;

    lib::cpp20matrix<float> cpp_mat(d.s1);
    lib::cpp20matrix<float> cpp_mat_1(d.s2);

    lib::time_taken t;
    t.start();
    auto c = cpp_mat.add_(cpp_mat_1);
    std::cout << "\n"
              << t.finish() << "\n";

    t.start();
    // for(auto i:c)std::cout << i;
    std::cout << "\n"
              << t.finish();
}
