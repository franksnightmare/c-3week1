#include "matrix.ih"

template <typename Type>
Matrix<Type> &Matrix<Type>::operator=(Matrix const &other)
{
    Matrix tmp(other);
    swap(tmp);
    return *this;
}
