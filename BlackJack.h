#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>

struct Players {
	std::string Name = "";
	unsigned int Wins = 0;
	unsigned int Cards = 0;
	int Sum;
	int NumSuit[10] = { 0 }; // Suit is from 0 to 3
	int NumCard[10] = { 0 };
};

bool IsEqual(std::vector<Players> VecEqual, int NumCard, int NumSuit) {
	unsigned int Array = 0;
	for (unsigned int Player = 0; VecEqual.size(); Player++) {
		for (Array = 0; Array < VecEqual[Player].Cards; Array++) {
			if (VecEqual[Player].NumCard[Array] == NumCard && VecEqual[Player].NumSuit[Array] == NumSuit) {
				return false;
			}
		}
	}
	return true;
}

std::string CardName(int SuitNum, int CardNum) {
	std::string SuitName, CardName, Sentence;
	switch (CardNum) {
	case 0:
		CardName = "Ace";
		break;
	case 1:
		CardName = "Two";
		break;
	case 2:
		CardName = "Three";
		break;
	case 3:
		CardName = "Four";
		break;
	case 4:
		CardName = "Five";
		break;
	case 5:
		CardName = "Six";
		break;
	case 6:
		CardName = "Seven";
		break;
	case 7:
		CardName = "Eight";
		break;
	case 8:
		CardName = "Nine";
		break;
	case 9:
		CardName = "Ten";
		break;
	case 10:
		CardName = "Jack";
		break;
	case 11:
		CardName = "Queen";
		break;
	case 12:
		CardName = "King";
		break;
	}
	switch (SuitNum) {
	case 0:
		SuitName = "Hearts";
		break;
	case 1:
		SuitName = "Diamonds";
		break;
	case 2:
		SuitName = "Clubs";
		break;
	case 3:
		SuitName = "Spades";
		break;
	}
	Sentence = "The " + CardName + " of " + SuitName;
	return Sentence;
}

std::vector<Players> ClearArray(std::vector<Players> VecClear) {
	unsigned int Array = 0;
	for (unsigned int Player = 0; Player < (VecClear.size()) ; Player++) {
		for (Array = 0; Array < VecClear[Player].Cards; Array++) {
			VecClear[Player].NumCard[Array] = 0;
			VecClear[Player].NumCard[Array] = 0;
		}
		VecClear[Player].Cards = 0;
	}
	return VecClear;
}