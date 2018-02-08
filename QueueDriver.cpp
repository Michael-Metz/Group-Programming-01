#include <iostream>
#include <string>

#include "Queue.h"

using namespace std;

int main() {
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
