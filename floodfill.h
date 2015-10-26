#ifndef FLOODFILL_H
#define FLOODFILL_H
#include <stdio.h>
#include <stdlib.h>

typedef struct {
int c;
int l;
unsigned char maximo;
unsigned char **imagem;
} PGM;

int char2int(FILE* fp);

PGM* LerPGM(char* entrada);

void FloodFill(PGM *entrada, int x, int y, unsigned char corAtual, unsigned char novaCor, PGM *saida);

void FloodFillNR(PGM *entrada, int x, int y, unsigned char corAtual, unsigned char novaCor, PGM *saida);

void int2char (int item, FILE* fp);

void SalvarPGM(PGM* img, char* saida);

void Print_Matriz_Pgm  (PGM* saida);

#endif