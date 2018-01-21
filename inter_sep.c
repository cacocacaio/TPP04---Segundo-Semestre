
#include "main.h"
#include "inter_sep.h"

FILE *f;
FILE *f1;
FILE *f2;

void inter_sep(char **arg_v)
{

    int i,j,aux=0,aux1=0;
    char *arquivo,*arquivo2,*arquivo3;

    arquivo = arg_v[3];
    arquivo2 = arg_v[4];
    arquivo3 = arg_v[5];

    if (*arg_v[1]=='t') strcat(arquivo3, ".txt");
    else if (*arg_v[1]=='b') strcat(arquivo3, ".bin");
    else{

        printf("Tipo incorreto de arquivo!");
        system("pause");
        exit(1);
    }

    if(*arg_v[1]=='t')
    {

        if( (f=fopen(arquivo, "r") ) == NULL) {
        printf("ERRO na abertura do arquivo: %s!!! O arquivo está criado? \n", arquivo);
        exit(1);
        }

        if( (f1=fopen(arquivo2, "r") ) == NULL) {
        printf("ERRO na abertura do arquivo: %s!!! O arquivo está criado? \n", arquivo2);
        exit(1);
        }
        if( (f2=fopen(arquivo3, "w+") ) == NULL) {
        printf("ERRO na abertura do arquivo: %s!!! O arquivo está criado? \n", arquivo3);
        exit(1);
        }



        while(!feof(f)) //Faz intersecção de dois conjuntos e cria um terceiro arquivo onde será armazenado (texto)
        {
        fscanf(f, "%d", &aux);

            rewind(f1);

            while(!feof(f1))
                {
                fscanf(f1, "%d", &aux1);
                    if(aux == aux1)
                        {
                        fprintf(f2, "%d\n", aux);
                        }
                }
        }

    }

                fclose(f);
                fclose(f1);
                fclose(f2);
                printf("Arquivos fechados!!");



    if(*arg_v[1]=='b')
    {

        if( (f=fopen(arquivo, "rb") ) == NULL) {
        printf("ERRO na abertura do arquivo: %s!!! O arquivo está criado? \n", arquivo);
        exit(1);
        }

        if( (f1=fopen(arquivo2, "rb") ) == NULL) {
        printf("ERRO na abertura do arquivo: %s!!! O arquivo está criado? \n", arquivo2);
        exit(1);
        }
        if( (f2=fopen(arquivo3, "w+b") ) == NULL) {
        printf("ERRO na abertura do arquivo: %s!!! O arquivo está criado? \n", arquivo3);
        exit(1);
        }

        while(!feof(f))
        {

        fread(&aux,sizeof(int),1, f);

            rewind(f1);

            while(!feof(f1)) //Faz intersecção de dois conjuntos e cria um terceiro arquivo onde será armazenado ( binário)
                {
                fread(&aux1,sizeof(int),1,f1);
                    if(aux == aux1)
                    {
                    fwrite(&aux,sizeof(int),1, f2);
                    }
                }
        }



    }




}
