#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <vector>

using namespace std;
int progress[5];// room #, Piovesan, Kempe, Robot, Exit?
string french;
string exitcode;
vector <char> letters;
int attempts = 3;

void clear() {
	COORD topLeft = { 0, 0 };
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen;
	DWORD written;

	GetConsoleScreenBufferInfo(console, &screen);
	FillConsoleOutputCharacterA(
		console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	FillConsoleOutputAttribute(
		console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
		screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	SetConsoleCursorPosition(console, topLeft);
}
void gameover() {

}
void piovesan() {//ask for a french sentence
	if (progress[1] == 0) {
		cout << "You have found Mme Piovesan in room 212\nYou ask her for help as you just want to leave\nShe responds in French with:\nBonjour, Pouvez vous traduire le mot casse-tete pour moi\n";
		cout << "Please enter what you believe the translation of casse-tete is in english:";
		cin >> french;
		while (french != "puzzle") {
			cout << "Essayer encore sil-vous-plait:";
			cin >> french;
		}
		cout << "Bien fait. Jadore faire les casse-tetes says Madame.\nShe slips you a note with the letters A U O on it and gives you no more information.";
		cout << "Your quest continues\n";
		cout << "As you leave the room you hear a click, she has locked the door and you may not visit her again...\n";
		letters.push_back('A');
		letters.push_back('U');
		letters.push_back('O');
		progress[1] = 1;
	}
	else {
		cout << "You have returned to room 212. The door is locked since you have already come here and Mme Piovesan does not have anymore assitance for you\nBetter move onto a different room";
	}
}
void kempe() {//solving math equation
	letters.push_back('G');
	letters.push_back('I');
	letters.push_back('N');
	letters.push_back('T');

}
void robot() {//drive to then shoot?
	letters.push_back('R');
	letters.push_back('D');
	letters.push_back('A');
}
void door() {//ask for secret word
	cout << "You have arrived at the front door.\nSeemingly the only escape point of the school.\nOn the door you see a padlock requiring 10 letters\n";
	cout << "From the teachers you have seen so far, you've collected these letters:";
	for (int i = 0; i < letters.size(); i++) {
		cout << letters[i] << " ";
	}
	cout << "\nWhat words have you come across today that are 10 letters\nYou'll need to input something to try and get out:";
	cin >> exitcode;
	for (int i = 0; i < exitcode.size(); i++) {
		exitcode[i] = tolower(exitcode[i]);
	}
	while (exitcode != "graduation") {
		attempts--;
		cout << "Unfortunately you have entered the wrong code. You only have " << attempts << " tries remaining before you are stuck in the school forever";
		cin >> exitcode;
		for (int i = 0; i < exitcode.size(); i++) {
			exitcode[i] = tolower(exitcode[i]);
		}
		if (attempts == 0) {
			gameover();
		}
	}
	clear();
	cout << "Congrats you have successfully graduated from Saint Mary's High School\nI wish you the very best on your future endeavours\nTry and not get stuck in a school again...\n";
}
void room() {
	switch (progress[0]) {
	case 212:
		piovesan();
		break;
	case 318:
		kempe();
		break;
	case 402:
		robot();
		break;
	case 200:
		door();
		break;
	case 238:  //Arnett
		break;
	case 237: //Cobb
		break;
	case 236: //Hrycak
		break;
	case 235: //Reitzel
		break;
	case 234: //Hillyer
		break;
	case 230: //Stairs
		break;
	case 1: //DRAMA
		break;
	case 211: //Neilly
		break;
	case 210: //Mr Fitz
		break;
	case 209://Hogan/Hint
		break;
	case 127://Start
		break;
	case 128://Skiba
		break;
	case 129://Chapel
		break;
	case 130://Music
		break;
	case 2://Guidance
		break;
	case 3: //office
		break;
	case 401://Co-op
		break;
	case 400://Shop
		break;
	case 320://Empty
		break;
	case 319://Walter
		break;
	case 315://Ward
		break;
	case 313://Takken
		break;
	case 326://Mcgee
		break;
	case 327: //Hannusch
		break;
	case 328://Ms Hannusch
		break;
	case 329://Kim
		break;
	case 301://Snider
		break;
	case 302://Annetta
		break;
	default://outside
		cout << "no room";
	}
}
void move() {

}

int main() {
	fstream gamefile;//most important for external files
	string theLine;//using to get data from file
	char oldfile;
	string filename;
	bool open = false;
	cout << "Welcome to the Role Playing Game\nYou are a grade 9 student of Saint Mary's who has been locked inside the building on your very first day.\nYou're knowledge of the rooms and teachers will be put to the test\n";
	do {
		cout << "Do you have a save file(Y or N)";//does user want to load or start new game
		cin >> oldfile;
		if (oldfile == 'y' || oldfile == 'Y') {//works with both upper and lower case
			cout << "Please enter the save file name without the type:";
			cin >> filename;//get file name
			filename += ".txt";//add file type
			gamefile.open(filename);//find and open file
			if (gamefile.is_open()) {
				open = true;
				for (int i = 0; i < 5; i++) {
					getline(gamefile, theLine);//get first line store in string
					progress[i] = stoi(theLine);//send to progress and convert to integer
				}
			}
		}
		else {
			cout << "Please enter the name of the file you would like to save to:";//new game, create a file save name
			cin >> filename;
			filename += ".txt";//add type
			ofstream gamefile(filename);//create the file
			open = true;//we know its open
			for (int i = 0; i < 5; i++) {
				progress[i] = 0;
			}
		}
	} while (open == false);
	clear();
	cout << "To win the game you must visit 3 different areas of the school and complete a task at each location\nThe game will begin shortly...\n";
	kempe();
	robot();
	piovesan();
	clear();
	door();
		
	return 0;
}
