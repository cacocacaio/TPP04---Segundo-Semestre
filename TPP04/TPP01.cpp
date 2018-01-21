#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

#define max 100
#define clear() printf("\033[H\033[J") // printf para limpar a tela no prompt de comando do linux, por algum motivo os comandos e função padrões para limar a tela não funcionaram.

int menu(void){ // Função que mostra as opções que o usuário tem para escolher

	int opcao;
	printf("Bem vindo ao programa, opções para escolher o que seja feito abaixo\nCriadores do programa: Juan Cardosos da Silva e Caio Nogueira\n\n");
    printf("******************************************************************\n");
	printf("*Opção 01: Gerar valores aleatorios                              *\n");
	printf("*Opção 02: Adicionar valores manualmente                         *\n");
	printf("*Opção 03: Exibir um dos Conjuntos                               *\n");
	printf("*Opção 04: Ordenar um dos conjuntos                              *\n");
	printf("*Opção 05: Encontrar a interseção entre A e B                    *\n");
	printf("*Opção 06: Encontrar a união entre A e B                         *\n");
	printf("*Opção 07: Encontrar a diferença A-B                             *\n");
	printf("*Opção 08: Encontrar a diferença B-A                             *\n");
	printf("*Opção 09: Procurar um elemento em um dos Conjuntos              *\n");
	printf("*Opção 10: Procurar por elementos repetidos em um dos Conjuntos  *\n");
    printf("******************************************************************\n\n");
	printf("Digite a sua opção: ");
	scanf("%d", &opcao);

	return (opcao);
}

short continua(){ // Função que pergunta se o usuário quer continuar o programa

	int ch;

	do{ // outro loop para verificação da opção escolhida

        system("cls");
		printf("Deseja continuar executando o programa?\nResponda S para sim e N para não:\n");
		ch = getchar();// usamos o getchar e especificaos que queremos apenas o s e n independente se for maiúscula e minúscula
	    ch = toupper(ch);

	} while ((ch != 'S') && (ch != 'N'));
	if (ch == 'S') return 1;
	else return 0;
}

void randomizerinator(int *A, int tam){ // Função que gera valores aleatórios para os conjuntos, usando como base até 100 valores aleatórios(valores aleatórios de 0-100).

    srand((unsigned)time(NULL));
    for (int i=0; i<tam; i++){

        *(A+i) = rand()%tam;
    }
}

void amostra(int *A, int tam, char conj){ // Função que mosra os valores que foram armazenado nos conjuntos.

    clear();
    for (int i=0; i<tam; i++){

        printf("%c[%d] = %d\n", conj, i, *(A+i));
    }
}

void Troca1(int *S, int Ind1, int Ind2) { // Função para troca dos valores.

    int aux;

    aux =  *(S+Ind1);
    *(S+Ind1) =  *(S+Ind2);
    *(S+Ind2) = aux;
} // Troca1

void ordena(int *A, int tam){ // Funçãp que ordena os valores dos conjuntos.

    int i=1, j, continua=1, exp1;

    while ( (i < tam ) && continua ) { // controla o numero de varreduras

        continua = 0;
        exp1 = tam-i;
        for (j = 0; j < exp1; j++) {  // aponta para as posicoes do array

            if ( *(A+j) > *(A+j+1) ) {

                // permutando elementos
                Troca1(A,j,j+1);
                continua = 1;          // realizou uma troca
            }
        }
        i++;
    }
    return;
}

void manulinator(int *A, int *tam, char conj){ // Função para adicionar valores manualmente , o usuário escolhe quais valores e o tamanho do conjunto

    memset(A, 0, max*sizeof(*A));
    printf("Quantos valores deseja adicionar?\n");
    scanf("%d", tam);

    for (int i=0; i<*tam; i++){

        printf("%c[%02d] = ", conj, i);
        scanf("%d", (A+i));
    }
}

void unilator(int *A, int *B, int tamA, int tamB){  //Função que faz a união entre os conjuntos A e B.

    int c[tamA + tamB];

    for (int i = 0; i<tamA; i++){

        c[i] = *(A+i);
    }

    for (int i = tamA; i<(tamB+tamA); i++){

        c[i] = *(B+i-tamA);
    }

    ordena (c, tamA+tamB);
    amostra(c, tamA+tamB, 'C');
}

void intersecao(int *A, int *B, int tamA, int tamB){ // Função para achar a interceção dos conjuntos.

    int c[tamA + tamB], tamC=0, rept=0;

    for (int i=0; i<tamA; i++){ // início do primeiro for

        for (int j=0; j<tamB; j++){ // segundo for

            if (*(A+i) == *(B+j)){ // terceiro for 

                rept = 0;
                for (int k=0; k<tamC; k++){ // quarto for

                    if (*(A+i) == *(c+k)){

                        rept = 1;
                    }
                } // fim do quarto for

                if (!rept){

                    *(c+tamC) = *(A+i); // Armazena os valores do conjunto de A para o conjunto C, assim criando a interceção.
                    tamC++;
                }
            } // fim do terceiro for
        } // fim do segundo for
    } // fim do primeiro for

    ordena (c, tamC);
    amostra(c, tamC, 'C');
    if (!tamC) printf("Não há interseção entre os conjuntos.");
}

void segregacao(int *A, int *B, int tamA, int tamB){

    int c[tamA], tamC=0, rept=0;

    for (int i=0; i<tamA; i++){

        rept = 0;
        for (int j=0; j<tamB; j++){

            if (*(A+i) == *(B+j)){

                rept = 1;
            }
        }

        for (int k=0; k<tamC; k++){

            if (*(A+i) == *(c+k)){

                rept = 1;
            }
        }

        if (!rept){

            *(c+tamC) = *(A+i);
            tamC++;
        }
    }

    ordena (c, tamC);
    amostra(c, tamC, 'C');
    if (!tamC) printf("Não há diferença entre os conjuntos.");
}

short Busca_Binaria_Iterativa(int *Str, int Chave, int Dim) // Função busca 
     {

    int ini = 0,   // indice que indica a posicao inicial do intervalo
        meio,      // indice que indica a posicao central do intervalo
        fim = Dim-1; // indice que indica a posicao final do intervalo

    while ( ini <= fim) {

        meio = (ini+fim)/2;
        if ( *(Str+meio) == Chave ) return(1); // elemento pertence ao array
        else if ( Chave < *(Str+meio) ) fim = meio - 1;
        else ini = meio + 1;
    }

    return(0);  // elemento nao pertence ao array
}  // Busca_Linear

void pesquisa(int *A, int tamA, char conj){

    int valor;

    printf("Que valor deseja encontrar?");
    scanf("%d", &valor);

    if (Busca_Binaria_Iterativa(A, valor, tamA)){

        printf("O valor %d está presente no conjunto %c.\n", valor, conj);
    }else{

        printf("O valor %d não está presente no conjunto %c.\n", valor, conj);
    }

}

void repetido(int *A, int tamA, char conj) // Verifica se existem valores repetidos na função.
    { // início da função

    int valor, rept = 0;

    for (int i = 0; i<tamA; i++){ //primeiro for

        for (int j = i+1; j<tamA; j++){ // segundo for

            if (*(A+i) == *(A+j)){ // início do if

                rept = 1;
            } // fim do if
        }// fim do segundo for
    } // fim do primeiro for
    if (rept) printf("Há valores repetidos no conjunto %c.\n", conj);
    else printf("Não há valores repetidos no conjunto %c.\n", conj);
} // fim da função

int main(){

	setlocale(LC_ALL, "Portuguese");
    int A[max], B[max], op=0, m=0, n=0;
    char conj;

	do { // Iníio do loop depois de fazer a escolha

		op = menu(); // Aqui a variavel op vai verificar qual opção foi esolhida e assim ir para o switch com o número escolhido

		switch(op){

            case 1: //Gerar Valores Aleatorios

                do{
                	system("cls");
                    printf("Você escolheu a opção %d\n", op);
                    printf("Gerar valores aleatorios para o conjunto A ou para o conjunto B?\n");
                    conj = getchar();
                    conj = toupper(conj);
                }while(conj != 'A' && conj != 'B');

                if (conj=='A'){

                    randomizerinator(A, max);
                    m = max;
                }else{

                    randomizerinator(B, max);
                    n=max;
                }
                printf("Valores gerados aleatoriamente.\nAperte qualquer tecla para continuar.\n");
                conj = getchar();
                conj = getchar();
            break;

            case 2: // Adicionar valores manualmente

                do{

                    system("cls");
                    printf("Você escolheu a opção %d\n", op);
                    printf("Gerar valores manualmente para o conjunto A ou o conjunto B?\n");
                    conj = getchar();
                    conj = toupper(conj);
                }while(conj != 'A' && conj != 'B');

                if (conj=='A'){

                    manulinator(A, &m, conj);
                }else{

                    manulinator(B, &n, conj);
                }
                printf("Valores adicionados.\nAperte qualquer tecla para continuar.\n");
                conj = getchar();
                conj = getchar();
            break;

            case 3: //Exibir um dos Conjuntos 

                do{

                    system("cls");
                    printf("Você escolheu a opção %d\n", op);
                    printf("Exibir um dos conjuntios\n");
                    printf("Visualizar o conjunto A ou B?\n");
                    conj = getchar();
                    conj = toupper(conj);
                }while(conj != 'A' && conj != 'B');

                if (conj=='A'){

                    amostra(A, m, conj);
                }else{

                    amostra(B, n, conj);

                }
                printf("Aperte qualquer tecla para continuar.\n");
                conj = getchar();
                conj = getchar();
            break;

            case 4: // Ordenar um dos conjuntos  

                do{
					
                    system("cls");
                    printf("Você escolheu a opção %d\n", op);
                    printf("Ordernar um dos conjuntos\n");
                    printf("Ordenar o conjunto A ou B?\n");
                    conj = getchar();
                    conj = toupper(conj);
                }while(conj != 'A' && conj != 'B');

                if (conj=='A'){

                    ordena(A, m);
                }else{

                    ordena(B, n);

                }
                printf("Conjunto ordenado.\nAperte qualquer tecla para continuar.\n");
                conj = getchar();
                conj = getchar();
            break;

            case 5: //  Encontrar a interseção entre A e B 

                system("cls");
                printf("Você escolheu a opção %d\n", op);
                printf("Encontrar a interseção entre A e B.\n");
                intersecao(A, B, m, n);
                printf("Aperte qualquer tecla para continuar.\n");
                conj = getchar();
                conj = getchar();
            break;

            case 6: // Encontrar a união entre A e B  

                system("cls");
                printf("Você escolheu a opção %d\n", op);
                printf("Encontrar a união entre A e B.\n");
                unilator(A, B, m, n);
                printf("Aperte qualquer tecla para continuar.\n");
                conj = getchar();
                conj = getchar();
            break;

            case 7: // Encontrar a diferença A-B 
                
                clear();
                printf("Você escolheu a opção %d\n", op);
                printf("Encontrar a diferença A-B.\n");
                segregacao(A, B, m, n);
                printf("Aperte qualquer tecla para continuar.\n");
                conj = getchar();
                conj = getchar();
            break;

            case 8: // Encontrar a diferença B-A 

                system("cls");
                printf("Você escolheu a opção %d\n", op);
                printf("Encontrar a diferença B-A.\n");
                segregacao(B, A, n, m);
                printf("Aperte qualquer tecla para continuar.\n");
                conj = getchar();
                conj = getchar();
            break;

            case 9: // Procurar um elemento em um dos Conjuntos

                do{

                    system("cls");
                    printf("Você escolheu a opção %d\n", op);
                    printf("Procurar um elemento em um dos Conjuntos.\n");
                    printf("Pesquisar no conjunto A ou B?\n");
                    conj = getchar();
                    conj = toupper(conj);
                }while(conj != 'A' && conj != 'B');

                if (conj=='A'){

                    ordena(A, m);
                    pesquisa(A, m, conj);
                }else{

                    ordena(B, n);
                    pesquisa(B, n, conj);

                }
                printf("Aperte qualquer tecla para continuar.\n");
                conj = getchar();
                conj = getchar();
            break;

            case 10: // Procurar por elementos repetidos em um dos Conjuntos

                do{

                    system("cls");
                    printf("Você escolheu a opção %d\n", op);
                    printf("Procurar por elementos repetidos em um dos Conjuntos.\n");
                    printf("Pesquisar no conjunto A ou B?\n");
                    conj = getchar();
                    conj = toupper(conj);
                }while(conj != 'A' && conj != 'B');

                if (conj=='A'){

                    ordena(A, m);
                    repetido(A, m, conj);
                }else{

                    ordena(B, n);
                    repetido(B, n, conj);

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
	}while ( continua() ); // O while aqui estÃ¡ sendo utilizado para criar o loop, esse caso ele verifica a opÃ§Ã£o da funÃ§Ã£o continua

	return 0;
}
