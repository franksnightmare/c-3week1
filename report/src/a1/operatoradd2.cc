#include "matrix.ih"

template <typename Type>
Matrix<Type> operator+(Matrix<Type> &&lhs,
    Matrix<Type> const &rhs)
{
    Matrix<Type> ret(move(lhs));
    ret.add(rhs);
    return ret;
}
