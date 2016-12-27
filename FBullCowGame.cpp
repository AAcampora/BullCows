#include "FBullCowGame.h"

using FString = std::string;
using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrenTry; }


bool FBullCowGame::IsGameWon() const{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString) {
	return false;
}

void FBullCowGame::Reset() {
	
	constexpr int MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;
	MyCurrenTry = 1;
	return;
}
