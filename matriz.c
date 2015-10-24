#include "matriz.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*------------------------------------------------------------------------------------------------------------------------------------
Protótipo: char ** New_Matriz_char(int linhas, int colunas)
Função: Cria uma matriz do tipo char de acordo com o o número de linhas e colunas
Entrada : Recebe um número inteiro para linhas e colunas da nova matriz
Saída : A saida é uma nova matriz do tipo char. OBS: kernel é apenas um nome de variável local.
------------------------------------------------------------------------------------------------------------------------------------*/

unsigned char ** New_Matriz_char(int linhas, int colunas)
{
    unsigned char **matriz;
    int lin_index; //Indice
    int col_index; //Indice
    matriz = (unsigned char** ) malloc(sizeof(unsigned char*)*linhas);
    for (lin_index = 0; lin_index < linhas; lin_index++)     //Para cada linha, aloca espaço para o numero de colunas
        matriz[lin_index] = (unsigned char* )malloc(sizeof(unsigned char) *colunas);
    return matriz;
}

/*------------------------------------------------------------------------------------------------------------------------------------
Protótipo: void Set_Matriz_char (char** kernel, int linha, int coluna, char element)
Função: Coloca o elemento (char) recebido em cada posição da matriz (recebida na entrada)
Entrada : Recebe a matriz para ser preenchida, a posiçao de linha e coluna, elemento a ser inserido.
Saída : -
------------------------------------------------------------------------------------------------------------------------------------*/

void Set_Matriz_char (char** matriz, int linha, int coluna, char element)
{
     matriz[linha][coluna] = element;
}

/*------------------------------------------------------------------------------------------------------------------------------------
Protótipo: char Get_Matriz_char (char** kernel,int linha, int coluna)
Função: Retornar uma determinada posiçao da matriz inserida
Entrada : Recebe a matriz e a posição
Saída : A saida é uma posiçao da matriz inserida
------------------------------------------------------------------------------------------------------------------------------------*/

char Get_Matriz_char (char** matriz,int linha, int coluna)
{
    return matriz[linha][coluna];

}

/*------------------------------------------------------------------------------------------------------------------------------------
Protótipo: char ** New_Matriz_char(int linhas, int colunas)
Função: Cria uma matriz do tipo char de acordo com o o número de linhas e colunas
Entrada : Recebe um número inteiro para linhas e colunas da nova matriz
Saída : A saida é uma nova matriz do tipo char. OBS: kernel é apenas um nome de variável local.
------------------------------------------------------------------------------------------------------------------------------------*/

char Get_Matriz_uchar(unsigned char** matriz,int linha, int coluna)
{
    return matriz[linha][coluna];

}

/*------------------------------------------------------------------------------------------------------------------------------------
Protótipo: char ** New_Matriz_char(int linhas, int colunas)
Função: Cria uma matriz do tipo char de acordo com o o número de linhas e colunas
Entrada : Recebe um número inteiro para linhas e colunas da nova matriz
Saída : A saida é uma nova matriz do tipo char. OBS: kernel é apenas um nome de variável local.
------------------------------------------------------------------------------------------------------------------------------------*/

void Print_Matriz_char  (char** matriz, int linhas, int colunas)

{
    int lin_index; //Indice
    int col_index; //Indice
    for (lin_index=0; lin_index<linhas; lin_index++){
        printf("\n" );
        for (col_index = 0; col_index<colunas; col_index++)
            printf("%3d ", matriz[lin_index][col_index] );
    }
}

/*------------------------------------------------------------------------------------------------------------------------------------
Protótipo: void Print_Matriz_uchar  (unsigned char** kernel, int linhas, int colunas)
Função: Imprimir na tela a matriz desejada do tipo unsigned char**
Entrada : Recebe dois inteiros para linhas e colunas e a matriz unsigned char** que deseja que seja mostrada na tela
Saída : -
------------------------------------------------------------------------------------------------------------------------------------*/

void Print_Matriz_uchar  (unsigned char** matriz, int linhas, int colunas)

{
    int lin_index; //Indice
    int col_index; //Indice
    for (lin_index=0; lin_index<linhas; lin_index++){
        printf("\n" );
        for (col_index = 0; col_index<colunas; col_index++)
            printf("%3d ", matriz[lin_index][col_index] );
    }
}

PGM* New_Matriz_Pgm(int linhas, int colunas)
{

    PGM* saida = (PGM*)(malloc (sizeof(PGM)));
    saida->l = linhas;
    saida->c = colunas;
    saida->maximo = 255;
    saida->imagem = New_Matriz_char(linhas,colunas);
    return saida;
}


