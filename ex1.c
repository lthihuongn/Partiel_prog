#include <stdio.h>

typedef struct {
    int estPositionne;
} Place;

int compteur;

Place parking[5][3];

void ajouter(int x, int y) {
    if (x >= 0 && x < 5 && y >= 0 && y < 3) {
        if (parking[x][y].estPositionne == 0){
            parking[x][y].estPositionne = 1;
            compteur +=1;
            if (x==0){
                printf("La place A%d vient d'etre prise\n", y+1);
            }else if (x==1){
                printf("La place B%d vient d'etre prise\n", y+1);
            }else if (x==2){
                printf("La place C%d vient d'etre prise\n", y+1);
            }else if (x==3){
                printf("La place D%d vient d'etre prise\n", y+1);
            }else if (x==4){
                printf("La place E%d vient d'etre prise\n", y+1);
            }
        }else{
            printf("La place est deja prise.\n");
        }
    }
}

void supprimer(int x, int y) {
    if (parking[x][y].estPositionne == 1) {
        parking[x][y].estPositionne = 0;
        compteur-=1;
        if (x==0){
            printf("La place A%d vient de se liberer\n", y+1);
        }else if (x==1){
            printf("La place B%d vient de se liberer\n", y+1);
        }else if (x==2){
            printf("La place C%d vient de se liberer\n", y+1);
        }else if (x==3){
            printf("La place D%d vient de se liberer\n", y+1);
        }else if (x==4){
            printf("La place E%d vient de se liberer\n", y+1);
        }
    }else{
        printf("La place est deja vide.\n");
    }
}

int main() {

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 3; ++j) {
            parking[i][j].estPositionne = 0;
        }
    }
    int x = 0;
    int y = 0;
    while (compteur >= 0) {
        int choix;
        printf("Bienvenue dans votre parking\n");
        printf("Que souhaitez-vous faire ?\n");
        printf("1. ajouter une voiture\n");
        printf("2. suprimmer une voiture et trouver une place\n");
        printf("3. quitter le parking\n");
        scanf("%d", &choix);
        if(choix == 1){
            if(x >=0 && x<7 && y >=0 && y<5){
                ajouter(x,y);
                if (parking[x][y+1].estPositionne == 0){
                    y+=1;
                    if (y>2){
                        y = 0;
                        x+=1;
                        if(x>4){
                            printf("Le parking est plein.\n");
                            y=2;
                            x=4;
                        }
                    }
                }
                else if (compteur ==15){
                    printf("Le parking est plein.\n");
                }

            }


        }else if(choix == 2){  //une fois le parking plein, il supprime les places en recommençant du début (cad A1) mais comme il supprime à reculons, à partir du moment où le parking est plein est que la place A1 est la seule de libre, il ne peut supprimer qu'elle.
            if (compteur > 0){
                y-=1;
                if (y<0){
                    y =2;
                    x-=1;
                    if (x<0){
                        x=3;
                        y=4;
                    }
                }
                supprimer(x,y);
            }else{
                printf("Le parking est deja vide\n");
            }
        }

        else if(choix == 3){
            printf("Vous quittez le parking, il y au total %d voitures. Au revoir.\n", compteur);
            break;
        }
        else{
            printf("Choisissez une commande valide");
        }
    }

    return 0;
}
