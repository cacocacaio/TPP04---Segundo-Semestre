#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <ctype.h>
#include <string.h>


#include "main.h"
#include "menu_ui.h"


int menu(void){

	int opcao;
	printf("Bem vindo ao programa, op��es para escolher o que seja feito abaixo\nCriadores do programa: Juan Cardosos da Silva e Caio Nogueira\n\n");
    printf("******************************************************************\n");
	printf("*Op��o 01: Gerar valores aleatorios                              *\n");
	printf("*Op��o 02: Adicionar valores manualmente                         *\n");
	printf("*Op��o 03: Exibir um dos Conjuntos                               *\n");
	printf("*Op��o 05: Encontrar a interse��o entre A e B                    *\n");
	printf("*Op��o 06: Encontrar a uni�o entre A e B                         *\n");
	printf("*Op��o 07: Encontrar a diferen�a A-B                             *\n");
	printf("*Op��o 08: Encontrar a diferen�a B-A                             *\n");
	printf("*Op��o 09: Procurar um elemento em um dos Conjuntos              *\n");
	printf("*Op��o 10: Ler um a  *\n");
    printf("******************************************************************\n\n");
	printf("Digite a sua op��o: ");
	scanf("%d", &opcao);

	return (opcao);
}

short continua(){

	int ch;

	do{

        system("cls");
		printf("Deseja continuar executando o programa?\nResponda S para sim e N para n�o:\n");
		ch = getchar();
	    ch = toupper(ch);

	} while ((ch != 'S') && (ch != 'N'));
	if (ch == 'S') return 1;
	else return 0;
}
