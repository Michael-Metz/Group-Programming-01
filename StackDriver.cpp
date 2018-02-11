#include <iostream>
#include <string>
#include <vector>
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
	Stack stack;
	string input;
	cout << "0";
	int x;
	vector<int> array;
	int iter = 0;
	array.push_back(0);
	iter++;
	stack.push(0);
	while (true)
	{
		cout << "\n>";
		getline(cin, input);

		switch (input[0])
		{

		case '+':
			x = parseNumber(input);
			x = stack.ontop() + x;
			cout << x;
			stack.push(x);
			array.push_back(0);
			iter++;
			break;
		case '-':
			x = parseNumber(input);
			x = stack.ontop() - x;
			cout << x;
			stack.push(x);
			array.push_back(0);
			iter++;
			break;
		case '/':
			x = parseNumber(input);
			x = stack.ontop() / x;
			cout << x;
			stack.push(x);
			array.push_back(0);
			iter++;
			break;
		case '*':
			x = parseNumber(input);
			x = stack.ontop() * x;
			cout << x;
			stack.push(x);
			array.push_back(0);
			iter++;
			break;
		case '%':
			x = parseNumber(input);
			x = stack.ontop() % x;
			cout << x;
			stack.push(x);
			array.push_back(0);
			iter++;
			break;

			//clear
		case 'C':
			stack.push(0);
			cout << "0";
			array.push_back(0);
			iter++;
			break;

			//undo
		case 'U':
			stack.undo();
			cout << stack.ontop();
			array[iter] = 1;
			iter++;
			break;

			//redo
		case 'R':
			if (array[iter - 1] == 1) {
				stack.redo();
				cout << stack.ontop();
				iter--;
				array[iter] = '\0';
			}
			else {
				cout << "No operations to redo\n" << stack.ontop();
			}
			
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
int parseNumber(string s) {

	string temp = "";
	//0x20 ascii space
	//0x30 to 0x39 are ascii numbers
	for (int i = 1; i < s.size(); i++) {
		if (s[i] != ' ') {
			temp += s[i];
		}
	}
	return stoi(temp);
}