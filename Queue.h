#include "NoSuchElementException.h"

struct QueueNode{
    int data;
    QueueNode* next;
};

class Queue{
private:
    int size;
    QueueNode* head;
    QueueNode* tail;
public:
    Queue();
    Queue(const Queue& q);
    Queue& operator=(const Queue& q);

    void enqueue(int item);
    int dequeue() throw(NoSuchElementException);
    int peek() const throw(NoSuchElementException);
    bool isEmpty() const ;
    int getSize() const;

    ~Queue();

};
