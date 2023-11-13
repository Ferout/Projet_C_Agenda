//
// Created by esteb on 13/11/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

// Function to create a cell
Cell* createCell(int value, int numLevels) {
    // Allocate memory for the cell structure
    Cell* newCell = (Cell*)malloc(sizeof(Cell));

    // Check if memory allocation was successful
    if (newCell == NULL) {
        // Handle memory allocation failure
        return NULL;
    }

    // Set the value and number of levels for the cell
    newCell->value = value;
    newCell->numLevels = numLevels;

    // Allocate memory for the array of pointers to cells at different levels
    newCell->levels = (Cell**)malloc(numLevels * sizeof(Cell*));

    // Check if memory allocation was successful
    if (newCell->levels == NULL) {
        // Handle memory allocation failure
        free(newCell); // Free the memory allocated for the cell structure
        return NULL;
    }

    // Initialize the array of pointers to NULL
    for (int i = 0; i < numLevels; ++i) {
        newCell->levels[i] = NULL;
    }

    // Return the pointer to the created cell
    return newCell;
}

// Function to create an empty list with the given maximum number of levels
List* createList(int maxLevels) {
    // Allocate memory for the list structure
    List* newList = (List*)malloc(sizeof(List));

    // Check if memory allocation was successful
    if (newList == NULL) {
        // Handle memory allocation failure
        return NULL;
    }

    // Set the maximum number of levels for the list
    newList->maxLevels = maxLevels;

    // Set the head of the list to NULL (empty list)
    newList->head = NULL;

    // Return the pointer to the created list
    return newList;
}

// Function to insert a cell with levels at the beginning of the list
void insertCellAtHead(List* list, Cell* cell) {
    // Set the levels of the cell to match the maximum levels of the list
    int levelsToSet = (cell->numLevels > list->maxLevels) ? list->maxLevels : cell->numLevels;
    cell->numLevels = levelsToSet;

    // Link the cell to the current head of the list
    for (int i = 0; i < levelsToSet; ++i) {
        cell->levels[i] = list->head;
    }

    // Set the head of the list to the new cell
    list->head = cell;
}

// Function to display all cells at a specific level in the list
void displayCellsAtLevel(List* list, int level) {
    printf("Level %d: [ list head_%d @-]-->", level,level);

    // Traverse the list and display cells at the specified level
    Cell* current = list->head;
    while (current != NULL) {
        if (level < current->numLevels) {
            printf("[ %d|@-]-->", current->value);
        }
        current = current->levels[0];  // Move to the next level
    }

    printf("NULL\n");
}

// Function to display all levels of the list
void displayAllLevels(List* list) {
    // Display cells at each level
    for (int i = 0; i < list->maxLevels; ++i) {
        displayCellsAtLevel(list, i);
    }
}

// Function to display all levels of the list with aligned cells
void displayAllLevelsAligned(List* list) {
    printf("All Levels Aligned:\n");

    // Display cells at each level with alignment
    for (int i = 0; i < list->maxLevels; ++i) {
        printf("Level %d: [ list head_%d @-]--", i,i);

        // Traverse the list and display cells at the specified level
        Cell* current = list->head;
        while (current != NULL) {
            if (i < current->numLevels) {
                printf(">[ %d|@-]--", current->value);
            } else {
                printf("-----------");  // Placeholder for empty cell
            }
            current = current->levels[0];  // Move to the next level
        }

        printf(">NULL\n");
    }
}

// Function to insert a cell at the correct position to keep the list sorted
void insertCellSorted(List* list, Cell* cell) {
    int levelsToSet = (cell->numLevels > list->maxLevels) ? list->maxLevels : cell->numLevels;
    cell->numLevels = levelsToSet;

    // Special case: If the list is empty or the new cell should be the new head
    if (list->head == NULL || cell->value < list->head->value) {
        for (int i = 0; i < levelsToSet; ++i) {
            cell->levels[i] = list->head;
        }
        list->head = cell;
        return;
    }

    // Traverse the list to find the correct position to insert the cell
    Cell* current = list->head;
    Cell* previous = NULL;

    while (current != NULL && current->value < cell->value) {
        previous = current;
        current = current->levels[0];
    }

    // Insert the cell at the correct position
    for (int i = 0; i < levelsToSet; ++i) {
        cell->levels[i] = current;
    }

    if (previous != NULL) {
        previous->levels[0] = cell;
    }
}


