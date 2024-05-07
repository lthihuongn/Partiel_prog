#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Voiture {
    char *marque;
    char *modele;
    int annee;
    struct Voiture * suivant;
} Voiture;


Voiture creer_voiture(char *marque, char *modele, int annee){
    Voiture voiture = {.marque = marque, .modele = modele, .annee= annee};
    return voiture;
}

void insert_end(Voiture* head[], Voiture *voiture) {
    Voiture* nouvelle_voiture = voiture;
    if (nouvelle_voiture != NULL) {
        if (*head == NULL) {
            *head = nouvelle_voiture;
        } else {
            Voiture * voiture_actuelle = *head;
            while (voiture_actuelle->suivant != NULL) {
                voiture_actuelle = voiture_actuelle->suivant;
            }
            voiture_actuelle->suivant = nouvelle_voiture;
        }
    } else {
        printf("Error : Create a new node is impossible.\n");
    }
}

void afficherListe(Voiture * head) {
    Voiture * voiture_actuelle = head;
    printf("Voitures de la liste :\n");
    while (voiture_actuelle != NULL) {
        printf("marque : %s, modele : %s, annee : %d\n", voiture_actuelle->marque, voiture_actuelle->modele, voiture_actuelle->annee);
        voiture_actuelle = voiture_actuelle->suivant;
    }
    printf("NULL\n");
}


void delete_element(Voiture* head[], char *modele){
    Voiture * voiture_actuelle = *head;
    if (strcmp(voiture_actuelle->modele, modele)){
        *head = voiture_actuelle->suivant;
    }else{
        while (strcmp(voiture_actuelle->suivant->modele, modele)!=0) {
            voiture_actuelle = voiture_actuelle->suivant;
        }
        voiture_actuelle->suivant = voiture_actuelle->suivant->suivant;
    }

}


int main() {
    Voiture * head = NULL;

    Voiture voiture1 = creer_voiture("Renault", "megane", 2000);
    Voiture voiture2 = creer_voiture("Fiat", "500", 1967);
        
    insert_end(&head, &voiture1);
    insert_end(&head, &voiture2);

    printf("liste de départ :\n");
    afficherListe(head);


    printf("liste en enlevant une voiture :\n");
    delete_element(&head, "500");
    afficherListe(head);

    // Liberation de la memoire
    while (head != NULL) {
        Voiture * temporary = head;
        head = head->suivant;
        free(temporary);
    }

    return 0;
}