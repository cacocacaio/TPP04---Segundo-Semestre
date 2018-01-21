#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <ctype.h>
#include <string.h>


#define max 100
#include "main.h"
#include "gerar_conjunto.c"
#include "ordenar.c"
#include "uniao.c"
#include "inter_sep.c"
#include "subtra_re.c"
#include "cmd_mostra.c"
#include "info.c"

int main(int argc, char *argv[])
{

    setlocale(LC_ALL,"Portuguese");


	do {

		op = menu();

		switch(op){

            case 1:

                do{
                	system("cls");
                    printf("Você escolheu a opção %d\n", op);
                    printf("Gerar valores aleatorios para o conjunto A ou para o conjunto B?\n");
                    conj = getchar();
                    conj = toupper(conj);
                }while(conj != 'A' && conj != 'B');


void manulinator(int *A, int *ta, char conj);
                if (conj=='A'){


                    m = max;
                }else{


                    n=max;
                }
                printf("Valores gerados aleatoriamente.\nAperte qualquer tecla para continuar.\n");
                conj = getchar();
                conj = getchar();
            break;

            case 2:

                do{

                    system("cls");
                    printf("Você escolheu a opção %d\n", op);
                    printf("Gerar valores manualmente para o conjunto A ou o conjunto B?\n");
                    conj = getchar();
                    conj = toupper(conj);
                }while(conj != 'A' && conj != 'B');

                if (conj=='A'){

                    manulinator(A,&m,conj);
                }else{

                    manulinator(B,&n,conj);
                }
                printf("Valores adicionados.\nAperte qualquer tecla para continuar.\n");
                conj = getchar();
                conj = getchar();
            break;

            case 3:

                do{

                    system("cls");
                    printf("Você escolheu a opção %d\n", op);
                    printf("Exibir um dos conjuntios\n");
                    printf("Visualizar o conjunto A ou B?\n");
                    conj = getchar();
                    conj = toupper(conj);
                }while(conj != 'A' && conj != 'B');

                if (conj=='A'){

                    amostra(A, &m, conj);
                }else{

                    amostra(B, &n, conj);
                }
                printf("Aperte qualquer tecla para continuar.\n");
                conj = getchar();
                conj = getchar();
            break;

            case 4:

                do{

                    system("cls");
                    printf("Você escolheu a opção %d\n", op);
                    printf("Ordernar um dos conjuntos\n");
                    printf("Ordenar o conjunto A ou B?\n");
                    conj = getchar();
                    conj = toupper(conj);
                }while(conj != 'A' && conj != 'B');

                if (conj=='A'){


                }else{



                }
                printf("Conjunto ordenado.\nAperte qualquer tecla para continuar.\n");
                conj = getchar();
                conj = getchar();
            break;

            case 5:

                system("cls");
                printf("Você escolheu a opção %d\n", op);
                printf("Encontrar a interseção entre A e B.\n");

                printf("Aperte qualquer tecla para continuar.\n");
                conj = getchar();
                conj = getchar();
            break;

            case 6:

                system("cls");
                printf("Você escolheu a opção %d\n", op);
                printf("Encontrar a união entre A e B.\n");

                printf("Aperte qualquer tecla para continuar.\n");
                conj = getchar();
                conj = getchar();
            break;

            case 7:

                system("CLS");
                printf("Você escolheu a opção %d\n", op);
                printf("Encontrar a diferença A-B.\n");

                printf("Aperte qualquer tecla para continuar.\n");
                conj = getchar();
                conj = getchar();
            break;

            case 8:

                system("cls");
                printf("Você escolheu a opção %d\n", op);
                printf("Encontrar a diferença B-A.\n");

                printf("Aperte qualquer tecla para continuar.\n");
                conj = getchar();
                conj = getchar();
            break;

            case 9:

                do{

                    system("cls");
                    printf("Você escolheu a opção %d\n", op);
                    printf("Procurar um elemento em um dos Conjuntos.\n");
                    printf("Pesquisar no conjunto A ou B?\n");
                    conj = getchar();
                    conj = toupper(conj);
                }while(conj != 'A' && conj != 'B');

                if (conj=='A'){



                }else{




                }
                printf("Aperte qualquer tecla para continuar.\n");
                conj = getchar();
                conj = getchar();
            break;

            case 10:

                do{

                    system("cls");
                    printf("Você escolheu a opção %d\n", op);
                    printf("Procurar por elementos repetidos em um dos Conjuntos.\n");
                    printf("Pesquisar no conjunto A ou B?\n");
                    conj = getchar();
                    conj = toupper(conj);
                }while(conj != 'A' && conj != 'B');

                if (conj=='A'){



                }else{




                }
                printf("Aperte qualquer tecla para continuar.\n");
                conj = getchar();
                conj = getchar();
            break;

            default:

                printf("Opção inválida.\nAperte qualquer tecla para continuar.\n");
                conj = getchar();
                conj = getchar();
            break;
		}
	}while ( continua() );

	return 0;
}

