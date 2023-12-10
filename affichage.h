//
// Created by Aurélien on 06/12/2023.
//

#ifndef AGENDA_GOMEZ_AFFICHAGE_H
#define AGENDA_GOMEZ_AFFICHAGE_H

#include "contact.h"

void menu_add_contact(t_input_list* input_list);

void menu_find_contact(t_input_list* input_list);

void menu_add_appointment(t_input_list* input_list);

void menu_display_contact(t_contact* contact);

void menu_display_appointment(t_input_list* input_list);

void menu_display_all_contacts(t_input_list* input_list);

int get_number_of_contacts(t_input_list* input_list);

void extract_appointments(t_input_list* input_list);

#endif //AGENDA_GOMEZ_AFFICHAGE_H
