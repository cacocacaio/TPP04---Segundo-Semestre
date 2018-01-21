
#include "main.h"
#include "cmd_mostra.h"

void cmd(char **arg_v)
{
    int x,y;
    char *arquivo;

    arquivo = arg_v[2];
    if (*arg_v[1]=='t') strcat(arquivo, ".txt");
    else if (*arg_v[1]=='b') strcat(arquivo, ".bin");
    else{
        printf("Tipo incorreto de arquivo!");
        system("pause");
        exit(1);
    }


    if(*arg_v[1]=='t'){

        if( (f=fopen(arquivo, "r") ) == NULL) {
        printf("ERRO na abertura do arquivo: %s!!!\n", arquivo);
        exit(1);
        }

        fscanf(f,"%d",&x);

    printf("Os números do arquivo %s são:\n", arquivo);

    while(!feof(f)) //Faz mostrar o conteúdo de um arquivo na tela (texto)
    {
        printf("%d\n", x);
        fscanf(f, "%d", &x);


    }
    printf("\n\n");
    fclose(f);
    printf("Arquivo fechado com sucesso!!\n\n");

    }






    if(*arg_v[1]=='b'){

        if( (f=fopen(arquivo, "rb") ) == NULL) {
        printf("ERRO na abertura do arquivo: %s!!!\n", arquivo);
        exit(1);
        }



        printf("Os números do arquivo %s são:\n", arquivo);
        while(!feof(f)) //Faz mostrar o conteúdo de um arquivo na tela (binário)
        {
                fread(&x,sizeof(int),1,f);
                printf("%d\n", x);
        }

                fclose(f);
                printf("Arquivo fechado com sucesso!!\n\n");

    }

}
