#include "matrix.ih"

template <typename Type>
Matrix<Type>::Matrix(Matrix &&tmp)
{
    swap(tmp);
}
