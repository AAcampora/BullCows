#pragma once
#include <string>

using FString = std::string; 
using int32 = int;

struct FBullCowCount {

	int32 Bulls = 0;
	int32 Cows = 0;
};
class FBullCowGame {
public:
	FBullCowGame();//constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLenght() const;
	bool IsGameWon() const;
	
	void Reset();
	bool CheckGuessValidity(FString); //TODO make a more rich return value
	// counts bulls & cows, and increases try # assuming valid guess

	FBullCowCount SubmitGuess(FString);

// ^^ Please try to ignore this and focus on the interface above ^^
private:
	int32 MyCurrentTry;
	int32	MyMaxTries;
	FString MyHiddenWord;
};