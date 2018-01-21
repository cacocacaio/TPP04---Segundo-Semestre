#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

//Projeto criado e desenvolvido no code::blocks - talvez seja necessário instalar ele para acessar o projeto
//Abaixo incluimos os arquivos necessários para a execução da main.
//ATENÇÃO O FORMATO ESCOLHIDO PARA OS ARQUIVOS BINÁRIOS FOI .bin

#include "main.h"
#include "gerar_conjunto.c"
#include "ordenar.c"
#include "uniao_helper.h"
#include "inter_sep.h"
#include "cmd_mostra.h"



int main(int arg_c, char *arg_v[])
{

    setlocale(LC_ALL,"Portuguese");

    int conta=0;
    for (conta=0; conta<arg_c; conta++){

        printf("%s\n", arg_v[conta]);
    }

    switch(arg_c){

        case 1:

        info(arg_v); // abre a informações do executável

        break;

        case 3:

            printf("lista arquivo ");

            if (*arg_v[1] == 't') printf("de tipo texto!\n");
            else if(*arg_v[1] == 'b') printf("de tipo binário!\n");
            else printf("\nOcorreu algum erro na entrada.\n");

            cmd(arg_v); // abre um arquivo txt ou binário

        break;

        case 4:

            if (atoi(arg_v[3]) > 0 ){

                printf("cria arquivo com numeros aleatórios!\n");
                add_random(arg_v); // cria um arquivo binário ou em txt com números

            }else printf("Quantidade incorreta de linhas!\n");
        break;

        case 6:

            switch(atoi(arg_v[2])){

                case 1:

                    printf("intersecção entre dois arquivos ");
                    if (*arg_v[1] == 't') printf("de tipo texto!");
                    else if(*arg_v[1] == 'b') printf("de tipo binário!\n");
                    else printf("\nOcorreu algum erro na entrada.\n");

                    inter_sep(arg_v); // acha a interseção entre 2 conjuntos criando um terceiro conjunto onde fica armazenado em um arquivo( os arquivos podem ser em binário ou em txt)

                break;

                case 2:

                    printf("união entre dois arquivos ");
                    if (*arg_v[1] == 't') printf("de tipo texto!");
                    else if(*arg_v[1] == 'b') printf("de tipo binário!\n");
                    else printf("\nOcorreu algum erro na entrada.\n");

                    uni_add(arg_v); // Acha a união entre os conjuntos criando um terceiro onde fica armazenado em um arquivo  (os arquivos podem ser em binário ou em txt)

                break;

                case 3:

                    printf("diferença entre dois arquivos ");
                    if (*arg_v[1] == 't') printf("de tipo texto!\n");
                    else if(*arg_v[1] == 'b') printf("de tipo binário!\n");
                    else printf("\nOcorreu algum erro na entrada.\n");

                    subtra_re(arg_v); // Faz a subtração de dois conjuntos criando um terceiro onde fica armazenado em um arquivo (os arquivos podem ser em binário ou em txt)

                break;

                default:
                    printf("Argumento incorreto!\n");
            }
        break;

        default:
            printf("quantidade incorreta de parâmetros!\n");
    }

    system("pause");



	return 0;
}

