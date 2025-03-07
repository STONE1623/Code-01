#ifndef _MAZE_H_
#define _MAZE_H

#include<iostream>
#include<ctime>
using namespace std;
extern int xStart;
extern int yStart; 
extern int xEnd;
extern int yEnd;
extern int flagSuccess;
void mazeGenerator(char** array, int length, int width);
void mazeTraverse(char** arr1, int** arr2, int length, int width, int x, int y);
void printMaze(char** arr1, int length, int width);
#endif