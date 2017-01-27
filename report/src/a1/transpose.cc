#include "matrix.ih"
template <typename Type>
Matrix<Type> Matrix<Type>::transpose() const
{
//    Matrix ret(d_nCols, d_nRows);     // trivial (intuitive) implementation
//
//    double const *data = d_data;
//
//    for (size_t row = 0; row != d_nRows; ++row)
//    {
//        for (size_t col = 0; col != d_nCols; ++col)
//            ret.el(col, row) = *data++;
//    }
//

    Matrix ret;                             // optimized implementation

    ret.d_nCols = d_nRows;                  // prepare the return Matrix
    ret.d_nRows = d_nCols;
    ret.d_data = new Type[size()];

    Type *src = d_data;
    Type *destBeg = ret.d_data;

                                // visit all rows. elements[0] of each
                                // row define the subsequent elements of 
                                // the first column, hence ++destBeg for
                                // subsequent row-indices:
    for (size_t row = 0; row != d_nRows; ++row, ++destBeg) 
    {
        Type *dest = destBeg; // subsequent elements of the columns appear
                                // nRows elements farther in the transposed 
                                // matrix. Hence dest += d_nRows in the 
                                // for-stmnt:
        for (size_t col = 0; col != d_nCols; ++col, dest += d_nRows, ++src)
            *dest = *src;
    }
        
    return ret;
}
