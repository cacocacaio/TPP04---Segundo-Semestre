#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "gerar_conjunto.h"
#include "main.h"

#define max 100

void manulinator(int *A, int *ta, char conj){

    int i;

    memset(A, 0, max*sizeof(*A));
    printf("Quantos valores deseja adicionar?\n");
    scanf("%d", ta);

    for (i=0; i<*ta; i++){

        printf("%c[%02d] = ", conj, i);
        scanf("%d", (A+i));
    }
}
