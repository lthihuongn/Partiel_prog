#include <stdio.h>
#include <stdlib.h>

int main() {

    int var1 =6;
    int var2 = 5;
    int *ptr1;



    // Allocation dynamique de mémoire pour 5 entiers
    ptr1 = (int *)malloc(5 * sizeof(int));


    // Utilisation de la mémoire allouée
    ptr1[0] = var1;
    var1 = var2;
    var2 = ptr1[0];
    printf("%d, %d", var1, var2);



    

    // Libération de la mémoire allouée
    free(ptr1);


    return 0;
}
