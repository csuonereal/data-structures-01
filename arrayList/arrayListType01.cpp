#include <iostream>
#include "arrayListType.h"

int main()
{
    arrayListType<int> intList(100);

    int counter;
    int number;

    std::cout << "Processing the integer list" << std::endl;
    std::cout << "Enter 10 integers: ";

    for (counter = 0; counter < 10; counter++)
    {
        std::cin >> number;
        intList.insertAt(counter, number);
    }

    std::cout << std::endl;
    std::cout << "The list you entered is: ";
    intList.print();
    std::cout << std::endl;

    std::cout << "Enter the item to be deleted: ";
    std::cin >> number;
    intList.removeAll(number);
    std::cout << "After removing " << number << ", the list is: " << std::endl;
    intList.print();
    std::cout << std::endl;

    return 0;
}
