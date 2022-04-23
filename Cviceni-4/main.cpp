// ALG1_Matrix_1_21.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.

#include <stdio.h>
#include "Matrix.h"

int main()
{
	printf("Nasobení skalarem: \n");
	Matrix* matNasS = new Matrix(6, 6);
	matNasS->FillSequentially();
	matNasS->MultiplyByScalar(matNasS, 11)->Print();


	printf("\nSecteni dvou matic: \n");
	Matrix* matSoucet1 = new Matrix(7, 6);
	matSoucet1->FillWithRandomNumbers(70);

	Matrix* matSoucet2 = new Matrix(7, 6);
	matSoucet2->FillWithRandomNumbers(90);

	matSoucet1->SumMatrices(matSoucet1, matSoucet2)->Print();
		

	printf("\nRozdil dvou matic: \n");
	Matrix* matRozdil1 = new Matrix(4, 5);
	matRozdil1->FillWithRandomNumbers(100);

	Matrix* matRozdil2 = new Matrix(4, 5);
	matRozdil2->FillWithRandomNumbers(30);
	/*
	matRozdil1->Print();
	printf("\n");
	matRozdil2->Print();
	printf("\n");
	*/
	matRozdil1->DiffMatrices(matRozdil1, matRozdil2)->Print();


	printf("\nNasobeni dvou matic: \n");
	Matrix* matNasobeni1 = new Matrix(3, 2);
	matNasobeni1->FillWithRandomNumbers(200);

	Matrix* matNasobeni2 = new Matrix(2, 2);
	matNasobeni2->FillWithRandomNumbers(100);
	/*
	matNasobeni1->Print();
	printf("\n");
	matNasobeni2->Print();
	printf("\n");
	*/
	matNasobeni1->MultiplyMatrices(matNasobeni1, matNasobeni2)->Print();

	
	printf("\n");
	const int matSize = 10000;						// 10, 100, 500 a 1000			10000
	Matrix* mat = new Matrix(matSize, matSize);
	mat->FillSequentially();

	Matrix* mat2 = new Matrix(matSize, matSize);
	mat2->FillSequentially();

	std::chrono::steady_clock::time_point begin = std::chrono::high_resolution_clock::now();
	Matrix* afterOperation = Matrix::SumMatricesOptimal(mat, mat2);
	std::chrono::steady_clock::time_point end = std::chrono::high_resolution_clock::now();

	PrintTimeDifference(begin, end);
	//afterOperation->Print();

	delete mat;

	return 0;
}
