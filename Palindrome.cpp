#include <iostream>
#include <math.h>
#include <string>

using namespace std;

int main() {
	string word;
	int length;
	bool pass;
	cout << "Please enter your word of choice:";
	getline(cin, word);//get input
	length = word.length();//size er up
	for (int i = 0; i < length; i++) {//convert all to lower case
		word[i] = tolower(word[i]);
	}
	int j = length - 1;//create secondary couunting variable
	for (int i = 0; i<length; i++) {//loop through the size of palindrome
		if (word[i] == word[j]) {//if they match we clear continue on
			pass = true;
		}
		else {//if they dont match, just fail it now stop going
			pass = false;
			break;
		}
		j -= 1;
	}
	if (pass == true) {//it made it all the way through with passes therefore its good
		cout << "This word is a palindrome\n";
	}
	else {//it failed once and so be it, tell user
		cout << "No palindrome in sight, try again I guess\n";
	}
	system("pause");
	return 0;
}
