#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector <int> numbers;

int main() {
	int values;
	int input;
	bool changed = false;
	cout << "Please enter how many values will be in your data set:";
	cin >> values;//how large will vector be
	cout << "Separated by spaces enter all the data:";
	for (int i = 0; i < values; i++) {
		cin >> input;//loop into vector with all inputs
		numbers.push_back(input);//send to vector
	}
	do {//repeat until all numbers have been changed
		changed = false;//reset bool to keep looping until perfect
		for (int i = 0; i < numbers.size() - 1; i++) {//from bottom to top
			if (numbers[i] > numbers[i + 1]) {//if number 1 is bigger than 2, swap
				swap(numbers[i], numbers[i + 1]);
				changed = true;//indicate there was a change and therefore loop again
			}
		}
		for (int i = numbers.size() - 1; i > 0; i--) {//same as above but back down the list
			if (numbers[i] < numbers[i - 1]) {//switch if wrong place
				swap(numbers[i], numbers[i - 1]);
				changed = true;
			}
		}
	} while (changed);//if change remains true loop. If no change occurs exit loop
	cout << "These is the data sorted from smallest to largest\n";
	for (int i = 0; i < numbers.size(); i++) {//output all digits in order
		cout << numbers[i] << " ";
	}

	return 0;
}
