//
// Created by michael on 2/3/2018.
//

#include "NoSuchElementException.h"
#include <iostream>

NoSuchElementException::NoSuchElementException(std::string message) {
    this->message = message;
}

void NoSuchElementException::printMessage() {
    std::cout << "NoSuchElementException: " << this->message;
}