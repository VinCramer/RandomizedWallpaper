//****************************************************
// File: Main.cpp
//
// Purpose: Run the RandomizedWallpaer program
//
// Written By: Vincent Cramer
//
// Compiler: Visual C++ 2015
//              
//****************************************************



#include <iostream>
#include <limits>
#include "Generator.h"



//****************************************************
// Function: showMenu
//
// Purpose: Displays a menu with all of the options
//			for the user to the standard output
//
//****************************************************
void showMenu() {
	//menu for user options showing different wallpaper options
	std::cout << "Menu:" << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;
	std::cout << "1. Completely randomized pixels wallpaper" << std::endl;
	std::cout << "2. Black and white squares wallpaper" << std::endl;
	std::cout << "3. Gradient tiles wallpaper" << std::endl;
	std::cout << "4. Proportional squares wallpaper" << std::endl;
	std::cout << "5. Only some colors wallpaper" << std::endl;
	std::cout << "6. Pick your own colors wallpaper" << std::endl;
	std::cout << "7. L-block wallpaper" << std::endl;
	std::cout << "8. Puzzle piece wallpaper" << std::endl;
	std::cout << "9. Quadrant variance wallpaper" << std::endl;
	std::cout << "10. Circle covered wallpaper" << std::endl;
	std::cout << "11. Randomized triangles wallpaper" << std::endl;
	std::cout << "12. Randomized Breakout/Brick Breaker wallpaper" << std::endl;
	std::cout << "13. Line pattern wallpaper" << std::endl;
	std::cout << "14. Symmetrical wallpaper" << std::endl;
	std::cout << "15. Grid wallpaper" << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;
	std::cout << "" << std::endl;
	std::cout << "Enter your choice: ";
}

int main() {
	int width=-1,height=-1,numColors, i=0, redVal, blueVal, greenVal, choice=-1;
	bool running = true;
	std::string name, redo;
	int numWallpapers = 0;
	bool valid;
	
	do {
		//reset potential validity of input
		valid = true;
		
		std::cout << "Enter the desired width (in pixels) of the wallpaper:" << std::endl;
		std::cin >> width;
		
		//checks for invalid input
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid entry for width of screen. Must be positive integer." << std::endl;
			valid = false;
		}
		
		std::cout << "" << std::endl;

		if (valid) {
			std::cout << "Enter the desired height (in pixels) of the wallpaper:" << std::endl;
			std::cin >> height;

			//checks for invalid input
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Invalid entry for height of screen. Must be positive integer." << std::endl;
				valid = false;
			}
		}
		std::cout << "" << std::endl;

		if (valid) {
			std::cout << "Enter the name of the wallpaper:" << std::endl;
			std::cin >> name;

			std::cout << "" << std::endl;

			showMenu();



			std::cin >> choice;
			std::cout << "" << std::endl;
			//checks for invalid input
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Invalid entry for wallpaper choice. Must be positive integer." << std::endl;
				choice = -1;
			}

		}

		if (valid) {

			switch (choice) {

			case 1:
				generatePixelWallpaper(width, height, name);
				numWallpapers++;
				break;

			case 2:
				generateGreyscaleWallpaper(width, height, name);
				numWallpapers++;
				break;

			case 3:
				generateGradientWallpaper(width, height, name);
				numWallpapers++;
				break;

			case 4:
				generateScaledSquaresWallpaper(width, height, name);
				numWallpapers++;
				break;

			case 5:

				//prompts user for number of randomly chosen colors
				std::cout << "Enter number of colors:" << std::endl;
				std::cin >> numColors;

				if (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "Invalid entry for number of colors. Must be positive integer." << std::endl;			
				}
				else {
					generateXColorsWallpaper(width, height, numColors, name);
					numWallpapers++;
				}
				break;

			case 6:
				//prompts user to select their colors for the wallpaper
			{
				std::cout << "Enter number of colors:" << std::endl;
				std::cin >> numColors;

				if (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "Invalid number of colors. Must be positive integer" << std::endl;
				}

				else {
					int *greenArr = new int[numColors];
					int *blueArr = new int[numColors];
					int *redArr = new int[numColors];

					for (i = 0;i < numColors;i++) {

						if (valid) {
							std::cout << "Enter red value of color number " << i << " :" << std::endl;
							std::cin >> redVal;
							if (std::cin.fail()||redVal<0||redVal>255) {
								std::cin.clear();
								std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
								std::cout << "Invalid red color. Must be positive integer 0-255." << std::endl;
								valid = false;
							}
							else {
								redArr[i] = redVal;
							}

						}

						if (valid) {
							std::cout << "Enter green value of color number " << i << " :" << std::endl;
							std::cin >> greenVal;
							if (std::cin.fail()||greenVal<0||greenVal>255) {
								std::cin.clear();
								std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
								std::cout << "Invalid green color. Must be positive integer 0-255." << std::endl;
								valid = false;
							}
							
							else {
								greenArr[i] = greenVal;
							}

						}

						if (valid) {
							std::cout << "Enter blue value of color number " << i << " :" << std::endl;
							std::cin >> blueVal;
							if (std::cin.fail()||blueVal<0||blueVal>255) {
								std::cin.clear();
								std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
								std::cout << "Invalid blue color. Must be positive integer 0-255." << std::endl;
								valid = false;
							}
							else {
								blueArr[i] = blueVal;
							}
						}
					}

					if (valid) {
						generateMyColorsWallpaper(width, height, numColors, greenArr, blueArr, redArr, name);
					}

					delete[] greenArr;
					delete[] blueArr;
					delete[] redArr;
					if (valid) {
						numWallpapers++;
					}
				}
				break;
			}

			case 7:
				generateLBlockWallpaper(width, height, name);
				numWallpapers++;
				break;

			case 8:
				generatePuzzleWallpaper(width, height, name);
				numWallpapers++;
				break;

			case 9:
				generateCornerOutWallpaper(width, height, name);
				numWallpapers++;
				break;

			case 10:
				generateCircleCoveredWallpaper(width, height, name);
				numWallpapers++;
				break;

			case 11:
				generateTriangleWallpaper(width, height, name);
				numWallpapers++;
				break;

			case 12:
				generateBreakoutWallpaper(width, height, name);
				numWallpapers++;
				break;

			case 13:
				generateLinePatternWallpaper(width, height, name);
				numWallpapers++;
				break;

			case 14:
				generateSymmetricalWallpaper(width,height,name);
				numWallpapers++;
				break;

			case 15:
				generateGridWallpaper(width,height,name);
				numWallpapers++;
				break;

			default:
				std::cout << "Invalid input. No wallpaper made." << std::endl;
				break;
			}

		}

		
		

		//prompts user for making another wallpaper
		do {
			std::cout << "Do you want to make another wallpaper? Enter \"N\" to stop, or \"Y\" to continue." << std::endl;
			std::cin >> redo;
			std::cout << "" << std::endl;

			if (redo == "N" || redo == "n") {
				running = false;
				break;
			}
			if (redo == "Y" || redo == "y") {
				running = true;
				break;
			}
		} while (true);
		
		

	} while (running);

	//congratulates user on their freshly made wallpaper(s), or shames them for not making any
	if (numWallpapers==1) {
		std::cout << "Enjoy the wallpaper!" << std::endl;
	}
	else if (numWallpapers==0) {
		std::cout << "Sorry you decided not to make any wallpapers today." << std::endl;
	}
	else {
		std::cout << "Enjoy the " << numWallpapers << " wallpapers!" << std::endl;
	}


	return 0;
}












