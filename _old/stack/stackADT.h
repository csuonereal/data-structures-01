#ifndef H_stackADT
#define H_stackADT

template <class T>
class stackADT
{
public:
    virtual void initializeStack() = 0;
    virtual bool isEmptyStack() = 0;
    virtual bool isFullStack() = 0;
    virtual void push(const T& newItem) = 0;
    virtual T top() = 0;
    virtual void pop() = 0;
    virtual void print() = 0;
};

#endif