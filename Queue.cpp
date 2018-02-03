#include "Queue.h"

Queue::Queue() {
    this->head = nullptr;
    this->tail = nullptr;
    this->size == 0;
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
        n->next = nullptr;
        tail = n;
    }
    size++;
}
/**
 * Remove one item from the head of the queue and return its result
 *
 * @throws NoSuchElementException if queue is empty
 * @return item at head of queue
 */
int Queue::dequeue() throw(NoSuchElementException) {
    if(head == nullptr || size == 0){
        NoSuchElementException* e = new NoSuchElementException;
        throw *e;
    }
    QueueNode* n = head;
    int data = n->data;

    head = n->next;
    delete n;
    size--;
    return data;
}