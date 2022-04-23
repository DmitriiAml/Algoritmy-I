#include <iostream>

using namespace std;

void bubbleSort(int* array, int size) {
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j + 1] < array[j])
            {
                swap(array[j+1], array[j]);
            }
        }
    }
}

int main()
{
    int mas1[7] = { 7,9,5,1,19,11,17 }, mas2[6] = { 8,18,14,2,4,10 }, masOdp[14] = {}, count = 0, sizeO;

    int size1 = sizeof(mas1) / 4;
    int size2 = sizeof(mas2) / 4;

    bubbleSort(mas1, size1);
    bubbleSort(mas2, size2);

    if (size1 > size2) sizeO = size1;
    else sizeO = size2;

    for (int i = 0; i < sizeO; i++)
    {
        if (size1 > size2 && i == size2) masOdp[count++] = mas1[i];
        else if (size1 < size2 && i == size1) masOdp[count++] = mas2[i];
        else
        {
            if (mas1[i] > mas2[i])
            {
                masOdp[count++] = mas2[i];
                masOdp[count++] = mas1[i];
            }
            else if (mas1[i] < mas2[i])
            {
                masOdp[count++] = mas1[i];
                masOdp[count++] = mas2[i];
            }
        }
    }

    for (int i = 0; i < size1 + size2; i++)
    {
        printf("%d ", masOdp[i]);
    }

    getchar();
    return 0;
}