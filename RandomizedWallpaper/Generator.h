//****************************************************
// File: Generator.h
//
// Purpose: Contains the function headers for the 
//			randomized wallpaper generator.
//
// Written By: Vincent Cramer
//
// Compiler: Visual C++ 2015
//              
//****************************************************


#include <string>
#include "bitmap_image.hpp"

void drawSquare(int x, int y, int side, int red, int green, int blue, image_drawer& drawer);

void generateLinePatternWallpaper(int width, int height, std::string name);

void generatePixelWallpaper(int width, int height, std::string name);

void generateGradientWallpaper(int width, int height, std::string name);

void generateGreyscaleWallpaper(int width, int height, std::string name);

void generateXColorsWallpaper(int width, int height, int numColors, std::string name);

void generateMyColorsWallpaper(int width, int height, int numColors, int greenArr[], int blueArr[], int redArr[], std::string name);

void generateLBlockWallpaper(int width, int height, std::string name);

void generateScaledSquaresWallpaper(int width, int height, std::string name);

void generatePuzzleWallpaper(int width, int height, std::string name);

void generateCornerOutWallpaper(int width, int height, std::string name);

void generateCircleCoveredWallpaper(int width, int height, std::string name);

void generateTriangleWallpaper(int width, int height, std::string name);

void generateBreakoutWallpaper(int width, int height, std::string name);

void generateSymmetricalWallpaper(int width, int height, std::string name);

void generateGridWallpaper(int width, int height, std::string name);