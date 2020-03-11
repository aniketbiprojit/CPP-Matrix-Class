#ifndef ETMATRIX_H
#define ETMATRIX_H 1
#include <cassert>
#include <iostream>
#include <initializer_list>
#include <vector>
namespace lib
{
template <typename T>
class etmatrix
{
private:
    bool array;
    size_t rows_n, cols_n;
    std::vector<T> vec;

public:
    constexpr size_t rows() { return rows_n; }
    constexpr size_t cols() { return cols_n; }

    etmatrix(const std::initializer_list<T> l)
    {
        array = true;
        vec = std::vector<T>(l);
    };

    etmatrix(const std::initializer_list<T> l, size_t rows, size_t cols)
    {
        array = false;
        vec = std::vector<T>(l);
        rows_n=rows;
        cols_n=cols;
    };


    etmatrix(const std::initializer_list<T> l)
    {

    }

    inline T &operator()(size_t i)
    {
        assert(i < vec.size());
        return vec[i];
    };
    inline const T &operator()(size_t i) const
    {
        assert(i < vec.size());
        return vec[i];
    };

    inline T &operator()(size_t i, size_t j)
    {
        int k = (i * (cols())) + j;
        assert(k<vec.size());
        return vec[k];
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
        return out;
    }
};

} // namespace lib
#endif // 1
