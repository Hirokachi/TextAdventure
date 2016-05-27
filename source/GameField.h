#include<list>
#include<string>
#include<iostream>

/**
 * class room - stores room name and description.
 */
class room {
	std::string name;
	std::string desc;
};

/**
 * struct roomConnections - template that stores connections between rooms.
 */
struct roomConnections {
 	room firstRoomName;
	room secondRoomName;
	bool isConnected;
	bool isBackTrackable;
	bool isPlayerInRoom;
};

/**
 * gameField class:
 * has private variables:
 * listOfRooms - a list of rooms that can exist in the subset for
 *				the gameField in the game
 * connections - a list of the first & second rooms that have two
 * 				flags that indicate either the connection between
 * 				the two rooms in question is there or not and/or
 *				the connection is backtrackable. *Connections make
 *				the room a real room in the gameField.*
 * %might have more variables%
 * has methods:
 * void directionalMove - verifies players move is  valid 
 *  					 & moves them to connected room based on choice.
 * void generateGameMap (size, randomize) - loads the list of rooms and generates 
 * 						gameMap connections between rooms and randomized
 *						start and end location.
 * private bool isWinnable - verifies the gameMap configuration is winnable.
 * bool hasNotWon - checks to see if player has made it to end-point
 * %might have more methods%
 */
class gameField {
	std::list listOfRooms <room>;
	std::list connections <roomConnections>;
	
	/*
	* Function/method directionalMove:
	* takes input for one of the possible exits for room & validates &
	* moves from one room to another when valid.
	*/
	void directionalMove () {
		std::string move;
		
		//do { //Maybe the do-while loop isn't needed either...
		std::getline (std::cin, move);
		
		for (connections.validmove: std::string valid) {
			if (0 != move.compare(valid)) {
				std::cout<< "That is not a valid move to move.\n";
				std::cout<< "Please try again.\n";
				std::getline (std::cin, move);
			}
			/* else {
				//not sure how to exit this when a valid move occurs
			} */
		}
		
		//Not sure how to move the user turn off the flag in the previous
		//room and turn on the flag in the next room and show description
		//the movement and new room.

		// } while (0 != move.compare(connections.validmove));
	}
	
	/*
	* void generateGameMap (size, randomize):
	*	loads the list of rooms and generates 
	* 	gameMap connections between rooms and randomized
	*	start and end location.
	*/
	void generateGameMap (std::string size, bool randomize) {
		
		//Load room description and name/id from file into
		//the listOfRooms.
		
		//for player input:
		//	Generate the connections between rooms
		//	Generate start and end positions
		//	run test verify if connections create a route to start to end
		// 	store as the current connected gameMap
		//  or load a pregenerated map of said size and store
		
	}
	/*
	* private bool isWinnable - verifies the gameMap configuration is winnable.
	*/
	private bool isWinnable () {
		
		//run from startpoint to end-point to see if a valid route exists.
		
		return (true);
	}
	
	/*
	* bool hasNotWon - checks to see if player has made it to end-point
	*/
	bool hasNotWon () {
		
		//check if player position matches the end-point
		//return true if they did, return false if not
		
		return (true);
	}
}
	