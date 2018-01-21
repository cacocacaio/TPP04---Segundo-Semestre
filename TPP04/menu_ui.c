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
	printf("Bem vindo ao programa, opções para escolher o que seja feito abaixo\nCriadores do programa: Juan Cardosos da Silva e Caio Nogueira\n\n");
    printf("******************************************************************\n");
	printf("*Opção 01: Gerar valores aleatorios                              *\n");
	printf("*Opção 02: Adicionar valores manualmente                         *\n");
	printf("*Opção 03: Exibir um dos Conjuntos                               *\n");
	printf("*Opção 05: Encontrar a interseção entre A e B                    *\n");
	printf("*Opção 06: Encontrar a união entre A e B                         *\n");
	printf("*Opção 07: Encontrar a diferença A-B                             *\n");
	printf("*Opção 08: Encontrar a diferença B-A                             *\n");
	printf("*Opção 09: Procurar um elemento em um dos Conjuntos              *\n");
	printf("*Opção 10: Ler um a  *\n");
    printf("******************************************************************\n\n");
	printf("Digite a sua opção: ");
	scanf("%d", &opcao);

	return (opcao);
}

short continua(){

	int ch;

	do{

        system("cls");
		printf("Deseja continuar executando o programa?\nResponda S para sim e N para não:\n");
		ch = getchar();
	    ch = toupper(ch);

	} while ((ch != 'S') && (ch != 'N'));
	if (ch == 'S') return 1;
	else return 0;
}
