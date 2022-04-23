#include "Matrix.h"

Matrix::Matrix(size_t nRows, size_t nCols)
{
    this->_data = new int[nRows * nCols];
    this->_nRows = nRows;
    this->_nCols = nCols;
}

Matrix::~Matrix()
{
    delete[] this->_data;
}

void Matrix::FillWithRandomNumbers(int max)
{
    for (size_t i = 0; i < this->GetNumberOfItemsInMatrix(); i++)
    {
        this->_data[i] = rand() % max;
    }
}

void Matrix::FillSequentially()
{
    for (size_t i = 0; i < this->GetNumberOfItemsInMatrix(); i++)
    {
        this->_data[i] = i;
    }
}

size_t Matrix::GetNumberOfItemsInMatrix()
{
    return this->_nRows * this->_nCols;
}

int Matrix::GetItem(size_t row, size_t col)
{
    return this->_data[row * this->_nCols + col];
}

void Matrix::SetItem(int item, size_t row, size_t col)
{
    this->_data[row * this->_nCols + col] = item;
}

void Matrix::Print()
{
    for (size_t i = 0; i < this->_nRows; i++)
    {
        for (size_t j = 0; j < this->_nCols; j++)
        {
            printf("%d\t", this->GetItem(i, j));
        }
        printf("\n");
    }
}

Matrix* Matrix::MultiplyByScalar(Matrix* m, int scalar)
{
    Matrix* res = new Matrix(m->_nRows, m->_nCols);

    for (size_t i = 0; i < m->GetNumberOfItemsInMatrix(); i++)
    {
        res->_data[i] = m->_data[i] * scalar;
    }

    return res;

    /*
    for (size_t i = 0; i < m->_nRows; i++)
    {
        for (size_t j = 0; j < m->_nCols; j++)
        {
            res->SetItem(m->GetItem(i, j) * scalar, i, j);
        }
    }

    return res;
    */
}

Matrix* Matrix::SumMatrices(Matrix* matrixA, Matrix* matrixB)
{
    Matrix* res = new Matrix(matrixA->_nRows, matrixA->_nCols);

    int cnt = 0;

    for (size_t i = 0; i < matrixA->_nRows; i++)
    {
        for (size_t j = 0; j < matrixA->_nCols; j++)
        {
            res->SetItem(matrixA->GetItem(i, j) + matrixB->GetItem(i, j), i, j);
            cnt++;
        }
    }
    printf("Count: %d\n", cnt);
    return res;
}

Matrix* Matrix::SumMatricesOptimal(Matrix* matrixA, Matrix* matrixB)
{
    Matrix* res = new Matrix(matrixA->_nRows, matrixA->_nCols);

    int* ptrA = matrixA->_data;
    int* ptrB = matrixB->_data;
    int* ptrRes = res->_data;

    for (size_t i = 0; i < res->_nRows * res->_nCols; i++)
    {
        *(ptrRes++) = *(ptrA++) + *(ptrB++);
    }

    return res;
}

Matrix* Matrix::DiffMatrices(Matrix* matrixA, Matrix* matrixB)
{
    Matrix* res = new Matrix(matrixA->_nRows, matrixA->_nCols);

    int* ptrA = matrixA->_data;
    int* ptrB = matrixB->_data;
    int* ptrRes = res->_data;

    for (size_t i = 0; i < res->_nRows * res->_nCols; i++)
    {
        *(ptrRes++) = *(ptrA++) - *(ptrB++);
    }

    return res;
}

Matrix* Matrix::MultiplyMatrices(Matrix* matrixA, Matrix* matrixB)
{
    Matrix* res = new Matrix(matrixA->_nRows, matrixA->_nCols);

    int* ptrA = matrixA->_data;
    int* ptrB = matrixB->_data;
    int* ptrRes = res->_data;

    for (size_t i = 0; i < matrixA->_nRows; i++)
    {
        for (size_t j = 0; j < matrixA->_nCols; j++)
        {
            for (size_t k = 0; k < matrixA->_nCols; k++)
                res->SetItem(matrixA->GetItem(i, k) * matrixB->GetItem(k, j), i, j); 
        }
    }
    return res;
}
