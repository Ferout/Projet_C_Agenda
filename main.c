//
// Created by Aurélien on 23/11/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fonction.h"
#include "models.h"
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

int main() {
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

