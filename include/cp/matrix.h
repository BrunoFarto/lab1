/**
 * Created by Herve Paulino
 * February 2024
 */

#ifndef CP_MATRIX_H
#define CP_MATRIX_H

#include <vector>
#include <ostream>
#include <algorithm>
#include <numeric>

namespace cp {

    /**
     * The matrix type as a vector of vectors
     */
    template <typename T>
    using matrix = std::vector<std::vector<T>>;

    /**
     * Make a matrix of given sizes with rows filled with increasing values starting at value
     * @tparam T Type of the matrix' elements
     * @param rows Number of rows
     * @param cols Number of columns
     * @param value the initial value
     * @return the matrix
     */
    template <typename T>
    matrix<T> make_matrix(std::size_t rows, std::size_t cols, T value = 1) {
        auto result = matrix<T> (rows, std::vector<T>(cols));
        for (std::vector<T>& row : result)
            std::iota(row.begin(), row.end(), value++);
        return result;
    }

    /**
     * Multiply two matrices
     * @tparam T type of the elements of matrix 1
     * @tparam U type of the elements of matrix 2
     * @param mat1 matrix 1
     * @param mat2 matrix 2
     * @return  mat1 x mat2
     */
    template <typename T, typename U>
    matrix<std::common_type_t<T, U>> matrix_mult(const matrix<T>& mat1, const matrix<U>& mat2) {

        using ResultType = std::common_type_t<T, U>;

        const auto mat1_cols = mat1[0].size();  // mat1 columns
        if (mat1_cols != mat2.size())
            throw std::runtime_error("Matrices are not compatible.");

        const auto mat1_rows = mat1.size();     // mat1 rows
        const auto mat2_cols = mat2[0].size();  // mat2 columns

        matrix<ResultType> result(mat1_rows, std::vector<ResultType>(mat2_cols, 0));

        for (auto i = 0; i < mat1_rows; i++)
            for (auto j = 0; j < mat2_cols; j++)
                for (auto k = 0; k < mat1_cols; k++)
                    result[i][j] += mat1[i][k]*mat2[k][j];

        return result;
    }


    /**
     * Write a matrix to an output stream
     *
     * @tparam T Type of the elements of the matrix
     * @param os the output stream
     * @param mat the matrix
     * @return the stream itself
     */
    template <typename T>
    std::ostream& operator<<(std::ostream& os, const matrix<T>& mat) { // The use of & denotes passing by reference
        for (auto& row : mat)
            os << mat[0] << "\n";
        return os;
    }

    /**
     * Write a vector to an output stream
     * @tparam T Type of the elements of the matrix
     * @param os the output stream
     * @param v the vector
     * @return the stream itself
     */
    template <typename T>
    std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) { // The use of & denotes passing by reference
        os << "[";
        if (!v.empty()) {
            os << v[0] ;
            std::for_each(std::cbegin(v) + 1,
                          std::cend(v),
                          [&os](auto e) { os << ", " << e; } // lambda expression
            );
        }
        os << "]";
        return os;
    }

}
#endif //CP_MATRIX_H
