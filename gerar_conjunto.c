#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "gerar_conjunto.h"
#include "ordenar.h"
#include "main.h"



FILE *f;
FILE *f1;
FILE *f2;

void add_random(char **arg_v){

    int i,j, aux, tam,tam1, aux1;
    char *arquivo,*arquivo2,*arquivo3;

    tam = atoi(arg_v[3]);
    arquivo = arg_v[2];
    if (*arg_v[1]=='t') strcat(arquivo, ".txt");
    else if (*arg_v[1]=='b') strcat(arquivo, ".bin");
    else{

        printf("Tipo incorreto de arquivo!");
        system("pause");
        exit(1);
    }

    int V[tam];

    srand (time(NULL));

    for (i=0; i<tam; i++){

        V[i]=rand()%100;
    }

    ordena(V, tam);

    if(*arg_v[1]=='t'){

        if((f=fopen(arquivo,"w"))==NULL){

        printf("Não foi possível gerar o arquivo");
        system("pause");
        exit(1);
        }

        for (i=0; i<tam; i++){ // Escrevendo o arquivo em txt

        aux = V[i];
        fprintf(f, "%d\n", aux);
        }

        fclose(f);

    }

    if(*arg_v[1]=='b'){

        if((f=fopen(arquivo,"wb"))==NULL){

        printf("Não foi possível gerar o arquivo");
        system("pause");
        exit(1);
        }

        for (j=0; j<i; j++){ //Escrevendo o arquivo em binário

        aux1 = V[j];
        fwrite(&aux1,sizeof(int),1, f);
        }

        fclose(f);

    }
}


