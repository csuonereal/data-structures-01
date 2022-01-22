#ifndef H_arrayStack
#define H_arrayStack

#include <iostream>
#include <cassert>
#include "stackADT.h"

template <class T>
class stackType : public stackADT<T>
{
public:
    const stackType<T> &operator=(const stackType<T> &);
    void initializeStack() override;
    bool isEmptyStack() override;
    bool isFullStack() override;
    void push(const T &) override;
    T top() override;
    void pop() override;
    void print() override;
    bool operator==(const stackType<T> &);
    stackType(int stackSize = 100);
    stackType(const stackType<T> &);
    ~stackType();

private:
    int _maxStackSize;
    int _stackTop;
    T *_myArray;
    void copyStack(const stackType<T> &);
};

template <class T>
void stackType<T>::initializeStack()
{
    this->_stackTop = 0;
}
template <class T>
bool stackType<T>::isEmptyStack()
{
    return (this->_stackTop == 0);
}
template <class T>
bool stackType<T>::isFullStack()
{
    return (this->_maxStackSize == this->_stackTop);
}

template <class T>
void stackType<T>::print()
{
    for (int i = 0; i < this->_stackTop; i++)
    {
        std::cout << this->_myArray[i] << " ";
    }
    std::cout << std::endl;
}
template <class T>
void stackType<T>::push(const T &newItem)
{
    if (!this->isFullStack())
    {
        _myArray[_stackTop] = newItem;
        _stackTop++;
    }
    else
        std::cout << "Cannot add to a full stack." << std::endl;
}
template <class T>
T stackType<T>::top()
{
    assert(this->_stackTop != 0);               //if stack is empty,
                                                //terminate the program
    return this->_myArray[this->_stackTop - 1]; //return the element of the
                                                //stack indicated by
                                                //stackTop - 1
} //end top
template <class T>
void stackType<T>::pop()
{
    if (!this->isEmptyStack())
        this->_stackTop--;
    else
        std::cout << "Cannot remove from a empty stack." << std::endl;
}
template <class T>
stackType<T>::stackType(int stackSize)
{
    if (stackSize <= 0)
    {
        std::cout << "Size of the array to hold the stack must "
                  << "be positive." << std::endl;
        std::cout << "Creating an array of size 100." << std::endl;
        this->_maxStackSize = 100;
    }
    else
        this->_maxStackSize = stackSize;
    this->_stackTop = 0;
    this->_myArray = new T[this->_maxStackSize];
}
template <class T>
stackType<T>::~stackType()
{
    delete[] this->_myArray;
}
template <class T>
void stackType<T>::copyStack(const stackType<T> &otherStack)
{
    delete[] this->_myArray;
    this->_maxStackSize = otherStack._maxStackSize;
    this->_stackTop = otherStack._stackTop;
    this->_myArray = new T[this->_maxStackSize];
    for (int i = 0; i < _stackTop; i++)
    {
        this->_myArray[i] = otherStack._myArray[i];
    }
}
template <class T>
stackType<T>::stackType(const stackType<T> &otherStack)
{
    this->_myArray = NULL;
    this->copyStack(otherStack);
}
template <class T>
const stackType<T> &stackType<T>::operator=(const stackType<T> &otherStack)
{
    if (this != &otherStack) //avoid self-copy
        copyStack(otherStack);

    return *this;
} //end operator=

template <class T>
bool stackType<T>::operator==(const stackType<T> &otherStack)
{
    if (this == &otherStack)
        return true;
    else if (_maxStackSize != otherStack._maxStackSize ||
             _stackTop != otherStack._stackTop)
        return false;
    else
    {
        for (int i = 0; i < _stackTop; i++)
            if (_myArray[i] != otherStack._myArray[i])
                return false;
        return true;
    }
}

#endif