#ifndef EMATRIX_H
#define EMATRIX_H 1
#include "matrix.hpp"
namespace lib
{
template <typename T>
class etmatrix : public matrix<T>
{
public:
    etmatrix(const std::initializer_list<T> l) : matrix<T>(l) {}
    etmatrix(const std::initializer_list<T> l, size_t rows, size_t cols) : matrix<T>(l, rows, cols) {}
    etmatrix(const std::initializer_list<std::initializer_list<T>> l) : matrix<T>(l){};

    inline friend std::ostream &operator<<(std::ostream &out, const etmatrix<T> e)
    {
        if (e.array == true)
        {
            auto it = e.vec.begin();
            out << "[";
            for (it; it < e.vec.end() - 1; it++)
            {
                out << *it << ", ";
            }
            out << *it << "]";
        }
        else
        {
            out << "[";
            for (int i = 0; i < e.rows_n; i++)
            {
                out << "[";
                for (int j = 0; j < e.cols_n; j++)
                {
                    if (j == e.cols_n - 1)
                        out << e.vec[(i * (e.cols_n)) + j] << "";
                    else
                        out << e.vec[(i * (e.cols_n)) + j]<< ", ";
                }
                if (i == e.rows_n - 1)
                    out << "]";
                else
                {
                    out << "], ";
                }
            }
            out << "]";
        }
        return out;
    }
};
} // namespace lib
#endif