#include "SearchContainer.h"
#include <iostream>

SearchContainer::SearchContainer(size_t arraySize, int maxValue)
{
    this->_dataSize = arraySize;
    this->_data = new int[arraySize];
    this->FillArray(maxValue);
}

SearchContainer::~SearchContainer()
{
    delete[] _data;
}

std::pair<bool, int> SearchContainer::SearchLinear(int element) // napr. arrSize = 1024; 
{
    for (size_t i = 0; i < this->_dataSize; i++)
    {
        if (this->_data[i] == element)
        {
            printf("Index of element: %d", i);
            return std::make_pair(true, i);
        }
        //return std::make_pair(false, -1);
    }
}

std::pair<bool, int> SearchContainer::SearchBinary(int element)
{
    int ii = 0, midd = 0, left = 0, right = _dataSize;
    bool success = false;

    while(success == false)
    {
        ii++;
        midd = (left + right) / 2;
        
        if (element < this->_data[ii]) right = midd - 1;         // pokud je hledana hodnota mensi nez hodnota v bunce, posuneme pravou hranici vyhledavani

        else if (element > this->_data[ii]) left = midd + 1;     // pokud je hledany vetsi nez hodnota v; posuneme levou hranici vyhledavani

        else
        {
            success = true;
            return std::make_pair(true, ii);                    // pokud jsou hodnoty stejne; funkce vrati index bunky
        }
    }
}

void SearchContainer::FillArray(int max)
{
    srand(time(NULL));
    for (size_t i = 0; i < this->_dataSize; i++)
    {
        this->_data[i] = rand() % (max + 1);
    }
}

void SearchContainer::SortArray()
{
    std::sort(this->_data, this->_data + this->_dataSize);
}

bool SearchContainer::IsSorted()
{
    for (size_t i = 0; i < this->_dataSize - 1; i++)
    {
        if (this->_data[i] > this->_data[i + 1])
        {
            return false;
        }
    }
    return true;
}

void SearchContainer::PrintData()
{
    for (size_t i = 0; i < this->_dataSize; i++)
    {
        printf("%d ", this->_data[i]);
    }
    printf("\n");
}

int SearchContainer::GetData(int getNum)
{
    return this->_data[getNum];
}

