#ifndef PILHA_H
#define PILHA_H


typedef unsigned char TipoChave;

typedef struct {
	int X;
	int Y;
}TipoItem;

typedef struct Celula *Apontador;

typedef struct Celula
{
	TipoItem Item;
	Apontador Prox;
}Celula;

typedef struct 
{
	Apontador Fundo, Topo;
	int Tamanho;
}TipoPilha;

void FPVazia(TipoPilha* Pilha);

int Vazia(TipoPilha Pilha);

void Empilha(TipoPilha* Pilha, TipoItem x);

void Desempilha(TipoPilha* Pilha, TipoItem* item);

#endif