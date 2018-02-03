//
// Created by michael on 2/3/2018.
//

#ifndef GROUP_PROGRAMMING_01_NOSUCHELEMENTEXCEPTION_H
#define GROUP_PROGRAMMING_01_NOSUCHELEMENTEXCEPTION_H

#include <string>

class NoSuchElementException{
private:
    string message;
public:
    NoSuchElementException(string message);
    void printMessage();
};

#endif //GROUP_PROGRAMMING_01_NOSUCHELEMENTEXCEPTION_H
