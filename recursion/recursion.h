#ifndef H_recursion
#define H_recursion

#include <iostream>
#include <string>

int factorial(int n)
{
    if (n > 1)
    {
        return n * factorial(n - 1);
    }
    else
    {
        return 1;
    }
}
int largest(int list[], int lowerIndex, int upperIndex)
{
    int m;
    if (lowerIndex == upperIndex)
        return list[lowerIndex];
    else
    {
        m = largest(list, lowerIndex + 1, upperIndex);
        if (m > list[lowerIndex])
            return m;
        else
            return list[lowerIndex];
    }
}
int fibIterative(int n)
{
    int f1 =0;
    int f2 = 1;
    int f;

    if (n < 2)
    {
        std::cout << n << std::endl;
    }
    else
    {
        for (int i = 2; i <= n; i++) 
        {
            f = f1 + f2;
            f1 = f2;
            f2 = f;
        }
    }
    return f;
}

int callCount = 0;
int fibRecursive(int n)
{
    callCount++;
    if (n < 2)
        return n;
    else
        return fibRecursive(n - 2) + fibRecursive(n - 1);
}
int dotIterative(int list1[], int list2[], int start, int end)
{
    int sum = 0;
    for (int i = 0; i <= end; i++)
        sum += list1[i] * list2[i];
    return sum;
}

int dotRecursive(int list1[], int list2[], int start, int end)
{
    int sum;
    if (start <= end)
    {
        sum = dotRecursive(list1, list2, start + 1, end);
        return sum + list1[start] * list2[start];
    }
    else
    {
        return 0;
    }
}
#endif