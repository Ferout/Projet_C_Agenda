//
// Created by Aurélien on 06/12/2023.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "fonction.h"
#include "contact.h"
#include "timer.h"
#include "affichage.h"

// Définition des constantes pour les choix de menu
#define MENU_ADD_CONTACT 1
#define MENU_FIND_CONTACT 2
#define MENU_DISPLAY_CONTACTS 3
#define MENU_ADD_APPOINTMENT 4
#define MENU_DISPLAY_APPOINTMENTS 5
#define MENU_EXTRACT_APPOINTMENTS 6
#define MENU_QUIT 7

void Partie1(){


    //Test pour la partie 1

    printf("Test Partie 1 : \n");

    printf("\n");

    printf("Liste a niveau vide : \n");

    int my_empty_list_level = 5;
    t_d_list* my_empty_list = create_list(my_empty_list_level);
    display_list(my_empty_list);

    printf("\n");

    printf("Insertion et affichage aligne : \n");

    int my_list_level = 5;
    t_d_list* my_list = create_list(my_list_level);

    insert_cell(91, 3, my_list);
    insert_cell(59, 5, my_list);
    insert_cell(56, 3, my_list);
    insert_cell(32, 5, my_list);
    insert_cell(31, 2, my_list);
    insert_cell(25, 1, my_list);
    insert_cell(18, 3, my_list);

    display_list(my_list);

    printf("\n");

}

void Partie2(){

    //Test pour la partie 2

    t_d_list *my_list_2 = MakeBigList(3);
    printf("Enregistrement des temps d execution \n");

    for (int n = 3; n < 16; ++n) {

        int valueToSearch = pow(2, n) - 1;
        t_d_list *my_list_2 = MakeBigList(n);


        startTimer();
        for (int j = 0; j <= 100000; ++j) {
            search_cell_classic(valueToSearch,my_list_2 );
        }
        stopTimer();

        char *time_lvl0 = getTimeAsString();

        startTimer();
        for (int j = 0; j <= 100000; ++j) {
            search_cell_dichotomy(valueToSearch,my_list_2 );
        }
        stopTimer();
        char *time_all_levels = getTimeAsString();

        printf("n=%d | niveau 0: %s  et multi-niveau: %s \n", n, time_lvl0, time_all_levels);

    }

    printf("\n");

}

int Partie3(){
    printf("Partie 3 Agenda : \n");
    printf("\n");
    // Création de la liste principale
    t_input_list* MAIN_LIST = create_input_list(4);
    int app_state = 1;

    while (app_state) {
        // Affichage du menu principal
        printf("%d contacts dans la liste\n", get_number_of_contacts(MAIN_LIST));
        printf("1. Ajouter un contact\n");
        printf("2. Chercher un contact\n");
        printf("3. Afficher les contacts\n");
        printf("4. Ajouter un rendez-vous\n");
        printf("5. Affichez les rendez-vous\n");
        printf("6. Extraire les rendez-vous\n");
        printf("7. Quitter\n");

        int choix = 0;
        scanf("%d", &choix);

        switch (choix) {
            case MENU_ADD_CONTACT: {
                menu_add_contact(MAIN_LIST);
                break;
            }

            case MENU_FIND_CONTACT: {
                menu_find_contact(MAIN_LIST);
                break;
            }

            case MENU_DISPLAY_CONTACTS: {
                menu_display_all_contacts(MAIN_LIST);
                break;
            }

            case MENU_ADD_APPOINTMENT: {
                menu_add_appointment(MAIN_LIST);
                break;
            }

            case MENU_DISPLAY_APPOINTMENTS: {
                menu_display_appointment(MAIN_LIST);
                break;
            }

            case MENU_EXTRACT_APPOINTMENTS: {
                extract_appointments(MAIN_LIST);
                break;
            }

            case MENU_QUIT: {
                app_state = 0;
                break;
            }

            default: {
                printf("Choix invalide\n");
                break;
            }
        }
    }

    return 0;
}


int main() {

    //Partie1();
    //Partie2();
    Partie3();
}