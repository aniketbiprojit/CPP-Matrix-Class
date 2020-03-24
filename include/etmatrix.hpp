#ifndef EMATRIX_H
#define EMATRIX_H 1
#include "matrix.hpp"
#include <vector>
namespace lib
{
template <typename T>
class etmatrix : public matrix<T>
{
public:
    etmatrix() : matrix<T>() {}
    etmatrix(const std::initializer_list<T> l) : matrix<T>(l) {}
    etmatrix(const std::initializer_list<T> l, size_t rows, size_t cols) : matrix<T>(l, rows, cols) {}
    etmatrix(const std::initializer_list<std::initializer_list<T>> l) : matrix<T>(l){};
    etmatrix(const std::vector<std::vector<T>> l) : matrix<T>(l){};

    template <typename expression>
    inline etmatrix<T> operator=(const expression &exp)
    {
        matrix<T>::vec = std::vector<T>(exp.size);
        matrix<T>::rows_n=exp.rows;
        matrix<T>::cols_n=exp.cols;

        for (size_t i = 0; i < matrix<T>::rows(); i++)
        {
            for (size_t j = 0; j < matrix<T>::cols(); j++)
            {
                matrix<T>::operator()(i, j) = exp(i, j);
            }
        }
        return *this;
    }

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
    size_t size, rows, cols;
    etmatrixsum(Left &l_val, Right &r_val) : l(l_val), r(r_val)
    {
        size = l.vec.size();
        rows = l.rows_n;
        cols = l.cols_n;
    }

    const T operator()(size_t i, size_t j) const
    {
        assert(l.vec.size() == r.vec.size());
        assert(l.rows_n == r.rows_n);
        assert(l.cols_n == r.cols_n);

        return l(i, j) + r(i, j);
    }

    T operator()(size_t i, size_t j)
    {
        return l(i, j) + r(i, j);
    }
};

// template <typename T=float,typename Left, typename Right>
// lib::etmatrixsum<T, Left, Right> operator+(Left &l, Right &r)
// {
//     return lib::etmatrixsum<T, Left, Right>(l, r);
// }
} // namespace lib
#endif