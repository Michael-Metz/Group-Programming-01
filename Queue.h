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
    void enqueue(int item);
    int dequeue() throw(NoSuchElementException);
    bool isEmpty();

};
