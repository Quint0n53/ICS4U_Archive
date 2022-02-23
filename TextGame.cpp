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
int level;
char gotodoor;

void twohundred();
void clear() {//explain this later when you know whats happening
	COORD topLeft = { 0, 0 };//identify top left
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); //get console
	CONSOLE_SCREEN_BUFFER_INFO screen;//copy the buffer speed
	DWORD written;//unsigned interger to loop

	GetConsoleScreenBufferInfo(console, &screen);//spam with spaces
	FillConsoleOutputCharacterA(
		console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	SetConsoleCursorPosition(console, topLeft);//reset to top corner
}
void hint(){
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
	if (progress[2] == 0) {
		int solution;
		cout << "Welcome to the math lab says Mr Kempe.\nYou will need to solve a simple math equation for me\nBe careful of BEDMAS\n";
		cout << "Please give me the answer to 5*3/4+1 =";
		cin >> solution;
		while (solution != 3) {
			cout << "Well well well, it looks like you will need to come visit my class sometime.\nYou have entered the wrong solution, try again:";
			cin >> solution;
		}
		cout << "Congratulations, you have made it through my impossible math class. I shall give you these letters to help you G I N T\n";
		cout << "As you leave Mr Kempe jumps into his ceiling beneath the painted tiles...never to be seen again\n";
		letters.push_back('G');
		letters.push_back('I');
		letters.push_back('N');
		letters.push_back('T');
		progress[2] = 1;
	}
	else {
		cout << "You have returned to room 318. The door is locked since you have already come here and Mr Kempe cannot be found\nBetter move onto a different room";
	}

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
	cout << "Would you like to try and exit or return to room 238?(T or R)\n";
	cin >> gotodoor;
	if (gotodoor == 'r' || gotodoor == 'R') {
		cout << "You will proceed back to the art room\n";
		twohundred();
	}
	else {
		cout << "You shall attempt to escape...Good luck\n";
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
void twohundred() {
	cout << "\nYou are currently in room " << progress[0] << "\nYou may advance to any room on this floor(238,237,236,235,234,228,212,211,210,209);";
	cout << "Where would you like to go:";
	cin >> progress[0];
	switch (progress[0]) {
	case 212:
		piovesan();
		break;
	case 238:  //Arnett
		cout << "You have entered room 238\n";
		cout << "Hello there says Mr Arnett. I hear you are stuck in the school.\nWhile I do not have any advice to help you...\nI do know this is the only location you may access the door from\n";
		cout << "Would you like to proceed to the door (Y or N):";
		cin >> gotodoor;
		if (gotodoor == 'y' || gotodoor == 'Y') {
			cout << "You will proceed to the door to try and escape/Mr Arnett wishes you the best of luck\n";
			door();
		}
		else {
			cout << "I see you have chosen to gather more materials.\nContinue on your adventure little one...\n";
			twohundred();
		}
		break;
	case 237: //Cobb
		cout << "You have entered room 237\n";
		break;
	case 236: //Hrycak
		cout << "You have entered room 236\n";
		break;
	case 235: //Reitzel
		cout << "You have entered room 235\n";
		break;
	case 234: //Hillyer
		cout << "You have entered room 234\n";
		break;
	case 228: //DRAMA
		cout << "You have entered room 228\n";
		break;
	case 211: //Neilly
		cout << "You have entered room 211\n";
		break;
	case 210: //Mr Fitz
		cout << "You have entered room 210\n";
		break;
	case 209://Hogan/Hint
		cout << "You have entered room 209\n";
		break;
	default://outside
		cout << "no room";
		twohundred();
	}
}
void threehundred() {
	clear();
	cout << "You are currently in room " << progress[0] << "\nYou may advance to any room on this floor(127,128,129,130,Office,Guidance);";
	cout << "Where would you like to go:";
	cin >> progress[0];
	switch (progress[0]) {
	case 318:
		kempe();
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
void onehundred() {
	cout << "You are currently in room " << progress[0] << "\nYou may advance to any room on this floor(127, 128, Chapel(129), Music(130),Office (110), Guidance(112))";
	cout << "\nWhere would you like to go:";
	cin >> progress[0];
	clear();
	switch (progress[0]) {
	case 127://Starts
		cout << "You have entered room 127\nAfter returning to your starting point there is nothing left here except for unoperable computers.\nLooks like this room wont help you\n";
		onehundred();
		break;
	case 128://Skiba
		cout << "You have entered room 128\n";
		cout << "Inside you find Ms Skiba, she wishes you the best of luck but cant give you any help on how to leave the school. Better find a new room\n";
		cout << "From this room there are stairs to the right. You may proceed to a different section of the school\nEnter a 1 to remain on the 100 floor or a 2 to proceed to the two hundreds:";
		cin >> level;
		if (level == 1) {
			clear();
			cout << "You chose to remain on the 100 floor.\n";
			onehundred();
		}
		else if(level == 2){
			clear();
			cout << "upstairs you go, good luck!";
			progress[0] = 209;
			twohundred();
		}
		else {
			clear();
			cout << "You entered an invalid floor number, You will be returned to floor one hundred\n";
			onehundred();
		}
		break;
	case 129://Chapel
		cout << "You have entered the chapel\n";
		cout << "You are now in the chapel\nNow would be a great moment to say a prayer to help you leave the school before you are stuck forever\n";
		cout << "After your short prayer and some rummaging there is no useful information in this room. Keep on moving\n";
		onehundred();
		break;
	case 130://Music
		cout << "You have entered the music room\n";
		cout << "It's very odd to hear such a quiet music room. You ponder around checking the recording studios\nBut still out of luck you must continue onto a new room\n";
		onehundred();
		break;
	case 112://Guidance add hint
		cout << "You have entered the guidance office\n";
		cout << "Inside you see Ms Bastien sitting there. She welcomes you into the room and stay for a few minutes.\nYou beg her that all you would like to do is leave\nShe tells you that she may be able to offer you a hint...\n";
		hint();
		break;
	case 110: //office
		cout << "You have entered the main office. To yourself you surely think there would be a solution here.\nWell you've been proven wrong. It is a total ghost town.\nYou look desperately for a key but they've all disapeared\n";
		onehundred();
		break;
	default://outside
		cout << "no room";
		onehundred();
	}
}
void fourhundred() {
	switch (progress[0]) {
	case 400://Shop
		break;
	case 401://Co-op
		break;
	case 402://robot
		robot();
		break;
	default://outside
		cout << "no room";
	}
}

int main() {
	fstream gamefile;//most important for external files
	string theLine;//using to get data from file
	char oldfile;
	string filename;
	bool open = false;
	cout << "Welcome to the Role Playing Game\nYou are a grade 9 student of Saint Mary's who has been locked inside the building on your very first day.\nYou're knowledge of the rooms and teachers will be put to the test\n";
	//do {
	//	cout << "Do you have a save file(Y or N)";//does user want to load or start new game
	//	cin >> oldfile;
	//	if (oldfile == 'y' || oldfile == 'Y') {//works with both upper and lower case
	//		cout << "Please enter the save file name without the type:";
	//		cin >> filename;//get file name
	//		filename += ".txt";//add file type
	//		gamefile.open(filename);//find and open file
	//		if (gamefile.is_open()) {
	//			open = true;
	//			for (int i = 0; i < 5; i++) {
	//				getline(gamefile, theLine);//get first line store in string
	//				progress[i] = stoi(theLine);//send to progress and convert to integer
	//			}
	//		}
	//	}
	//	else {
	//		cout << "Please enter the name of the file you would like to save to:";//new game, create a file save name
	//		cin >> filename;
	//		filename += ".txt";//add type
	//		ofstream gamefile(filename);//create the file
	//		open = true;//we know its open
	//		for (int i = 0; i < 5; i++) {
	//			progress[i] = 0;
	//		}
	//	}
	//} while (open == false);
	clear();//clear out save stuff
	cout << "To win the game you must visit 3 different areas of the school and complete a task at each location\nThe game will begin shortly...\n";
	cout << "You begin in the computer lab where I assume you are playing this game.\nYou will move from room to room as well as using the stairs and portals to travel from point to point\nGOOD LUCK!\n";
	progress[0] = 127;
	onehundred();
	return 0;
}
