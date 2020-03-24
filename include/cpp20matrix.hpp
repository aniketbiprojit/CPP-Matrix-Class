#ifndef CPP20MATRIX_H
#define CPP20MATRIX_H 1
#include <vector>
#include <range/v3/all.hpp>
namespace lib
{
template <typename T>
class cpp20matrix
{
public:
    std::vector<T> vec;
    cpp20matrix(std::initializer_list<std::initializer_list<T>> l)
    {
        vec.clear();
        for (auto it = l.begin(); it < l.end(); it++)
        {
            std::vector<T> temp;
            for (auto inner_it = it->begin(); inner_it < it->end(); inner_it++)
                vec.push_back(*inner_it);
        }
    }

    inline friend auto operator+(const lib::cpp20matrix<T> &left, const lib::cpp20matrix<T> &right)
    {
        auto sum = ranges::views::zip_with(std::plus{}, left.vec, right.vec);
        return sum;
    }
};
} // namespace lib
#endif // CPP20MATRIX_H
