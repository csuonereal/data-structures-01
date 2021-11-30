//Test Program
#include <iostream>
#include "linkedListStack.h"

int main()
{
    linkedStackType<int> stack1;
    linkedStackType<int> stack2;
    linkedStackType<int> stack3;
    int x;

    stack1.push(23);
    stack1.push(45);
    stack1.push(38);

    stack1.print();



    x = stack1.top();
    
    std::cout <<x << std::endl;

    stack1.pop();
    stack1.print();
    return 0;
}
