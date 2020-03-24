#include <iostream>
#include <vector>
#include "etmatrix.hpp"
#include "cpp20matrix.hpp"
#include "time.hpp"
#include "data.hpp"

int main(int argc, char *argv[])
{
    std::cout << "C++ version\nBuilt on Version: 201709\nCurrent Version\t: " << __cplusplus << std::endl;
    for (int n = 10; n <= 1000; n *= 10)
    {
        int et = 0, cpp = 0;
        lib::data_generate d(n);
        lib::etmatrix<float> e_mat(d.s1);
        lib::etmatrix<float> e_mat_1(d.s2);
        lib::etmatrix<float> e;

        lib::data_generate d2(n);
        lib::cpp20matrix<float> cpp_mat(d2.s1);
        lib::cpp20matrix<float> cpp_mat_1(d2.s2);

        std::cout << "N=" << n << "\n";
        lib::time_taken t;
        t.start("CPP_MATRIX_ADD");

        auto c = cpp_mat.add_(cpp_mat_1);
        cpp += t.finish();
        std::cout << cpp << "\n";

        t.start("CPP_MATRIX_ACCESS");

        for (auto i : c)
            auto k = i;

        int temp = t.finish();
        cpp += temp;
        std::cout << temp;

        t.start("\nET_MATRIX_ADD");

        e = e_mat + e_mat_1;
        e = e + e_mat_1;
        et += t.finish();
        std::cout << et << "\n";

        t.start("ET_MATRIX_ACCESS");
        access(e);

        temp = t.finish();
        et += temp;
        std::cout << temp << "\n";

        std::cout << "ET: " << et << "\nCPP: " << cpp << "\n\n";
    }
}
