//
// Created by Aurélien on 23/11/2023.
//

#include "fonction.h"
#include <stdio.h>
#include <stdlib.h>

t_d_cell *create_cell(int value, int level) {

    t_d_cell *cell = (t_d_cell*) malloc(sizeof(t_d_cell));

    cell->value = value;
    cell->level = level;
    cell->next = (t_d_cell**) malloc(sizeof(t_d_cell*) * level);

    for(int i = 0; i < level; i++) {
        cell->next[i] = NULL;
    }

    return cell;
}

void display_cell(t_d_cell* cell) {

    for(int i = 0; i < cell->level; i++) {
        printf("[ %d|@ ]-->\n", cell->value);
    }

    return;
}
t_d_list *create_list(int max_level) {

    t_d_list *list = (t_d_list*) malloc(sizeof(t_d_list));

    list->max_level = max_level;
    list->heads = (t_d_cell**) malloc(sizeof(t_d_cell*) * max_level);

    for(int i = 0; i < max_level; i++) {

        list->heads[i] = NULL;

    }

    return list;
}
void display_list(t_d_list* list) {

    for(int i = 0; i < list->max_level; i++) {

        printf("[list head_%d @-]--", i);
        t_d_cell *tmp = list->heads[i];
        t_d_cell *cursor = list->heads[0];

        // Cursor compare les valeurs de la liste au niveau 0 avec le niveau i

        while(cursor != NULL) {
            if(tmp == NULL) {
                printf("----------");
                cursor = cursor->next[0];
                continue;
            }
            if(cursor->value == tmp->value) {
                printf(">[ %d|@ ]--", tmp->value);
                tmp = tmp->next[i];

            } else {
                printf("----------");
            }
            cursor = cursor->next[0];
        }

        printf(">NULL\n");

    }

}

void insert_cell(int value , int level, t_d_list* list) {

    t_d_cell *cell = create_cell(value, level);

    for(int i = 0; i < level; i++) {

        if(list->heads[i] == NULL) {

            list->heads[i] = cell;

        } else {

            if(list->heads[i]->value > value) {

                cell->next[i] = list->heads[i];
                list->heads[i] = cell;

            } else {
                t_d_cell *tmp = list->heads[i];

                while(tmp->next[i] != NULL && tmp->next[i]->value < value) {

                    tmp = tmp->next[i];

                }

                cell->next[i] = tmp->next[i];
                tmp->next[i] = cell;

            }

        }

    }

    return;
}

t_d_cell* search_cell_classic(int value, t_d_list* list) {

    t_d_cell *tmp = list->heads[0];

    while(tmp != NULL && tmp->value < value) {
        tmp = tmp->next[0];
    }

    if(tmp != NULL && tmp->value == value) {
        return tmp;

    } else {
        return NULL;

    }
}

/**
 * @param value
 * @param list
 * @return
 */
t_d_cell* search_cell_optimal(int value, t_d_list* list) {

    t_d_cell *tmp = list->heads[list->max_level - 1];

    for(int i = list->max_level - 1; i >= 0; i--) {
        while(tmp != NULL && tmp->value < value) {

            tmp = tmp->next[i];
        }

        if(tmp != NULL && tmp->value == value) {
            return tmp;

        }

        tmp = list->heads[i];

    }

    return NULL;
}


#include "fonction.h"
