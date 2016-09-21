// Stephanie Keck
// CS 1412 003
// Project 1
// Implementation of PGM analyzing and frame generating logic.

#include "stdheader.h"
#include "framelist.h"
#include "frames.h"

list readPGM(char * filename) {
	int columns;
	int rows;
	frame seed;

	char check[3];

	FILE * pgm = fopen(filename, "r");

	fscanf(pgm, "%s", check);

	if (strcmp(check, "P2") != 0) {
		return NULL;
	}

	fscanf(pgm, "%d %d", &columns, &rows);
	fscanf(pgm, "%*d", NULL);

	seed = (frame) malloc(sizeof(char*) * rows);
	for (int i = 0; i < rows; i++) {
		seed[i] = (char*) malloc(sizeof(char) * columns);
	}

	char * scannedValue;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			fscanf(pgm, "%s", scannedValue);
			if (strcmp(scannedValue, "0") != 0) {
				seed[i][j] = 'X';
			} else {
				seed[i][j] = 'O';
			}
		}
	}

	fclose(pgm);

	list L = newList();
	L->columns = columns;
	L->rows = rows;
	append(L, seed);

	return L;
}

list generateFrames(list L, int frameNum) {
	frame f = L->head->f;
	frame nextFrame;
	for (int i = 0; i < frameNum; i++) {
		nextFrame = generateNextFrame(f, L->columns, L->rows);
		append(L, nextFrame);
		f = L->tail->f;
	}

	return L;
}

frame generateNextFrame(frame f, int columns, int rows) {
	frame newFrame = (frame) malloc(sizeof(char*) * rows);
	for (int i = 0; i < rows; i++) {
		newFrame[i] = (char*) malloc(sizeof(char) * columns);
	}

	int neighbors;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			neighbors = calcLiveNeighbors(f, i, j, rows, columns);
			if (f[i][j] == 'X') {
				if (neighbors < 2) {
					newFrame[i][j] = 'O';
				} else if (neighbors < 4) {
					newFrame[i][j] = 'X';
				} else {
					newFrame[i][j] = 'O';
				}
			} else {
				if (neighbors == 3) {
					newFrame[i][j] = 'X';
				} else {
					newFrame[i][j] = 'O';
				}
			}
			// printf("%d,%d: %c  ", i, j, newFrame[i][j]);
		}
		// printf("\n");
	}
	// printf("\n");

	return newFrame;
}

int calcLiveNeighbors(frame f, int row, int column, int rows, int columns) {
	int liveNeighbors = 0;

	int spaceAbove = row > 0;
	int spaceBelow = rows-1 > row;
	int spaceLeft = column > 0;
	int spaceRight = columns-1 > column;

	if (spaceAbove && f[row-1][column] == 'X') liveNeighbors++;
	if (spaceBelow && f[row+1][column] == 'X') liveNeighbors++;
	if (spaceLeft && f[row][column-1] == 'X') liveNeighbors++;
	if (spaceRight && f[row][column+1] == 'X') liveNeighbors++;

	if (spaceAbove && spaceRight && f[row-1][column+1] == 'X') liveNeighbors++;
	if (spaceAbove && spaceLeft && f[row-1][column-1] == 'X') liveNeighbors++;
	if (spaceBelow && spaceRight && f[row+1][column+1] == 'X') liveNeighbors++;
	if (spaceBelow && spaceLeft && f[row+1][column-1] == 'X') liveNeighbors++;

	return liveNeighbors;
}

list addBorders(list L) {
	node n = L->head;
	while (n != NULL) {
		n->f = addBorderToFrame(n->f, L->rows, L->columns);
		n = n->next;
	}

	return L;
}

frame addBorderToFrame(frame f, int rows, int columns) {
	frame borderedFrame = (frame) malloc(sizeof(char*)*(rows+2));
	for (int i = 0; i < rows + 2; i++) {
		borderedFrame[i] = (char*) malloc(sizeof(char)*(columns + 2));

		for (int j = 0; j < columns+2; j++) {
			borderedFrame[i][j] = 'O';
		}
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			borderedFrame[i+1][j+1] = f[i][j];
		}
	}

	for (int i = 0; i < rows; i++) {
		free(f[i]);
	}
	free(f);

	return borderedFrame;
}

void generateOutput(list L) {
	int index = 0;
	node n = L->head;
	while (n != NULL) {
		printOutputForFrame(n->f, index, L->rows, L->columns);
		n = n->next;
		index++;
	}
}

void printOutputForFrame(frame f, int index, int rows, int columns) {
	if (index == 0) {
		printf("Seed: %d %d\n", rows, columns);
	} else {
		printf("Frame: %d\n", index);
	}

	for (int i = 0; i < rows+2; i++) {
		for (int j = 0; j < columns+2; j ++) {
			printf("%c ", f[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}