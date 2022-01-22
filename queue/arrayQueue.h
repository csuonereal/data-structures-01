#ifndef h_arrayQueue
#define h_arrayQueue
#include <iostream>
#include "queue.h"

template <class T>
class arrayListQ : public queue<T>
{
public:
    bool isEmptyQueue() override;
    bool isFullQueue() override;
    void initializeQueue() override;
    T getFront() override;
    T getRear() override;
    void addQueue(const T &element) override;
    void deleteQueue() override;
    arrayListQ(int size = 100);
    arrayListQ(const arrayListQ<T> &other);
    ~arrayListQ();

protected:
    int _maxQueueSize;
    int _length;
    int _queueFront;
    int _queueRear;
    T *_list;
};

template <class T>
bool arrayListQ<T>::isEmptyQueue()
{
    if (_length == 0)
    {
        return true;
    }
    return false;
}
template <class T>
bool arrayListQ<T>::isFullQueue()
{
    if (_length == _maxQueueSize)
    {
        return true;
    }
    return false;
}
template <class T>
void arrayListQ<T>::initializeQueue()
{
    //(queueRear+1)%maxQueueSize
    _queueFront = 0;
    _queueRear = _maxQueueSize - 1;
    _length = 0;
}
template <class T>
T arrayListQ<T>::getFront()
{
    return _list[_queueFront];
}
template <class T>
T arrayListQ<T>::getRear()
{
    return _list[_queueRear];
}
template <class T>
void arrayListQ<T>::addQueue(const T &element)
{
    if (!this->isFullQueue())
    {
        _queueRear = (_queueRear + 1) % _maxQueueSize;
        _length++;
        _list[_queueRear] = element;
    }
    else
    {
        std::cerr << "LIST IS FULL" << std::endl;
    }
}
template <class T>
void arrayListQ<T>::deleteQueue()
{
    if (!this->isEmptyQueue())
    {
        _length--;
        _queueFront = (_queueFront + 1) % _maxQueueSize;
    }
    else
    {
        std::cerr << "LIST IS EMPTY" << std::endl;
    }
}
template <class T>
arrayListQ<T>::arrayListQ(int size)
{
    if (size < 0)
    {
        std::cerr << "WE NEED A POSITIVE SIZE" << std::endl;
    }
    else
    {
        _maxQueueSize = size;
    }
    _queueFront = 0;
    _queueRear = _maxQueueSize - 1;
    _length = 0;
    _list = new T[_maxQueueSize];
}
template <class T>
arrayListQ<T>::arrayListQ(const arrayListQ<T> &other)
{
    _queueFront = other.queueFront;
    _queueRear = other._queueRear;
    _length = other._length;
    _maxQueueSize = other._maxQueueSize;
    _list = new T[_maxQueueSize];
    for (int i = _queueFront; i <= _queueRear; i = (i + 1) % _maxQueueSize)
        _list[i] = other._list[i];
}
template <class T>
arrayListQ<T>::~arrayListQ()
{
    delete[] _list;
}

#endif