#include <iostream>
#include "midterm.h"

int main()
{
    midterm midterm;

    const int arraySize = 4;
    int myArray[] = {3, 1, 2, 0};
    midterm.insertionSort(myArray, arraySize);
    midterm.printArray(myArray, arraySize);
}