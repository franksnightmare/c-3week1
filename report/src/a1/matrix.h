#ifndef INCLUDED_MATRIX_
#define INCLUDED_MATRIX_

#include <iosfwd>
#include <initializer_list>

template <typename Type>
class Matrix
{
    size_t d_nRows = 0;
    size_t d_nCols = 0;
    Type *d_data = 0;

    class Proxy
    {
        friend class Matrix;
	template <typename U>
        friend std::istream &operator>>(std::istream &in, Proxy &&prox);

        Matrix &d_mat;

        int d_direction = Matrix::BY_ROWS;
        size_t d_from = 0;
        size_t d_count = ~0UL;
        size_t d_nRows;
        size_t d_nCols;

        Proxy(Matrix &mat, int extractionType, size_t from,
                size_t count, size_t nRows, size_t nCols);

        std::istream &extractFrom(std::istream &in);
        std::istream &extractRows(std::istream &in);
        std::istream &extractCols(std::istream &in);
    };

    friend class Proxy;

    template <typename U>
    friend std::istream &operator>>(std::istream &in, Proxy &&mat);


    public:
        enum Extraction
        {
            BY_ROWS,
            BY_COLS
        };

        typedef std::initializer_list
            <std::initializer_list<Type>> IniList;

        Matrix() = default;
        Matrix(size_t nRows, size_t nCols);
        Matrix(Matrix const &other);
        Matrix(Matrix &&tmp);
        Matrix(IniList inilist);

        ~Matrix()
        {
			delete d_data;
		}

        Matrix &operator=(Matrix const &rhs);
        Matrix &operator=(Matrix &&tmp);


        size_t nRows() const;
        size_t nCols() const;
        size_t size() const;

        static Matrix identity(size_t dim);

        Matrix &tr();
        Matrix transpose() const;

        void swap(Matrix &other);

        Type *operator[](size_t idx);
        Type const *operator[](size_t idx) const;

            Matrix &operator+=(Matrix const &rhs)   &;
            Matrix &&operator+=(Matrix const &rhs) &&;

        Proxy operator()(size_t nRows, size_t nCols,
                         Extraction type = BY_ROWS);
        Proxy operator()(Extraction type, size_t
            from = 0, size_t count = ~0UL);

    private:
        template <typename U>
        friend Matrix operator+(Matrix const &lhs, Matrix const &rhs);

		template <typename U>
        friend Matrix operator+(Matrix &&lhs, Matrix const &rhs);

        void add(Matrix const &rhs);

        size_t extractionLimits(size_t from, size_t count, size_t available);
        void setDimensions(size_t nRows,
            size_t nCols);

        template <typename U>
        friend bool operator==(Matrix const &lhs, Matrix const &rhs);

        Type &el(size_t row, size_t col) const;
};

template <typename Type>
std::ostream &operator<<(std::ostream &out,
    Matrix<Type> const &mat);
template <typename Type>
std::istream &operator>>(std::istream &in,
    Matrix<Type> &mat);

template <typename Type>
inline bool operator!=(Matrix<Type> const &lhs,
    Matrix<Type> const &rhs)
{
    return not (lhs == rhs);
}

template <typename Type>
inline Type *Matrix<Type>::operator[](size_t idx)
{
    return &el(idx, 0);
}

template <typename Type>
inline Type const *Matrix<Type>::operator[](size_t idx) const
{
    return &el(idx, 0);
}
template <typename Type>
inline size_t Matrix<Type>::nCols() const
{
    return d_nCols;
}
template <typename Type>
inline size_t Matrix<Type>::nRows() const
{
    return d_nRows;
}
template <typename Type>
inline size_t Matrix<Type>::size() const
{
    return d_nRows * d_nCols;
}

template <typename Type>
inline Type &Matrix<Type>::el(size_t row, size_t col) const
{
    return d_data[row * d_nCols + col];
}

#endif
