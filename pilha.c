#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "pilha.h"


void FPVazia(TipoPilha* Pilha)
{
	Pilha->topo = (Apontador)malloc (sizeof(Celula));
	Pilha->fundo  = Pilha->topo;
	Pilha->topo->prox = NULL;
	Pilha->Tamanho = 0;
}

int Vazia(TipoPilha* Pilha)
{
	return (Pilha->topo == Pilha->fundo);
}

void Empilha(TipoPilha* Pilha, TipoItem x)
{
	Apontador novo;
	novo = (Apontador) malloc(sizeof(Celula));
	Pilha->topo->Item = x;
	novo->prox = Pilha->topo;
	Pilha->topo = novo;
	Pilha->Tamanho++;
}

int Desempilha(TipoPilha* Pilha, TipoItem* item)
{
	Apontador q;
	if(Vazia(Pilha)) printf("Pilha vazia"); return 0;
	q = Pilha->topo;
	Pilha->topo = q->prox;
	free(q);
	Pilha->Tamanho --;
	*item = Pilha->topo->Item; return 1; 
}






