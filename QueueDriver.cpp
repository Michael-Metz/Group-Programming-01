#include <iostream>
#include <string>

#include "Queue.h"

using namespace std;

int main() {

    int x;
    int randInteger;
    cout << "Input value of x:  ";
    cin >> x;
    randInteger = rand() % x + 1; //between 1 and x
    
    Queue q;
    for(int i = 0; i < 10; i++){
        q.enqueue(i);
    }
    for(int i = 0; i < 11; i++){
        try{
            cout << q.dequeue() << endl;
        }catch (NoSuchElementException){
            cout << "hullo" << endl;
        }
    }

}
