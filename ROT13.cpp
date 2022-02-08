#include <iostream>
#include <fstream>//needed to access file
#include <string>
#include <vector>

using namespace std;

int main() {
	fstream myfile;//file variable name
	string line;//helps get stuff from file
	char alphabet[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };

	myfile.open("myfile.txt");//transfer file to the variable

	if (myfile.is_open()) {//check for openness
		while (getline(myfile, line)) {//get line from file one at a time
			for (int i = 0; i < line.size(); i++) {//loop for amount of characters in line
				line[i] = tolower(line[i]);//convert all to lower case
				for (int j = 0; j < 26; j++) {//loop through alphabet
					if (line[i] == alphabet[j]) {//if the line and alphabet match
							line[i] = alphabet[(j + 13)%26];//add 13 letters, if after m(above 13) modulo 26 to retun to inside the array
							break;//stop
					}
				}
			}
			cout << line << endl;//output one line at a time
		}
	}
	else {
		cout << "try again\n";//if open failed
	}
	system("pause");
	return 0;
}
