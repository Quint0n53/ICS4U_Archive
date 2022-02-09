#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int limit;
	int total = 0;
	int num1 = 1;
	int num2 = 1;
	cout << "Please specify the value you would like" << endl;
	cin >> limit;//user input
	cout << "1 1 ";//start
	for (;;) {//loop until break
		int total = num1 + num2;//find next num
		if (total > limit) {//check against user
			break;
		}
		cout << total << " ";//output total
		num1 = num2 + 0;//set next numbers
		num2 = total + 0;
	}
	cout << endl;
	system("pause");
	return 0;
}
