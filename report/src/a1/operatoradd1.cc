#include "matrix.ih"

template <typename Type>
Matrix<Type> operator+(Matrix<Type> const &lhs, Matrix<Type> const &rhs)
{
    Matrix<Type> ret(lhs);
    ret.add(rhs);
    return ret;
}
