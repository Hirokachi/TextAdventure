#include <iostream>
#include <String>


bool setMap () {
	bool map [3][2] = {true, false, true, true, false, true};
	
	return (map);
}

int main() {
	std::string answer = "non";
	bool isNotOut = true;
	int coordinates[2] = { 0,0 };
	std::string direction = "";

	bool map[3][2] = { setMap() };

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
		if (coordinates[0] == 0 && coordinates[1] == 0)
			std::cout << "You find yourself in a cage and your exits are:\n";
		if (map[coordinates[0]][coordinates[1]++])
			std::cout << "South\n";
		if (map[coordinates[0]++][coordinates[1]])
			std::cout << "East\n";
			
		do {
			std::getline(std::cin, direction);
			if (!map[coordinates[0]][coordinates[1]++] || !map[coordinates[0]++][coordinates[1]])
				std::cout << "You can't go that way.\n Please try a different way.\n";
		} while (!map[coordinates[0]][coordinates[1]] && !map[coordinates[0]++][coordinates[1]]);
		if (map[coordinates[0]][coordinates[1]++]) {
			std::cout << "you find yourself in a cordoor\n";
			coordinates[1]++;
		}
		if (map[coordinates[0]++][coordinates[1]]) {
			std::cout << "you find yourself in a cordoor\n";
			coordinates[0]++;
		}
		if (coordinates[0] == 2 && coordinates[1] == 1) {
			std::cout << "You find the exit!\n Congradulations!\n You climb out of the dungeon!\n You win!\n";
			isNotOut = false;
		}
	}

	return 0;
}
