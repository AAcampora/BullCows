#include "FBullCowGame.h"
#include <map>
#define TMap std::map

using FString = std::string;
using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); } // default constructor

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLenght() const{ return MyHiddenWord.length();}
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

int32 FBullCowGame::GetMaxTries() const { 
	TMap<int32, int32> WordLengthToMaxtries{ {3, 5}, {4, 5}, {5, 5}, {6, 5} };
	return WordLengthToMaxtries[MyHiddenWord.length()];
}


void FBullCowGame::Reset() {
	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	bGameIsWon = false;
	return;
}


EGuessStatus FBullCowGame::CheckGuessValidity(FString guess) const {

	if (!IsIsogram(guess)) //if the guess isn't an isogram
	{
			return EGuessStatus::Not_Isogram;
	}
	else if (!IsLowercase(guess)) //if the guess isn't all lowercase
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

bool FBullCowGame::IsIsogram(FString Word) const
{
	// treat 0 and 1 letter words as isograms
	if (Word.length() <= 1) { return true;  }

	TMap<char, bool> LetterSeen;//instance and setup of map
	for (auto Letter : Word)		//for each letter in the word
	{
		Letter = tolower(Letter); // convert to lowercase if any
		if (LetterSeen[Letter]) {	//if the letter is in the map
			return false;	//we do not have an isogram		
		} else {
			LetterSeen[Letter] = true;	//add the letter to the map as seen
		}
	}
	
	return true;
}

bool FBullCowGame::IsLowercase(FString Word) const
{
		//check if any of this are present
		for (auto Letter : Word)
		{
			if (!islower(Letter))
			{
				return false;
			} 
		}
		return true;
}

