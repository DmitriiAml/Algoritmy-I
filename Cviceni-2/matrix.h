#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <iostream>

#pragma once
class Matrix
{
private:
    int* _data;
    size_t _nRows;
    size_t _nCols;
public:
    Matrix(size_t nRows, size_t nCols);
    ~Matrix();
    void FillWithRandomNumbers(int max);
    void FillSequentially();
    size_t GetNumberOfItemsInMatrix();
    int GetItem(size_t row, size_t col);
    void SetItem(int item, size_t row, size_t col);
    void Print();

    static Matrix* MultiplyByScalar(Matrix* m, int scalar);
    static Matrix* SumMatrices(Matrix* matrixA, Matrix* matrixB);
    static Matrix* SumMatricesOptimal(Matrix* matrixA, Matrix* matrixB);
    static Matrix* DiffMatrices(Matrix* matrixA, Matrix* matrixB);
    static Matrix* MultiplyMatrices(Matrix* matrixA, Matrix* matrixB);
};


//std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
// Mereny usek
//std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
inline void PrintTimeDifference(std::chrono::steady_clock::time_point begin, std::chrono::steady_clock::time_point end) {
    long long t = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
    printf("%lld [ms]\n", t);
}