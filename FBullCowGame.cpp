#include "FBullCowGame.h"

using FString = std::string;
using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }


bool FBullCowGame::IsGameWon() const{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString) {
	return false;
}

//recives a VALID guess, increments turn, and returns a count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	//increment the turn number
	MyCurrentTry++;
	//setup a return value 
	FBullCowCount BullCowCount;
	// loop throught all letters in the guess
	int32 HiddenWordLenght = MyHiddenWord.length();
	for (int32 i = 0; i < HiddenWordLenght; i++) 
	{
		//compare letters againg the hidden word 
		for (int32 j = 0; j < HiddenWordLenght; j++) 
		{
			//if they match then
			if (Guess[j] == MyHiddenWord[i]) 
			{

				if (i == j)
				{
					// if they're in the same place 
					BullCowCount.Bulls++; //increment bulls
				}				
				else 
				{
					BullCowCount.Cows++; //increment cows

				}
				
			}
		}
	}
	return BullCowCount;
}

void FBullCowGame::Reset() {
	
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "ant";
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	return;
}
