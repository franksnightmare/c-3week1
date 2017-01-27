#include "matrix.ih"

template <typename Type>
Matrix<Type>::Matrix(IniList iniList)
:
    d_nRows(iniList.size()),
    d_nCols(iniList.begin()->size()),
    d_data(new Type[size()])
{
    auto ptr = d_data;
    for (auto &list: iniList)
    {
        if (list.size() != d_nCols)
        {
            cerr << "Matrix(IniList): varying"
            " number of elements in rows\n";
            exit(1);
        }
        memcpy(ptr, &*list.begin() , list.size() * sizeof(Type));
        ptr += list.size();
    }
}
