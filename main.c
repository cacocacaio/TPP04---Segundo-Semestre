#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

//Projeto criado e desenvolvido no code::blocks - talvez seja necess�rio instalar ele para acessar o projeto
//Abaixo incluimos os arquivos necess�rios para a execu��o da main.
//ATEN��O O FORMATO ESCOLHIDO PARA OS ARQUIVOS BIN�RIOS FOI .bin

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

        info(arg_v); // abre a informa��es do execut�vel

        break;

        case 3:

            printf("lista arquivo ");

            if (*arg_v[1] == 't') printf("de tipo texto!\n");
            else if(*arg_v[1] == 'b') printf("de tipo bin�rio!\n");
            else printf("\nOcorreu algum erro na entrada.\n");

            cmd(arg_v); // abre um arquivo txt ou bin�rio

        break;

        case 4:

            if (atoi(arg_v[3]) > 0 ){

                printf("cria arquivo com numeros aleat�rios!\n");
                add_random(arg_v); // cria um arquivo bin�rio ou em txt com n�meros

            }else printf("Quantidade incorreta de linhas!\n");
        break;

        case 6:

            switch(atoi(arg_v[2])){

                case 1:

                    printf("intersec��o entre dois arquivos ");
                    if (*arg_v[1] == 't') printf("de tipo texto!");
                    else if(*arg_v[1] == 'b') printf("de tipo bin�rio!\n");
                    else printf("\nOcorreu algum erro na entrada.\n");

                    inter_sep(arg_v); // acha a interse��o entre 2 conjuntos criando um terceiro conjunto onde fica armazenado em um arquivo( os arquivos podem ser em bin�rio ou em txt)

                break;

                case 2:

                    printf("uni�o entre dois arquivos ");
                    if (*arg_v[1] == 't') printf("de tipo texto!");
                    else if(*arg_v[1] == 'b') printf("de tipo bin�rio!\n");
                    else printf("\nOcorreu algum erro na entrada.\n");

                    uni_add(arg_v); // Acha a uni�o entre os conjuntos criando um terceiro onde fica armazenado em um arquivo  (os arquivos podem ser em bin�rio ou em txt)

                break;

                case 3:

                    printf("diferen�a entre dois arquivos ");
                    if (*arg_v[1] == 't') printf("de tipo texto!\n");
                    else if(*arg_v[1] == 'b') printf("de tipo bin�rio!\n");
                    else printf("\nOcorreu algum erro na entrada.\n");

                    subtra_re(arg_v); // Faz a subtra��o de dois conjuntos criando um terceiro onde fica armazenado em um arquivo (os arquivos podem ser em bin�rio ou em txt)

                break;

                default:
                    printf("Argumento incorreto!\n");
            }
        break;

        default:
            printf("quantidade incorreta de par�metros!\n");
    }

    system("pause");



	return 0;
}

