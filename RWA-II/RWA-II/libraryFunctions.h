#include <iostream>
#include <vector>
#include <fstream>
#include <string>

std::vector<std::vector<char>> maze;
std::vector<std::vector<char>> expPath;

// Function 1: readInputMaze(path)

std::vector<std::vector<char>> readInputMaze(std::string path){
	
	std::ifstream f(path);
	std::string line;
	
	if (!f){
		std::cout << "File not found!" << std::endl;
		exit(0);
	}
	else{
		while (std::getline(f, line)){
			std::vector<char> row;
			for (auto character:line){
				row.push_back(character);
			}
			maze.push_back(row);
			expPath.push_back(row);
		}
	}
	f.close();
	return maze;
}

// Function 2: displayMaze()

void displayMaze(std::vector<std::vector<char>> MAZE){
	
	for (unsigned int row=0; row<MAZE.size(); row++){
		for (unsigned int col=0; col<MAZE[row].size(); col++){
			std::cout << MAZE[row][col];
		}
		std::cout << "\n";
	}
}

// Function 3: IsValid(Coordinates)
bool IsValid(int x, int y){
	// (x, y) is coordinates, expected in script frame
	if ((x>=0) & (x<=45) & (y>=0) & (y<=30) & (maze[x][y]!='#'))
		return true;
	else
		return false;
}


// Function 4: getCoordinates()
std::vector<int> getCoordinates(){
	
	std::vector<int> UC; // User Coordinates
	int x1, y1, x2, y2;
	
	// Get Start Coordinates
	std::cout << "Please enter Start Coordinates: ";
	std::cin >> x1 >> y1;
	UC.push_back(x1);
	UC.push_back(y1);
	
	// Check Validity
	if (!IsValid(30-y1, x1)){
		std::cout << "\nWrong Start Coordinates Entered!!!!\n";
		return getCoordinates();
	}
	
	// Get Goal Coordinates
	std::cout << "Please enter goal Coordinates: ";
	std::cin >> x2 >> y2;
	UC.push_back(x2);
	UC.push_back(y2);
	
	// Check Validity
	if (!IsValid(30-y2, x2)){
		std::cout << "\nWrong Goal Coordinates Entered!!!!\n";
		return getCoordinates();
	}
	
	return UC;
}


// Function 4: updateMaze()
std::vector<std::vector<char>> updateMaze(std::vector<int> SC){
	// SC: Coordinates expected in Script Format
	int x1, x2, y1, y2;
	x1 = SC[0];
	y1 = SC[1];
	x2 = SC[2];
	y2 = SC[3];
	
	maze[x1][y1] = 'S';
	maze[x2][y2] = 'G';
	return maze;
}


// Function 5: FindPath()

bool FindPath(std::vector<int> start, std::vector<int> goal)
{	// start and goal are expected in SC Coordinates
	int x{start[0]};
	int y{start[1]};
	
//	std::cout << x << " - " << y << " - " << goal[0] << " - " << goal[1] << std::endl;
	
	// Check coordinates for validity:
	if (!(IsValid(x, y)))
		return false;
	
	// Have we reached Goal?
    if(goal[0] == x && goal[1] == y) {
        return true;
    }
	
	// Mark each valid path point with a '+'
    maze[x][y] = '+';
	
	// Go north:
	start = {x-1,y};
    if(FindPath(start, goal))
        return true;
	
	// Go east:
	start = {x,y+1};
    if(FindPath(start, goal))
        return true;
	
	// Go south:
	start = {x+1,y};
    if(FindPath(start, goal))
        return true;
	
	// Go west:
	start = {x,y-1};
    if(FindPath(start, goal))
        return true;
	
	// Mark non-valid path as false:
    maze[x][y] = ' ';
    return false;
}
