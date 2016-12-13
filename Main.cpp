#include <iostream>
#include <string>
#include <stdio.h>
using namespace std; 

//functions prototype
void PrintIntro(int word);
string GetGuess();
void RepeatGuess(string guess);
void GuessLoop(int number);
bool AskToPlayAgain();

//the entry point of our operator 
int main() {
	constexpr int WORD_LENGTH = 9;
	int NUMBER_OF_TURNS = 5;
	bool bPlayAgain = false;
	do {
		PrintIntro(WORD_LENGTH);
		GuessLoop(NUMBER_OF_TURNS);
		//play again option
		bPlayAgain = AskToPlayAgain();
	}
	while (bPlayAgain);
	
	return 0; //exit the application
}
void PrintIntro(int word) {
	//prints on screen the intrudutcion
	cout << "Welcome to Bulls and Cows, a fun word game \n";
	cout << "Can you guess the " << word;
	cout << (" letter isogram i'm thinking of? \n");
	cout << endl;
	return;
}

string GetGuess() {
	//Asks Guess to the player
	cout << "Please enter your guess: \n\n ";
	string Guess = "";
	getline(cin, Guess);

	return Guess;
}

void RepeatGuess(string guess) {
	//Repeat guess to the player
	cout << "Your guess was: " << guess << endl << endl;
}

void GuessLoop(int number) {
	// loop for the number of turns asking for guesses

	for (int count = 1; count <=number; count++) {
		RepeatGuess(GetGuess());
		cout << endl;
	}
}

bool AskToPlayAgain() {

	cout << "Do you want to play again? (y/n) ";
	string Response = "";
	getline(cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y');
	cout << endl;
}