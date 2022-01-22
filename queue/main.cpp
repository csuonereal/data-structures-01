#include <iostream>
#include "arrayQueue.h"
#include "linkedQueue.h"

void test1()
{
    arrayListQ<int> queue1;
    int x, y;

    x = 4;
    y = 5;
    queue1.addQueue(x); //5 9 16 4 2
    queue1.addQueue(y);
    x = queue1.getFront();
    queue1.deleteQueue();
    queue1.addQueue(x + 5);
    queue1.addQueue(16);
    queue1.addQueue(x);
    queue1.addQueue(y - 3);

    std::cout << "queue1: ";

    while (!queue1.isEmptyQueue())
    {
        std::cout << queue1.getFront() << " ";
        queue1.deleteQueue();
    }

    std::cout << std::endl;
}
void test2()
{
    linkedListQ<int> queue1;
    int x, y;

    x = 4;
    y = 5;
    queue1.addQueue(x); //5 9 16 4 2
    queue1.addQueue(y);
    x = queue1.getFront();
    queue1.deleteQueue();
    queue1.addQueue(x + 5);
    queue1.addQueue(16);
    queue1.addQueue(x);
    queue1.addQueue(y - 3);

    std::cout << "queue1: ";

    while (!queue1.isEmptyQueue())
    {
        std::cout << queue1.getFront() << " ";
        queue1.deleteQueue();
    }

    std::cout << std::endl;
}

int main()
{
    //test1();
    test2();
    return 0;
}