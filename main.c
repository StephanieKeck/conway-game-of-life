// Stephanie Keck
// CS 1412 003
// Project 1
// Main application logic.

#include "stdheader.h"
#include "framelist.h"
#include "frames.h"

int main(int argc, char ** argv) {

	// Read arguments from Std in
	char * inputPGM = argv[1];
	int numOfFrames = atoi(argv[2]);

	// Read PGM File.
	list seedFrame = readPGM(inputPGM);

	// Generate frames
	list frames = generateFrames(seedFrame, numOfFrames);

	// Add borders to frames
	frames = addBorders(frames);

	// Output frames to Std out
	generateOutput(frames);

}