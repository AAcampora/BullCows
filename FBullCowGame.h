/*
The game logic (no view code or director user interatcion)
The game is a simple guess the word game based on Mastermind
*/
#pragma once

#include <string>

//To make syntax Unreal friendly
using FString = std::string; 
using int32 = int;

struct FBullCowCount
{

	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};


class FBullCowGame {
public:
	FBullCowGame();//constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLenght() const;
	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FString guess) const;
	
	void Reset();
	FBullCowCount SubmitValidGuess(FString);

// ^^ Please try to ignore this and focus on the interface above ^^
private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
	bool bGameIsWon;
	bool IsIsogram(FString guess) const;
	bool IsLowercase(FString guess) const;
};
