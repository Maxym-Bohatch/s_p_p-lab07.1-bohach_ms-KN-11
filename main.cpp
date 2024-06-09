#include <iostream>
#include "Matrix.h"

int main() {
    size_t rows, cols;
    std::cout << "Enter number of rows: ";
    std::cin >> rows;
    std::cout << "Enter number of columns: ";
    std::cin >> cols;

    Matrix<int> matrix(rows, cols);

    std::cout << "Enter matrix elements:\n";
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            int value;
            std::cin >> value;
            matrix.setElement(i, j, value);
        }
    }

    std::cout << "Matrix:\n";
    matrix.print();

    size_t zeroCount = matrix.countZeros();
    std::cout << "Number of zeros in the matrix: " << zeroCount << std::endl;

    int A, B;
    std::cout << "Enter range A and B: ";
    std::cin >> A >> B;
    int sumRange = matrix.sumInRange(A, B);
    std::cout << "Sum of elements in range [" << A << ", " << B << "]: " << sumRange << std::endl;

    matrix.sortByAbsDescending();
    std::cout << "Matrix after sorting by absolute values in descending order:\n";
    matrix.print();

    return 0;
}
