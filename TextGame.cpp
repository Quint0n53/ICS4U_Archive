#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <vector>
#include <stdlib.h>
#include <conio.h>

using namespace std;
int progress[5];// room #, Piovesan, Kempe, Robot, Hints
string french;
string exitcode;
vector <char> letters;
int attempts = 3;
int level;
char gotodoor;
char tosave;
int hints = 0;
char again;
fstream gamefile;//most important for external files
string filename;

void twohundred();//templates
void fourhundred();
void gameover();
void onehundred();
void threehundred();
void save() {
	gamefile.close();
	ofstream gamefile(filename);//open file in writable manner
	for (int i = 0; i < 5; i++) {
		gamefile << progress[i] << endl;//output
	}
	cout << "Your file name is " << filename;//tell user filename
	gamefile.close();//close
	exit(0);//exit game
}
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
void hint() {
	hints++;
	cout << "You have chosen a great room. In this room the staff member passes you a note.\nAt the very top in big bold letters it says HINT\nYou are beyond grateful\n";
	switch (hints) {
	case 1:
		cout << "This is your first hint. It says visit one room per floor excluding the 100.\nYou reason that this must mean 200, 300 and the MTO building\n";
		cout << "You will return to the room you were just in now\n";
		break;
	case 2:
		cout << "This is now your second hint. The note informs you to go visit room 212, 318 and the Innovation space.\n";
		cout << "To yourself you think these hints are becoming much more helpful.\nAt what point will you be given the solution..\n";
		break;
	case 3:
		cout << "This is your final hint. After this you have lost the game\nThe hint appears to no longer be a hint but rather the answers 3, puzzle and RRRRUULLLLLULLDDDDDD\n";
		cout << "You pray to yourself that this is all you will need to escape finally\n";
		break;
	case 4:
		cout << "This is unfortunate\nYou have used up all of your hints.\n";
		gameover();//no more hints
		break;
	default:
		break;
	}
	progress[4] = hints;//set the progress with hints for saving
	if (progress[0] < 200) {//return
		onehundred();
	}
	else if (progress[0] < 300) {
		twohundred();
	}
	else if (progress[0] < 400) {
		threehundred();
	}
	else {
		fourhundred();
	}
}
void gameover() {//
	cout << "\nUnfortunately you have lost the game. You are stuck in the school forever...Press enter to finish\n";
	_getch();//wait for enter
	exit(0);//close game
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
		clear();
		cout << "Bien fait. Jadore faire les casse-tetes says Madame.\nShe slips you a note with the letters A U O on it and gives you no more information.";
		cout << "Your quest continues\n";
		cout << "As you leave the room you hear a click, she has locked the door and you may not visit her again...\n";
		letters.push_back('A');
		letters.push_back('U');
		letters.push_back('O');
		progress[1] = 1;
	}
	else {
		cout << "You have returned to room 212.\nThe door is locked since you have already come here and Mme Piovesan does not have anymore assitance for you\nBetter move onto a different room";
	}
	progress[0] = 212;
	twohundred();
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
		cout << "You have returned to room 318. The door is locked since you have already come here and Mr Kempe cannot be found\nBetter move onto a different room\n";
	}
	cout << "Press enter to continue\n";
	_getch();
	threehundred();
}
void robot() {
	if (progress[3] == 0) {//check if been here before
		string robot;
		cout << "Welcome to the innovation space; the robotics club home.\nYou see Mr Varsava is trying to help the robot leave the field\n";
		cout << "Please tell him which direction to move the robot all in one large sequence\n(R is right, L is Left, U is Up, D is Down)\n";
		cout << "|_ _ _ _ _ _ _ _ _ _ _ _|\n";
		cout << "|_ _ _ _ _ _ _ _ _ _ _ _|\n";
		cout << "|_ _ _ _ _ _ _ _ _ _ _ _|\n";
		cout << "|_ _ _ _ _ _ _ _ _ _ _ _|\n";
		cout << "|_ _ X X X X X X _ _ _ _|\n";
		cout << "|_ _ X _ _ _ X X X X X _|\n";
		cout << "|_ _ X _ X _ _ _ _ _ X _|\n";
		cout << "|_ _ X _ X X X X X _ X _|\n";
		cout << "|_ _ X _ X R _ _ _ _ X _|\n";
		cout << "|_ _ X _ X X X X X X X _|\n";
		cout << "|_ _ X _ X _ _ _ _ _ _ _|\n";
		cout << "|_ _ X _ X _ _ _ _ _ _ _|\n";
		cin >> robot;
		while (robot != "RRRRUULLLLLULLDDDDDD") {//code
			clear();
			cout << "Try again, the robot did not exit the field ";
			cout << "Please tell him which direction to move the robot all in one large sequence\n(R is right, L is Left, U is Up, D is Down)\n";
			cout << "|_ _ _ _ _ _ _ _ _ _ _ _|\n";
			cout << "|_ _ _ _ _ _ _ _ _ _ _ _|\n";
			cout << "|_ _ _ _ _ _ _ _ _ _ _ _|\n";
			cout << "|_ _ _ _ _ _ _ _ _ _ _ _|\n";
			cout << "|_ _ X X X X X X _ _ _ _|\n";
			cout << "|_ _ X _ _ _ X X X X X _|\n";
			cout << "|_ _ X _ X _ _ _ _ _ X _|\n";
			cout << "|_ _ X _ X X X X X _ X _|\n";
			cout << "|_ _ X _ X R _ _ _ _ X _|\n";
			cout << "|_ _ X _ X X X X X X X _|\n";
			cout << "|_ _ X _ X _ _ _ _ _ _ _|\n";
			cout << "|_ _ X _ X _ _ _ _ _ _ _|\n";
			cin >> robot;//try again
		}
		cout << "Congratulations, the robot has successfuly exited the field.\nYou see the letters R D A on the side of the robot\n";
		cout << "As you leave Mr Kempe jumps into his ceiling beneath the painted tiles...never to be seen again\n";
		letters.push_back('R');//give letters
		letters.push_back('D');
		letters.push_back('A');
		progress[3] = 1;//set progress
	}
	else {
		cout << "You have already saved the robot in the Innovation space\nBetter move onto a different room";
	}
	fourhundred();//return
}
void door() {//ask for secret word
	clear();
	if (attempts == 0) {//stop them if they try anything
		gameover();
	}
	cout << "You have arrived at the front door.\nSeemingly the only escape point of the school.\nOn the door you see a padlock requiring 10 letters\n";
	cout << "From the teachers you have seen so far, you've collected these letters:";
	for (int i = 0; i < letters.size(); i++) {
		cout << letters[i] << " ";//output vector
	}
	cout << "Would you like to try and exit or return to room 238?(T or R)\n";
	cin >> gotodoor;
	if (gotodoor == 'r' || gotodoor == 'R') {//do they want to continue
		cout << "You will proceed back to the art room\n";
		twohundred();
	}
	else {
		cout << "You shall attempt to escape...Good luck\n";
	}
	cout << "\nWhat words have you come across today that are 10 letters\nYou'll need to input something to try and get out:";
	cin >> exitcode;//get ciode
	for (int i = 0; i < exitcode.size(); i++) {
		exitcode[i] = tolower(exitcode[i]);//make lower case
	}
	if (exitcode != "graduation") {
		attempts--;
		if (attempts == 0) {//stop them if they run out of tries
			gameover();
		}
		cout << "Unfortunately you have entered the wrong code.\nYou only have " << attempts << " tries remaining before you are stuck in the school forever";
		cout << "\nDo you wish to try again(Y or N)\n";
		cin >> again;
		if (again == 'Y' || again == 'y') {//try again
			door();
		}
		else {
			twohundred();
		}
	}
	clear();
	cout << "Congrats you have successfully graduated from Saint Mary's High School\nI wish you the very best on your future endeavours\nTry and not get stuck in a school again...\n";
	cout << "Press enter to close the program\n"; // they passed
	_getch();
	exit(0);
}
void twohundred() {
	cout << "\nYou are currently in room " << progress[0] << "\nYou may advance to any room on this floor(238,237,236,235,234,228,212,211,210,209);";
	cout << "Where would you like to go:";
	cin >> progress[0];
	clear();
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
		cout << "This is the home education room. You grab a snack from one of the fridges.\nAfter snooping through all the drawers and various storage areas you do not find anything useful\n";
		cout << "You decide its best to move onto a different room\n";
		twohundred();
		break;
	case 236: //Hrycak
		cout << "You have entered room 236\nInside you find Mr Hrycak making an espresso he offers you some help with the puzzle\n";
		hint();
		break;
	case 235: //Reitzel
		cout << "You have entered room 235\nYou find Mr Reitzel practing his french for the DELF, he informs you that there is nothing in his room to help you";
		twohundred();
		break;
	case 234: //Hillyer
		cout << "You have entered room 234\nInside you see the ghost of Ms Hillyer who no longer works at our school\nYou immedietely run out of the door\n";
		cout << "You are faced with three options, stay on the 200s, go up the stairs to the 300s or head outside to the MTO building\n";
		cout << "For 200s enter a 2, for 300s enter a 3 and for the MTO enter a 4";
		cin >> level;
		if (level == 2) {
			twohundred();
		}
		else if (level == 3) {
			progress[0] = 320;
			threehundred();
		}
		else if (level == 4) {
			progress[0] = 403;
			fourhundred();
		}
		else {
			twohundred();
		}
		break;
	case 228: //DRAMA
		cout << "You have entered room 228\nThis is where the magic of the school happens\nYou see Mrs Ward dancing and opt to not bother her\nProceed to a differnet room";
		twohundred();
		break;
	case 210: //Mr Fitz
		cout << "You have entered room 210\nMr Fitzsimmons is teaching a lesson about his favorite band and how he keeps his beard so lucious\nYou accept his tips and move onto the next room\n";
		twohundred();
		break;
	case 209://Hogan
		cout << "You have entered room 209\nMr Hogan welcomes you in, he wishes that he had more for you\nUnfortunately he is very busy with other students\Proceed to another room\n";
		twohundred();
		break;
	default://outside
		cout << "no room";
		twohundred();
	}
}
void threehundred() {
	clear();
	cout << "You are currently in room " << progress[0] << "\nYou may advance to any room on this floor(318,339,319,315,313,327,328,329,201,302,320);";
	cout << "Where would you like to go:";
	cin >> progress[0];
	switch (progress[0]) {
	case 318:
		kempe();
		break;
	case 339://Empty
		cout << "You have entered the save room, would you like to save your progress Y or N";
		cin >> tosave;
		if (tosave == 'Y' || tosave == 'y') {
			save();
		}
		else {
			cout << "You shall now move to another room,\n";
			threehundred();
		}
		break;
	case 319://Walter
		cout << "Mr Walter in in the back of his room playing Clash of Clans\nHe looks very busy better not ask him for help\n";
		threehundred();
		break;
	case 315://Ward
		cout << "As you peek into room 315, you barely see the top of someones head\nUopn operning the door you see Mr Ward teching titrations\nYou didnt understand these when you took his course\nBetter leave while you can\n";
		threehundred();
		break;
	case 313://Takken
		cout << "The very front of the school, Ms Takkens room\nInside you see her playing a game of trivia with herself\nShe asks you one question, you did not get it right but decide to move on\n";
		threehundred();
		break;
	case 327: //Hannusch
		cout << "Possibly the longest teaching teacher currently at SMHS\nIn room 327 you find Mr Hannusch giving a philosophy lesson\nIts inspiring but cannot help you\nBetter keep moving\n";
		threehundred();
		break;
	case 328://Ms Hannusch
		cout << "Husband and wife are next to each other\nYou ask Ms Hannusch for help, She offers you a cup of tea but cannot give you any assistance\n";
		threehundred();
		break;
	case 329://Kim
		cout << "Walking down the hallway you hear grunting coming from one room\nUpon further nvestigation its Master Kim practing his martial arts\nHe challenges you to a duel\nIn hopes of preserving your life you decline the fight\n";
		threehundred();
		break;
	case 301://Snider
		cout << "You walk into the secret room, from the door you spot Ms Snider with her cute baby\n you spend the next few minutes playing and giving her a break from the crying baby\nAfter 5 minutes you chose to leave and try and find some help\n";
		threehundred();
		break;
	case 302://Annetta
		cout << "You open the door to 302, it is an absolute Sauna, inside you find Mr Anetta passing out and dripping sweat\nYou find him some water and offer to take him with you\nHe does'nt want to be a bother so he stays there\nBetter leave before you become another victim\n";
		threehundred();
		break;
	case 320:
		cout << "You have entered room 320\nInside you see the ghost of Ms Hillyer who no longer works at our school\nYou immedietely run out of the door\n";
		cout << "You are faced with three options, stay on the 300s, go down the stairs to the 200s or head outside to the MTO building\n";
		cout << "For 200s enter a 2, for 300s enter a 3 and for the MTO enter a 4";
		cin >> level;
		if (level == 2) {
			progress[0] = 234;
			twohundred();
		}
		else if (level == 3) {
			threehundred();
		}
		else if (level == 4) {
			progress[0] = 403;
			fourhundred();
		}
		else {
			threehundred();
		}
		break;
	default://outside
		cout << "no room";
		threehundred();
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
		else if (level == 2) {
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
	cout << "You are currently in room " << progress[0] << "\nYou may advance to any room on this floor(Coop(401), Innovation(402), Shop(400), Hallway(403))";
	cout << "\nWhere would you like to go:";
	cin >> progress[0];
	clear();
	switch (progress[0]) {
	case 403://Hallway
		cout << "You are in the hallway in the MTO building, will you remain here or proceed to the school\nEnter a 4 to stay here, a 3 to head upstairs or a 2 to go downstairs\n";
		cin >> level;
		if (level == 2) {
			progress[0] = 234;//head to 200s
			twohundred();
		}
		else if (level == 3) {//head to 300s
			progress[0] = 320;
			threehundred();
		}
		else if (level == 4) {//head to 400s
			progress[0] = 403;
			fourhundred();
		}
		else {
			fourhundred();
		}
	case 400://Shop
		cout << "Unfortunately you did not wear eye protection while entering the shop. Your game is now over.";
		gameover();
		break;
	case 401://Co-op
		cout << "In the coop room you dont see anyone. Just an empty space that looks unsued.\nProceed to a different room";
		fourhundred();
		break;
	case 402://robot
		robot();
		break;
	default://outside
		cout << "no room";
	}
}

int main() {
	string theLine;//using to get data from file
	char oldfile;
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
				if (progress[1] == 1) {//restore vector to progress status
					letters.push_back('A');
					letters.push_back('U');
					letters.push_back('O');
				}
				if (progress[2] == 1) {
					letters.push_back('G');
					letters.push_back('I');
					letters.push_back('N');
					letters.push_back('T');
				}
				if (progress[3] == 1) {
					letters.push_back('R');
					letters.push_back('D');
					letters.push_back('A');
				}
				hints = progress[4];

			}
			else {
				open = false;
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
			progress[0] = 127;
		}
	} while (open == false);
	clear();//clear out save stuff
	cout << "To win the game you must visit 3 different areas of the school and complete a task at each location\nThe game will begin shortly...\n";
	cout << "You begin in the computer lab where I assume you are playing this game.\nYou will move from room to room as well as using the stairs and portals to travel from point to point\nGOOD LUCK!\n";
	cout << "To save your progress head to room 339 at any point during the game\nPress enter to begin\n";
	_getch();//wait for enter
	clear();
	if (progress[0] == 339) {//save point
		threehundred();
	}
	else {//new game
		onehundred();
	}
	return 0;
}
