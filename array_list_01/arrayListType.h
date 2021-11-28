#ifndef H_arrayListType
#define H_arrayListType

#include <iostream>
#include <cassert>
template <class T>
class arrayListType
{
public:
    const arrayListType<T> &operator=(const arrayListType<T> &);
    bool isEmpty();
    bool isFull();
    int listSize();
    int maxListSize();
    void print();
    bool isItemAtEqual(int location, const T &item);
    void insertAt(int location, const T &item);
    void insertEnd(const T &item);
    void removeAt(int location);
    void removeAtV2(int location);
    void removeAll(const T &item);
    void retrieveAt(int location, const T &item);
    void replaceAt(int location, const T &item);
    void clearList();
    int seqSearch(const T &item);
    void insert(const T &item);
    //insertItem at the end of the list. However, first the
    //list is searched to see whether the item to be inserted
    void remove(const T &item);
    T min();
    T max();
    arrayListType(int size = 100);
    //constructor
    //Creates an array of the size specified by the
    //parameter size. The default array size is 100.
    arrayListType(const arrayListType<T> &otherList);
    //copy constructor
    ~arrayListType();
    //destructor
    //Deallocates the memory occupied by the array.

protected:
    T *_list;
    int _length;
    int _maxSize;
};

template <class T>
bool arrayListType<T>::isEmpty()
{
    return (_length == 0);
}
template <class T>
bool arrayListType<T>::isFull()
{
    return (_length == _maxSize);
}
template <class T>
int arrayListType<T>::listSize()
{
    return _length;
}
template <class T>
int arrayListType<T>::maxListSize()
{
    return _maxSize;
}
template <class T>
void arrayListType<T>::print()
{
    for (int i = 0; i < _length; i++)
    {
        std::cout << _list[i] << " ";
    }
    printf("\n");
}
template <class T>
bool arrayListType<T>::isItemAtEqual(int location, const T &item)
{
    return (_list[location] = item);
}
template <class T>
void arrayListType<T>::insertAt(int location, const T &item)
{
    if (location < 0 && location >= _maxSize)
    {
        std::cerr << "The position of the item to be inserted is out of range" << std::endl;
    }
    else
    {
        if (_length >= _maxSize)
        {
            std::cerr << "Cannot insert in a full list" << std::endl;
        }
        else
        {
            for (int i = _length; i > location; i--)
            {
                _list[i] = _list[i - 1];
            }
            _list[location] = item;
            _length++;
        }
    }
}
template <class T>
void arrayListType<T>::insertEnd(const T &item)
{
    if (_length >= _maxSize)
    {
        std::cerr << "Cannot insert in a full list" << std::endl;
    }
    else
    {
        _list[_length] = item;
        _length++;
    }
}
template <class T>
void arrayListType<T>::removeAt(int location)
{
    if (location < 0 || location >= _length)
    {
        std::cerr << "The location of the item to be removed is out of range" << std::endl;
    }
    else
    {
        for (int i = location; i < _length - 1; i++)
        {
            _list[i] = _list[i + 1];
        }
        _length--;
    }
}
template <class T>
void arrayListType<T>::removeAtV2(int location)
{
    if (location < 0 || location >= _length)
        std::cerr << "The location of the item to be removed is out of range" << std::endl;
    else
    {
        _list[location] = _list[_length - 1];
        _length--;
    }
} //end removeAt

template <class T>
void arrayListType<T>::removeAll(const T &item)
{
    int loc;
    if (_length == 0)
    {
        std::cerr << "Cannot delete from an empty list" << std::endl;
    }
    else
    {
        loc = 0;
        while (loc < _length)
        {
            if (_list[loc] == item)
            {
                removeAtV2(loc);
            }
            else
            {
                loc++;
            }
        }
    }
}
template <class T>
T arrayListType<T>::min()
{
    assert(_length != 0);
    T smallest = _list[0];
    for (int i = 1; i < _length; i++)
    {
        if (smallest >= _list[i])
        {
            smallest = _list[i];
        }
    }
    return smallest;
}
template <class T>
T arrayListType<T>::max()
{
    assert(_length != 0);
    T largest = _list[0];
    for (int i = 1; i < _length; i++)
    {
        if (largest <= _list[i])
        {
            largest = _list[i];
        }
    }
    return largest;
}
template <class T>
void arrayListType<T>::retrieveAt(int location, const T &item)
{
    if (location < 0 || location >= _length)
    {
        std::cerr << "The location of the item to be retrieved is out of range" << std::endl;
    }
    else
    {
        item = _list[location];
    }
}

template <class T>
void arrayListType<T>::replaceAt(int location, const T &item)
{
    if (location < 0 || location >= _length)
    {
        std::cerr << "The location of the item to be replaced is out of range" << std::endl;
    }
    else
    {
        _list[location] = item;
    }
}

template <class T>
void arrayListType<T>::clearList()
{
    _length = 0;
}
template <class T>
int arrayListType<T>::seqSearch(const T &item)
{
    int loc;
    bool found = false;
    for (loc = 0; loc < _length; loc++)
    {
        if (_list[loc] == item)
        {
            found = true;
            break;
        }
    }
    if (found)
    {
        return loc;
    }
    else
    {
        return -1;
    }
}
template <class T>
void arrayListType<T>::insert(const T &item)
{
    int loc;
    if (_length == 0)
    {
        _list[_length] = item;
        _length++;
    }
    else if (_length == _maxSize)
    {
        std::cerr << "Cannot insert in a full list" << std::endl;
    }
    else
    {
        loc = seqSearch(item);
        if (loc == -1)
        {
            _list[_length] = item;
        }
        else
        {
            std::cerr << "The item to be inserted is already in the list. No duplicates are allowed." << std::endl;
        }
    }
}
template <class T>
void arrayListType<T>::remove(const T &item)
{
    int loc;

    if (_length == 0)
        std::cerr << "Cannot delete from an empty list." << std::endl;
    else
    {
        loc = seqSearch(item);

        if (loc != -1)
        {
            removeAt(loc);
        }

        else
        {
            std::cerr << "The item to be deleted is not in the list." << std::endl;
        }
    }
} //end remove

template <class T>
arrayListType<T>::arrayListType(int size)
{
    if (size < 0)
    {
        std::cerr << "The array size must be positive. Creating an array size of 100." << std::endl;
        _maxSize = 100;
    }
    else
    {
        _maxSize = size;
    }
    _length = 0;
    _list = new T[_maxSize];
    assert(_list != NULL);
}
template <class T>
arrayListType<T>::~arrayListType()
{
    delete[] _list;
}

template <class T>
arrayListType<T>::arrayListType(const arrayListType<T> &otherList)
{
    _maxSize = otherList._maxSize;
    _length = otherList._length;
    _list = new T[_maxSize]; //create the array
    assert(_list != NULL);   //terminate if unable to allocate
                             //memory space

    for (int j = 0; j < _length; j++) //copy otherList
        _list[j] = otherList._list[j];
} //end copy constructor

#endif