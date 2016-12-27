#pragma once
#include <string>



class FBullCowGame {
public:
	FBullCowGame();//constructor

	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;
	
	void Reset(); // TODO make a more rich return value.
	bool CheckGuessValidity(std::string); //TODO make a more rich return value



// ^^ Please try to ignore this and focus on the interface above ^^
private:
	int MyCurrenTry;
	int	MyMaxTries;

};