#include "matrix.ih"

template <typename Type>
void Matrix<Type>::setDimensions(size_t nRows, size_t nCols)
{
    size_t nextSize = nCols * nRows;

    if (nextSize > size())
    {
        Type *next = new Type[nextSize];
        delete[] d_data;
        d_data = next;
    }

    d_nRows = nRows;
    d_nCols = nCols;
}
    
