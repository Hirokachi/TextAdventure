#include <iostream>
#include <String>

//Fun Global Variable that is here to make sure all functions can access variable.
bool gameField[4][3] = { true, false, true, true, true, true, false, true, true, false, false, true };

/**
* This function validates a chosen exit/direction.
* @return direction: validated direction.
*/
std::string isValidDirection (int coordinateX, int coordinateY){
	bool isValid;
	std::string direction;
	
	//This loop validates if your direction/exit is a valid 
	//direction/exit and if you typed a valid direction/exit name.
	do {
		isValid = true;
		std::getline(std::cin, direction);
		if ((!gameField[coordinateX + 1][coordinateY] || !gameField[coordinateX][coordinateY + 1] 
			|| !gameField[coordinateX][coordinateY - 1] || !gameField[coordinateX - 1][coordinateY]) 
			&& (direction == "North" || direction == "South" || direction == "East" || direction == "West")) {
			std::cout << "You can't go that way. Please try a different way.\n";
			isValid = false;	
		}
		else if (direction != "North" && direction != "South" && direction != "East" && direction != "West") {
			std::cout << "That is not a valid Direction. Please Try again.\n";
			isValid = false;
		}
	} while (isValid == false);
	
	return (direction);
}

/**
 * Prints out the possible exits/directions from the room.
 * @param coordinateX, coordinateY: coordinates where the player is.
 * @param gameField
 */
 void possibleExits (int coordinateX, int coordinateY) {
	 
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
	std::string answer = "non";
	
	//Flags to end the game and open a door.
	bool isNotOut = true;
	bool hasKey = false;
	
	//the coordinates to indicate where the player is.
	int coordinateY = 0;
	int coordinateX = 0;
	
	//various situational commands to play the game.
	std::string direction = "";
	std::string command = "";

	//This is text to welcome the player
	std::cout << "Welcome to Text Adventure!\n";

	//This loop validates the input for starting the game.
	do {
		if (answer == "non") {
			std::cout << "Shall we get started?\n";
			std::getline(std::cin, answer);
		}
		else {
			std::cout << "That is not a valid answer.\n";
			std::cout << "Please answer yes or no.\n";
			std::getline(std::cin, answer);
		}
	} while (answer != "yes" && answer != "no");

	//This loop is where the game actually starts
	while (answer == "yes" && isNotOut) {
		
		//validates the direction/exit.
		direction = isValidDirection (coordinateX, coordinateY);
		
		//Sets the text for the starting point and tells you your exits and 
		//coordinates.
		if (coordinateX == 0 && coordinateY == 0) {
			std::cout << "You find yourself in a cage. Your exits are:\n";
			possibleExits(coordinateX, coordinateY);
			
		}
			
		//After verifying that the direction/exit is valid this block of if
		//statements does the moving and printing of the next room.
		if ( direction == "South") {
			coordinateY++;
			if (coordinateX == 3 && coordinateY == 1) {
				std::cout << "You bump in to a locked door!\n";
				coordinateY--;
			}
			else {
				//Sets the text for the room and tells you your exits and 
				//coordinates
				std::cout << "You find yourself in a Hallway. Your exits are:\n";
				possibleExits(coordinateX, coordinateY);
			}
			
		}
		else if (direction == "East") {
			coordinateX++;
			//Sets the text for the room and tells you your exits and 
		    //coordinates
			std::cout << "You find yourself in a Hallway. Your exits are:\n";
			possibleExits(coordinateX, coordinateY);
		}
		else if (direction == "North") {
			coordinateY--;
			//Sets the text for the room and tells you your exits and 
		    //coordinates
			std::cout << "You find yourself in a Hallway. Your exits are:\n";
			possibleExits(coordinateX, coordinateY);
		}
		else if (direction == "West") {
			coordinateX--;
			if (coordinateX == 0 && coordinateY == 3) {
				//Sets the text for the room and tells you your exits and 
				//coordinates
				std::cout << "You find yourself at a dead end. ";
				std::cout << "You notice that there is a small but seemingly "; std::cout << "out of place small chest near the north wall. ";
				std::cout << "(hint: try 'open chest'.) Your exits are:\n";
				possibleExits(coordinateX, coordinateY);
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
				possibleExits(coordinateX, coordinateY);
			}
		}
		
		//This if statement checks to see if you got to the end point and ends 
		//the game.
		if (coordinateX == 3 && coordinateY == 2) {
			std::cout << "You find the exit!\n Congradulations! You climb out of the dungeon! You win!\n";
			isNotOut = false;
		}
	}
	return 0;
}
