//
// Created by michael on 2/3/2018.
//

#include "NoSuchElementException.h"
#include <iostream>

NoSuchElementException::NoSuchElementException() {
    std::cout << "Tried dequeueing a empty queue" << std::endl;
}