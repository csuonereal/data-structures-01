#ifndef h_arrayList
#define h_arrayList
#include <iostream>
#include <cassert>

template <class T>
class arrayList
{
public:
    bool isEmpty();
    bool isFull();
    int getListSize();
    int getMaxListSize();
    void print();
    void printTopN(std::string type = "asc", int n = 10);
    bool isItemEqual(int location, T &other);
    void insertAt(int location, T &other);
    void insertEnd(T &other);
    void removeAt(int location);
    void removeAll();
    void retrieveAt(int location, T &retItem);
    void replaceAt(int location, T &repItem);
    int search(T &searchKey);
    void insert(T &newItem);
    void remove(T &toBeDeletedItem);
    T getMax();
    T getMin();
    arrayList(int size = 100);
    arrayList(const arrayList<T> &other);
    ~arrayList();

protected:
    T *_list;
    int _length;
    int _maxSize;
};

template <class T>
bool arrayList<T>::isEmpty()
{
    if (_length == 0)
    {
        return true;
    }
    return false;
}
template <class T>
bool arrayList<T>::isFull()
{
    if (_length == _maxSize)
    {
        return true;
    }
    return false;
}

template <class T>
int arrayList<T>::getListSize()
{
    return _length;
}
template <class T>
int arrayList<T>::getMaxListSize()
{
    return _maxSize;
}
template <class T>
void arrayList<T>::print()
{
    for (int i = 0; i < _length; i++)
    {
        std::cout << _list[i] << " ";
    }
}
template <class T>
void arrayList<T>::printTopN(std::string type , int n )
{
    if (n > 0)
    {
        if (type == "asc")
        {
            for (int i = 0; i < n; i++)
            {
                std::cout << _list[i] << std::endl;
            }
        }
        else if (type == "desc")
        {
            for (int i = _length - 1; n >= 0; n--, i--)
            {
                std::cout << _list[i] << std::endl;
            }
        }
    }
    else
    {
        std::cout << "Invalid input for n." << std::endl;
    }
}
template <class T>
bool arrayList<T>::isItemEqual(int location, T &other)
{
    if (_list[location] = other)
    {
        return true;
    }
    return false;
}
template <class T>
void arrayList<T>::insertAt(int location, T &other)
{
    if (location < 0 || location >= _maxSize)
    {
        std::cerr << "INVALID LOCATION" << std::endl;
    }
    else
    {
        if (_length >= _maxSize)
        {
            std::cerr << "LIST IS FULL" << std::endl;
        }
        else
        {
            for (int i = _length - 1; i > location; i--)
            {
                _list[i] = _list[i - 1];
            }
            _list[location] = other;
            _length++;
        }
    }
}

template <class T>
void arrayList<T>::insertEnd(T &other)
{
    if (_length >= _maxSize)
    {
        std::cerr << "LIST IS FULL" << std::endl;
    }
    else
    {
        _list[_length - 1] = other;
        _length++;
    }
}
template <class T>
void arrayList<T>::removeAt(int location)
{
    if (location < 0 || location >= _length)
    {
        std::cerr << "INVALID POSTITON TO DELETE" << std::endl;
    }
    else
    {
        for (int i = location; i < _length; i++)
        {
            _list[i] = _list[i + 1];
        }
        _length--;
    }
}

template <class T>
T arrayList<T>::getMax()
{
    T largest = _list[0];
    for (int i = 0; i < _length - 1; i++)
    {
        if (_list[i] >= largest)
        {
            largest = _list[i];
        }
    }
    return largest;
}
template <class T>
T arrayList<T>::getMin()
{
    T smallest = _list[0];
    for (int i = 0; i < _length - 1; i++)
    {
        if (_list[i] <= smallest)
        {
            smallest = _list[i];
        }
    }
    return smallest;
}

template <class T>
void arrayList<T>::removeAll()
{
    _length = 0;
}

template <class T>
void arrayList<T>::retrieveAt(int location, T &retItem)
{
    if (location < 0 || location >= _length)
    {
        std::cerr << "INVALID POSITION" << std::endl;
    }
    else
    {
        retItem = _list[location];
    }
}
template <class T>
void arrayList<T>::replaceAt(int location, T &repItem)
{
    if (location < 0 || location >= _length)
    {
        std::cerr << "INVALID POSITION" << std::endl;
    }
    else
    {
        _list[location] = repItem;
    }
}
template <class T>
int arrayList<T>::search(T &searchKey)
{
    int loc;
    bool found = false;
    for (loc = 0; loc < _length; loc++)
    {
        if (_list[loc] == searchKey)
        {
            found = true;
            break;
        }
    }
    if (found)
        return loc;
    else
        return -1;
}
template <class T>
void arrayList<T>::insert(T &newItem)
{
    int loc;
    if (_length == 0)
    {
        _list[_length] = newItem;
        _length++;
    }
    else if (_length == _maxSize)
    {
        std::cerr << "LIST IS FULL" << std::endl;
    }
    else
    {
        loc = this->search(newItem);
        if (loc == -1)
        {
            _list[_length] = newItem;
            _length++;
        }
        else
        {
            std::cerr << "ALREADY EXISTS" << std::endl;
        }
    }
}
template <class T>
void arrayList<T>::remove(T &toBeDeletedItem)
{
    int loc;
    if (_length == 0)
    {
        std::cerr << "EMPTY LIST" << std::endl;
    }
    else
    {
        loc = this->search(toBeDeletedItem);
        if (loc == -1)
        {
            removeAt(loc);
        }
        else
        {
            std::cerr << "THE ITEM IS NOT FOUND" << std::endl;
        }
    }
}
template <class T>
arrayList<T>::arrayList(int size)
{
    if (size < 0)
    {
        std::cout << "WE NEED A POSITIVE SIZE" << std::endl;
    }
    else
    {
        _maxSize = size;
    }
    _length = 0;
    _list = new T[_maxSize];
}
template <class T>
arrayList<T>::arrayList(const arrayList<T> &other)
{
    _maxSize = other._maxSize;
    _length = other._length;
    _list = new T[_maxSize];

    for (int i = 0; i < _length; i++)
    {
        _list[i] = other._list[i];
    }
}
template <class T>
arrayList<T>::~arrayList()
{
    delete[] _list;
}
#endif
