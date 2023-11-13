
#include <stdio.h>
#include <stdlib.h>
#include "cell.h"
#include "list.h"
#include <string.h>

int main() {
    // Création d'une cellule avec 3 niveaux
    Cell* cell1 = createCell(10, 3);
    Cell* cell2 = createCell(20, 2);
    Cell* cell3 = createCell(30, 3);

    // Création d'une liste avec un maximum de 4 niveaux
    List* myList = createList(4);

    // Insertion de cellules dans la liste
    insertCellAtHead(myList, cell1);
    insertCellAtHead(myList, cell2);
    insertCellAtHead(myList, cell3);

    // Affichage des cellules à un niveau donné
    displayCellsAtLevel(myList, 1);

    // Affichage de tous les niveaux de la liste
    displayAllLevels(myList);

    // Affichage de tous les niveaux de la liste avec alignement
    displayAllLevelsAligned(myList);

    // Insertion d'une cellule triée
    Cell* cell4 = createCell(15, 2);
    insertCellSorted(myList, cell4);

    // Affichage de tous les niveaux de la liste après l'insertion triée
    displayAllLevels(myList);

    // Libération de la mémoire
    free(cell1);
    free(cell2);
    free(cell3);
    free(cell4);
    free(myList);

    return 0;
}