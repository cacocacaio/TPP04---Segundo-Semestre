#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define max 100

#include "ordenar.h"

void ordena(int *A, int n)
{
   int i, key, j;
    printf("%d", n);
   for (i = 1; i < n; i++)
   {
       key = *(A+i);
       j = i-1;

       /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
       while (j >= 0 && *(A+j) > key)
       {
           *(A+j+1) = *(A+j);
           j = j-1;
       }
       *(A+j+1) = key;
   }
}

void amostra(int *A, int *tam, char conj){ // Função que mosra os valores que foram armazenado nos conjuntos.

    int i;
    printf("%d\n", *tam);
    ordena(A, *tam);
    system("cls");
    for (i=0; i<*tam; i++){

        printf("%c[%d] = %d\n", conj, i, *(A+i));
    }
}

void Troca1(int *S, int Ind1, int Ind2) { // Função para troca dos valores.

    int aux;

    aux =  *(S+Ind1);
    *(S+Ind1) =  *(S+Ind2);
    *(S+Ind2) = aux;
} // Troca1
