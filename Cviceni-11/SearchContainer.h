#include <stdio.h>
#include <vector>
#include <chrono>
#include <algorithm>
#include <stdlib.h>

using namespace std;

#pragma once

class SearchContainer
{
public:
    SearchContainer(size_t arraySize, int maxValue);
    ~SearchContainer();
    std::pair<bool, int> SearchLinear(int element);
    std::pair<bool, int> SearchBinary(int element);
    void SortArray();
    bool IsSorted();
    void PrintData();
    int GetData(int getNum);

private:
    void FillArray(int max);
    int* _data;
    size_t _dataSize;
};

//std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
// Mereny usek
//std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
inline void PrintTimeDifference(std::chrono::steady_clock::time_point begin, std::chrono::steady_clock::time_point end) {
    long long t = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
    printf("%lld [ms]\n", t);
}