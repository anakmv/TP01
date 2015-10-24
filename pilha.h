#ifndef PILHA_H
#define PILHA_H
#define MaxTam 1000


typedef int TipoChave;

typedef struct {
	TipoChave Chave;
}TipoItem;

typedef struct Celula_str* Apontador;

typedef struct Celula_str
{
	TipoItem Item;
	Apontador prox;
} Celula;

typedef struct 
{
	Apontador fundo, topo;
	int Tamanho;
} TipoPilha;

void FPVazia(TipoPilha* Pilha);

int Vazia(TipoPilha* Pilha);

void Empilha(TipoPilha* Pilha, TipoItem x);

int Desempilha(TipoPilha* Pilha, TipoItem* item);

#endif