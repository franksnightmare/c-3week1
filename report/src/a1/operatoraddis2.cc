#include "matrix.ih"

template <typename Type>
Matrix<Type> &&Matrix<Type>::operator+=(Matrix const &rhs) &&
{
    add(rhs);
    return move(*this);
}
