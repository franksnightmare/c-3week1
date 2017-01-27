#include "matrix.ih"

template <typename Type>
typename Matrix<Type>::Proxy Matrix<Type>::operator()(Extraction type, size_t from, size_t count)
{
    return type == BY_ROWS ?
        Proxy{*this, BY_ROWS, from, extractionLimits(from, count, d_nRows),
                                                d_nRows, d_nCols}
    :
        Proxy{*this, BY_COLS, from, extractionLimits(from, count, d_nCols),
                                                d_nRows, d_nCols};
}
