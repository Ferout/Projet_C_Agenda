//
// Created by esteb on 13/11/2023.
//

#ifndef UNTITLED4_LIST_H
#define UNTITLED4_LIST_H

#include "cell.h"

// Definition of the list structure
typedef struct List {
    int maxLevels;  // Maximum number of levels in the list
    Cell* head;     // Head of the list
} List;

// Function to create an empty list with the given maximum number of levels
List* createList(int maxLevels);

// Function to insert a cell with levels at the beginning of the list
void insertCellAtHead(List* list, Cell* cell);

// Function to display all cells at a specific level in the list
void displayCellsAtLevel(List* list, int level);

// Function to display all levels of the list
void displayAllLevels(List* list);

// Function to display all levels of the list with aligned cells
void displayAllLevelsAligned(List* list);

// Function to insert a cell at the correct position to keep the list sorted
void insertCellSorted(List* list, Cell* cell);


#endif //UNTITLED4_LIST_H
