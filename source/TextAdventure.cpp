#include <iostream> //maybe not needed?
#include <string>   //maybe not needed?
#include "GameField.h"

 
/**
 * Where the program starts.
 */
int main() {
	//The first answer to start the game.
	std::string randomize = "non";
	std::string mapSize = "non";
	
	//This is text to welcome the player
	std::cout << "Welcome to Text Adventure!\n";
	
	//Asks the player/user if map should be randomly generated or pregenerated.
	do {
		if (randomize == "non") {
			std::cout << "Before we get started, please let me know if you want a pregenerated or random map.\n";
			std::getline(std::cin, randomize);
		}
		else if (randomize != "no" && randomize != "yes") {
			std::cout << "That is not a valid answer. Please answer either pregenerated or random.\n";
			std::getline(std::cin, randomize);
		}
	} while (randomize != "no" && randomize != "yes");
	
	//Asks the player/user if the map should be either a small, medium or large map and tells
	// the player/user how many blocks a small, medium or large maps are.
	do {
		if (mapSize == "non") {
			std::cout << "Before we get started, please let me know if you want the map to be small, medium or large.\n";
			std::cout << "small is a 5x5 room box.\n";
			std::cout << "medium is a 10x10 room box.\n";
			std::cout << "large is a 15x15 room box.\n";
			std::getline(std::cin, mapSize);
		}
		else if (mapSize != "small" || mapSize != "large" || mapSize != "medium") {
			std::cout << "That is not a valid answer. Please answer either small, medium or large.\n";
			std::getline(std::cin, mapSize);
		}
	} while (mapSize != "small" && mapSize != "large" && mapSize != "medium");
	
	if (mapSize == "small" && randomize == "yes") {
		generateGameMap (5, true); 
	}
	else if (mapSize == "medium" && randomize == "yes") {
		
		generateGameMap (10, true); 
	}
	else if (mapSize == "large" && randomize == "yes") {
		generateGameMap (15, true);
	}
	else if (mapSize == "small" && randomize == "no") {
		generateGameMap (5, false); 
	}
	else if (mapSize == "medium" && randomize == "no") {
		generateGameMap (10, false) 
	}
	else if (mapSize == "large" && randomize == "no") {
		generateGameMap (15, false) 
	}
	
	
	std::cout<<"End of game :)";

	return 0;
}
 