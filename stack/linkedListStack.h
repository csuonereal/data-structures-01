#ifndef H_stackType
#define H_stackType

#include <iostream>
#include <cassert>
#include "stackADT.h"

template <class T>
class node
{
public:
    T _data;
    node<T> *_next;
};

template <class T>
class linkedStackType : public stackADT<T>
{
public:
    const linkedStackType<T> &operator=(const linkedStackType<T> &);
    bool isEmptyStack() override;
    bool isFullStack() override;
    void initializeStack() override;
    void print() override;
    void push(const T &) override;
    T top() override;
    void pop() override;
    bool operator==(const linkedStackType<T> &) const;
    linkedStackType();
    linkedStackType(const linkedStackType<T> &);
    ~linkedStackType();

private:
    node<T> *_stackTop;
    void copyStack(const linkedStackType<T> &otherStack);
};

template <class T>
linkedStackType<T>::linkedStackType()
{
    _stackTop = nullptr;
}
template <class T>
bool linkedStackType<T>::isEmptyStack()
{
    return (_stackTop == nullptr);
}
template <class T>
bool linkedStackType<T>::isFullStack()
{
    return false;
}
template <class T>
void linkedStackType<T>::initializeStack()
{
    node<T> *temp;
    while (_stackTop == nullptr)
    {
        temp = _stackTop;
        _stackTop = _stackTop->_next;
        delete temp;
    }
}
template <class T>
void linkedStackType<T>::print()
{
    if (this->isEmptyStack())
    {
        std::cout << "List is empty." << std::endl;
    }
    else
    {
        node<T> *current = this->_stackTop;
        while (current != nullptr)
        {
            std::cout << current->_data << " ";
            current = current->_next;
        }
        printf("\n");
    }
}
template <class T>
void linkedStackType<T>::push(const T &newElement)
{
    node<T> *newNode;
    newNode = new node<T>;
    newNode->_data = newElement;
    newNode->_next = _stackTop;

    _stackTop = newNode;
}
template <class T>
T linkedStackType<T>::top()
{
    assert(_stackTop != NULL);
    return _stackTop->_data;
}
template <class T>
void linkedStackType<T>::pop()
{
    node<T> *temp;
    if (_stackTop != nullptr)
    {
        temp = _stackTop;
        _stackTop = _stackTop->_next;
        delete temp;
    }
    else
        std::cout << "Cannot remove from an empty stack." << std::endl;
}
template <class T>
void linkedStackType<T>::copyStack(const linkedStackType<T> &otherStack)
{
    node<T> *newNode, *current, *last;
    if (_stackTop != nullptr)
    {
        this->initializeStack();
    }
    if (otherStack._stackTop == nullptr)
    {
        _stackTop = nullptr;
    }
    else
    {
        current = otherStack._stackTop;
        _stackTop = new node<T>;
        _stackTop->_data = current->_data;
        _stackTop->_next = nullptr;
        while (current != nullptr)
        {
            newNode = new node<T>;

            newNode->_data = current->_data;
            newNode->_next = nullptr;
            last->_next = newNode;
            last = newNode;
            current = current->_next;
        } //end while
    }
}
template <class T>
linkedStackType<T>::linkedStackType(const linkedStackType<T> &otherStack)
{
    _stackTop = nullptr;
    copyStack(otherStack);
}

template <class T>
linkedStackType<T>::~linkedStackType()
{
    initializeStack();
}

template <class T>
const linkedStackType<T> &linkedStackType<T>::operator=(const linkedStackType<T> &otherStack)
{
    if (this != &otherStack) //avoid self-copy
        copyStack(otherStack);

    return *this;
} //end operator=

template <class T>
bool linkedStackType<T>::operator==(const linkedStackType<T> &otherStack) const
{

    node<T> *current1 = _stackTop;
    node<T> *current2 = otherStack._stackTop;

    if (this == &otherStack)
        return true;
    else
    {
        while (current1 != nullptr && current2 != nullptr)
        {
            if (current1->_data != current2->_data)
                return false;

            current1 = current1->_next;
            current2 = current2->_next;
        }

        if (current1 != nullptr || current2 != nullptr)
            return false;

        return true;
    }
}
#endif