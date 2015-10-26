#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matriz.h"
#include "floodfill.h"
#include "pilha.h"

int main(int argc, char const *argv[])
{
	unsigned char corAtual;
	unsigned char novaCor;
	PGM* entrada = LerPGM((char*)argv[1]);
	PGM* saida = New_Matriz_Pgm(entrada->l, entrada->c);
	char* ff = (char*)argv[4];

	int x = atoi(argv[2]);
	int y = atoi(argv[3]);

	corAtual = entrada->imagem [x][y];
	novaCor = 127;
	
	FloodFillNR(entrada, x, y, corAtual, novaCor, saida);

	SalvarPGM(saida, ff);

}