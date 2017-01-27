#include "matrix.ih"

template <typename Type>
istream &Matrix<Type>::Proxy::extractCols(istream &in)
{
    d_mat.setDimensions(d_nRows, d_nCols);

    for (; d_count--; ++d_from)
    {
        for (size_t row = 0, end = d_mat.nRows(); row != end; ++row)
            in >> d_mat[row][d_from];
    }

    return in;
}
