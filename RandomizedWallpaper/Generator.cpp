//****************************************************
// File: Generator.cpp
//
// Purpose: Contains the functions which create 
//			various different wallpapers  depending 
//			on user input
//
// Written By: Vincent Cramer
//
// Compiler: Visual C++ 2015
//              
//****************************************************

#include "Generator.h"
#include <ctime>
#include <cstdlib>


//****************************************************
// Function: generatePixelWallpaper
//
// Purpose: Creates a wallpaper consisting of pixels
//			in a randomized color scheme. This function
//			generates 1-pixel sized squares.
//
//****************************************************
void generatePixelWallpaper(int width, int height, std::string name) {

	bitmap_image wallpaper(width,height);
	image_drawer drawer(wallpaper);

	int i = 0;
	int j = 0;

	srand(time(NULL));

	int red, green, blue;


	for (i = 0;i < width;i++) {
		for (j = 0;j < height;j++) {

			//*********************************
			//generates a rand int 0-255, 
			//including both 0 and 255
			//*********************************
			red = rand() % 256;
			green = rand() % 256;
			blue = rand() % 256;

			//sets pen color
			drawer.pen_color(red,green,blue);

			//used for drawing individual pixels.
			drawer.plot_pixel(i,j);
		}
	}	


	//saves wallpaper as designated name.
	wallpaper.save_image(name + ".bmp");
}



//****************************************************
// Function: generateGreyscaleWallpaper
//
// Purpose: Creates a wallpaper consisting of squares
//			roughly 1% of the screen area, in various
//			shades from white to black only.
//
//****************************************************
void generateGreyscaleWallpaper(int width, int height, std::string name) {

	bitmap_image wallpaper(width,height);
	image_drawer drawer(wallpaper);

	int i = 0;
	int j = 0;

	srand(time(NULL));

	int area = width*height;
	int squareArea = area / 100;
	int side = sqrt(squareArea);

	int colorValue;

	for (i = 0;i < width;i+=side) {
		for (j = 0;j < height;j+=side) {

			//***********************************
			//to make a color somewhere between 
			//white, grey, and black, you need 
			//to make all the RGB values the same
			//***********************************
			colorValue = rand() % 256;
			
			drawSquare(i, j, side, colorValue,colorValue,colorValue, drawer);

		}
	}

	wallpaper.save_image(name + ".bmp");
}

//****************************************************
// Function: generateGradientWallpaper
//
// Purpose: Creates a wallpaper consisting of squares
//			roughly 1% of the screen area. These 
//			squares have random, small changes in color
//			to them as they are generated. If a red,
//			blue, or green value from the change 
//			forces the value to make an invalid RGB
//			code, the value is "wrapped around"
//
//****************************************************
void generateGradientWallpaper(int width, int height, std::string name) {

	bitmap_image wallpaper(width,height);
	image_drawer drawer(wallpaper);

	int i = 0;
	int j = 0;

	srand(time(NULL));

	int red = rand() % 256;
	int green = rand() % 256;
	int blue = rand() % 256;

	int greenTemp = green;
	int redTemp = red;
	int blueTemp = blue;

	//*******************************
	//the below values are used in 
	//calculating the transition 
	//effect. Every time we change 
	//256 pixels in some direction, 
	//we force a change on some rgb 
	//value. 256 was chosen since 
	//it is the number of values for
	//each part of an rgb color code
	//*******************************
	int wallWidth = width/ 256;
	int wallHeight = height / 256; 
	

	//****************************
	//used to see which color 
	//changes in a row: 0 for 
	//green, 1 for blue, 2 for 
	//red. Also used to reset a 
	//chosen color upon completion
	//of a column
	//****************************
	int whoChanges = rand() % 3;
	
	
	//****************************
	//the values below determine 
	//what direction a value in 
	//the rgb code changes. For 
	//all of the values, if it is
	//0 it decreases, and if it 
	//is 1 it increases 
	//****************************
	int redChange = rand() % 2;
	int blueChange = rand() % 2;
	int greenChange = rand() % 2;

	for (i = 0;i < width;i++) {
		for (j = 0;j < height;j++) {

			if (j % wallHeight == 0) {
				
				if (whoChanges == 0) {
					if (greenChange == 0) {
						green--;
					}
					else {
						green++;
					}


					if (green < 0) {
						green = 255;
					}
					if (green > 255) {
						green = 0;
					}
				}
			
					else if (whoChanges == 1) {
						if (blueChange == 0) {
							blue--;
						}
						else {
							blue++;
						}


						if (blue < 0) {
							blue = 255;
						}
						if (blue > 255) {
							blue = 0;
						}
					}

					else {
						if (redChange==0) {
							red--;
						}
						else {
							red++;
						}

						if (red<0) {
							red = 255;
						}
						if (red>255) {
							red = 0;
						}
					}
			}

			drawer.pen_color(red, green, blue);

			drawer.plot_pixel(i, j);
		}

		if (whoChanges==0) {
			green = greenTemp;
		}
		else if (whoChanges==1) {
			blue = blueTemp;
		}
		else {
			red = redTemp;
		}

		
		if (i % wallWidth == 0) {
			
			if (whoChanges==0) {

				if (redChange == 0) {
					red--;
				}
				else {
					red++;
				}

				if (red < 0) {
					red = 255;
				}
				if (red > 255) {
					red = 0;
				}


				if (blueChange == 0) {
					blue--;
				}
				else {
					blue++;
				}

				if (blue < 0) {
					blue = 255;
				}
				if (blue > 255) {
					blue++;
				}
			}


			else if (whoChanges == 1) {

				if (greenChange == 0) {
					green--;
				}
				else {
					green++;
				}

				if (green < 0) {
					green = 255;
				}

				if (green > 255) {
					green = 0;
				}


				if (redChange == 0) {
					red--;
				}
				else {
					red++;
				}

				if (red < 0) {
					red = 255;
				}
				if (red > 255) {
					red++;
				}
			}


			else {

				if (greenChange == 0) {
					green--;
				}
				else {
					green++;
				}

				if (green < 0) {
					green = 255;
				}
				if (green > 255) {
					green = 0;
				}


				if (blueChange == 0) {
					blue--;
				}
				else {
					blue++;
				}

				if (blue < 0) {
					blue = 255;
				}
				if (blue > 255) {
					blue++;
				}
			}

		}
		
	}

	wallpaper.save_image(name + ".bmp");
}


//****************************************************
// Function: generateXColorsWallpaper
//
// Purpose: Creates a wallpaper consisting of squares
//			roughly 1% of the screen area of various
//			colors. The number of possible colors to
//			be randomly chosen is determined by user
//			before function call
//
//****************************************************
void generateXColorsWallpaper(int width, int height, int numColors, std::string name) {
	
	int *greenArr = new int[numColors];
	int *blueArr = new int[numColors];
	int *redArr = new int[numColors];



	bitmap_image wallpaper(width,height);
	image_drawer drawer(wallpaper);

	int i = 0;
	int j = 0;

	srand(time(NULL));

	int green, red, blue;


	//generates array of random color value
	for (int k = 0;k < numColors;k++) {

		red = rand() % 256;
		green = rand() % 256;
		blue = rand() % 256;
		greenArr[k] = green;
		redArr[k] = red;
		blueArr[k] = blue;
	}


	int area = width*height;
	int squareArea = area / 100;
	int side = sqrt(squareArea);

	int randNum;

	for (i = 0;i < width;i+=side) {
		for (j = 0;j < height;j+=side) {

			//picks 1 of the colors to use on this iteration
			randNum = rand() % numColors;

			drawSquare(i, j, side, redArr[randNum], greenArr[randNum], blueArr[randNum], drawer);

		}
	}

	wallpaper.save_image(name + ".bmp");
	

	delete[] greenArr;
	delete[] blueArr;
	delete[] redArr;
}

//****************************************************
// Function: generateMyColorsWallpaper
//
// Purpose: Creates a wallpaper consisting of squares
//			roughly 1% of the screen area. Colors are
//			chosen by user before function call
//
//****************************************************
void generateMyColorsWallpaper(int width, int height, int numColors, 
	int greenArr[], int blueArr[], int redArr[], std::string name) {

	bitmap_image wallpaper(width,height);
	image_drawer drawer(wallpaper);
	int i = 0;
	int j = 0;

	int area = width*height;
	int squareArea = area / 100;
	int side = sqrt(squareArea);

	srand(time(NULL));

	int randNum;

	for (i = 0;i < width;i+=side) {
		for (j = 0;j < height;j+=side) {

			randNum = rand() % numColors;

			drawSquare(i, j, side, redArr[randNum], greenArr[randNum], blueArr[randNum], drawer);


		}
	}

	wallpaper.save_image(name + ".bmp");

}


//****************************************************
// Function: generateLBlockWallpaper
//
// Purpose: Creates a wallpaper consisting of squares
//			roughly 1% of the screen area in an "L" 
//			pattern - 2 by 3 rectangles composed of 2
//			colors divided like so:
//				color1 - color1 
//				color1 - color2		
//				color2 - color2
//
//****************************************************
void generateLBlockWallpaper(int width, int height, std::string name) {

	bitmap_image wallpaper(width,height);
	image_drawer drawer(wallpaper);

	int i = 0;
	int j = 0;

	int area = width*height;
	int squareArea = area / 1000;
	int side = sqrt(squareArea);

	srand(time(NULL));

	int red1, red2, green1, green2, blue1, blue2;


	for (i = 0;i < width;i+=(2*side)) {
		for (j = 0;j < height;j+=(3*side)) {

			red1 = rand() % 256;
			green1 = rand() % 256;
			blue1 = rand() % 256;

		
			//below is used for drawing first L (left)
		
			//upper-left square
			drawSquare(i,j, side, red1, green1, blue1, drawer);

			//upper right square
			drawSquare(i+side, j, side, red1, green1, blue1, drawer);

			//middle left square
			drawSquare(i,j+side, side, red1, green1, blue1, drawer);

			

			red2 = rand() % 256;
			green2 = rand() % 256;
			blue2 = rand() % 256;


			//below is used for drawing second L (right)
			
			//middle-right
			drawSquare(i+side,j+side, side, red2, green2, blue2, drawer);

			
			//lower left
			drawSquare(i, j + (2*side), side, red2, green2, blue2, drawer);


			//lower right
			drawSquare(i + side, j + (2*side), side, red2, green2, blue2, drawer);

		}
	}

	wallpaper.save_image(name + ".bmp");
}

//****************************************************
// Function: generateScaledSquaresWallpaper
//
// Purpose: Creates a wallpaper consisting of squares
//			roughly 1% of the screen area. Colors are
//			chosen at random
//
//****************************************************
void generateScaledSquaresWallpaper(int width, int height, std::string name) {
	
	bitmap_image wallpaper(width,height);
	image_drawer drawer(wallpaper);
	
	int i = 0;
	int j = 0;

	srand(time(NULL));

	int area = width*height;
	int squareArea = area / 100;
	int side = sqrt(squareArea);

	int red, green, blue;

	for (i = 0;i < width;i+=side) {
		for (j = 0;j < height;j+=side) {

			red = rand() % 256;
			green = rand() % 256;
			blue = rand() % 256;

			drawSquare(i,j, side, red, green, blue, drawer);
		}
	}

	wallpaper.save_image(name + ".bmp");
}

//****************************************************
// Function: generatePuzzleWallpaper
//
// Purpose: Creates a wallpaper consisting of squares
//			roughly 1% of the screen area in an 
//			"puzzle" pattern - 3 by 3 squares composed
//			of 2 colors divided like so:
//				color1 - color1 - color2
//				color1 - color2 - color2
//				color1 - color1 - color2
//
//****************************************************
void generatePuzzleWallpaper(int width, int height, std::string name) {

	bitmap_image wallpaper(width,height);
	image_drawer drawer(wallpaper);

	int i = 0;
	int j = 0;

	int area = width*height;
	int squareArea = area / 1000;
	int side = sqrt(squareArea);

	int red1, blue1, green1, red2, blue2, green2;

	srand(time(NULL));

	for (i = 0;i < width;i+=(side*3)) {
		for (j = 0;j < height;j+=(side*3)) {

			red1 = rand() % 256;
			green1 = rand() % 256;
			blue1 = rand() % 256;

			//draws left C-block			

			//top part of C-block
			for (int k = i;k < i+(2*side);k+=side) {
				drawSquare(k, j, side, red1, blue1, green1, drawer);
			}

			//middle of C-block
			drawSquare(i, j+side, side, red1, blue1, green1, drawer);
			

			//bottom of C-block
			for (int k = i;k < i + (2 * side);k+=side) {
				drawSquare(k,j+(2*side), side, red1, blue1, green1, drawer);
			}


			//perpindicular block

			//perpindicular block colors
			red2 = rand() % 256;
			green2 = rand() % 256;
			blue2 = rand() % 256;

			//draws upper-right block in perpindicular block
			drawSquare(i+(2*side), j, side, red2, blue2, green2, drawer);

			//draws middle line in perpindicular block
			for (int k = 1;k <= 2;k++) {
				drawSquare(i + (k * side), j+side, side, red2, blue2, green2, drawer);
			}

			//draws bottom-right block in perpindicular block
			drawSquare(i + (2 * side), j + (2*side), side, red2, blue2, green2, drawer);

		}
	}

	wallpaper.save_image(name + ".bmp");
}


//****************************************************
// Function: generateCornerOutWallpaper
//
// Purpose: Creates a wallpaper consisting of squares
//			roughly 1% of the screen area with colors 
//			chosen at random, and divided up by 
//			quadrant of the screen. Starts with 4 
//			colors, 1 per corner, and randomly changes
//			as it generates image. If any change to 
//			an RGB value would make it invalid, it 
//			changes back to its original value. Ex: if 
//			increasing red from 255 to 256, it would
//			keep red at 255.
//
//****************************************************
void generateCornerOutWallpaper(int width, int height, std::string name) {

	bitmap_image wallpaper(width,height);
	image_drawer drawer(wallpaper);

	int i = 0;
	int j = 0;

	int choice, direction;

	srand(time(NULL));

	int red1 = rand() % 256;
	int green1 = rand() % 256;
	int blue1 = rand() % 256;

	int red2 = rand() % 256;
	int green2 = rand() % 256;
	int blue2 = rand() % 256;

	int red3 = rand() % 256;
	int green3 = rand() % 256;
	int blue3 = rand() % 256;

	int red4 = rand() % 256;
	int green4 = rand() % 256;
	int blue4 = rand() % 256;

	int halfWidth = width / 2;
	int halfHeight = height / 2;
	
	

	//sets pen color
	drawer.pen_color(red1, green1, blue1);

	//quadrant 1
	for (i = 0;i < halfWidth;i++) {
		for (j = 0;j < halfHeight;j++) {
			
			//****************************************
			//if choice is 0, red is chosen to change.
			//if choice is 1, blue is chosen, and if
			//choice is 2, green changes.
			//****************************************
			choice = rand() % 3;

			//****************************************
			//if direction of change is 0, then the 
			//chosen value does not change. if 
			//direction is 1, then it decreases by 1,
			//and if it is 2, it increases by 1.
			//****************************************
			direction = rand() % 3;

			drawer.plot_pixel(i, j);

			if (choice==0) {
				if (direction==1) {
					red1--;
				}
				else if (direction==2) {
					red1++;
				}
			}
			else if (choice==1) {
				if (direction==1) {
					blue1++;
				}
				else if (direction==2) {
					blue1--;
				}
			}
			else {
				if (direction==1) {
					green1++;
				}
				else if (direction==2) {
					green1--;
				}
			}

			//****************************************
			//if color would exceed boundaries of RGB,
			//the color value doesn't change
			//****************************************
			if (green1>255) {
				green1 = 255;
			}
			if (green1<0) {
				green1 = 0;
			}
			if (red1>255) {
				red1 = 255;
			}
			if (red1<0) {
				red1 = 0;
			}
			if (blue1>255) {
				blue1 = 255;
			}
			if (blue1<0) {
				blue1 = 0;
			}

			drawer.pen_color(red1, green1, blue1);


		}
	}

	
	drawer.pen_color(red2, green2, blue2);

	//quadrant 2
	for (i = halfWidth;i < width;i++) {
		for (j = 0; j < halfHeight;j++) {
			
			//****************************************
			//if choice is 0, red is chosen to change.
			//if choice is 1, blue is chosen, and if
			//choice is 2, green changes.
			//****************************************
			choice = rand() % 3;

			//****************************************
			//if direction of change is 0, then the 
			//chosen value does not change. if 
			//direction is 1, then it decreases by 1,
			//and if it is 2, it increases by 1.
			//****************************************
			direction = rand() % 3;

			drawer.plot_pixel(i, j);

			if (choice==0) {

				if (direction==1) {
					red2--;
				}

			else if (direction==2) {
				red2++;
				}

			}

			else if (choice==1) {

				if (direction==1) {
					blue2++;
				}

				else if (direction==2) {
					blue2--;
				}

			}

			else {
				
				if (direction==1) {
					green2++;
				}

				else if (direction==2) {
					green2--;
				}

			}

			//****************************************
			//if color would exceed boundaries of RGB,
			//the color value doesn't change
			//****************************************
			if (green2>255) {
				green2 = 255;
			}
			if (green2<0) {
				green2 = 0;
			}
			if (red2>255) {
				red2 = 255;
			}
			if (red2<0) {
				red2 = 0;
			}
			if (blue2>255) {
				blue2 = 255;
			}
			if (blue2<0) {
				blue2 = 0;
			}

			drawer.pen_color(red2, green2, blue2);
			


		}
	}

	drawer.pen_color(red3, green3, blue3);

	//quadrant 3
	for (i = 0;i < halfWidth;i++) {
		for (j = halfHeight;j < height;j++) {
			
			//****************************************
			//if choice is 0, red is chosen to change.
			//if choice is 1, blue is chosen, and if
			//choice is 2, green changes.
			//****************************************
			choice = rand() % 3;

			//****************************************
			//if direction of change is 0, then the 
			//chosen value does not change. if 
			//direction is 1, then it decreases by 1,
			//and if it is 2, it increases by 1.
			//****************************************
			direction = rand() % 3;

			drawer.plot_pixel(i, j);

			if (choice==0) {
				
				if (direction==1) {
					red3--;
				}

				else if (direction==2) {
					red3++;
				}

			}
			else if (choice==1) {
				if (direction==1) {
					blue3++;
				}
				else if (direction==2) {
					blue3--;
				}
			}
			else {
				if (direction==1) {
					green3++;
				}
				else if (direction==2) {
					green3--;
				}
			}

			//****************************************
			//if color would exceed boundaries of RGB,
			//the color value doesn't change
			//****************************************
			if (green3>255) {
				green3 = 255;
			}
			if (green3<0) {
				green3 = 0;
			}
			if (red3>255) {
				red3 = 255;
			}
			if (red3<0) {
				red3 = 0;
			}
			if (blue3>255) {
				blue3 = 255;
			}
			if (blue3<0) {
				blue3 = 0;
			}

			drawer.pen_color(red3, green3, blue3);
		}
	}

	drawer.pen_color(red4, green4, blue4);

	//quadrant 4
	for (i = halfWidth;i < width;i++) {
		for (j = halfHeight;j < height;j++) {

			//****************************************
			//if choice is 0, red is chosen to change.
			//if choice is 1, blue is chosen, and if
			//choice is 2, green changes.
			//****************************************
			choice = rand() % 3;


			//****************************************
			//if direction of change is 0, then the 
			//chosen value does not change. if 
			//direction is 1, then it decreases by 1,
			//and if it is 2, it increases by 1.
			//****************************************
			direction = rand() % 3;

			drawer.plot_pixel(i, j);

			if (choice==0) {
				if (direction==1) {
					red4--;
				}
				else if (direction==2) {
					red4++;
				}
			}

			else if (choice==1) {
				if (direction==1) {
					blue4++;
				}
				else if (direction==2) {
					blue4--;
				}
			}

			else {
				if (direction==1) {
					green4++;
				}
				else if (direction==2) {
					green4--;
				}
			}

			//****************************************
			//if color would exceed boundaries of RGB,
			//the color value doesn't change
			//****************************************
			if (green4>255) {
				green4 = 255;
			}
			if (green4<0) {
				green4 = 0;
			}
			if (red4>255) {
				red4 = 255;
			}
			if (red4<0) {
				red4 = 0;
			}
			if (blue4>255) {
				blue4 = 255;
			}
			if (blue4<0) {
				blue4 = 0;
			}

			drawer.pen_color(red4, green4, blue4);
		}
	}

	wallpaper.save_image(name + ".bmp");
}

//****************************************************
// Function: generateCircleCoveredWallpaper
//
// Purpose: Creates a wallpaper consisting of circles
//			on a black background of various colors.
//			Radius is uniform across all circles
//
//****************************************************
void generateCircleCoveredWallpaper(int width, int height, std::string name) {

	bitmap_image wallpaper(width,height);
	image_drawer drawer(wallpaper);

	int i = 0;
	int j = 0;

	

	srand(time(NULL));

	int radius = (rand()%100)+5;

	for (i = 0;i < width;i+=radius/2) {
		for (j = 0;j < height;j+=radius/2) {

			int red = rand() % 256;
			int green = rand() % 256;
			int blue = rand() % 256;

			drawer.pen_color(red, green, blue);

			drawer.circle(i,j,radius);
			
		}
	}

	wallpaper.save_image(name + ".bmp");
}

//****************************************************
// Function: generateTriangleWallpaper
//
// Purpose: Creates a wallpaper consisting of 
//			triangles
//			on a black background of various size and
//			colors, and random positions.
//
//****************************************************
void generateTriangleWallpaper(int width, int height, std::string name) {

	bitmap_image wallpaper(width,height);
	image_drawer drawer(wallpaper);

	int i = 0;

	srand(time(NULL));

	int numTriangles = rand() % ((width+height)/2);

	for (i = 0;i < numTriangles;i++) {

		//random colors
		int red = rand() % 256;
		int green = rand() % 256;
		int blue = rand() % 256;

		//random x coordinates
		int x1 = rand() % width;
		int x2 = rand() % width;
		int x3 = rand() % width;

		//random y coordinates
		int y1 = rand() % height;
		int y2 = rand() % height;
		int y3 = rand() % height;

		drawer.pen_color(red, green, blue);
		drawer.triangle(x1, y1, x2, y2, x3, y3);
	}



	wallpaper.save_image(name + ".bmp");
}


//****************************************************
// Function: generateBreakoutWallpaper
//
// Purpose: Creates a wallpaper reminiscient of 
//			Breakout - 6 randomly colored bars 
//			approximately a third down the screen, and
//			a random position for the white paddle and
//			white ball
//
//****************************************************
void generateBreakoutWallpaper(int width, int height, std::string name) {

	bitmap_image wallpaper(width,height);
	image_drawer drawer(wallpaper);

	int i = 0;
	int j = 0;

	int area = width*height;
	int squareArea = area / 1000;
	int side = sqrt(squareArea);

	srand(time(NULL));
	
	int red = rand() % 256;
	int green = rand() % 256;
	int blue = rand() % 256;

	int barsHeight = side * 6;
	int thirdOfHeight = height / 3;

	int startBars = thirdOfHeight - barsHeight;

	//draws bars
	for (i = startBars;i < barsHeight+startBars; i += side) {
		for (j = 0;j < width; j += side) {
			drawSquare(j, i, side, red,green,blue, drawer);
			}
		red = rand() % 256;
		green = rand() % 256;
		blue = rand() % 256;
	}
	
	int paddleStartY = height*.9-side;
		
	int paddleLength = side * 6;

	int paddleStartX = rand() % (width-paddleLength);
		
		

	//draws white paddle
	for (int k = paddleStartX;k < paddleStartX+paddleLength;k++) {
		drawSquare(k, paddleStartY, side, 255, 255, 255, drawer);
	}
		
	//generates random coordinates for ball
	int ballStartX = rand() % width;
	int ballStartY = rand() % height;

	//********************************************
	//if ball coordinates are between the bars or 
	//within the paddle, fix them
	//********************************************
	if (ballStartY<barsHeight+startBars) {
		ballStartY += barsHeight + startBars;
	}

	if (ballStartY>paddleStartY) {
		ballStartY -= side;
	}

	//draws white ball
	drawSquare(ballStartX, ballStartY, side, 255, 255, 255, drawer);
		
	wallpaper.save_image(name + ".bmp");
}

//****************************************************
// Function: drawSquare
//
// Purpose: Creates a square at the given coordinates
//			with the given drawer, using the given
//			colors
//
//****************************************************
void drawSquare(int x, int y, int side, int red, int green, int blue, image_drawer& drawer) {
	drawer.pen_color(red, green, blue);

	for (int i = y;i < y + side;i++) {
		for (int j = x;j < x + side;j++) {
			drawer.plot_pixel(j, i);
		}
	}
}




//****************************************************
// Function: generateLinePatternWallpaper
//
// Purpose: Creates a wallpaper consisting of random 
//			horizontal and vertical colors, whose 
//			length increased at the image generation 
//			moved away from the upper left corner. 
//			Example:
//				color1 - color2 - color4
//				color3 - color3 - color4
//				color5 - color5 - color5 ...
//
//****************************************************
void generateLinePatternWallpaper(int width, int height, std::string name) {

	bitmap_image wallpaper(width,height);
	image_drawer drawer(wallpaper);
	int i = 0;
	int j = 0;

	int area = width*height;
	int squareArea = area / 100;
	int side = sqrt(squareArea);

	srand(time(NULL));

	
	int red, blue, green;

	red = rand() % 256;
	green = rand() % 256;
	blue = rand() % 256;

	//draw 1st upper left square
	drawSquare(i, j, side, red, blue, green, drawer);

	//change colors from original upper left corner
	red = rand() % 256;
	green = rand() % 256;
	blue = rand() % 256;

	//draw hoirzontal squares
	for (i = side;i < width;i+=side) {
		for (j = 0;j < i;j+=side) {
			
			drawSquare(i,j,side,red,blue,green,drawer);
		}
		red = rand() % 256;
		green = rand() % 256;
		blue = rand() % 256;
	}
	
	//draw vertical squares
	for (i = side;i < height;i+=side) {
		for (j = 0;j <= i;j+=side) {
			drawSquare(j, i, side, red, blue, green, drawer);
		}

		red = rand() % 256;
		green = rand() % 256;
		blue = rand() % 256;
	}
	
	wallpaper.save_image(name + ".bmp");
}

//****************************************************
// Function: generateSymmetricalWallpaper
//
// Purpose: Creates a wallpaper consisting of random 
//			squares with reflective symmetry.
//
//****************************************************
void generateSymmetricalWallpaper(int width, int height, std::string name) {
	bitmap_image wallpaper(width, height);
	image_drawer drawer(wallpaper);

	int i = 0;
	int j = 0;

	int area = width*height;
	int squareArea = area / 100;
	int side = sqrt(squareArea);


	srand(time(NULL));

	int red, green, blue;

	//****************************************************
	//since we're having the left and right half be 
	//equivalent, we only need to generate half the number
	//of colored squares per row.
	//****************************************************
	for (i = 0;i < height;i += side) {
		for (j = 0;j < width/2;j += side) {

			red = rand() % 256;
			green = rand() % 256;
			blue = rand() % 256;

			
			drawSquare(j,i, side, red, green, blue, drawer);
			drawSquare(width-(j+side), i, side, red, green, blue, drawer);
		}
	}

	//saves wallpaper as designated name.
	wallpaper.save_image(name + ".bmp");

}

//****************************************************
// Function: generateGridWallpaper
//
// Purpose: Creates a wallpaper consisting of random 
//			squares with black grid lines roughly 
//			1/10 as wide and long as the squares
//
//****************************************************
void generateGridWallpaper(int width, int height, std::string name) {

	bitmap_image wallpaper(width, height);
	image_drawer drawer(wallpaper);

	int i = 0;
	int j = 0;

	srand(time(NULL));

	int area = width*height;
	int squareArea = area / 100;
	int side = sqrt(squareArea);

	int red, green, blue;

	for (i = 0;i < width;i += side) {
		for (j = 0;j < height;j += side) {

			red = rand() % 256;
			green = rand() % 256;
			blue = rand() % 256;

			drawSquare(i, j, side, red, green, blue, drawer);
		}
	}



	//vertical grid lines
	for (i = 0;i < width;i+=side) {
		for (j = 0;j < height;j++) {

			drawSquare(i, j, side/10, 0,0,0, drawer);

		}
	}

	//final vertical line
	i = width - side/20;
	for (j = 0;j < height;j++) {
		drawSquare(i, j, side / 10, 0, 0, 0, drawer);

	}

	
	//horizontal lines
	for (i = 0;i < height + (side / 10);i+=side) {
		for (j = 0;j <= width+(side/10);j++) {
			drawSquare(j, i, side / 10, 0, 0, 0, drawer);
		}
	}

	//final horizontal line
	i = height - side / 20;
	for (j = 0;j < width;j++) {
		drawSquare(j, i, side / 10, 0, 0, 0, drawer);

	}


	//saves image
	wallpaper.save_image(name + ".bmp");
}













