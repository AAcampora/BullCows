#include "FBullCowGame.h"

using FString = std::string;
using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); } // default constructor

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLenght() const{ return MyHiddenWord.length();}
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }

void FBullCowGame::Reset() {

	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	bGameIsWon = false;
	return;
}


EGuessStatus FBullCowGame::CheckGuessValidity(FString guess) const {

	if (false) //if the guess isn't an isogram
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (false) //if the guess isn't all lowercase
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (guess.length() != GetHiddenWordLenght()) //if the guess length is less than hidden word
	{
		return EGuessStatus::Wrong_Length;
	}
	else //otherwise 
	{
		return EGuessStatus::OK;
	}
	
}

//recives a VALID guess, increments turn, and returns a count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	
	MyCurrentTry++; 
	FBullCowCount BullCowCount;
	
	// loop through all letters in the hidden word
	int32 HiddenWordLenght = MyHiddenWord.length();
	for (int32 i = 0; i < HiddenWordLenght; i++) 
	{
		//loop through letters in the guess
		for (int32 j = 0; j < HiddenWordLenght; j++) 
		{
			//if they match then
			if (Guess[j] == MyHiddenWord[i]) 
			{

				// if they're in the same place 
				if (i == j)
				{
					BullCowCount.Bulls++; //increment bulls
				}				
				else 
				{
					BullCowCount.Cows++; //increment cows
				}
				
			}
		}
	}

	if (BullCowCount.Bulls == HiddenWordLenght)
	{
		bGameIsWon = true;
	}
	else
	{
		bGameIsWon = false;
	}

	return BullCowCount;
}

