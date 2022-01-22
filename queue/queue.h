#ifndef h_queue
#define h_queue

template <class T>
class queue
{
public:
    virtual bool isEmptyQueue() = 0;
    virtual bool isFullQueue() = 0;
    virtual void initializeQueue() = 0;
    virtual T getFront() = 0;
    virtual T getRear() = 0;
    virtual void addQueue(const T &element) = 0;
    virtual void deleteQueue() = 0;
};

#endif