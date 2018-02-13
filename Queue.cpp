#include "Queue.h"
#include <iostream>

using namespace std;
Queue::Queue() {
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}


/**
 * Deconstructor to free up all memory used by queue
 */
Queue::~Queue() {
    tail = nullptr;

    QueueNode* temp;

    while(head != nullptr){
        temp = head;
        head = head->next;
        delete temp;
    }
}

/**
 * Copy constructor
 * @param q
 */
Queue::Queue(const Queue& q) {
    this->head = nullptr;
    this->tail = nullptr;
    size = 0;

    QueueNode* t = q.head;
    while (t != nullptr)
    {
        this->enqueue(t->data);
        t = t->next;
    }
}

/**
 * Overridding assignment operator
 * @param q
 * @return
 */
Queue& Queue::operator=(const Queue& q) {
    Queue* seperate = new Queue(q);
    return *seperate;
}

/**
 * Creates a node with passed data,
 * Pushes the node on to the tail of the queue
 *
 * @param data - that you want to push onto the tail of the queue
 */
void Queue::enqueue(int data) {
    QueueNode* n = new QueueNode;
    n->data = data;

    if(tail == nullptr){
        head = tail = n;
    } else{
        tail->next = n;
        tail = n;
    }
    n->next = nullptr;

    size++;
//    cout << "addded: " << tail->data << endl;
}
/**
 * Remove one item from the head of the queue and return its result
 *
 * @throws NoSuchElementException if queue is empty
 * @return item at head of queue
 */
int Queue::dequeue() throw(NoSuchElementException) {
    if(isEmpty())
        throw new NoSuchElementException();

    QueueNode* n = head;
    int data = n->data;

    head = n->next;
    //check if queue is now empty
    if(head == nullptr)
        tail = nullptr;

    delete n;
    size--;
//    cout << "removed: " << data << endl;
    return data;
}
/**
 * Returns the first item from the head of the queue but doesnt remove it
 *
 * @throws NoSuchElementException if queue is empty
 * @return item at head of queue
 */
int Queue::peek() const throw(NoSuchElementException) {
    if(isEmpty())
        throw new NoSuchElementException();

    return head->data;
}

/**
 * Returns the amount of nodes currently in the queue
 *
 * @return amount of nodes in queue
 */
int Queue::getSize() const {
    return size;
}

/**
 * Returns if any nodes are currently in the queue
 * @return true if queue is empty
 */
bool Queue::isEmpty() const {
    return size == 0 ? true : false;
}