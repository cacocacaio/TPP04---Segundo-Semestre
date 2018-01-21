
#include "main.h"
#include "info_helper.h"

void info(char **arg_v)
{

    //Aqui estamos mostrando todoas as informções necessárias para executar o programa com parâmetros
    //Como o projeto foi feito no code::blocks talvez não seja possível usar os executar parâmetros do Dev-C++

            printf("Informações sobre o programa:\n\n");
            printf("***Este programa realiza as seguintes operções********\n\n");

            printf("\n OBS: O programa realiza operações com arquivos em binário e em formato de texto.\n\n\n");

            printf("******************************************************\n");
            printf("*1 - Cria um conjunto                                *\n");
            printf("*2 - Realiza intersecção entre os conjuntos          *\n");
            printf("*3 - Realiza a união entre os conjuntos              *\n");
            printf("*4 - Realiza a diferença entre os conjuntos (A - B)  *\n");
            printf("*4 - Realiza a diferença entre os conjuntos (B - A)  *\n");
            printf("*5 - Mostra um conjunto a tela do CMD                *\n");
            printf("******************************************************\n");
            printf("\n\n\n");

            //Todos os conjuntos são armazenados em um tipo de arquivo.

            printf("Parâmetros a ser utilizado no ao executar o programa:\n\n");
            printf("1 - [...]\\main.exe t arquivo quantidade_de_elementos\n");// cria um conjunto em texto
            printf("1 - [...]\\main.exe b arquivo quantidade_de_elementos\n\n"); // cria um conjunto em binário
            printf("2 - [...]\\main.exe t 1 arquivo1.txt arquivo2.txt arquivo3\n");//Intersecção entre conjuntos em texto
            printf("2 - [...]\\main.exe b 1 arquivo1.bin arquivo2.bin arquivo3\n\n");//Intersecção entre conjuntos em binário
            printf("3 - [...]\\main.exe t 2 arquivo1.txt arquivo2.txt arquivo3\n");// União entre conjuntos em texto
            printf("3 - [...]\\main.exe b 2 arquivo1.bin arquivo2.bin arquivo3\n\n");// União entre conjuntos em binário
            printf("4 - [...]\\main.exe t 3 arquivo1.txt arquivo2.txt arquivo3\n");//A - B Texto
            printf("4 - [...]\\main.exe b 3 arquivo1.bin arquivo2.bin arquivo3\n\n");//A - B Binário
            printf("4 - [...]\\main.exe t 3 arquivo2.txt arquivo1.txt arquivo3\n"); //faz B - A Texto
            printf("4 - [...]\\main.exe b 3 arquivo2.bin arquivo1.bin arquivo3\n\n"); // faz B - A Binário
            printf("5 - [...]\\main.exe t arquivo\n"); //Mostra arquivo em texto
            printf("5 - [...]\\main.exe b arquivo\n\n\n"); //Mostra arquivo em binário

            printf("[...]\\main.exe ---> abre esta página com informações\n\n");

}
