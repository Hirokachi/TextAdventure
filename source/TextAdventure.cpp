#include <iostream>
#include <String>

int main() {
	std::string answer = "non";
	bool isNotOut = true;
	bool hasKey = false;
	bool isValid = true;
	int coordinateY = 0;
	int coordinateX = 0;
	std::string direction = "";
	std::string done = "";
	std::string command = "";

	bool map[4][3] = { true, false, true, true, true, true, false, true, true,
	false, false, true };

	std::cout << "Welcome to Text Adventure!\n";

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

	while (answer == "yes" && isNotOut) {

		do {
			if (coordinateX == 0 && coordinateY == 0) {
				std::cout << "You find yourself in a cage. Your exits are:\n";
				if (map[coordinateX][coordinateY - 1])
					std::cout << "North\n";
				if (map[coordinateX][coordinateY + 1])
					std::cout << "South\n";
				if (map[coordinateX + 1][coordinateY])
					std::cout << "East\n";
				if (map[coordinateX - 1][coordinateY])
					std::cout << "West\n";
			}
			std::cout << "Your coordinates are: x: " << coordinateX <<" y: " << coordinateY << std::endl;
			std::getline(std::cin, direction);
			if ((!map[coordinateX + 1][coordinateY] || !map[coordinateX][coordinateY + 1] || !map[coordinateX][coordinateY - 1]  || !map[coordinateX - 1][coordinateY]) && (direction == "North" || direction == "South" || direction == "East" || direction == "West")) {
				std::cout << "You can't go that way. Please try a different way.\n";
				isValid = false;
			}
			else if (direction != "North" && direction != "South" && direction != "East" && direction != "West") {
				std::cout << "That is not a valid Direction. Please Try again.\n";
				isValid = false;
			}

		} while (!isValid);

		if ( direction == "South") {
			coordinateY++;
			if (coordinateX == 3 && coordinateY == 2) {
				std::cout << "You find the exit!\n Congradulations! You climb out of the dungeon! You win!\n";
				isNotOut = false;
				std::getline(std::cin, done);
			}
			if (coordinateX == 3 && coordinateY == 1) {
				std::cout << "You bump in to a locked door!\n";
				coordinateY--;
				
			}
			else {
				std::cout << "You find yourself in a Hallway. Your exits are:\n";
				if (map[coordinateX][coordinateY - 1])
					std::cout << "North\n";
				if (map[coordinateX][coordinateY + 1])
					std::cout << "South\n";
				if (map[coordinateX + 1][coordinateY])
					std::cout << "East\n";
				if (map[coordinateX - 1][coordinateY])
					std::cout << "West\n";
				std::cout << "Your coordinates are: x: " << coordinateX <<" y: " << coordinateY << std::endl;
			}
			
		}
		else if (direction == "East") {
			coordinateX++;
			std::cout << "You find yourself in a Hallway. Your exits are:\n";
			if (map[coordinateX][coordinateY - 1])
				std::cout << "North\n";
			if (map[coordinateX][coordinateY + 1])
				std::cout << "South\n";
			if (map[coordinateX + 1][coordinateY])
				std::cout << "East\n";
			if (map[coordinateX - 1][coordinateY])
				std::cout << "West\n";
			std::cout << "Your coordinates are: x: " << coordinateX <<" y: " << coordinateY << std::endl;
		}
		else if (direction == "North") {
			coordinateY--;
			std::cout << "You find yourself in a Hallway. Your exits are:\n";
			if (map[coordinateX][coordinateY - 1])
				std::cout << "North\n";
			if (map[coordinateX][coordinateY + 1])
				std::cout << "South\n";
			if (map[coordinateX + 1][coordinateY])
				std::cout << "East\n";
			if (map[coordinateX - 1][coordinateY])
				std::cout << "West\n";
			std::cout << "Your coordinates are: x: " << coordinateX <<" y: " << coordinateY << std::endl;
		}
		else if (direction == "West") {
			coordinateX--;
			if (coordinateX == 0 && coordinateY == 3) {
				std::cout << "You find yourself at a dead end. You notice that there is a small but seemingly out of place small chest near the north wall. (hint: try 'open chest'.) Your exits are:\n";
				if (map[coordinateX][coordinateY - 1])
					std::cout << "North\n";
				if (map[coordinateX][coordinateY + 1])
					std::cout << "South\n";
				if (map[coordinateX + 1][coordinateY])
					std::cout << "East\n";
				if (map[coordinateX - 1][coordinateY])
					std::cout << "West\n";
				std::cout << "Your coordinates are: x: " << coordinateX <<" y: " << coordinateY << std::endl;
				std::getline(std::cin, command);
				if (command == "open chest") {
					std::cout << "Upon opening the chest, you find a key and take the key.\n";
					hasKey = true;
				}
			}
			else {
				std::cout << "You find yourself in a Hallway. Your exits are:\n";
				if (map[coordinateX][coordinateY - 1])
					std::cout << "North\n";
				if (map[coordinateX][coordinateY + 1])
					std::cout << "South\n";
				if (map[coordinateX + 1][coordinateY])
					std::cout << "East\n";
				if (map[coordinateX - 1][coordinateY])
					std::cout << "West\n";
				std::cout << "Your coordinates are: x: " << coordinateX <<" y: " << coordinateY << std::endl;
			}
		}
	}
	return 0;
}
