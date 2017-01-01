#include <iostream>
#include <string>
#include <stdio.h>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

//global variables
int32 MaxTries = 0;
int32 CurrentTry = 0;

//functions prototype
void PrintIntro();
FText GetGuess();
FText GetValidGuess();
void PlayGame();
bool AskToPlayAgain();

// an instance of  the game
FBullCowGame BCGame; 
int32 WORD_LENGTH = BCGame.GetHiddenWordLenght();

//the entry point of our operator 
int main() {
	bool bPlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		//play again option
		bPlayAgain = AskToPlayAgain();
	}
	while (bPlayAgain);
	
	return 0; //exit the application
}

void PrintIntro() {
	//prints on screen the intrudutcion
	std::cout << "Welcome to Bulls and Cows, a fun word game \n";
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << (" letter isogram i'm thinking of? \n");
	std::cout << std::endl;
	return;
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	// loop asking for guesses while the game
	// is NOT won and there are still tries remaining
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries) {
		FText Guess = GetValidGuess();

		// submit valid guess to the game, and receive counts
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << "\n\n";
	}
}

// loop continually until the user gives a valid guess
FText GetValidGuess()
{
	FText Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do {
		// get a guess from the player
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << CurrentTry << " of " << BCGame.GetMaxTries();
		std::cout << ". Enter your guess: ";
		std::getline(std::cin, Guess);

		// check status and give feedback
		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status) {
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << WORD_LENGTH << " letter word.\n\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word witout repeating letters.\n\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter all lowercase letters.\n\n";
			break;
		default:
			// assume the guess is valid
			break;
		}
	} while (Status != EGuessStatus::OK); // keep looping until we get no errors
	return Guess;
}


bool AskToPlayAgain() {

	FText Response = "";
	std::cout << "Do you want to play again? (y/n) ";
	std::getline(std::cin, Response);

	std::cout << std::endl;
	return (tolower(Response[0]) == 'y');

}

