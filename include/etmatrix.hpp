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
    template <typename expression>
    void test(const expression exp)
    {
        for (size_t i = 0; i < matrix<T>::rows(); i++)
        {
            for (size_t j = 0; j < matrix<T>::cols(); j++)
            {
                std::cout << exp(i, j);
            }
        }
    }
    // inline etmatrix<T> operator=(const expression &exp)
    // {
    //     std::cout << "ok";
    //     for (size_t i = 0; i < matrix<T>::rows(); i++)
    //     {
    //         for (size_t j = 0; j < matrix<T>::cols(); j++)
    //         {
    //             matrix<T>::operator()(i, j) = exp(i, j);
    //         }
    //     }
    //     return *(this);
    // }

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
                        out << e.vec[(i * (e.cols_n)) + j] << ", ";
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

template <typename T, typename Left, typename Right>
class etmatrixsum
{
private:
    const Left &l;
    const Right &r;

public:
    etmatrixsum(Left &l_val, Right &r_val) : l(l_val), r(r_val) {}

    // const T &operator()(size_t i, size_t j) const
    // {
    //     return l(i, j) + r(i, j);
    // }

    T operator()(size_t i, size_t j)
    {
        return l(i, j) + r(i, j);
    }
};

template <typename Left, typename Right>
lib::etmatrixsum<int, Left, Right> operator+(Left &l, Right &r)
{
    return lib::etmatrixsum<int, Left, Right>(l, r);
}
} // namespace lib
#endif