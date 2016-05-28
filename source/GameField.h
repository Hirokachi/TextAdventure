#include<list>
#include<string>
#include<iostream>

/**
 * class playerPosition stores the uniqueID of the current room.
 */
class playerPosition {
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

/**
 * struct roomConnections - template that stores the connections
 *				 between rooms and in what direction.
 */
struct roomConnections {
 	room firstRoomName;
	room secondRoomName;
	enum directionalExits { north, south, east, west };
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
		//Define the variable storeing player choice
		std::string move;
		
		//get direction from player.
		std::getline (std::cin, move);
		
		//Check if direction has a valid connection from the room they are in.
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
		
		return (true /*false if player position matches the room with isEnd marked true*/);
	}
};
