
struct StackNode
{
    char c;
    int data1;
    int data2;
    StackNode* next;
	StackNode* previous;
};

class Stack
{
private:
    StackNode* top;
public:
    void push(int x);
	int ontop();
	void undo();
	void redo();
    int pop();
    bool isEmpty();
    Stack();
};