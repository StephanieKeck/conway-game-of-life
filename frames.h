// Stephanie Keck
// CS 1412 003
// Project 1
// Header file for frame generating logic.

#ifndef ___Frames_H___
#define ___Frames_H___

#include "stdheader.h"
#include "framelist.h"

list readPGM(char *);
list generateFrames(list, int);
frame generateNextFrame(frame, int, int);
int calcLiveNeighbors(frame, int, int, int, int);
list addBorders(list);
frame addBorderToFrame(frame, int, int);
void generateOutput(list);
void printOutputForFrame(frame, int, int, int);

#endif