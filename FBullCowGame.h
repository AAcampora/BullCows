#pragma once
#include <string>

using FString = std::string; 
using int32 = int;

class FBullCowGame {
public:
	FBullCowGame();//constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;
	
	void Reset();
	bool CheckGuessValidity(FString); //TODO make a more rich return value
	// provide a method for counting bulls & cows, and increasing turn #


// ^^ Please try to ignore this and focus on the interface above ^^
private:
	int32 MyCurrenTry;
	int32	MyMaxTries;

};