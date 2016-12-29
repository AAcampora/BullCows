#include <iostream>
#include <string>
#include <stdio.h>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

//functions prototype
void PrintIntro(int32 word);
FText GetGuess();
void RepeatGuess(FText guess);
void PlayGame(int32 number);
bool AskToPlayAgain();
int32 MaxTries = 0;
int32 CurrentTry = 0;
FBullCowGame BCGame; // an instance of  the game

//the entry point of our operator 
int main() {
	int32 WORD_LENGTH = BCGame.GetHiddenWordLenght();
	int32 NUMBER_OF_TURNS = 5;
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

void PrintIntro(int32 word) {
	//prints on screen the intrudutcion
	std::cout << "Welcome to Bulls and Cows, a fun word game \n";
	std::cout << "Can you guess the " << word;
	std::cout << (" letter isogram i'm thinking of? \n");
	std::cout << std::endl;
	return;
}

FText GetGuess() {
	//Asks Guess to the player

	FText Guess = "";
	CurrentTry = BCGame.GetCurrentTry();
	std::cout << "Try: " << CurrentTry <<". Please enter your guess: \n\n ";
	std::getline(std::cin, Guess);

	return Guess;
}

void RepeatGuess(FText guess) {

	//check guess validity
	EWordStatus Status = BCGame.CheckGuessValidity(guess);
	FBullCowCount BullCowCount;
	switch (Status)
	{
	
	case EWordStatus::not_Isogram:
		std::cout << "Word not an Isogram!" << std::endl;
		break;
	case EWordStatus::wrong_lenght:
		std::cout << "Please enter a " <<BCGame.GetHiddenWordLenght() << " letter word. \n";
		break;
	case EWordStatus::not_lowercase:
		std::cout << "Please write in lowercase! \n";
		break;
	default:
		//assume the guess is valid
		BullCowCount = BCGame.SubmitGuess(guess);
		break;
	}
	std::cout  <<  std::endl;
	
	//print number of bulls and cows 

	std::cout << "Bulls = " << BullCowCount.Bulls;
	std::cout << ". Cows = " << BullCowCount.Cows << std::endl;
}

void PlayGame(int32 number) {

	MaxTries = BCGame.GetMaxTries();
	std::cout << "try " << MaxTries << std::endl;
	// loop for the number of turns asking for guesses
	//TODO change from FOR to WHILE loop
	for (int32 count = 1; count <=MaxTries; count++) {
		RepeatGuess(GetGuess()); 
		std::cout << std::endl;
	}

	//TODO game summary
}

bool AskToPlayAgain() {

	FText Response = "";
	std::cout << "Do you want to play again? (y/n) ";
	std::getline(std::cin, Response);

	std::cout << std::endl;
	return (tolower(Response[0]) == 'y');
	
}