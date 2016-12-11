#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

void PrintIntro(int word);
string GetGuess();
void RepeatGuess(string guess);

//the entry point of our operator 
int main()
{
	constexpr int WORD_LENGTH = 9;
	PrintIntro(WORD_LENGTH);


	RepeatGuess(GetGuess());
	RepeatGuess(GetGuess());


	return 0;
}
void PrintIntro(int word)
{
	//prints on screen the intrudutcion
	cout << "Welcome to Bulls and Cows, a fun word game \n";
	cout << "Can you guess the " << word;
	cout << (" letter isogram i'm thinking of? \n");
	cout << endl;
	return;
}

string GetGuess()
{
	//Asks Guess to the player
	cout << "Please enter your guess: \n ";
	string Guess = "";
	getline(cin, Guess);
	return Guess;
}

void RepeatGuess(string guess)
{
	//Repeat guess to the player
	cout << "Your guess was: " << guess << endl;
}