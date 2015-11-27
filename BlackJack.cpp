#include "BlackJack.h"

int main() {
	// Create Vector with the players, using vec because of an undiefined amount of players
	std::vector<Players> VecPlayers;
	// PlayerCount counts number of players and lines
	unsigned int PlayerCount = 0, CardCount = 0;
	// StrLine is a general string used for storing lines in  files
	std::string StrLine = "";
	// Firstly get the players
	std::cout << "Please give the players. \n: ";
	while (std::cin >> StrLine) {
		if (StrLine == ".") break;
		VecPlayers.push_back(Players());
		VecPlayers[PlayerCount].Name = StrLine;
		PlayerCount++;
		std::cout << ": ";
		
	}
	srand(int(time(NULL)));
	PlayerCount = 0;
	std::cin.ignore();


	int Sum = 0, LargestSum =  0;
	unsigned int WhichCard = 0;
	std::string WinnersName = "";
	char Answer = 0;
	do {
		std::cout << VecPlayers[PlayerCount].Name << "'s Turn: ";
		std::cin.ignore();
		for (CardCount = 0; CardCount <= 1; CardCount++) {
			VecPlayers[PlayerCount].NumCard[CardCount] = (rand() % 13);
			VecPlayers[PlayerCount].NumSuit[CardCount] = (rand() % 4);
			VecPlayers[PlayerCount].Cards++;
			
			while (IsEqual(VecPlayers, VecPlayers[PlayerCount].NumCard[CardCount], VecPlayers[PlayerCount].NumSuit[CardCount])) {
				VecPlayers[PlayerCount].NumCard[CardCount] = (rand() % 13);
				VecPlayers[PlayerCount].NumSuit[CardCount] = (rand() % 4);
			}
			
		}

		std::cout << "You have:" << std::endl;
		for (CardCount = 0; CardCount < VecPlayers[PlayerCount].Cards; CardCount++) {
			std::cout << CardName(VecPlayers[PlayerCount].NumSuit[CardCount], VecPlayers[PlayerCount].NumCard[CardCount]) << std::endl;
		}
		if ((VecPlayers[PlayerCount].NumCard[0] + 1) >= 10) {
			VecPlayers[PlayerCount].Sum = 10;
			std::cout << std::endl << "10";
		}
		else {
			std::cout << std::endl << (VecPlayers[PlayerCount].NumCard[0] + 1);
			VecPlayers[PlayerCount].Sum = (VecPlayers[PlayerCount].NumCard[0] + 1);
		}

		
		for (CardCount = 1; CardCount < VecPlayers[PlayerCount].Cards; CardCount++) {
			
			if ((VecPlayers[PlayerCount].NumCard[CardCount] + 1) >= 10) {
				VecPlayers[PlayerCount].Sum = VecPlayers[PlayerCount].Sum + 10;
				std::cout << " + " << "10";
			}
			else {
				VecPlayers[PlayerCount].Sum = VecPlayers[PlayerCount].Sum + (VecPlayers[PlayerCount].NumCard[CardCount] + 1);
				std::cout << " + " << VecPlayers[PlayerCount].NumCard[CardCount] + 1;
			}
		}

		std::cout << " = " << VecPlayers[PlayerCount].Sum << std::endl;

		WhichCard = 2;
		std::cout << "Do you want another card? Y/N? \n:";
		std::cin >> Answer;
		WhichCard = 2;
		while (Answer == 'Y') {
			VecPlayers[PlayerCount].NumCard[WhichCard] = (rand() % 13);
			VecPlayers[PlayerCount].NumSuit[WhichCard] = (rand() % 4);
			VecPlayers[PlayerCount].Cards++;
			WhichCard++;
			
			std::cout << std::endl << "You have:" << std::endl;
			for (CardCount = 0; CardCount < VecPlayers[PlayerCount].Cards; CardCount++) {
				std::cout << CardName(VecPlayers[PlayerCount].NumSuit[CardCount], VecPlayers[PlayerCount].NumCard[CardCount]) << std::endl;
			}
			if ((VecPlayers[PlayerCount].NumCard[0] + 1) >= 10) {
				Sum = 10;
				std::cout << std::endl << "10";
			}
			else {
				std::cout << std::endl << (VecPlayers[PlayerCount].NumCard[0] + 1);
				Sum = (VecPlayers[PlayerCount].NumCard[0] + 1);
			}


			for (CardCount = 1; CardCount < VecPlayers[PlayerCount].Cards; CardCount++) {

				if ((VecPlayers[PlayerCount].NumCard[CardCount] + 1) >= 10) {
					Sum = Sum + 10;
					std::cout << " + " << "10";
				}
				else {
					Sum = Sum + (VecPlayers[PlayerCount].NumCard[CardCount] + 1);
					std::cout << " + " << VecPlayers[PlayerCount].NumCard[CardCount] + 1;
				}
			}
			std::cout << " = " << Sum << std::endl << std::endl << "Do you want another card? Y/N? \n:";
			std::cin >> Answer;
			
		}
		std::cin.ignore();
		std::cout << std::string(100, '\n');
		LargestSum = 0;
		if ((VecPlayers.size()-1) == PlayerCount) {
			for (PlayerCount = 0; VecPlayers.size() < PlayerCount; PlayerCount++) {
				if (VecPlayers[PlayerCount].Sum > LargestSum) {
					LargestSum = VecPlayers[PlayerCount].Sum;
					WinnersName = VecPlayers[PlayerCount].Name;
				}
			}

			std::cout << WinnersName << " is the winner!\n:";
			VecPlayers = ClearArray(VecPlayers);
			PlayerCount = 0;

		}
		else {
			PlayerCount++;
		}
	} while (true);
	return 1;
}