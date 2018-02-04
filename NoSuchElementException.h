#ifndef GROUP_PROGRAMMING_01_NOSUCHELEMENTEXCEPTION_H
#define GROUP_PROGRAMMING_01_NOSUCHELEMENTEXCEPTION_H

#include <string>

class NoSuchElementException{
private:
    std::string message;
public:
    NoSuchElementException(std::string message);
    void printMessage();
};

#endif //GROUP_PROGRAMMING_01_NOSUCHELEMENTEXCEPTION_H
