#include "Stack.h"
#include <iostream>

Stack::Stack()
{
    this -> top = nullptr;
}

/**
 * This function will create a new node to be put into the stack,
 * set's the nodes data1 to the passed value, and sets the top
 * of the stack to the entered node.
 *
 * @param the data to add to the top of the stack
 */
void Stack::push(int x)
{
    StackNode* node;

    node = new StackNode;
    node -> data1 = x;
    node -> next = top;
    top = node;
}
int Stack::ontop()
{
	StackNode* current = this->top;
	int x = current->data1;
	return x;
}
void Stack::undo()
{
	StackNode* current = top;
	top = top->next;
	top->previous = current;
	

}
void Stack::redo()
{
	top = top->previous;
}

/**
 * Creates a new node to take the value out of the top of the stack
 * Then goes down to the next variable and makes that the first of the stack
 * deletes the temporary node and returns the data.
 *
 * @return data1 of a StackNode
 */
int Stack::pop()
{
    StackNode* current = this->top;
    int x = current -> data1;

    top = top -> next;
    delete current;

    return x;
}

/**
 * If the stack is null, it will return true, otherwise false.
 * @return
 */
bool Stack::isEmpty()
{
    return this->top == nullptr;
}