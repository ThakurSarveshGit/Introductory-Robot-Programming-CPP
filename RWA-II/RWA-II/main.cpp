#include "libraryFunctions.h"


int main(int argc, char **argv)
{
	// Read & Display Maze
	maze = readInputMaze("../maze.txt");
	displayMaze(maze);
	
	// Get Coordinates from user
	std::vector<int> UC = getCoordinates(); // UC: User Coordinates Format
	
	std::vector<int> SC{30-UC[1], UC[0], 30-UC[3], UC[2]};// SC: Script coordinates format
	
	// Update the start and goal positions & Display Maze
	maze = updateMaze(SC);
	displayMaze(maze);
	
	// Start Positions
	std::vector<int> start{SC[0], SC[1]};
	
	// Goal Positions
	std::vector<int> goal{SC[2], SC[3]};
	
	// Find Path on the Maze and Display Final Maze
	if (FindPath(start, goal)){
		std::cout << "Yay! Found a path" << std::endl;
		maze = updateMaze(SC);
		displayMaze(maze);
	}
	
	else
		std::cout << "No path found!" << std::endl;
	
	return 0;
}
