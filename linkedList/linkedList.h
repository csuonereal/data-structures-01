#ifndef H_linkedListType
#define H_linkedListType

#include <iostream>
#include <cassert>

template <class T>
class node
{
public:
    T _data;
    node *_next;
};
template <class T>
class linkedList
{
public:
    int _length;
    node<T> *_head;
    node<T> *_tail;
    linkedList();
    ~linkedList();
    bool isEmpty();
    int getLength();
    void insertAtEnd(T data);
    void insertAtBegin(T data);
    void insertAfter(node<T> *prevNode, T data);
    void deleteAt(int idx);
    void deleteNodesByValue(T value);
    void print();
};

template <class T>
linkedList<T>::linkedList()
{
    this->_length = 0;
    this->_head = nullptr;
    this->_tail = nullptr;
}
template <class T>
linkedList<T>::~linkedList()
{
    node<T> *next = this->_head;
    node<T> *curr = nullptr;
    while (next != nullptr)
    {
        curr = next;
        next = curr->_next;
        delete curr;
    }
    std::cout << "List deleted." << std::endl;
}

template <class T>
bool linkedList<T>::isEmpty()
{
    return this->_head == nullptr;
}

template <class T>
int linkedList<T>::getLength()
{
    return this->_length;
}

template <class T>
void linkedList<T>::insertAtBegin(T data)
{
    node<T> *newNode = new node<T>();
    newNode->_data = data;
    newNode->_next = this->_head;
    if (this->isEmpty())
    {
        this->_tail = newNode;
    }
    this->_head = newNode;
    this->_length++;
}

template <class T>
void linkedList<T>::insertAtEnd(T data)
{
    node<T> *newNode = nullptr;
    if (this->isEmpty())
    {
        newNode = new node<T>();
        this->_head = newNode;
    }
    else
    {
        newNode = this->_tail;
        newNode->_next = new node<T>();
        newNode = newNode->_next;
    }
    newNode->_data = data;
    newNode->_next = nullptr;
    this->_tail = newNode;
    this->_length++;
}
template <class T>
void linkedList<T>::insertAfter(node<T> *prevNode, T data)
{
    if (prevNode == nullptr)
    {
        std::cout << "prevNode cannot be NULL." << std::endl;
        return;
    }
    node<T> *newNode = new node<T>();
    newNode->_data = data;
    newNode->_next = prevNode->_next;
    prevNode->_next = newNode;
}
template <class T>
void linkedList<T>::print()
{
    if (isEmpty())
    {
        std::cout << "List is empty." << std::endl;
    }
    else
    {
        node<T> *current = this->_head;
        while (current != nullptr)
        {
            std::cout << current->_data << " ";
            current = current->_next;
        }
        printf("\n");
    }
}

template <typename T>
void checkTail(linkedList<T> *list)
{
    std::cout << "Tail is set to nullprt: " << (list->tail_ == nullptr) << std::endl;
}

template <typename T>
void checkHead(linkedList<T> *list)
{
    std::cout << "Head is set to nullprt: " << list->isEmpty() << std::endl;
}

#endif