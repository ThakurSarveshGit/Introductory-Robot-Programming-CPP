/***
 * Introduction To Robot Programming - ENPM809Y
 * Assignment One: Implementation - Arrays and Vectors
 * 
 * @author Sarvesh Thakur
 * @version 1.0
 * Date: 9/17/2019
 * 
 * @section LICENSE
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 * 
 * @section DESCRIPTION
 * 
 * Final Vectors should look like:
 * [ blue white green]
 * [ white green white]
 * [ green blue white]
 * 
 * The user is given six out of the nine colors: and must input
 * the remaining colors: green, white, and blue.
 * 
*/

#include <iostream>
#include <array>
#include <vector>


/**
* @brief An exercise in creating and using arrays and vectors.
* @author Sarvesh Thakur
* @param 2D array (3 rows, 2 columns)
* @param 3 vectors for storing 2D array
* @param peg1 - variable for missing peg
* @param peg2 - variable for missing peg
* @param peg3 - variable for missing peg
* @param 2D vector (3 rows, 3 columns)
* @return Display the nine pegs in the tray
*/


int main(int argc, char **argv)
{

	// 1. Create a 2D array of std::string with 3 rows and 2 cols
	// 2. Initialize the array to have the following elements
	std::string tray[3][2]{{"blue", "white"}, {"green", "white"}, {"green","white"}};
	
	// 3. Create 3 std::string vectors (color_vec1, color_vec2, and
	// color_vec3), each representing a row of pegs
	
	// 4. Read the 2D array and store values of each row in a vector
	// 		- color_vec1: First row of the array
	// 		- color_vec2: Second row of the array
	// 		- color_vec3: Third row of the array
	
	std::vector<std::string> color_vec1{tray[0][0], tray[0][1]};
	std::vector<std::string> color_vec2{tray[1][0], tray[1][1]};
	std::vector<std::string> color_vec3{tray[2][0], tray[2][1]};
	
	// 5. Prompt the user to enter the color for the missing peg using the picture of the tray
	//	- Only 1 cout: The user should enter the three colors on the same
	//	  line
	//	- The user should enter: green white blue
	
	std::string peg1;
	std::string peg2;
	std::string peg3;
	
	std::cout << "Please enter color for 3 pegs: ";
	std::cin >> peg1 >> peg2 >> peg3;
	
	// 6. Appropriately insert the first, second, and third input in
	// 	  color_vec1, color_vec2, and color_vec3, at 3rd, 1st and 2nd pos
	// 	  respectively
	
	color_vec1.insert(color_vec1.begin() + 2, peg1);
	color_vec2.insert(color_vec2.begin(), peg2);
	color_vec3.insert(color_vec3.begin() + 1, peg3);
	
	
	// 7. Display the elements of each vector in the console
	
	std::cout << color_vec1.at(0) << "\t" << color_vec1.at(1) << "\t" << color_vec1.at(2) << std::endl;
	std::cout << color_vec2.at(0) << "\t" << color_vec2.at(1) << "\t" << color_vec2.at(2) << std::endl;
	std::cout << color_vec3.at(0) << "\t" << color_vec3.at(1) << "\t" << color_vec3.at(2) << std::endl;	
	
	std::cout << "\n--------------- 2D Vector ------------------ \n" << std::endl;
	
	// 8. Create a 2D vector (3 rows and 3 columns) of std::string
	// 	  named color_vec_2d
	// 9. Use color_vec1, color_vec2, and color_vec3 to build color_vec_2d
	
	std::vector<std::vector<std::string> > color_vec_2d {
		{color_vec1.at(0), color_vec1.at(1), color_vec1.at(2)},
		{color_vec2.at(0), color_vec2.at(1), color_vec2.at(2)},
		{color_vec3.at(0), color_vec3.at(1), color_vec3.at(2)}
	};
	
	// 10. Display size of color_vec_2d
	std::cout << "\nSize: " << color_vec_2d.size() << " x " << color_vec_2d[0].size() << "\n" << std::endl;
	
	// 11. Display color_vec_2d in console.
	for (unsigned int i=0; i<color_vec_2d.size(); i++){
		for (unsigned int j=0; j<color_vec_2d.size(); j++){
			std::cout << color_vec_2d[i][j] << "\t";
		}
			std::cout << "\n";
	}
	
	
	return 0;
}