#include "matrix.ih"

template <typename Type>
Matrix<Type>::Proxy::Proxy(Matrix &mat, int extractionType, size_t from, 
                     size_t count, size_t nRows, size_t nCols)
:
    d_mat(mat),
    d_direction(extractionType),
    d_from(from),
    d_count(count),
    d_nRows(nRows),
    d_nCols(nCols)
{}

