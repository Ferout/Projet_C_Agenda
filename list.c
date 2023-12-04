//
// Created by esteb on 13/11/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include <math.h>

// Function to create a cell
Cell* createCell(int value, int numLevels) {
    // Allocate memory for the cell structure

    Cell* newcell = malloc(sizeof(Cell*)+ sizeof(Cell**) *numLevels);

    // Set the value and number of levels for the cell
    newcell->value = value;
    newcell->numLevels = numLevels;


    // Initialize the array of pointers to NULL
    for (int i = 0; i < numLevels; ++i) {
        newcell->levels[i] = NULL;
    }

    // Return the pointer to the created cell
    return newcell;
}

// Function to create an empty list with the given maximum number of levels
List* createList(int maxLevels) {
    // Allocate memory for the list structure
    List* newList = (List*)malloc(sizeof(List));



    // Set the maximum number of levels for the list
    newList->maxLevels = maxLevels;
    for (int i = 0; i < maxLevels; i++)
    // Set the head of the list to NULL (empty list)
        newList->head[i] = NULL;

    // Return the pointer to the created list
    return newList;
}

// Function to insert a cell with levels at the beginning of the list
void insertSorted(List* list, Cell* cell) {
    int level = cell->numLevels - 1;

    // If the list is empty, or the new cell value is smaller than the head value
    if (list->head[level] == NULL || cell->value < list->head[level]->value) {
        cell->levels[level] = list->head[level];
        list->head[level] = cell;
    } else {
        // Find the position to insert the cell
        Cell* current = list->head[level];
        Cell* previous = NULL;
        while (current != NULL && current->value < cell->value) {
            previous = current;
            current = current->levels[level];
        }

        // Insert the cell at the correct position
        cell->levels[level] = current;
        if (previous != NULL) {
            previous->levels[level] = cell;
        } else {
            // If previous is NULL, it means the cell should be the new head
            list->head[level] = cell;
        }
    }

    // Insert the cell in lower levels
    for (int i = level - 1; i >= 0; --i) {
        if (list->head[i] == NULL || cell->value < list->head[i]->value) {
            cell->levels[i] = list->head[i];
            list->head[i] = cell;
        } else {
            // Find the position to insert the cell in lower levels
            Cell* current = list->head[i];
            Cell* previous = NULL;
            while (current != NULL && current->value < cell->value) {
                previous = current;
                current = current->levels[i];
            }

            // Insert the cell at the correct position in lower levels
            cell->levels[i] = current;
            if (previous != NULL) {
                previous->levels[i] = cell;
            } else {
                // If previous is NULL, it means the cell should be the new head
                list->head[i] = cell;
            }
        }
    }
}
// Function to display all cells at a specific level in the list
void displayCellsAtLevel(List* list, int level) {
    printf("Level %d: [ list head_%d @-]-->", level,level);

    // Traverse the list and display cells at the specified level
    Cell* current = list->head[level];
    while (current != NULL) {
        if (level < current->numLevels) {
            printf("[ %d|@-]-->", current->value);
        }
        current = current->levels[0];  // Move to the next level
    }

    printf("NULL\n");
}
void displayListByLevel(List* list, int level) {
    Cell* current = list->head[level];
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->levels[level];
    }
    printf("\n");
}
// Function to display all levels of the list
void displayAllLevels(List* list) {
    for (int i = list->maxLevels - 1; i >= 0; --i) {
        printf("Level %d: ", i);
        displayListByLevel(list, i);
    }
}

// Function to display all levels of the list with aligned cells
void displayAllLevelsAligned(List* list) {
    printf("All Levels Aligned:\n");

    // Display cells at each level with alignment
    for (int i = 0; i < list->maxLevels; ++i) {
        printf("Level %d: [ list head_%d @-]--", i,i);

        // Traverse the list and display cells at the specified level
        Cell* current = list->head[i];
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


List* MakeBigList(int n) {
    int cellCount = (int)pow(2, n) - 1;
    int middle = (int)(cellCount/2);
    int level = 1;
    List* newList = createList(n);

    for (int i = 1; i <= cellCount; ++i) {
        Cell* cell;
        if (i % 2 == 0) {
            level += i > middle + 1? -1 : 1;
            cell = createCell(i, level);
        }
        else {
            cell = createCell(i, 1); // Si le chiffre est impair le niveau est 1
        }
        insertSorted(newList, cell);
    }

    return newList;
}
Cell* search(List* list, int value){
    int level = list->maxLevels - 1;
    Cell* next = list->head[level];
    Cell* lastInferior = next;

    for (; level >= 0; --level) {
        if (lastInferior->value <= value) {
            while (next != NULL) {
                if (next->value == value) return next;
                if (next->value > value) break;

                lastInferior = next;
                next = next->levels[level];
            }

            next = lastInferior;
        }
        else {
            next = list->head[level];
            lastInferior = next;
        }
    }

    return NULL;


}

