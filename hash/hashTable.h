#ifndef h_hashTable
#define h_hashTable
#include <iostream>
#include <cassert>

template <class T>
class hashTable
{
public:
    void insert(int hashIndex, const T &item);
    void search(int &hashIndex, const T &item, bool &found);
    bool isItemAtEqual(int hashIndex, const T &item);
    void retrieve(int hashIndex, const T &item);
    void remove(int hashIndex, const T &item);
    void print();
    void calculateIndex(const T &item, int &hashIndex);
    hashTable(int size = 101);
    ~hashTable();

protected:
    T *_hTable; //pointer to the hash table
    int *_indexStatusList;
    int _length;
    int _maxSize;
};
template <class T>
void hashTable<T>::calculateIndex(const T &item, int &hashIndex)
{
    int ascii = item;
    hashIndex = (ascii % _maxSize);
}
template <class T>
void hashTable<T>::insert(int hashIndex, const T &item)
{
    int pCount = 0;
    int inc = 1;
    while (_indexStatusList[hashIndex] == 1 && _hTable[hashIndex] != item && pCount < _maxSize / 2)
    {
        pCount++;
        hashIndex = (hashIndex + inc) % _maxSize;
        inc += 2;
    }
    if (_indexStatusList[hashIndex] != 1)
    {
        _hTable[hashIndex] = item;
        _indexStatusList[hashIndex] = 1;
        _length++;
    }
    else if (_hTable[hashIndex] == item)
    {
        std::cerr << "NO DUPLICATES ARE ALLOWED" << std::endl;
    }
    else
    {
        std::cerr << "TABLE IS FULL" << std::endl;
    }
}
template <class T>
void hashTable<T>::search(int &hashIndex, const T &item, bool &found)
{
    int pCount = 0;
    int inc = 1;
    while (_indexStatusList[hashIndex] != 0 && _hTable[hashIndex] != item && pCount < _maxSize / 2)
    {
        pCount++;
        hashIndex = (hashIndex + inc) % _maxSize;
        inc += 2;
    }
    if (_indexStatusList[hashIndex] == 1 && _hTable[hashIndex] == item)
    {
        hashIndex = hashIndex;
        found = true;
    }
    else
    {
        found = false;
    }
}
template <class T>
bool hashTable<T>::isItemAtEqual(int hashIndex, const T &item)
{
    if (_hTable[hashIndex] == item)
    {
        return true;
    }
    return false;
}
template <class T>
void hashTable<T>::retrieve(int hashIndex, const T &item)
{
    if (_indexStatusList[hashIndex] == 1)
    {
        item = _hTable[hashIndex];
    }
}
template <class T>
void hashTable<T>::remove(int hashIndex, const T &item)
{
    bool found;
    search(hashIndex, item, found);
    if (found)
    {
        _indexStatusList[hashIndex] = -1;
        _length--;
    }
    else
    {
        std::cerr << "ITEM IS NOT FOUND IN THE LIST" << std::endl;
    }
}
template <class T>
void hashTable<T>::print()
{
    for (int i = 0; i < _maxSize; i++)
    {
        if (_indexStatusList[i] == 1)
        {
            std::cout << i << "->" << _indexStatusList[i] << " " << _hTable[i] << std::endl;
        }
    }
}
template <class T>
hashTable<T>::hashTable(int size)
{
    _hTable = new T[size];
    _indexStatusList = new int[size];
    _length = 0;
    _maxSize = size;

    for (int i = 0; i < _maxSize; i++)
    {
        _indexStatusList[i] = 0; //0 means available 1 means full
    }
}
template <class T>
hashTable<T>::~hashTable()
{
    delete[] _hTable;
    delete[] _indexStatusList;
}
#endif
