#include "GameField.h"

 
/**
 * Where the program starts.
 */
int main() {
	//The first answer to start the game.
	std::string randomize = "non";
	std::string mapSize = "non";
	char anykey;
	GameField gamemap = new GameField ();
	
	//This is text to welcome the player
	std::cout << "Welcome to Text Adventure!\n";
	
	//Asks the player/user if map should be randomly generated or not.
	do {
		if (randomize == "non") {
			std::cout << "Before we get started, please answer yes or no for a random map.\n";
			std::getline(std::cin, randomize);
		}
		else if (randomize != "no" && randomize != "yes") {
			std::cout << "That is not a valid answer. Please answer either yes or no for random map.\n";
			std::getline(std::cin, randomize);
		}
	} while (randomize != "no" && randomize != "yes");
	
	//Asks the player/user if the map should be either a small, medium or large map and tells
	// the player/user how many blocks a small, medium or large maps are.
	do {
		if (mapSize == "non") {
			std::cout << "Before we get started, please let me know if you want the map to be small, medium or large.\n";
			std::cout << "Your options are:\n"
			std::cout << "small, which has 25 total rooms.\n";
			std::cout << "medium, which has 100 total rooms.\n";
			std::cout << "large, which has 225 total rooms.\n";
			std::getline(std::cin, mapSize);
		}
		else if (mapSize != "small" || mapSize != "large" || mapSize != "medium") {
			std::cout << "That is not a valid answer. Please answer either small, medium or large.\n";
			std::cout << "The options again are:\n"
			std::cout << "small, which has 25 total rooms.\n";
			std::cout << "medium, which has 100 total rooms.\n";
			std::cout << "large, which has 225 total rooms.\n";
			std::getline(std::cin, mapSize);
		}
	} while (mapSize != "small" && mapSize != "large" && mapSize != "medium");
	
	//Generate gamemap connections based on player input.
	if (mapSize == "small" && randomize == "yes") {
		gamemap.generateGameMap (25, true); 
	}
	else if (mapSize == "medium" && randomize == "yes") {
		gamemap.generateGameMap (100, true); 
	}
	else if (mapSize == "large" && randomize == "yes") {
		gamemap.generateGameMap (225, true);
	}
	else if (mapSize == "small" && randomize == "no") {
		gamemap.generateGameMap (25, false); 
	}
	else if (mapSize == "medium" && randomize == "no") {
		gamemap.generateGameMap (100, false) 
	}
	else if (mapSize == "large" && randomize == "no") {
		gamemap.generateGameMap (225, false) 
	}
	
	do{
		//Simulate walking...
		gamemap.directionalMove ();
		
	}while (gamemap.hasNotWon ());

	//End of game text :D!!
	std::cout << "Congrates, you have won! :D\n";
	std::cout << "Press any key to continue:\n";
	std::cin >> anykey;

	return 0;
}
 