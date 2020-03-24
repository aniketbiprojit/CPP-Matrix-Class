#ifndef DATA_H
#define DATA_H

#include <initializer_list>
#include <random>
namespace lib
{
template <typename T = float>
class data_generate
{
private:
    std::minstd_rand g;
    bool flag = false;

public:
    data_generate(size_t rows, size_t cols)
    {
        this->operator()(rows, cols);
    }

    data_generate(size_t rows = 10)
    {
        this->operator()(rows, rows);
    }

    auto operator()(size_t rows, size_t cols)
    {
        flag = (flag == false) ? init() : true;
        for (size_t i = 0; i < rows; i++)
        {
            std::vector<T> temp1;
            std::vector<T> temp2;
            for (size_t j = 0; j < cols; j++)
            {
                temp1.push_back(g());
                temp2.push_back(g());
            }
            s1.push_back(temp1);
            s2.push_back(temp2);
        }
    }

    bool init()
    {
        g.seed(42);
        return true;
    }
    std::vector<std::vector<T>> s1;
    std::vector<std::vector<T>> s2;
};

} // namespace lib
#endif // DATA_H
