#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

template <typename T>
class Matrix {
private:
    std::vector<std::vector<T>> data;
    size_t rows;
    size_t cols;

public:
    Matrix(size_t rows, size_t cols);
    void setElement(size_t row, size_t col, T value);
    T getElement(size_t row, size_t col) const;
    size_t countZeros() const;
    T sumInRange(T A, T B) const;
    void sortByAbsDescending();
    void print() const;
};

// Визначення функцій шаблону

template <typename T>
Matrix<T>::Matrix(size_t rows, size_t cols) : rows(rows), cols(cols), data(rows, std::vector<T>(cols, 0)) {}

template <typename T>
void Matrix<T>::setElement(size_t row, size_t col, T value) {
    if (row < rows && col < cols) {
        data[row][col] = value;
    }
}

template <typename T>
T Matrix<T>::getElement(size_t row, size_t col) const {
    if (row < rows && col < cols) {
        return data[row][col];
    }
    return T(); // Повернути значення за замовчуванням, якщо індекси не валідні
}

template <typename T>
size_t Matrix<T>::countZeros() const {
    size_t count = 0;
    for (const auto& row : data) {
        count += std::count(row.begin(), row.end(), 0);
    }
    return count;
}

template <typename T>
T Matrix<T>::sumInRange(T A, T B) const {
    T sum = 0;
    for (const auto& row : data) {
        for (const auto& elem : row) {
            if (elem >= A && elem <= B) {
                sum += elem;
            }
        }
    }
    return sum;
}

template <typename T>
void Matrix<T>::sortByAbsDescending() {
    std::vector<T> flat;
    for (const auto& row : data) {
        flat.insert(flat.end(), row.begin(), row.end());
    }

    std::sort(flat.begin(), flat.end(), [](T a, T b) {
        return std::abs(a) > std::abs(b);
        });

    auto it = flat.begin();
    for (auto& row : data) {
        for (auto& elem : row) {
            elem = *it++;
        }
    }
}

template <typename T>
void Matrix<T>::print() const {
    for (const auto& row : data) {
        for (const auto& elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
}

#endif // MATRIX_H
