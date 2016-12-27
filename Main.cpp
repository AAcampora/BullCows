#include <iostream>
#include <string>
#include <stdio.h>
#include "FBullCowGame.h"

//functions prototype
void PrintIntro(int word);
std::string GetGuess();
void RepeatGuess(std::string guess);
void PlayGame(int number);
bool AskToPlayAgain();
int MaxTries = 0;
int CurrentTry = 0;
FBullCowGame BCGame; // an instance of  the game

//the entry point of our operator 
int main() {
	constexpr int WORD_LENGTH = 9;
	int NUMBER_OF_TURNS = 5;
	bool bPlayAgain = false;
	do {
		PrintIntro(WORD_LENGTH);
		PlayGame(NUMBER_OF_TURNS);
		//play again option
		bPlayAgain = AskToPlayAgain();
	}
	while (bPlayAgain);
	
	return 0; //exit the application
}

void PrintIntro(int word) {
	//prints on screen the intrudutcion
	std::cout << "Welcome to Bulls and Cows, a fun word game \n";
	std::cout << "Can you guess the " << word;
	std::cout << (" letter isogram i'm thinking of? \n");
	std::cout << std::endl;
	return;
}

std::string GetGuess() {
	//Asks Guess to the player

	std::string Guess = "";
	CurrentTry = BCGame.GetCurrentTry();
	std::cout << "Try: " << CurrentTry <<". Please enter your guess: \n\n ";
	std::getline(std::cin, Guess);

	return Guess;
}

void RepeatGuess(std::string guess) {
	//Repeat guess to the player
	std::cout << "Your guess was: " << guess << std::endl << std::endl;
}

void PlayGame(int number) {
	
	//BCGame.Reset();
	MaxTries = BCGame.GetMaxTries();
	std::cout << "try " << MaxTries << std::endl;
	// loop for the number of turns asking for guesses
	for (int count = 1; count <=MaxTries; count++) {
		RepeatGuess(GetGuess());
		std::cout << std::endl;
	}
}

bool AskToPlayAgain() {

	std::string Response = "";
	std::cout << "Do you want to play again? (y/n) ";
	std::getline(std::cin, Response);

	std::cout << std::endl;
	return (tolower(Response[0]) == 'y');
	
}