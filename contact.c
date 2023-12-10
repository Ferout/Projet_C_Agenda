//
// Created by Aurélien on 23/11/2023.
//

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "contact.h"

// Fonction pour saisir une chaîne de caractères depuis la console
char* scan_string() {
    int max_size = 100;
    char* string = (char*) malloc(sizeof(char) * max_size);
    scanf("%s", string);
    return string;
}

// Fonction pour obtenir le nom formaté d'un contact (nom_de_famille_prenom)
char* get_name_formatted(t_contact* contact) {
    // Allouer de la mémoire pour la nouvelle chaîne
    char* name = (char*) malloc(sizeof(char) * (strlen(contact->nom_de_famille) + strlen(contact->prenom) + 2)); // +2 pour le tiret bas et le caractère nul

    // Copier le nom de famille dans la nouvelle chaîne et le convertir en minuscules
    for(int i = 0; i < strlen(contact->nom_de_famille); i++) {
        name[i] = tolower(contact->nom_de_famille[i]);
    }
    name[strlen(contact->nom_de_famille)] = '\0'; // Assurer la null-termination

    // Ajouter le tiret bas
    strncat(name, "_", 1);

    // Ajouter le prénom et le convertir en minuscules
    for(int i = 0; i < strlen(contact->prenom); i++) {
        name[strlen(contact->nom_de_famille) + 1 + i] = tolower(contact->prenom[i]);
    }

    // Assurer la null-termination de la chaîne
    name[strlen(contact->nom_de_famille) + strlen(contact->prenom) + 1] = '\0';

    return name;
}

// Fonction pour vérifier si str1 vient avant str2 dans l'ordre alphabétique
int is_name_before(char* str1, char* str2) {
    int i = 0;
    int j = 0;

    while(str1[i] != '\0' && str2[j] != '\0') {
        if(str1[i] < str2[j]) {
            return 1;
        } else if(str1[i] > str2[j]) {
            return 0;
        }
        i++;
        j++;
    }

    // Si str1 est plus court que str2, str1 vient avant
    if(str1[i] == '\0') {
        return 1;
    } else {
        return 0;
    }
}

// Fonction pour trouver un contact dans la liste
t_input * find_contact(char* nom_de_famille, t_input_list* liste) {
    for(int i = 0; i < liste->niveau_max; i++) {
        t_input* tmp = liste->tetes[i];
        while(tmp != NULL) {
            if(strcmp(tmp->contact->nom_de_famille, nom_de_famille) == 0) {
                return tmp;
            }
            tmp = tmp->suivant;
        }
    }
    return NULL;
}

// Fonction pour créer un contact
t_contact* create_contact(char* prenom, char* nom_de_famille) {
    t_contact* contact = (t_contact*) malloc(sizeof(t_contact));
    contact->nom_de_famille = nom_de_famille;
    contact->prenom = prenom;
    return contact;
}

// Fonction pour créer un rendez-vous
t_appointment* create_appointment(char* objet, int heure, int minute, int jour, int mois, int annee) {
    t_appointment* appointment = (t_appointment*) malloc(sizeof(t_appointment));
    appointment->objet = objet;
    appointment->heure = heure;
    appointment->minute = minute;
    appointment->jour = jour;
    appointment->mois = mois;
    appointment->annee = annee;
    appointment->suivant = NULL;
    return appointment;
}

// Fonction pour créer une entrée avec un contact
t_input* create_input(t_contact* contact, int niveau) {
    t_input* input = (t_input*) malloc(sizeof(t_input));
    input->contact = contact;
    input->rendez_vous = NULL;
    input->suivant = NULL;
    input->niveau = niveau;
    return input;
}

// Fonction pour créer une liste d'entrées
t_input_list* create_input_list(int niveau) {
    t_input_list* liste = (t_input_list*) malloc(sizeof(t_input_list));
    liste->tetes = (t_input **) malloc(sizeof(t_input*) * niveau);
    liste->niveau_max = niveau;
    for(int i = 0; i < niveau; i++) {
        liste->tetes[i] = NULL;
    }
    return liste;
}

// Fonction pour insérer un rendez-vous dans une entrée
void insert_appointment(t_appointment* rendez_vous, t_input* input) {
    rendez_vous->suivant = input->rendez_vous;
    input->rendez_vous = rendez_vous;
}

// Fonction pour insérer un contact dans la liste
void insert_input(t_contact * contact, t_input_list* liste) {
    // Vérifier si le contact est déjà dans la liste
    char* nom = get_name_formatted(contact);

    for(int i = 0; i < liste->niveau_max; i++) {
        t_input* tmp = liste->tetes[i];

        while(tmp != NULL) {
            if(strcmp(get_name_formatted(tmp->contact), nom) == 0) {
                printf("Contact déjà présent dans la liste.\n");
                return;
            }
            tmp = tmp->suivant;
        }
    }

    // Insérer le contact dans la liste par ordre alphabétique uniquement sur le niveau 0
    t_input* entree = create_input(contact, 0);

    if(liste->tetes[0] == NULL) {
        liste->tetes[0] = entree;
        return;
    }

    if(is_name_before(nom, get_name_formatted(liste->tetes[0]->contact))) {
        entree->suivant = liste->tetes[0];
        liste->tetes[0] = entree;
        return;
    }

    t_input* tmp = liste->tetes[0];

    while(tmp->suivant != NULL && is_name_before(get_name_formatted(tmp->suivant->contact), nom)) {
        tmp = tmp->suivant;
    }

    entree->suivant = tmp->suivant;
    tmp->suivant = entree;
}

// Fonction pour afficher la liste d'entrées
void display_input_list(t_input_list* liste) {
    for(int i = 0; i < liste->niveau_max; i++) {
        printf("[tête de liste_%d @-]-->", i);
        t_input *tmp = liste->tetes[i];

        while(tmp != NULL) {
            printf("[ %s|@ ]-->", tmp->contact->nom_de_famille);
            tmp = tmp->suivant;
        }

        printf("NULL\n");
    }
}

