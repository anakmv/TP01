#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "floodfill.h"
#include "pilha.h"
#include "matriz.h"

int char2int(FILE* fp)
{
	int saida;
    fscanf(fp, "%d", &saida);
    return saida;
}

PGM* LerPGM(char* entrada)
{
	int lin;
	int col;
	FILE* fp = fopen(entrada, "r");
	PGM* img = (PGM*)malloc(sizeof(PGM));

	if(fgetc(fp) != 80 || fgetc(fp) != 50){printf("Erro: Arquivo incompatível");}   //Verifica se os dois primeiros caracteres são "P" e "2"
    fgetc(fp); 

    img->c = char2int(fp);
    img->l = char2int(fp);

    img->maximo = (unsigned char) char2int(fp);     //Pega o valor máximo de cada elemento da matriz (cada pixel)
    img->imagem = (unsigned char**) New_Matriz_char(img->l, img->c);
    for(lin = 0; lin < img->l; lin++)  //Adicona cada elemento da matriz do arquivo na matriz PGM
        for(col = 0; col<img->c; col++)
           Set_Matriz_char((char** )img->imagem, lin, col, char2int(fp) );

    fclose(fp);
    return img; 
}

void Print_Matriz_Pgm  (PGM* saida)

{
    int lin_index; //Indice
    int col_index; //Indice
    printf("%d - %d\n", saida->l, saida->c);
    for (lin_index=0; lin_index<saida->l; lin_index++){
        printf("\n" );
        for (col_index = 0; col_index<saida->c; col_index++)
            printf("%3d ", saida->imagem [lin_index][col_index] );
    }
}

void FloodFill(PGM *entrada, int x, int y, unsigned char corAtual, unsigned char novaCor, PGM *saida)
{ 
    if(x < 0 || x >= entrada->l || y < 0 || y >= entrada->c) 
        return;
    if(entrada->imagem[x][y] != corAtual)
        return;
    entrada->imagem[x][y] = novaCor;
    saida->imagem = entrada->imagem;
    FloodFill(entrada, x + 1, y, corAtual, novaCor, saida);
    FloodFill(entrada, x - 1, y, corAtual, novaCor, saida);
    FloodFill(entrada, x, y + 1, corAtual, novaCor, saida);
    FloodFill(entrada, x, y - 1, corAtual, novaCor, saida);

}

// void FloodFill(PGM *entrada, int x, int y, unsigned char corAtual, unsigned char novaCor, PGM *saida)
// {
//     TipoPilha* Aux;
//     FPVazia(Aux);
//     if (corAtual == novaCor) return;
//     while (Vazia(Aux) == 0)
//         Desempilha(Aux);
//     while(Vazia(Aux) == 0)
//     {
//         saida->imagem[y][x] = novaCor;
//         if(x + 1 < entrada->c && entrada->imagem[x + 1][y] == corAtual)
//         {          
//             if(!push(x + 1, y)) return;           
//         }    
//         if(x - 1 >= 0 && entrada->imagem[x - 1][y] == corAtual)
//         {
//             if(!push(x - 1, y)) return;           
//         }    
//         if(y + 1 < h && entrada->imagem[x][y + 1] == corAtual)
//         {
//             if(!push(x, y + 1)) return;           
//         }    
//         if(y - 1 >= 0 && entrada->imagem[x][y - 1] == corAtual)
//         {
//             if(!push(x, y - 1)) return;           
//         }    
//     }     
//}
    

void int2char (int item, FILE* fp){
    fprintf(fp, "%d", item);

}

void SalvarPGM(PGM* img, char* saida){
    int lin, col, x=0;
    FILE* fp = fopen(saida, "w");

    fputs("P2\n", fp);
    fputc(10,fp);

    int2char(img->c, fp);fputc(32,fp);
    int2char(img->l, fp);fputc(32,fp);
    int2char(img->maximo, fp);

    fputc(10, fp);
    for (lin = 0 ; lin < img->l ; lin++){
        for(col = 0 ; col < img->c ; col++){
            int2char(img->imagem[lin][col], fp);
            fputc(32,fp);


        }
fputs("\n", fp);

    }
}

