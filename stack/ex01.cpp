#include <iostream>
#include "arrayStack.h"

int main()
{
    stackType<int> stack1(50);
    stackType<int> stack2(50);
    stackType<int> stack3(100);
    int x;

    stack1.initializeStack();
    stack1.push(23);
    stack1.push(45);
    stack1.push(68);

    stack2 = stack1;
    x = stack2.top();
    stack2.pop();
    stack2.push(23);

    stack1.print();
    stack2.print();

    std::cout << x << std::endl;
}