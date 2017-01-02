/* This is console executable, that makes use of the BullCow class.
This acts as the view in MVC pattern, and is responsible for all
user interatcion. For game logic see the FBullCow class.
*/
#pragma once

#include <iostream>
#include <string>
#include <stdio.h>
#include "FBullCowGame.h"

//To make syntax Unreal friendly
using FText = std::string;
using int32 = int;

//global variables
int32 MaxTries = 0;
int32 CurrentTry = 0;

//functions prototype as outside a class
void PrintIntro();
FText GetValidGuess();
void PlayGame();
bool AskToPlayAgain();
void PrintGameSummary();



FBullCowGame BCGame;	// an instance of  the game
int32 WORD_LENGTH = BCGame.GetHiddenWordLenght();

//the entry point of our operator 
int main() {

	//TODO initialise game or help
		//TODO ask the lenght of the hidden word 
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
	std::cout << "\n\nWelcome to Bulls and Cows, a fun word game \n";
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << (" letter isogram i'm thinking of? \n");
	//TODO tell player about /help 

	std::cout << std::endl;
	std::cout << "          }   {         ___ " << std::endl;
	std::cout << "          (o o)        (o o) " << std::endl;
	std::cout << "   /-------\\ /          \\ /-------\\ " << std::endl;
	std::cout << "  / | BULL |O            O| COW  | \\ " << std::endl;
	std::cout << " *  |-,--- |              |------|  * " << std::endl;
	std::cout << "    ^      ^              ^      ^ " << std::endl;
	std::cout << std::endl;
	return;
}

void PlayGame() // plays a single game to compleation
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
	PrintGameSummary();
	return;
}

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

void PrintGameSummary() {

	//if game goes out of max tries
	if (!BCGame.IsGameWon())
	{
		std::cout << "Better luck next time... \n\n"; //game is lost 
	}
	else
	{
		std::cout << "Well done, you won!!! \n\n"; // game is won
	}
}
