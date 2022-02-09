#include <iostream>
#include <math.h>

using namespace std;

int main() {
	int num1 = 0;
	int num2 = 0;
	int operation = 0;
	double result = 0;
	int again = 0;
	for (;;) {
		cout << "Welcome to my calculator\n1 = +, 2 = -, 3 = *, 4 = /, 5 = ^, 6 = root, 7 modulous divison\nPlease enter the operation you would like perform:";
		cin >> operation;
		if (operation == 5 || operation == 6) {
			cout << "Please enter the base value:";
			cin >> num1;
			cout << "Please enter the index value:";
			cin >> num2;
		}
		else if (operation == 1 || operation == 2 || operation == 3 || operation == 4 || operation == 7) {
			cout << "Please enter the first value:";
			cin >> num1;
			cout << "Please enter the second value:";
			cin >> num2;
		}
		else {
			cout << "The operation you tried to use does not exist in this calculator. Pleas try using #1-6\n";
			system("pause");
			return 0;
		}
		if (operation == 1) {
			result = num1 + num2;
		}
		else if (operation == 2) {
			result = num1 - num2;
		}
		else if (operation == 3) {
			result = num1 * num2;
		}
		else if (operation == 4) {
			result = num1 / num2;
		}
		else if (operation == 5) {
			result = pow(num1, num2);
		}
		else if (operation == 6) {
			result = pow(num1, 1 / num2);
		}
		else {
			result = num1 % num2;
		}
		cout << "The result of your calculation is " << result << endl;
		cout << endl << "Would you like to perform additional calculations? 1 for yes, 2 for no/n";
		cin >> again;
		if (again == 1) {
			continue;
		}
		else {
			break;
		}
	}
	cout << "Thank you for using my calculator.\n";

	system("pause");
	return 0;
}
