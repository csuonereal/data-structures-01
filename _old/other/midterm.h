#ifndef H_midterm
#define H_midterm
#include <iostream>
#include <cassert>

class midterm
{
public:
    midterm();
    int maximumValue(int myArr[], int n);
    void insertionSort(int arr[], int n);
    void printArray(int arr[], int n);
};

midterm::midterm() {}
int midterm::maximumValue(int myArr[], int n)
{
    int max = myArr[0];
    for (int i = 0; i < n; i++)
    {
        if (max <= myArr[i])
        {
            max = myArr[i];
        }
    }
    return max;
}
void midterm::insertionSort(int arr[], int n)
{
    int i, j, key; //1
    for (i = 1; i < n; i++)
    {                 //n-1
        key = arr[i]; //n-1
        j = i - 1;    //n-1
        while (j >= 0 && arr[j] > key)
        {                        //n-2
            arr[j + 1] = arr[j]; //n-2
            j = j - 1;           //n-2
        }
        arr[j + 1] = key; //n-1
    }
}
void midterm::printArray(int arr[], int n)
{
    int i;
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

#endif
