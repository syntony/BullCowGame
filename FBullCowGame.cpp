#include "FBullCowGame.h"

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }


void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "and";

	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;

	return;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}
EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (false) // if the guess in't an isogram
	{
		return EGuessStatus::Not_Isogramm; // return error
	}
	else if (false) // if the guess isn't all lowercase
	{
		return EGuessStatus::Not_Lowercase; // return error
	}
	else if (GetHiddenWordLength() != Guess.length()) // if the guess length is wrong
	{
		return EGuessStatus::Wrong_Length; // return error
	}
	else // otherwise
	{
		return EGuessStatus::OK; // return ok
	}
}

// receives a VALID guess, incriments try, and return count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	// incriment the try number
	MyCurrentTry++;

	// setup return variable
	FBullCowCount BullCowCount;

	// loop through all leters in the guess
	int32 HiddenWordLength = MyHiddenWord.length();
	
	for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++)
	{
		// compare letters agains the hidden word
		for (int32 GChar = 0; GChar < Guess.length(); GChar++)
		{
			// if they match
			if (Guess[GChar] == MyHiddenWord[MHWChar])
			{
				// if they're in the same place
				if (MHWChar == GChar)
				{
					BullCowCount.Bulls++; // increment bulls
				}
				else
				{
					BullCowCount.Cows++;// increment cows
				}
			}
		}
	}

	return BullCowCount;
}
