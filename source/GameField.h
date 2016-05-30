#include<list>
#include<string>
#include<iostream>
#include<fstream>

/**
 * class playerPosition stores the uniqueID of the current room.
 */
class playerPosition {
public:
	int uniqueID;
};
 
/**
 * class room - stores room uniqueID, name, isStart, isEnd, and description.
 */
class room {
	int uniqueID;
	std::string name;
	std::string desc;
	bool isStart;
	bool isEnd;
};

//Commands that are available for player (only has directions
enum class commandlist : char { n, s, e, w };

/*
* struct roomConnections - template that stores the connections
*				 between rooms and in what direction.
*/
struct roomConnections {
 	room firstRoomName;
	room secondRoomName;
	std::list<char> exits;
};

/**
 * gameField class:
 * has private variables:
 * listOfRooms - a list of rooms that can exist in the subset for
 *				the gameField in the game
 * connections - a list of the first & second rooms (i.e. ab) and a valid exit
 * %might have more variables%
 * has methods:
 * void directionalMove - verifies players move is  valid 
 *  					 & moves them to connected room based on choice.
 * void generateGameMap (size, randomize) - loads the list of rooms and generates 
 * 						gameMap connections between rooms and randomized
 *						start and end location.
 * private bool isWinnable - verifies the gameMap configuration is winnable.
 * private bool hasNotWon - checks to see if player has made it to end-point
 * private printRoomDesc (room:uniqueID) - Prints room's description when player enters room.
 * %might have more methods%
 */
class GameField {

	std::list<room> listOfRooms;
	std::list<roomConnections> connections;

//public:
//	GameField () {
//		std::string line;
//		std::ifstream myfile("roomsfile.txt");
//		if (myfile.is_open()) {
//			while (std::getline(myfile, line)) {
//				std::cout << line << '\n';
//			}
//			myfile.close();
//		}
//		else
//			std::cout << "Unable to open file.";
//	}
	
//private:
	/*
	* private bool isWinnable - verifies the gameMap configuration 
	*					is winnable.
	*/
	bool isWinnable () {
		
		return (true /*true if there is a connection from startpoint to end otherwise false*/ );
	}

	/*
	* private printRoomDesc (int uniqueID) - Prints room's 
	*			description when player enters room.
	*/
	void printRoomDesc (int uniqueID) {
		//print room Description based on uniqueID.
	}

public:
	/*
	* Function/method directionalMove:
	* takes input for one of the possible exits for room & validates &
	* moves from one room to another when valid.
	*/
	void directionalMove () {
		commandlist directions;

		//Define the variable storeing player choice
		char move;

		//printRoomDesc (playerPosition.uniqueID);

		//Tell the player they can move now.
		std::cout << "Please enter a direction.\n";

		//get direction from player.
		std::cin >> move;

		//Check if command is valid
		if (directions::n == move) {
			std::cout << "You did try to move North which means that I program correctly. Hurray for me!!!";
		}
		else {
			std::cout << "You didn't try to move north you silly player. Boo, I don't know how to use enums to hold commands.";
		}
		//Move player into room from that direction.
		//Print out new Room Description.
		
	}
	
	/*
	* void generateGameMap (totalRooms, randomize):
	*	loads the list of rooms and generates 
	* 	gameMap connections between rooms and randomized
	*	start and end location.
	*/
	void generateGameMap (int totalRooms, bool randomize) {
		
		//Load room description and name/id from file into the listOfRooms.
		
		//for player input:
		//	for the total number of Rooms:
		//		Generate the connections between rooms
		//	Generate start and end positions and set in the room
		//	run test verify if connections create a route to start to end
		// 	store as the current connected gameMap
		//  or load a pregenerated map of said size and store
		
	}
	
	/*
	* private bool hasNotWon - is at the room that is marked at Endpoint.
	*/
	bool hasNotWon () {
		
		return (false /*false if player position matches the room with isEnd marked true*/);
	}
};
