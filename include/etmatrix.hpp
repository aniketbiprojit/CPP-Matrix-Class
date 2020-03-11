#ifndef ETMATRIX_H
#define ETMATRIX_H 1
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
    size_t rows() { return rows_n; }
    size_t cols() { return cols_n; }

    etmatrix(const std::initializer_list<T> l, size_t size)
    {
        array = true;
        vec = std::vector<T>(l);
    };

    etmatrix(const std::initializer_list<T> l, size_t row, size_t col)
    {
        array = false;
        vec = std::vector<T>(l);
    };

    friend std::ostream& operator <<(std::ostream& out,const etmatrix<T> e){
        out << "testing";
        return out;
    } 
};

} // namespace lib
#endif // 1
