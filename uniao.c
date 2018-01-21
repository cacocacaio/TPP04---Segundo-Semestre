#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

FILE *f;
FILE *f1;
FILE *f2;

#include "uniao_helper.h"


void uni_add(char **arg_v)
{

    int x,y;
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

    if(*arg_v[1]=='t'){

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

        fscanf(f,"%d",&x);
        fscanf(f1,"%d",&y);

        while(!(feof(f)) && !(feof(f1))) //Faz união de dois conjuntos e cria um terceiro arquivo onde será armazenado (texto)
            {
                if(x<=y)
                    {
                        fprintf(f2,"%d\n", x);
                        fscanf(f,"%d",&x);

                    }
                else
                    {
                        fprintf(f2,"%d\n", y);
                        fscanf(f,"%d",&y);

                    }

            }

                while(!(feof(f)))
                {
                fscanf(f,"%d",&x);
                fprintf(f2,"%d\n", x);


                }

                while(!(feof(f1)))
                {
                fscanf(f1,"%d",&y);
                fprintf(f2,"%d\n", y);


                }

    }


                fclose(f);
                fclose(f1);
                fclose(f2);
                printf("Arquivos fechados!!");



    if(*arg_v[1]=='b'){

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

        fread(&x,sizeof(int),1,f);
        fread(&y,sizeof(int),1,f1);

        while(!feof(f) && !feof(f1)){ //Faz união de dois conjuntos e cria um terceiro arquivo onde será armazenado ( binário)
            if(x<=y){
                fwrite(&x,sizeof(int),1,f2);
                fread(&x,sizeof(int),1,f);
            }
            else{
                fwrite(&y,sizeof(int),1,f2);
                fread(&y,sizeof(int),1,f1);
            }
        }


    }




}


