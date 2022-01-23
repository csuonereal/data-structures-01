#include <iostream>
#include "hashTable.h"
void test1()
{
    hashTable<int> intHTable(19);
    int num;
    int key;
    bool found;

    std::cout << "Enter 5 integers: " << std::endl;
    for (int i = 0; i < 5; i++)
    {
        std::cin >> num;
        intHTable.calculateIndex(num, key);
        intHTable.insert(key, num);
    }
    intHTable.print();

    std::cout << "Enter item to be deleted: " << std::endl;
    std::cin >> num;
    std::cout << std::endl;

    intHTable.calculateIndex(num, key);
    intHTable.remove(key, num);
    intHTable.print();

    std::cout << "Enter item to be searched: " << std::endl;
    std::cin >> num;
    std::cout << std::endl;

    intHTable.calculateIndex(num, key);
    intHTable.search(key, num, found);

    if (found)
        std::cout << "Item found in the list" << std::endl;
    else
        std::cout << "Item not in the list." << std::endl;

    std::cout << "Enter item to be inserted: ";
    std::cin >> num;
    std::cout << std::endl;

    intHTable.calculateIndex(num, key);
    intHTable.insert(key,num);

    intHTable.print();
}
int main()
{

    test1();

    return 0;
}