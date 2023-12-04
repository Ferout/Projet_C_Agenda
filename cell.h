//
// Created by esteb on 13/11/2023.
//

#ifndef UNTITLED4_CELL_H
#define UNTITLED4_CELL_H

// Definition of the cell structure
typedef struct Cell {
    int value;           // Value of the cell
    int numLevels;       // Number of levels in the cell
    struct Cell* levels[]; // Array of pointers to cells at different levels
} Cell;

// Function to create a cell
Cell* createCell(int value, int numLevels);



#endif //UNTITLED4_CELL_H
