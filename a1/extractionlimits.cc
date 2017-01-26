#include "matrix.ih"

template <typename Type>
size_t Matrix<Type>::extractionLimits(size_t from, size_t count, size_t available)
{
    return  from >= available ?         0                :
            from + count >= available ? available - from :
                                        count;
}
