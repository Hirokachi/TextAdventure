#include <iostream>
#include <String>

int main() {
	std::string answer = "non";
	bool isNotOut = true;
	int coordinates[2] = { 0,0 };
	int coordinateY = 0;
	int coordinateX = 0;
	std::string direction = "";
	std::string done = "";

	bool map[3][2] = { true, false, true, true, false, true };

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
			if (coordinates[0] == 0 && coordinates[1] == 0)
				std::cout << "You find yourself in a cage. Your exits are:\n";
			if (map[coordinateX][coordinateY + 1])
				std::cout << "South\n";
			if (map[coordinateX][coordinateY - 1])
				std::cout << "North\n";
			if (map[coordinateX + 1][coordinateY])
				std::cout << "East\n";
			if (map[coordinateX - 1][coordinateY])
				std::cout << "West\n";
			std::cout << "Your coordinates are: x: " << coordinateX <<" y: " << coordinateY << std::endl;
			std::getline(std::cin, direction);
			if ((!map[coordinateX + 1][coordinateY] || !map[coordinateX][coordinateY + 1]
				|| !map[coordinateX][coordinateY - 1]  || !map[coordinateX - 1][coordinateY]) &&
				(direction == "North" || direction == "South" || direction == "East" || direction == "West")) {
				std::cout << "You can't go that way. Please try a different way.\n";
			}
			else if (direction != "North" && direction != "South" && direction != "East" &&
				direction != "West") {
				std::cout << "That is not a valid Direction. Please Try again.\n";
			}

		} while ((!map[coordinateX + 1][coordinateY] || !map[coordinateX][coordinateY + 1]
				|| !map[coordinateX][coordinateY - 1]  || !map[coordinateX - 1][coordinateY]) 
				&& (direction != "North" && direction != "South" && direction != "East" 
				&& direction != "West"));

		if ( direction == "South") {
			coordinates[0]++;
			std::cout << "You find yourself in a Hallway. Your exits are:\n";
			if (map[coordinateX][coordinateY + 1])
				std::cout << "South\n";
			if (map[coordinateX][coordinateY - 1])
				std::cout << "North\n";
			if (map[coordinateX + 1][coordinateY])
				std::cout << "East\n";
			if (map[coordinateX - 1][coordinateY])
				std::cout << "West\n";
			std::cout << "Your coordinates are: x: " << coordinateX <<" y: " << coordinateY << std::endl;
		}
		else if (direction == "East") {
			coordinates[1]++;
			std::cout << "You find yourself in a Hallway. Your exits are:\n";
			if (map[coordinateX][coordinateY + 1])
				std::cout << "South\n";
			if (map[coordinateX][coordinateY - 1])
				std::cout << "North\n";
			if (map[coordinateX + 1][coordinateY])
				std::cout << "East\n";
			if (map[coordinateX - 1][coordinateY])
				std::cout << "West\n";
			std::cout << "Your coordinates are: x: " << coordinateX <<" y: " << coordinateY << std::endl;
		}
		else if (direction == "North") {
			coordinates[0]--;
			std::cout << "You find yourself in a Hallway. Your exits are:\n";
			if (map[coordinateX][coordinateY + 1])
				std::cout << "South\n";
			if (map[coordinateX][coordinateY - 1])
				std::cout << "North\n";
			if (map[coordinateX + 1][coordinateY])
				std::cout << "East\n";
			if (map[coordinateX - 1][coordinateY])
				std::cout << "West\n";
			std::cout << "Your coordinates are: x: " << coordinateX <<" y: " << coordinateY << std::endl;
		}
		else if (direction == "West") {
			coordinates[1]--;
			std::cout << "You find yourself in a Hallway. Your exits are:\n";
			if (map[coordinateX][coordinateY + 1])
				std::cout << "South\n";
			if (map[coordinateX][coordinateY - 1])
				std::cout << "North\n";
			if (map[coordinateX + 1][coordinateY])
				std::cout << "East\n";
			if (map[coordinateX - 1][coordinateY])
				std::cout << "West\n";
			std::cout << "Your coordinates are: x: " << coordinateX <<" y: " << coordinateY << std::endl;
		}

		if (coordinates[0] == 2 && coordinates[1] == 1) {
			std::cout << "You find the exit!\n Congradulations! You climb out of the dungeon! You win!\n";
			isNotOut = false;
			std::getline(std::cin, done);
		}
	}

	return 0;
}
