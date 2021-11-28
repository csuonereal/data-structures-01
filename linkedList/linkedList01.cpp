#include <iostream>
#include "linkedList.h"

int main()
{
    linkedList<int> *list1 = new linkedList<int>();

    for (int i = 0; i < 10; i++)
    {
        //list1->insertAtBegin(i);
        list1->insertAtEnd(i);
    }

    list1->insertAfter(list1->_head->_next, 42);
    list1->print();
    list1->deleteAt(2);
    list1->print();
}