#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;

int parseNumber(string s);


/**
 * Contains the main loop for the menu of the calculator
 * the switch statements handles all the commands the user can enter
 *
 * @return 0 when finished.
 */
int main() {

    string input;
    cout << "0";
    int x;

    while(true)
    {
        cout << "\n>";
        getline(cin,input);

        switch (input[0])
        {

            case '+':
            case '-':
            case '/':
            case '*':
            case '%':
                x = parseNumber(input);
                cout << x;
                break;

            //clear
            case 'C':
                break;


            //undo
            case 'U':
                break;

            //quit
            case 'Q':
                cout << "\n\nGoodbye\n\n";
                return 0;

        }

    }
}


/**
 * Parses the number from a string that contains lots 0 or more spaces
 * at the beginning of the string
 *
 * @param s - contains a numbers, and may contain spaces at the beginning.
 * @return integer
 */
int parseNumber(string s){

    string temp = "";
    //0x20 ascii space
    //0x30 to 0x39 are ascii numbers
    for(int i = 1; i < s.size() ; i++){
        if(s[i] != ' '){
            temp += s[i];
        }
    }
    return stoi(temp);
}