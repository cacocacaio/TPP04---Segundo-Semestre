
#include "main.h"
#include "subtra_re.h"

void subtra_re(char **arg_v)
{
    int x,y,aux,aux2;
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

        while(!feof(f)){ //Faz subtração de dois conjuntos e cria um terceiro arquivo onde será armazenado (texto)
            aux = 0;
            while(!feof(f1))
            {
                fscanf(f1,"%d",&y);

                if(x==y)
                    {
                        aux = 1;
                        break;
                    }
            }

            if(!aux)
            {
            fprintf(f2,"%d\n",x);
            }
            rewind(f1);
            fscanf(f,"%d",&x);

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
        while(!feof(f)){ //Faz subtração de dois conjuntos e cria um terceiro arquivo onde será armazenado (binário)
            aux = 0;
            while(!feof(f1))
            {
                fread(&y,sizeof(int),1,f1);

                if(x==y)
                    {
                        aux = 1;
                        break;
                    }
            }

            if(!aux)
            {
            fwrite(&x,sizeof(int),1,f2);
            }
            fseek(f1,0,SEEK_SET);
            fread(&x,sizeof(int),1,f);


        }

    }
                fclose(f);
                fclose(f1);
                fclose(f2);
                printf("Arquivos fechados!!");

}
