#include "matrix.ih"

template <typename Type>
istream &Matrix<Type>::Proxy::extractRows(istream &in) 
{
    d_mat.setDimensions(d_nRows, d_nCols);

    for (; d_count--; ++d_from)
    {
        auto rowPtr = d_mat[d_from];
        for (size_t col = 0, end = d_mat.nCols(); col != end; ++col)
            in >> rowPtr[col];
    }
    return in;
}

