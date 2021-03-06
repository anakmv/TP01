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

void FloodFillNR(PGM *entrada, int x, int y, unsigned char corAtual, unsigned char novaCor, PGM *saida)
{
    if (corAtual == novaCor) return;

    TipoPilha pilha;
    FPVazia(&pilha);

    TipoItem pixel;

    pixel.X = x;
    pixel.Y = y;
 
    Empilha(&pilha, pixel);

    while(Vazia(pilha) == 0){
        Desempilha(&pilha, &pixel);
        // printf("desempilhou: %d %d\n",pixel.X,pixel.Y);

        if(entrada->imagem[pixel.X][pixel.Y] == corAtual){
            entrada->imagem[pixel.X][pixel.Y] = novaCor;
            saida->imagem = entrada->imagem;

            //testa condições de fronteira do pixel leste
            if ((pixel.X+1)>=0 && (pixel.X+1)<entrada->l){
                // printf("empilhou leste\n");
                TipoItem leste;
                leste = pixel;
                leste.X++;
                Empilha(&pilha, leste);
            }
            //testa condições de fronteira do pixel oeste
            if ((pixel.X-1)>=0 && (pixel.X-1)<entrada->l){
                // printf("empilhou oeste\n");
                TipoItem oeste;
                oeste = pixel;
                oeste.X--;
                Empilha(&pilha, oeste);
            }
            //testa condições de fronteira do pixel norte
            if ((pixel.Y+1)>=0 && (pixel.Y+1)<entrada->c){
                // printf("empilhou norte\n");
                TipoItem norte;
                norte = pixel;
                norte.Y++;
                Empilha(&pilha, norte);
            }
            //testa condições de fronteira do pixel sul
            if ((pixel.Y-1)>=0 && (pixel.Y-1)<entrada->c){
                // printf("empilhou sul\n");
                TipoItem sul;
                sul = pixel;
                sul.Y--;
                Empilha(&pilha, sul);
            }
        }
    } 
}

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

void FloodFillNR8(PGM *entrada, int x, int y, unsigned char corAtual, unsigned char novaCor, PGM *saida)
{
    if (corAtual == novaCor) return;

    TipoPilha pilha;
    FPVazia(&pilha);

    TipoItem pixel;

    pixel.X = x;
    pixel.Y = y;
 
    Empilha(&pilha, pixel);

    while(Vazia(pilha) == 0){
        Desempilha(&pilha, &pixel);
        // printf("desempilhou: %d %d\n",pixel.X,pixel.Y);

        if(entrada->imagem[pixel.X][pixel.Y] == corAtual){
            entrada->imagem[pixel.X][pixel.Y] = novaCor;
            saida->imagem = entrada->imagem;

            //testa condições de fronteira do pixel leste
            if ((pixel.X+1)>=0 && (pixel.X+1)<entrada->l){
                // printf("empilhou leste\n");
                TipoItem leste;
                leste = pixel;
                leste.X++;
                Empilha(&pilha, leste);
            }
            //testa condições de fronteira do pixel oeste
            if ((pixel.X-1)>=0 && (pixel.X-1)<entrada->l){
                // printf("empilhou oeste\n");
                TipoItem oeste;
                oeste = pixel;
                oeste.X--;
                Empilha(&pilha, oeste);
            }
            //testa condições de fronteira do pixel norte
            if ((pixel.Y+1)>=0 && (pixel.Y+1)<entrada->c){
                // printf("empilhou norte\n");
                TipoItem norte;
                norte = pixel;
                norte.Y++;
                Empilha(&pilha, norte);
            }
            //testa condições de fronteira do pixel sul
            if ((pixel.Y-1)>=0 && (pixel.Y-1)<entrada->c){
                // printf("empilhou sul\n");
                TipoItem sul;
                sul = pixel;
                sul.Y--;
                Empilha(&pilha, sul);
            }
            //testa condições de fronteira do pixel sudeste
            if ((pixel.X+1)>=0 && (pixel.X+1)<entrada->l && (pixel.Y-1)>=0 && (pixel.Y-1)<entrada->c){
                // printf("empilhou sudeste\n");
                TipoItem sudeste;
                sudeste = pixel;
                sudeste.X++;
                sudeste.Y--;
                Empilha(&pilha, sudeste);
            }
            //testa condições de fronteira do pixel sudoeste
            if ((pixel.X-1)>=0 && (pixel.X-1)<entrada->l && (pixel.Y-1)>=0 && (pixel.Y-1)<entrada->c){
                // printf("empilhou sudoeste\n");
                TipoItem sudoeste;
                sudoeste = pixel;
                sudoeste.X--;
                sudoeste.Y--;
                Empilha(&pilha, sudoeste);
            }
            //testa condições de fronteira do pixel nordeste
            if ((pixel.X+1)>=0 && (pixel.X+1)<entrada->l && (pixel.Y-1)>=0 && (pixel.Y-1)<entrada->c){
                // printf("empilhou nordeste\n");
                TipoItem nordeste;
                nordeste = pixel;
                nordeste.X++;
                nordeste.Y++;
                Empilha(&pilha, nordeste);
            }
        }
    } 
}