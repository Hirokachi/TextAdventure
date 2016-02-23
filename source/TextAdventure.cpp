#include <iostream>
#include <String>

/**
* This function validates a chosen exit/direction.
* @return direction: validated direction.
*/
std::string isValidDirection ( bool gameField[6][6], int coordinateX, int coordinateY){
	bool isValid;
	std::string direction;
	
	//This loop validates if your direction/exit is a valid 
	//direction/exit and if you typed a valid direction/exit name.
	do {
        
        //prompt the user for direction.
		std::getline(std::cin, direction);
        
		//this verifies that the direction and the point in the multi-dimensional array in 
        //that direction is marked as false meaning that the user cannot go that way. 
        //allow the user to reenter the direction they want to go.
		if ((!gameField[coordinateX + 1][coordinateY] && direction == "East") 
                || (!gameField[coordinateX][coordinateY + 1] && direction == "South")
				|| (!gameField[coordinateX][coordinateY - 1] && direction == "North")
                || (!gameField[coordinateX - 1][coordinateY] &&  direction == "West")) {
		        std::cout << "You can't go that way. Please try a different way.\n";
			isValid = false;	
		}
        //Otherwise if the direction is not a valid direction then allow the user to reenter it.
		else if (direction != "North" && direction != "South" && direction != "East" 
                    && direction != "West") {
			std::cout << "That is not a valid Direction. Please Try again.\n";
			isValid = false;
		}
		//Otherwise the direction is valid and will exit the loop.
		else {
			isValid = true;
		}
		
	} while (!isValid);
	
	return (direction);
}

/**
 * Prints out the possible exits/directions from the room.
 * @param coordinateX, coordinateY: coordinates where the player is.
 * @param gameField
 */
 void possibleExits (bool gameField[6][6], int coordinateX, int coordinateY) {
	 
	if (gameField[coordinateX][coordinateY - 1])
				std::cout << "North\n";
			if (gameField[coordinateX][coordinateY + 1])
				std::cout << "South\n";
			if (gameField[coordinateX + 1][coordinateY])
				std::cout << "East\n";
			if (gameField[coordinateX - 1][coordinateY])
				std::cout << "West\n";
			std::cout << "Your coordinates are: x: " << coordinateX <<" y: " << coordinateY << std::endl;
 }

/**
 * Where the program starts.
 */
int main() {
	//The first answer to start the game.
	std::string generateMap = "non";
	std::string mapSize = "non";
	
	//Flags to end the game and open a door.
	bool isNotOut = true;
	bool hasKey = false;
	
	//the coordinates to indicate where the player is.
	int coordinateY = 1;
	int coordinateX = 1;
	
	//various situational commands to play the game.
	std::string direction = "";
	std::string command = "";
	
	//Asks the player/user if map should be randomly generated or pregenerated.
	do {
		if (generateMap == "non") {
			std::cout << "Before we get started, please let me know if you want a pregenerated or random map.";
			std::getline(std::cin, generateMap);
		}
		else if (generateMap != "pregenerated" && generateMap != "random") {
			std::cout << "That is not a valid answer. Please answer either pregenerated or random.";
			std::getline(std::cin, generateMap);
		}
	} while (generateMap != "pregenerated" && generateMap != "random");
	
	//Asks the player/user if the map should be either a small, medium or large map and tells
	// the player/user how many blocks a small, medium or large maps are.
	do {
		if (mapSize == "non") {
			std::cout << "Before we get started, please let me know if you want the map to be small, medium or large.\n";
			std::cout << "Small is a 6x6 block box.\n";
			std::cout << "Medium is a 10x10 block box.\n";
			std::cout << "Large is a 15x15 block box.\n";
			std::getline(std::cin, mapSize);
		}
		else if (mapSize != "small" || mapSize != "large" || mapSize != "medium") {
			std::cout << "That is not a valid answer. Please answer either small, medium or large.\n";
			std::getline(std::cin, mapSize);
		}
	} while (mapSize != "small" && mapSize != "large" && mapSize != "medium");
	
	
	if (mapSize == "small" && generateMap == "pregenerated") {
		//gamefield (map of moveable areas, moveable areas are set as true.)
		bool gameField[6][6] = { {false, false, false, false, false, false},
			{false, true, true, false, false, false}, {false, false, true, false, true, false},
			{false, true, true, false, true, false}, {false, true, true, true, true, false},
			{false, false, false, false, false, false} };

		//This is text to welcome the player
		std::cout << "Welcome to Text Adventure!\n";

		//This loop is where the game actually starts
		while (isNotOut) {
			
			//Sets the text for the starting point and tells you your exits and 
			//coordinates.
			if (coordinateX == 1 && coordinateY == 1 && direction != "North" 
						&& direction != "South" && direction != "East" 
						&& direction != "West") {
				std::cout << "You find yourself in a cage. Your exits are:\n";
				possibleExits(gameField, coordinateX, coordinateY);		
			}
				
			//After verifying that the direction/exit is valid this block of if
			//statements does the moving and printing of the next room.
			if ( direction == "South") {
				coordinateY++;
				if (coordinateX == 5 && coordinateY == 3) {
					//Sets the text for the room and tells you your exits and 
					//coordinates
					std::cout << "You find yourself at a dead end. ";
					std::cout << "You notice that there is a small but seemingly ";
					std::cout << "out of place small chest near the north wall. ";
					std::cout << "(hint: try 'open chest'.) Your exits are:\n";
					possibleExits(gameField, coordinateX, coordinateY);	
					std::getline(std::cin, command);
					if (command == "open chest") {
						std::cout << "Upon opening the chest, you find a key and "; std::cout << "take the key.\n";
						hasKey = true;
					}
				}
				else {
					//Sets the text for the room and tells you your exits and 
					//coordinates
					std::cout << "You find yourself in a Hallway. Your exits are:\n";
					possibleExits(gameField, coordinateX, coordinateY);
				}
			}
			else if (direction == "East") {
				coordinateX++;
				//Sets the text for the room and tells you your exits and 
				//coordinates
				std::cout << "You find yourself in a Hallway. Your exits are:\n";
				possibleExits(gameField, coordinateX, coordinateY);	
			}
			else if (direction == "North") {
				coordinateY--;
				//Sets the text for the room and tells you your exits and 
				//coordinates
				if (coordinateX == 5 && coordinateY == 5) {
					std::cout << "You bump in to a locked door!\n";
					coordinateY++;
				}
				else if (coordinateX == 1 && coordinateY == 1) {
					std::cout << "You find yourself in a cage. Your exits are:\n";
					possibleExits(gameField, coordinateX, coordinateY);		
				}
				else {
					std::cout << "You find yourself in a Hallway. Your exits are:\n";
					possibleExits(gameField, coordinateX, coordinateY);	
				}
			}
			else if (direction == "West") {
				coordinateX--;
				//Sets the text for the room and tells you your exits and 
				//coordinates
				std::cout << "You find yourself in a Hallway. Your exits are:\n";
				possibleExits(gameField, coordinateX, coordinateY);
			}

			//validates the direction/exit.
			direction = isValidDirection(gameField, coordinateX, coordinateY);
			
			//This if statement checks to see if you got to the end point and ends 
			//the game.
			if (coordinateX == 5 && coordinateY == 3) {
				std::cout << "You find the exit!\n Congradulations! You climb out of the dungeon! You win!\n";
				isNotOut = false;
			}
		}
	}
	else {
		std::cout << "no other options exist at this time.\n";
	}

	return 0;
}
