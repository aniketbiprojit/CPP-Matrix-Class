#ifndef MATRIX_H
#define MATRIX_H 1
#include <cassert>
#include <iostream>
#include <initializer_list>
#include <vector>
namespace lib
{
template <typename T>
class matrix
{
private:
public:
    bool array;
    size_t rows_n, cols_n;
    std::vector<T> vec;
    constexpr size_t rows() { return rows_n; }
    constexpr size_t cols() { return cols_n; }

    matrix(const std::initializer_list<T> l)
    {
        array = true;
        vec = std::vector<T>(l);
    };

    matrix(const std::initializer_list<T> l, size_t rows, size_t cols)
    {
        array = false;
        vec = std::vector<T>(l);
        rows_n = rows;
        cols_n = cols;
    };

    matrix(const std::initializer_list<std::initializer_list<T>> l)
    {
        array = false;
        vec.clear();
        rows_n = l.size();
        auto temp = *(l.begin());
        cols_n = temp.size();
        for (auto it = l.begin(); it < l.end(); it++)
        {
            assert(it->size() == cols_n);
            for (auto inner = (*it).begin(); inner < (*it).end(); inner++)
            {
                vec.push_back(*inner);
            }
        }
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
        assert(k < vec.size());
        return vec[k];
    }

    inline friend std::ostream &operator<<(std::ostream &out, const matrix<T> e)
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

} // namespace lib
#endif // 1
