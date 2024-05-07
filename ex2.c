#include <stdio.h>
#include <string.h>

typedef struct {
    char* nom;
    int age;
    double taille; //(en cm)

} Personne;

Personne creer_personne(char* nom, int age, double taille){
    Personne pers = {.nom = nom, .age = age, .taille = taille};
    return pers;
}

void afficherListe(Personne **personnes, int taille_tab){
    for (int i = 0; i < taille_tab; ++i) {
        printf("personne %d\n", i+1);
        printf("nom : %s\n", personnes[i]->nom);
        printf("age : %d\n", personnes[i]->age);
        printf("taille : %d\n", personnes[i]->taille);
    }
}


int main() {

    Personne pers1 = creer_personne("Francois", 34, 167);
    Personne pers2 = creer_personne("Francis", 45, 190);

    Personne *personnes[] = { &pers1, &pers2 };
    afficherListe(personnes, 2);

    return 0;
}
