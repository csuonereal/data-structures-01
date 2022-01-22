#include <iostream>
#include "recursion.h"

int main()
{

    // 1 1 2 3 5
    std::cout << fibRecursive(5) << std::endl;
    std::cout << fibIterative(5) << std::endl;

    std::cout << callCount << std::endl;
}