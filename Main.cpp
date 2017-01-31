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
bool InitialiseGame();
void PrintHelp();
void IsHelpNeeded();
bool CheckDifficulty();

FBullCowGame BCGame;	// an instance of  the game
int32 WORD_LENGTH = BCGame.GetHiddenWordLenght();

//the entry point of our operator 
int main() {

	bool bPlayAgain = false;
	

	do {
		PrintIntro();
		IsHelpNeeded();

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
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
	{
		// //get difficulty input from player
		//if (CheckDifficulty())
		//{
			FText Guess = GetValidGuess();
		//	// submit valid guess to the game, and receive counts
			FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

			std::cout << "Bulls = " << BullCowCount.Bulls;
			std::cout << ". Cows = " << BullCowCount.Cows << "\n\n";

		/*}	*/	
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

bool InitialiseGame()
{
	std::cout << "if  you want to begin, please enter: start "<< std::endl;
	std::cout << "if you need help, please enter: help" << std::endl;
	std::cout << std::endl;
	
	FText Choice = "";
	std::getline(std::cin, Choice);//get the input from player 
	
	if (tolower(Choice[0]) == 's')
	{
		return true;
	}
	else
	{
		return false;
	}
}

void PrintHelp()
{

		std::cout << "-Help\n-A Isogram is a word or phrase without a repeating letter.\n";
		std::cout << "-An example can be the word ISOGRAM.\n";
		std::cout << "-Your score is Bulls and Cows:\nBulls are the right letters in the right position\n";
		std::cout << "-Cows are the right letters in the wrong position\n";
		std::cout << "-Use the score to help you guessing the right word.\n\n";
		return;
}

void IsHelpNeeded()
{
	if (!InitialiseGame())
	{
		PrintHelp();
	}
	else
	{
		return;
	}

}

bool CheckDifficulty()
{
	std::cout << "please enter difficulty: 1 = easy, 2 = medium, 3 = hard.\n " << std::endl;
	FText difficulty = "";
	std::getline(std::cin, difficulty);
	
	//switch (difficulty) //TODO set difficulty
	//{
	//default:
	//	break;
	//}
	return true;
}

// hi this is test