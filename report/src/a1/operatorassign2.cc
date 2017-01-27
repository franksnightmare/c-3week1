#include "matrix.ih"

template <typename Type>
Matrix<Type> &Matrix<Type>::operator=(Matrix &&tmp)
{
    swap(tmp);
    return *this;
}
