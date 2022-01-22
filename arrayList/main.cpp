#include <iostream>
#include "arrayList.h"
void test1()
{
    arrayList<int> intList1(100);
    arrayList<int> intList2(100);

    int number;
    int position;

    std::cout << "Enter 5 integers" << std::endl;
    for (int i = 0; i < 5; i++)
    {
        std::cin >> number;
        intList1.insertAt(i, number);
    }

    std::cout << "The list you entered is: ";
    intList1.print();
    std::cout << std::endl;
    std::cout << "Enter the position to be deleted: ";
    std::cin >> position;

    intList1.removeAt(position);
    std::cout << "After removing the element at " << position << " the list is: ";
    intList1.print();
}

void test2()
{
    arrayList<int> intList(100);

    int number;

    std::cout << "Enter 10 integers: ";

    for (int i = 0; i < 10; i++)
    {
        std::cin >> number;
        intList.insertAt(i, number);
    }

    std::cout << std::endl;
    std::cout << "The list you entered is: ";
    intList.print();
    std::cout << std::endl;

    std::cout << "The smallest element in the list is: " << intList.getMin() << std::endl;
}


int main()
{
    //test1();
    test2();
    return 0;
}