#include<iostream>
#include<string>
#define HEIGHT 9
#define WIDTH 9
using namespace std;
int lines;
int x;
bool quit = false;
char board[HEIGHT][WIDTH];
string startpositions = "012345678ACNBKQBNCBPPPPPPPPC--------D--------E--------F--------GppppppppHcnbqkbnc";
int startingboard;
int counter = 0;
bool player = false; //true means player 1, false means player 2
string userinput;
int movefromx;
char location_letter;
char selected_piece;
int turn_number = 0;
int movetox;
int movetoy;
char movetoletter;
int movefromy;
bool legalmove = false;
bool player1win = false;
bool player2win = false;
char a = '4';
int lettertonumber(int movefromy) {
	if (location_letter == 'A' || location_letter == 'a') {
		movefromy = 1;
	}
	else if (location_letter == 'B' || location_letter == 'b') {
		movefromy = 2;
	}
	else if (location_letter == 'C' || location_letter == 'c') {
		movefromy = 3;
	}
	else if (location_letter == 'D' || location_letter == 'd') {
		movefromy = 4;
	}
	else if (location_letter == 'E' || location_letter == 'e') {
		movefromy = 5;
	}
	else if (location_letter == 'F' || location_letter == 'f') {
		movefromy = 6;
	}
	else if (location_letter == 'G' || location_letter == 'g') {
		movefromy = 7;
	}
	else if (location_letter == 'H' || location_letter == 'h') {
		movefromy = 8;
	}
	else {
		cout << "PLEASE CHOSE A LETTER ON THE BOARD";
	}
	return movefromy;
}

int movetolettertonumber(int movetoy) {
	if (movetoletter == ('A') || movetoletter == ('a') ) {
		movetoy = 1;
	}
	else if (movetoletter == 'B' || movetoletter ==('b')) {
		movetoy = 2;
	}
	else if (movetoletter == 'C' ||movetoletter == ('c')) {
		movetoy = 3;
	}
	else if (movetoletter == 'D' || movetoletter==('d')) {
		movetoy = 4;
	}
	else if (movetoletter == 'E' ||movetoletter== ('e')) {
		movetoy = 5;
	}
	else if (movetoletter == 'F' || movetoletter==('f')) {
		movetoy = 6;
	}
	else if (movetoletter == 'G' || movetoletter == 'g') {
		movetoy = 7;
	}
	else if (movetoletter == 'H' || movetoletter == 'h') {
		movetoy = 8;
	}
	else {
		cout << "PLEASE CHOSE A LETTER ON THE BOARD" << endl;
		//cin >> location_letter;
	}
	return movetoy;
}
void screenjump(int lines) {
	for (x = 0; x < lines; x++) {
		cout << endl;
	}
}
void init() {
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			board[i][j] = startpositions[counter];
			counter++;
		}
	}
} //loads board for the for the first turn
void turncounter() {
	player = (turn_number % 2 == 0);
	return;
}
void printboard() {
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			cout << board[i][j] << "\t";
		}
		cout << endl;
		cout << endl;
	}
	turn_number++;
}
void endgame() {
	bool p1KingFound = false;
	bool p2KingFound = false;
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			if (board[i][j] == 'K') {	//player 1's king
				p1KingFound = true;

			}
			else if (board[i][j] == 'k') { //player 2's king
				p2KingFound = true;
			}
		}
	}
	if (!p1KingFound) {
		player2win = true;
	}
	if (!p2KingFound) {
		player1win = true;
	}
}

bool canMove = true;
void collisionCheck() {
	if (movetoy > movefromy && movefromx == movetox) { //checks if collision going down
		for (int i = movefromy + 1; i < movetoy; i++) {
			if (board[i][movefromx] != '-') {
				canMove = false;
			}
		}
	}
	else if (movetoy < movefromy && movefromx == movetox) { //checks if collision going up
		//cout << "TEST LINE 135" << endl;
		for (int i = movefromy - 1; i > movetoy; i--) {
			if (board[i][movefromx] != '-') {
				//cout << "TEST LINE 138" << endl;
				canMove = false;
			}
		}
	}
	else if (movetox > movefromx && movefromy == movetoy) {  //checks if collision going to the right
		for (int i = movefromx + 1; i < movetox; i++) {
			if (board[movefromx][i] != '-') {
				canMove = false;
			}
		}
	}
	else if (movetox < movefromx && movefromy == movetoy) {  //checks if collision going to the left
		for (int i = movefromx - 1; i < movetox; i--) {
			if (board[movefromx][i] != '-') {
				canMove = false;
			}
		}
	}
	else if (movetox > movefromx && movetoy > movefromy) {  //checks if collision going down right
		int j = movefromx;
		for (int i = movefromy + 1; i < movetoy; i++) {
			
				if (board[i][j] != '-') {
					canMove = false;
				
			}
				j++;
		}
	}
	else if (movetox > movefromx && movetoy < movefromy) {  //checks if collision going up right
		int j = movefromx;
		for (int i = movefromy - 1; i > movetoy; i--) {
				if (board[i][j] != '-') {
					canMove = false;
				}
				j--;
		}
	}
	else if (movetox < movefromx && movetoy > movefromy) { //checks if collision going down left
		int j = movefromx;
		for (int i = movefromy + 1; i > movetoy; i++) {
			
				if (board[i][j] != '-') {
					canMove = false;
				}
				j++;
			}	
	}
	else if (movetox < movefromx && movetoy < movefromy) { //checks if collision going up left
		int j = movefromx;
			for (int i = movefromy - 1; i < movetoy; i--) {
				if (board[i][j] != '-') {
					canMove = false;
				}
				j++;
			}
	}
	else {
		canMove = true;
	}
}

void kingcontrol() {
	collisionCheck();
	if (canMove &&
		((movetoy == movefromy + 1 && movetox == movefromx) ||
		(movetoy == movefromy - 1 && movetox == movefromx) ||
		(movetoy == movefromy && movetox == movefromx + 1) ||
		(movetoy == movefromy && movetox == movefromx - 1) ||
		(movetoy == movefromy + 1 && movetox == movefromx + 1) ||
		(movetoy == movefromy + 1 && movetox == movefromx - 1) ||
		(movetoy == movefromy - 1 && movetox == movefromx + 1) ||
		(movetoy == movefromy - 1 && movetox == movefromx - 1))){
		legalmove = true;
		return;
	}
	else {
		legalmove = false;
		return;
	}
}
void knightcontrol() {
	if (true) {
		/*cout << endl << endl;
		cout << movetoy << endl;
		cout << movefromy << endl;
		cout << movetox << endl;
		*/
		//cout << movefromx << endl;
		cout << endl << endl;
		if ((movetoy == movefromy + 2 && movetox == movefromx + 1) ||
			(movetoy == movefromy + 2 && movetox == movefromx - 1) ||
			(movetoy == movefromy - 2 && movetox == movefromx + 1) ||
			(movetoy == movefromy - 2 && movetox == movefromx - 1) ||
			(movetoy == movefromy + 1 && movetox == movefromx + 2) ||
			(movetoy == movefromy + 1 && movetox == movefromx - 2) ||
			(movetoy == movefromy - 1 && movetox == movefromx + 2) ||
			(movetoy == movefromy - 1 && movetox == movefromx - 2)) {
			legalmove = true;
			return;
		}
		else {
			legalmove = false;
			return;
		}
	}
}
void queencontrol() {
	collisionCheck ();
	if (canMove && 
		((movetoy == movefromy + 1 && movetox == movefromx + 1) ||
		(movetoy == movefromy + 2 && movetox == movefromx + 2) ||
		(movetoy == movefromy + 3 && movetox == movefromx + 3) ||
		(movetoy == movefromy + 4 && movetox == movefromx + 4) ||
		(movetoy == movefromy + 5 && movetox == movefromx + 5) ||
		(movetoy == movefromy + 6 && movetox == movefromx + 6) ||
		(movetoy == movefromy + 1 && movetox == movefromx - 1) ||
		(movetoy == movefromy + 2 && movetox == movefromx - 2) ||
		(movetoy == movefromy + 3 && movetox == movefromx - 3) ||
		(movetoy == movefromy + 4 && movetox == movefromx - 4) ||
		(movetoy == movefromy + 5 && movetox == movefromx - 5) ||
		(movetoy == movefromy + 6 && movetox == movefromx - 6) ||
		(movetoy == movefromy - 1 && movetox == movefromx + 1) ||
		(movetoy == movefromy - 2 && movetox == movefromx + 2) ||
		(movetoy == movefromy - 3 && movetox == movefromx + 3) ||
		(movetoy == movefromy - 4 && movetox == movefromx + 4) ||
		(movetoy == movefromy - 5 && movetox == movefromx + 5) ||
		(movetoy == movefromy - 6 && movetox == movefromx + 6) ||
		(movetoy == movefromy - 1 && movetox == movefromx - 1) ||
		(movetoy == movefromy - 2 && movetox == movefromx - 2) ||
		(movetoy == movefromy - 3 && movetox == movefromx - 3) ||
		(movetoy == movefromy - 4 && movetox == movefromx - 4) ||
		(movetoy == movefromy - 5 && movetox == movefromx - 5) ||
		(movetoy == movefromy - 6 && movetox == movefromx - 6) ||
		(movetoy == movefromy + 1 && movetox == movefromx) ||
		(movetoy == movefromy + 2 && movetox == movefromx) ||
		(movetoy == movefromy + 3 && movetox == movefromx) ||
		(movetoy == movefromy + 4 && movetox == movefromx) ||
		(movetoy == movefromy + 5 && movetox == movefromx) ||
		(movetoy == movefromy + 6 && movetox == movefromx) ||
		(movetox == movefromx + 1 && movetoy == movefromy) ||
		(movetox == movefromx + 2 && movetoy == movefromy) ||
		(movetox == movefromx + 3 && movetoy == movefromy) ||
		(movetox == movefromx + 4 && movetoy == movefromy) ||
		(movetox == movefromx + 5 && movetoy == movefromy) ||
		(movetox == movefromx + 6 && movetoy == movefromy) ||
		(movetoy == movefromy - 1 && movetox == movefromx) ||
		(movetoy == movefromy - 2 && movetox == movefromx) ||
		(movetoy == movefromy - 3 && movetox == movefromx) ||
		(movetoy == movefromy - 4 && movetox == movefromx) ||
		(movetoy == movefromy - 5 && movetox == movefromx) ||
		(movetoy == movefromy - 6 && movetox == movefromx) ||
		(movetox == movefromx - 1 && movetoy == movefromy) ||
		(movetox == movefromx - 2 && movetoy == movefromy) ||
		(movetox == movefromx - 3 && movetoy == movefromy) ||
		(movetox == movefromx - 4 && movetoy == movefromy) ||
		(movetox == movefromx - 5 && movetoy == movefromy) ||
		(movetox == movefromx - 6 && movetoy == movefromy) ||
		(movetox == movefromx - 7 && movetoy == movefromy) ||
		(movetox == movefromx - 8 && movetoy == movefromy) ||
		(movetox == movefromx + 7 && movetoy == movefromy) ||
		(movetox == movefromx + 8 && movetoy == movefromy) ||
		(movetoy == movefromy - 7 && movetox == movefromx) ||
		(movetoy == movefromy - 8 && movetox == movefromx) ||
		(movetoy == movefromy + 7 && movetox == movefromx) ||
		(movetoy == movefromy + 8 && movetox == movefromx) ||
		(movetoy == movefromy - 7 && movetox == movefromx - 7) ||
		(movetoy == movefromy - 8 && movetox == movefromx - 8) ||
		(movetoy == movefromy - 6 && movetox == movefromx - 6) ||
		(movetoy == movefromy + 7 && movetox == movefromx + 7) ||
		(movetoy == movefromy + 8 && movetox == movefromx + 8))) {
		legalmove = true;
		return;
	}
	else {
		legalmove = false;
		return;
	}
}
void bishopcontrol() {
	//cout << "TEST LINE 100" << endl;
	collisionCheck();
	if (true) {
		if (canMove &&
			((movetoy == movefromy + 1 && movetox == movefromx + 1) ||
			(movetoy == movefromy + 2 && movetox == movefromx + 2) ||
			(movetoy == movefromy + 3 && movetox == movefromx + 3) ||
			(movetoy == movefromy + 4 && movetox == movefromx + 4) ||
			(movetoy == movefromy + 5 && movetox == movefromx + 5) ||
			(movetoy == movefromy + 6 && movetox == movefromx + 6) ||
			(movetoy == movefromy + 1 && movetox == movefromx - 1) ||
			(movetoy == movefromy + 2 && movetox == movefromx - 2) ||
			(movetoy == movefromy + 3 && movetox == movefromx - 3) ||
			(movetoy == movefromy + 4 && movetox == movefromx - 4) ||
			(movetoy == movefromy + 5 && movetox == movefromx - 5) ||
			(movetoy == movefromy + 6 && movetox == movefromx - 6) ||
			(movetoy == movefromy - 1 && movetox == movefromx + 1) ||
			(movetoy == movefromy - 2 && movetox == movefromx + 2) ||
			(movetoy == movefromy - 3 && movetox == movefromx + 3) ||
			(movetoy == movefromy - 4 && movetox == movefromx + 4) ||
			(movetoy == movefromy - 5 && movetox == movefromx + 5) ||
			(movetoy == movefromy - 6 && movetox == movefromx + 6) ||
			(movetoy == movefromy - 1 && movetox == movefromx - 1) ||
			(movetoy == movefromy - 2 && movetox == movefromx - 2) ||
			(movetoy == movefromy - 3 && movetox == movefromx - 3) ||
			(movetoy == movefromy - 4 && movetox == movefromx - 4) ||
			(movetoy == movefromy - 5 && movetox == movefromx - 5) ||
			(movetoy == movefromy - 6 && movetox == movefromx - 6) ||
			(movetoy == movefromy - 7 && movetox == movefromx - 7) ||
			(movetoy == movefromy - 8 && movetox == movefromx - 8) ||
			(movetoy == movefromy - 6 && movetox == movefromx - 6) ||
			(movetoy == movefromy + 7 && movetox == movefromx + 7) ||
			(movetoy == movefromy + 8 && movetox == movefromx + 8))){
			legalmove = true;
			return;
		}
		else {
			legalmove = false;
			return;
		}
	}
}
void castlecontrol() {
	collisionCheck();
	if (true) {
		cout << "TESTLINE 341";
		if (canMove &&
			((movetoy == movefromy + 1 && movetox == movefromx) ||
			(movetoy == movefromy + 2 && movetox == movefromx) ||
			(movetoy == movefromy + 3 && movetox == movefromx) ||
			(movetoy == movefromy + 4 && movetox == movefromx) ||
			(movetoy == movefromy + 5 && movetox == movefromx) ||
			(movetoy == movefromy + 6 && movetox == movefromx) ||
			(movetox == movefromx + 1 && movetoy == movefromy) ||
			(movetox == movefromx + 2 && movetoy == movefromy) ||
			(movetox == movefromx + 3 && movetoy == movefromy) ||
			(movetox == movefromx + 4 && movetoy == movefromy) ||
			(movetox == movefromx + 5 && movetoy == movefromy) ||
			(movetox == movefromx + 6 && movetoy == movefromy) ||
			(movetoy == movefromy - 1 && movetox == movefromx) ||
			(movetoy == movefromy - 2 && movetox == movefromx) ||
			(movetoy == movefromy - 3 && movetox == movefromx) ||
			(movetoy == movefromy - 4 && movetox == movefromx) ||
			(movetoy == movefromy - 5 && movetox == movefromx) ||
			(movetoy == movefromy - 6 && movetox == movefromx) ||
			(movetox == movefromx - 1 && movetoy == movefromy) ||
			(movetox == movefromx - 2 && movetoy == movefromy) ||
			(movetox == movefromx - 3 && movetoy == movefromy) ||
			(movetox == movefromx - 4 && movetoy == movefromy) ||
			(movetox == movefromx - 5 && movetoy == movefromy) ||
			(movetox == movefromx - 6 && movetoy == movefromy) ||
			(movetox == movefromx - 7 && movetoy == movefromy) ||
			(movetox == movefromx - 8 && movetoy == movefromy) ||
			(movetox == movefromx + 7 && movetoy == movefromy) ||
			(movetox == movefromx + 8 && movetoy == movefromy) ||
			(movetoy == movefromy - 7 && movetox == movefromx) ||
			(movetoy == movefromy - 8 && movetox == movefromx) ||
			(movetoy == movefromy + 7 && movetox == movefromx) ||
			(movetoy == movefromy + 8 && movetox == movefromx))) {
			legalmove = true;
			return;
		}

	}
	else {
		legalmove = false;
		return;
	}

	if (player == false) {

	}
}
void pawncontrol() {
	//cout << "TEST LINE 100" << endl;
	collisionCheck();
	if (player == true) {
		if (canMove &&
			((movetoy == movefromy + 1 && movetox == movefromx) ||
			(movetoy == movefromy + 1 && movetox == movefromx - 1) ||
			(movetoy == movefromy + 2 && movefromy == 2) ||
			(movetoy == movefromy + 1 && movetox == movefromx + 1))) {
			legalmove = true;
			return;
		}

		else {
			legalmove = false;
			return;
		}
	}
	if (player == false) {
		//cout << "TEST LINE 112";
		if (canMove &&
			((movetoy == movefromy - 1 && movetox == movefromx) ||
			(movetoy == movefromy - 1 && movetox == movefromx + 1) ||
			(movetoy == movefromy - 2 && movefromy == 7) ||
			(movetoy == movefromy - 1 && movetox == movefromx - 1))) {
			legalmove = true;
			return;
		}
		else {
			legalmove = false;
			return;
		}
	}
}

int main() {
	init();
	printboard();
	cout << " \nWELCOME TO CHESS. THIS GAME WILL BE SHOWING YOU A BOARD WITH SEVERAL DIFFERENT LETTERS ON IT" << endl;
	cout << "FOR YOUR REFERNCE,\n K = KING,\n Q = QUEEN,\n B = BISHOP,\n N = KNIGHT,\n C = ROOK,\n AND P = PAWN" << endl;
	cout << "PLAYER ONE IS AT THE TOP, WHILE PLAYER TWO IS AT THE BOTTOM OF THE SCREEN" << endl;
	cout << "PLAYER TWO WILL GO FIRST." << endl;
	while (!quit) {
		cout << "PLEASE CHOOSE THE LETTER NUMBER COMBINATION OF THE PIECE YOU WOULD LIKE TO MOVE:\t";
		cin >> userinput;
		movefromx = stoi((userinput.substr (1,1)));
		location_letter = userinput[0];
		movefromy = lettertonumber(location_letter);
		//cout << board[movefromy][movefromx] << endl;
		selected_piece = board[movefromy][movefromx];
		//cout << selected_piece << endl;
		while (selected_piece != '-') {
			if (player == true) {
				if (selected_piece == 'K') {			//code for King on Player 1
					//cout << "PLEASE ENTER THE NUMBER OF WHERE YOU WOULD LIKE TO MOVE TO:\t";
					//cin >> movetox;
					//cout << "PLEASE ENTER THE LETTER OF WHERE YOU WOULD LIKE TO MOVE TO:\t";
					//cin >> movetoletter;
					cout << "PLEASE ENTER THE LETTER NUMBER OF WHERE YOU WOULD LIKE TO MOVE:\t";
					cin >> userinput;
					movetox = stoi((userinput.substr(1, 1)));
					movetoletter = userinput[0];
					movetoy = movetolettertonumber(movetoletter);
					kingcontrol();
					if (legalmove == true) {
						board[movefromy][movefromx] = '-';
						board[movetoy][movetox] = 'K';
						screenjump(25);
						printboard();
						//cout << turn_number << endl;
						turncounter();
						endgame();
					}
					if (legalmove = false) {
						cout << "PLEASE ENTER A LEGAL MOVE." << endl;
						selected_piece = '-';
					}
				}
				else if (selected_piece == 'Q') {			//code for Queen on Player 1
					//cout << "PLEASE ENTER THE NUMBER OF WHERE YOU WOULD LIKE TO MOVE TO:\t";
					//cin >> movetox;
					//cout << "PLEASE ENTER THE LETTER OF WHERE YOU WOULD LIKE TO MOVE TO:\t";
					//cin >> movetoletter;
					cout << "PLEASE ENTER THE LETTER NUMBER OF WHERE YOU WOULD LIKE TO MOVE:\t";
					cin >> userinput;
					movetox = stoi((userinput.substr(1, 1)));
					movetoletter = userinput[0];
					movetoy = movetolettertonumber(movetoletter);
					//cout << board[movetoy][movetox];
					queencontrol();
					if (legalmove == true) {
						board[movefromy][movefromx] = '-';
						board[movetoy][movetox] = 'Q';
						screenjump(25);
						printboard();
						//cout << turn_number << endl;
						turncounter();
						endgame();
					}
					else {
						cout << "PLEASE ENTER A LEGAL MOVE." << endl;
						selected_piece = '-';
					}
				}
				else if (selected_piece == 'B') {			//code for Bishop on player 1
					//cout << "PLEASE ENTER THE NUMBER OF WHERE YOU WOULD LIKE TO MOVE TO:\t";
					//cin >> movetox;
					//cout << "PLEASE ENTER THE LETTER OF WHERE YOU WOULD LIKE TO MOVE TO:\t";
					//cin >> movetoletter;
					cout << "PLEASE ENTER THE LETTER NUMBER OF WHERE YOU WOULD LIKE TO MOVE:\t";
					cin >> userinput;
					movetox = stoi((userinput.substr(1, 1)));
					movetoletter = userinput[0];
					movetoy = movetolettertonumber(movetoletter);
					//cout << board[movetoy][movetox];
					bishopcontrol();
					if (legalmove == true) {
						board[movefromy][movefromx] = '-';
						board[movetoy][movetox] = 'B';
						screenjump(25);
						printboard();
						//cout << turn_number << endl;
						turncounter();
						endgame();
					}
					else {
						cout << "PLEASE ENTER A LEGAL MOVE." << endl;
						selected_piece = '-';
					}
				}
				else if (selected_piece == 'N') {			//code for knight on player 1
					//cout << "PLEASE ENTER THE NUMBER OF WHERE YOU WOULD LIKE TO MOVE TO:\t";
					//cin >> movetox;
					//cout << "PLEASE ENTER THE LETTER OF WHERE YOU WOULD LIKE TO MOVE TO:\t";
					//cin >> movetoletter;
					cout << "PLEASE ENTER THE LETTER NUMBER OF WHERE YOU WOULD LIKE TO MOVE:\t";
					cin >> userinput;
					movetox = stoi((userinput.substr(1, 1)));
					movetoletter = userinput[0];
					movetoy = movetolettertonumber(movetoletter);
					//cout << board[movetoy][movetox];
					knightcontrol();
					if (legalmove == true) {
						board[movefromy][movefromx] = '-';
						board[movetoy][movetox] = 'N';
						screenjump(25);
						printboard();
						//cout << turn_number << endl;
						turncounter();
						endgame();
					}
					if (legalmove == false) {
						cout << "PLEASE ENTER A LEGAL MOVE." << endl;
						selected_piece = '-';
					}
				}
				else if (selected_piece == 'C') {			//code for castle on player 1
					//cout << "PLEASE ENTER THE NUMBER OF WHERE YOU WOULD LIKE TO MOVE TO:\t";
					//cin >> movetox;
					//cout << "PLEASE ENTER THE LETTER OF WHERE YOU WOULD LIKE TO MOVE TO:\t";
					//cin >> movetoletter;
					cout << "PLEASE ENTER THE LETTER NUMBER OF WHERE YOU WOULD LIKE TO MOVE:\t";
					cin >> userinput;
					movetox = stoi((userinput.substr(1, 1)));
					movetoletter = userinput[0];
					movetoy = movetolettertonumber(movetoletter);
					//cout << board[movetoy][movetox];
					castlecontrol();
					if (legalmove == true) {
						board[movefromy][movefromx] = '-';
						board[movetoy][movetox] = 'C';
						screenjump(25);
						printboard();
						//cout << turn_number << endl;
						turncounter();
						endgame();
						//cout << player << endl;
					}
					if (legalmove == false) {
						cout << "PLEASE ENTER A LEGAL MOVE.\n";
						selected_piece = '-';
					}
				}
				else if (selected_piece == 'P') {			//code for pawn on player 1
					//cout << "PLEASE ENTER THE NUMBER OF WHERE YOU WOULD LIKE TO MOVE TO:\t";
					//cin >> movetox;
					//cout << "PLEASE ENTER THE LETTER OF WHERE YOU WOULD LIKE TO MOVE TO:\t";
					//cin >> movetoletter;
					cout << "PLEASE ENTER THE LETTER NUMBER OF WHERE YOU WOULD LIKE TO MOVE:\t";
					cin >> userinput;
					movetox = stoi((userinput.substr(1, 1)));
					movetoletter = userinput[0];
					movetoy = movetolettertonumber(movetoletter);
					//cout << board[movetoy][movetox];
					pawncontrol();
					cout << legalmove;
					if (legalmove == true) {
						board[movefromy][movefromx] = '-';
						board[movetoy][movetox] = 'P';
						screenjump(25);
						printboard();
						//cout << turn_number << endl;
						turncounter();
						endgame();
						// << player << endl;
					}
					if (legalmove == false) {
						cout << "PLEASE ENTER A LEGAL MOVE.\n";
						selected_piece = '-';
					}
				}
				else if (selected_piece == 'q' || selected_piece == 'k' || selected_piece == 'b' || selected_piece == 'n' || selected_piece == 'c' || selected_piece == 'p') {
					cout << "PLEASE CHOOSE A PIECE ON YOUR SIDE.\n";
					selected_piece = '-';
				}
				else {
					selected_piece = '-';
				}
			}

			if (player == false) {
				//cout << "TEST LINE 206" << endl;
				if (selected_piece == 'k') {			//code for King on player 2
					//cout << "PLEASE ENTER THE NUMBER OF WHERE YOU WOULD LIKE TO MOVE TO:\t";
					//cin >> movetox;
					//cout << "PLEASE ENTER THE LETTER OF WHERE YOU WOULD LIKE TO MOVE TO:\t";
					//cin >> movetoletter;
					cout << "PLEASE ENTER THE LETTER NUMBER OF WHERE YOU WOULD LIKE TO MOVE:\t";
					cin >> userinput;
					movetox = stoi((userinput.substr(1, 1)));
					movetoletter = userinput[0];
					movetoy = movetolettertonumber(movetoletter);
					movetoy = movetolettertonumber(movetoletter);
					//cout << board[movetoy][movetox];
					kingcontrol();
					if (legalmove == true) {
						board[movefromy][movefromx] = '-';
						board[movetoy][movetox] = 'k';
						screenjump(25);
						printboard();
						//cout << turn_number << endl;
						turncounter();
						endgame();
					}
					if (legalmove == false) {
						cout << "PLEASE ENTER A LEGAL MOVE." << endl;
						selected_piece = '-';
					}
				}
				else if (selected_piece == 'q') {			//code for Queen on player 2

					//cout << "PLEASE ENTER THE NUMBER OF WHERE YOU WOULD LIKE TO MOVE TO:\t";
					//cin >> movetox;
					//cout << "PLEASE ENTER THE LETTER OF WHERE YOU WOULD LIKE TO MOVE TO:\t";
					//cin >> movetoletter;
					cout << "PLEASE ENTER THE LETTER NUMBER OF WHERE YOU WOULD LIKE TO MOVE:\t";
					cin >> userinput;
					movetox = stoi((userinput.substr(1, 1)));
					movetoletter = userinput[0];
					movetoy = movetolettertonumber(movetoletter);
					movetoy = movetolettertonumber(movetoletter);
					//cout << board[movetoy][movetox];
					queencontrol();
					if (legalmove == true) {
						board[movefromy][movefromx] = '-';
						board[movetoy][movetox] = 'q';
						canMove = true;
						screenjump(25);
						printboard();
						//cout << turn_number << endl;
						turncounter();
						endgame();
					}
					else {
						cout << "PLEASE ENTER A LEGAL MOVE." << endl;
						selected_piece = '-';
					}
				}
				else if (selected_piece == 'b') {			// code for Bishop on player 2
					//cout << "PLEASE ENTER THE NUMBER OF WHERE YOU WOULD LIKE TO MOVE TO:\t";
					//cin >> movetox;
					//cout << "PLEASE ENTER THE LETTER OF WHERE YOU WOULD LIKE TO MOVE TO:\t";
					//cin >> movetoletter;
					cout << "PLEASE ENTER THE LETTER NUMBER OF WHERE YOU WOULD LIKE TO MOVE:\t";
					cin >> userinput;
					movetox = stoi((userinput.substr(1, 1)));
					movetoletter = userinput[0];
					movetoy = movetolettertonumber(movetoletter);
					movetoy = movetolettertonumber(movetoletter);
					//cout << board[movetoy][movetox];
					bishopcontrol();
					if (legalmove == true) {
						board[movefromy][movefromx] = '-';
						board[movetoy][movetox] = 'b';
						screenjump(25);
						printboard();
						//cout << turn_number << endl;
						turncounter();
						endgame();
					}
					if (legalmove == false) {
						cout << "PLEASE ENTER A LEGAL MOVE.\n";
						selected_piece = '-';
					}
				}
				else if (selected_piece == 'n') {			// code for knight on player 2
					//cout << "PLEASE ENTER THE NUMBER OF WHERE YOU WOULD LIKE TO MOVE TO:\t";
					//cin >> movetox;
					//cout << "PLEASE ENTER THE LETTER OF WHERE YOU WOULD LIKE TO MOVE TO:\t";
					//cin >> movetoletter;
					cout << "PLEASE ENTER THE LETTER NUMBER OF WHERE YOU WOULD LIKE TO MOVE:\t";
					cin >> userinput;
					movetox = stoi((userinput.substr(1, 1)));
					movetoletter = userinput[0];
					movetoy = movetolettertonumber(movetoletter);
					movetoy = movetolettertonumber(movetoletter);
					//cout << board[movetoy][movetox];
					knightcontrol();
					if (legalmove == true) {
						board[movefromy][movefromx] = '-';
						board[movetoy][movetox] = 'n';
						screenjump(25);
						printboard();
						//cout << turn_number << endl;
						turncounter();
						endgame();
					}
					if (legalmove == false) {
						cout << "PLEASE ENTER A LEGAL MOVE." << endl;
						selected_piece = '-';
					}
				}
				else if (selected_piece == 'c') {			// code for castle on player 2
					//cout << "PLEASE ENTER THE NUMBER OF WHERE YOU WOULD LIKE TO MOVE TO:\t";
					//cin >> movetox;
					//cout << "PLEASE ENTER THE LETTER OF WHERE YOU WOULD LIKE TO MOVE TO:\t";
					//cin >> movetoletter;
					cout << "PLEASE ENTER THE LETTER NUMBER OF WHERE YOU WOULD LIKE TO MOVE:\t";
					cin >> userinput;
					movetox = stoi((userinput.substr(1, 1)));
					movetoletter = userinput[0];
					movetoy = movetolettertonumber(movetoletter);
					movetoy = movetolettertonumber(movetoletter);
					//cout << board[movetoy][movetox];
					castlecontrol();
					if (legalmove == true) {
						board[movefromy][movefromx] = '-';
						board[movetoy][movetox] = 'c';
						screenjump(25);
						printboard();
						//cout << turn_number << endl;
						turncounter();
						endgame();
						//cout << player << endl;
					}
					if (legalmove == false) {
						cout << "PLEASE ENTER A LEGAL MOVE.\n";
						selected_piece = '-';
					}
				}
				else if (selected_piece == 'p') {      //code for pawn on player 2
						//cout << "TEST LINE 247";
					//cout << "PLEASE ENTER THE NUMBER OF WHERE YOU WOULD LIKE TO MOVE TO:\t";
					//cin >> movetox;
					//cout << "PLEASE ENTER THE LETTER OF WHERE YOU WOULD LIKE TO MOVE TO:\t";
					//cin >> movetoletter;
					cout << "PLEASE ENTER THE LETTER NUMBER OF WHERE YOU WOULD LIKE TO MOVE:\t";
					cin >> userinput;
					movetox = stoi((userinput.substr(1, 1)));
					movetoletter = userinput[0];
					movetoy = movetolettertonumber(movetoletter);
					movetoy = movetolettertonumber(movetoletter);
					//cout << movetoy << endl;
					//cout << board[movetoy][movetox] << endl;
					pawncontrol();
					//cout << legalmove << endl;
					if (legalmove == true) {
						board[movefromy][movefromx] = '-';
						board[movetoy][movetox] = 'p';
						screenjump(25);
						printboard();
						//cout << turn_number << endl;
						turncounter();
						endgame();
						//cout << player << endl;
					}
					if (legalmove == false) {
						cout << "PLEASE ENTER A LEGAL MOVE.\n";
						selected_piece = '-';
					}
				}
				else if (selected_piece == 'Q' || selected_piece == 'K' || selected_piece == 'B' || selected_piece == 'N' || selected_piece == 'C' || selected_piece == 'P') {
					cout << "PLEASE CHOOSE A PIECE ON YOUR SIDE.\n";
					selected_piece = '-';
				}
				else {
					selected_piece = '-';
				}
			}
			
		}

		cout << "PLEASE CHOOSE A REAL PIECE.\n";
		if (player1win == true) {
			cout << "CONGRADULATIONS PLAYER 1, YOU HAVE WON" << endl;
			cout << "wanna play again Y/N" << endl;
			cin >> userinput;
			if (userinput == "N" || userinput == "n") {
				quit = true;
			}
			else if (userinput == "Y" || userinput == "y") {
				counter = 0;
				init();
				screenjump(25);
				printboard();
				cout << " \nWELCOME TO CHESS. THIS GAME WILL BE SHOWING YOU A BOARD WITH SEVERAL DIFFERENT LETTERS ON IT" << endl;
				cout << "FOR YOUR REFERNCE,\n K = KING,\n Q = QUEEN,\n B = BISHOP,\n N = KNIGHT,\n C = CASTLE,\n AND P = PAWN" << endl;
				cout << "PLAYER ONE IS AT THE TOP, WHILE PLAYER TWO IS AT THE BOTTOM OF THE SCREEN" << endl;
			}
		}
		if (player2win == true) {
			cout << "CONGRADUALTIONS PLAYER 2, YOU HAVE WON" << endl;
			cout << "wanna play again Y/N" << endl;
			cin >> userinput;
			if (userinput == "N" || userinput == "n") {
				quit = true;
			}
			else if (userinput == "Y" || userinput == "y") {
				counter = 0;
				init();
				screenjump(25);
				printboard();
				cout << " \nWELCOME TO CHESS. THIS GAME WILL BE SHOWING YOU A BOARD WITH SEVERAL DIFFERENT LETTERS ON IT" << endl;
				cout << "FOR YOUR REFERNCE,\n K = KING,\n Q = QUEEN,\n B = BISHOP,\n N = KNIGHT,\n C = CASTLE,\n AND P = PAWN" << endl;
				cout << "PLAYER ONE IS AT THE TOP, WHILE PLAYER TWO IS AT THE BOTTOM OF THE SCREEN" << endl;
			}
		}

	}


}