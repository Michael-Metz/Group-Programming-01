//
// Created by michael on 2/3/2018.
//

#include "NoSuchElementException.h"
#include <iostream>

using namespace std;

NoSuchElementException::NoSuchElementException(string message) {
    this->message = message;
}

void NoSuchElementException::printMessage() {
    cout << "NoSuchElementException: " << message;
}