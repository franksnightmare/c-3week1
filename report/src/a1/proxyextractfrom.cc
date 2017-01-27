#include "matrix.ih"

template <typename Type>
istream &Matrix<Type>::Proxy::extractFrom(istream &in)
{
    return d_direction == Matrix<Type>::BY_ROWS ? extractRows(in) : extractCols(in);
}

