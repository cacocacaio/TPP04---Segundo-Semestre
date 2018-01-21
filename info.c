
#include "main.h"
#include "info_helper.h"

void info(char **arg_v)
{

    //Aqui estamos mostrando todoas as inform��es necess�rias para executar o programa com par�metros
    //Como o projeto foi feito no code::blocks talvez n�o seja poss�vel usar os executar par�metros do Dev-C++

            printf("Informa��es sobre o programa:\n\n");
            printf("***Este programa realiza as seguintes oper��es********\n\n");

            printf("\n OBS: O programa realiza opera��es com arquivos em bin�rio e em formato de texto.\n\n\n");

            printf("******************************************************\n");
            printf("*1 - Cria um conjunto                                *\n");
            printf("*2 - Realiza intersec��o entre os conjuntos          *\n");
            printf("*3 - Realiza a uni�o entre os conjuntos              *\n");
            printf("*4 - Realiza a diferen�a entre os conjuntos (A - B)  *\n");
            printf("*4 - Realiza a diferen�a entre os conjuntos (B - A)  *\n");
            printf("*5 - Mostra um conjunto a tela do CMD                *\n");
            printf("******************************************************\n");
            printf("\n\n\n");

            //Todos os conjuntos s�o armazenados em um tipo de arquivo.

            printf("Par�metros a ser utilizado no ao executar o programa:\n\n");
            printf("1 - [...]\\main.exe t arquivo quantidade_de_elementos\n");// cria um conjunto em texto
            printf("1 - [...]\\main.exe b arquivo quantidade_de_elementos\n\n"); // cria um conjunto em bin�rio
            printf("2 - [...]\\main.exe t 1 arquivo1.txt arquivo2.txt arquivo3\n");//Intersec��o entre conjuntos em texto
            printf("2 - [...]\\main.exe b 1 arquivo1.bin arquivo2.bin arquivo3\n\n");//Intersec��o entre conjuntos em bin�rio
            printf("3 - [...]\\main.exe t 2 arquivo1.txt arquivo2.txt arquivo3\n");// Uni�o entre conjuntos em texto
            printf("3 - [...]\\main.exe b 2 arquivo1.bin arquivo2.bin arquivo3\n\n");// Uni�o entre conjuntos em bin�rio
            printf("4 - [...]\\main.exe t 3 arquivo1.txt arquivo2.txt arquivo3\n");//A - B Texto
            printf("4 - [...]\\main.exe b 3 arquivo1.bin arquivo2.bin arquivo3\n\n");//A - B Bin�rio
            printf("4 - [...]\\main.exe t 3 arquivo2.txt arquivo1.txt arquivo3\n"); //faz B - A Texto
            printf("4 - [...]\\main.exe b 3 arquivo2.bin arquivo1.bin arquivo3\n\n"); // faz B - A Bin�rio
            printf("5 - [...]\\main.exe t arquivo\n"); //Mostra arquivo em texto
            printf("5 - [...]\\main.exe b arquivo\n\n\n"); //Mostra arquivo em bin�rio

            printf("[...]\\main.exe ---> abre esta p�gina com informa��es\n\n");

}
