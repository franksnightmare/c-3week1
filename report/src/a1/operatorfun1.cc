#include "matrix.ih"

template <typename Type>
typename Matrix<Type>::Proxy Matrix<Type>::operator()(size_t nRows, size_t nCols, Extraction type)
{
    return type == BY_ROWS ?
        Proxy{*this, BY_ROWS, 0, nRows, nRows, nCols}
    :
        Proxy{*this, BY_COLS, 0, nCols, nRows, nCols};
}
