#ifndef h_linkedQueue
#define h_linkedQueue
#include <iostream>
#include <cassert>
#include "queue.h"

template <class T>
class node
{
public:
    T _data;
    node<T> *_next;
};

template <class T>
class linkedListQ : public queue<T>
{
public:
    bool isEmptyQueue() override;
    bool isFullQueue() override;
    void initializeQueue() override;
    T getFront() override;
    T getRear() override;
    void addQueue(const T &element) override;
    void deleteQueue() override;
    linkedListQ();
    linkedListQ(linkedListQ<T> &other);
    ~linkedListQ();

protected:
    node<T> *_queueFront;
    node<T> *_queueRear;
};

template <class T>
bool linkedListQ<T>::isEmptyQueue()
{
    if (_queueFront == nullptr)
    {
        return true;
    }
    return false;
}
template <class T>
bool linkedListQ<T>::isFullQueue()
{
    return false;
}
template <class T>
void linkedListQ<T>::initializeQueue()
{
    node<T> *temp;
    while (_queueFront != nullptr)
    {
        temp = _queueFront;
        _queueFront = temp->_next;
        delete temp;
    }
    _queueRear = nullptr;
}
template <class T>
T linkedListQ<T>::getFront()
{
    return _queueFront->_data;
}
template <class T>
T linkedListQ<T>::getRear()
{
    return _queueRear->_data;
}
template <class T>
void linkedListQ<T>::addQueue(const T &element)
{
    node<T> *newNode = new node<T>();
    newNode->_data = element;
    newNode->_next = nullptr;
    if (_queueFront == nullptr)
    {
        _queueFront = newNode;
        _queueRear = newNode;
    }
    else
    {
        _queueRear->_next = newNode;
        _queueRear = newNode;
    }
}
template <class T>
void linkedListQ<T>::deleteQueue()
{
    node<T> *temp;
    if (!this->isEmptyQueue())
    {
        temp = _queueFront;
        _queueFront = _queueFront->_next;
        delete temp;
        if (_queueFront == nullptr)
        {
            _queueRear = nullptr;
        }
    }
    else
    {
        std::cerr << "LIST IS EMPTY" << std::endl;
    }
}
template <class T>
linkedListQ<T>::linkedListQ()
{
    _queueFront = nullptr;
    _queueRear = nullptr;
}
template <class T>
linkedListQ<T>::linkedListQ(linkedListQ<T> &other)
{
    node<T> *newNode;
    node<T> *current;

    if (other._queueFront == nullptr)
    {
        _queueFront = nullptr;
        _queueRear = nullptr;
    }
    else
    {
        current = other._queueFront;

        _queueFront = new node<T>;
        _queueFront->_data = current->_data;
        _queueFront->_data = nullptr;

        _queueRear = _queueFront;

        current = current->_data;
        while (current != nullptr)
        {
            newNode = new node<T>;
            newNode->_data = current->_data;
            newNode->_next = nullptr;

            _queueRear->_next = newNode;
            _queueRear = newNode;

            current = current->_next;
        }
    }
}
template <class T>
linkedListQ<T>::~linkedListQ()
{
    node<T> *temp;
    while (_queueFront != nullptr)
    {
        temp = _queueFront;
        _queueFront = _queueFront->_next;
        delete temp;
    }
    _queueRear = nullptr;
}
#endif
