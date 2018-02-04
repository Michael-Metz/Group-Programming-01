
struct StackNode
{
    char c;
    int data1;
    int data2;
    StackNode* next;
};

class Stack
{
private:
    StackNode* top;
public:
    void push(int x);
    int pop();
    bool isEmpty();
    Stack();
};