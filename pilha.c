#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "pilha.h"


void FPVazia(TipoPilha* Pilha)
{
	Pilha->Topo = (Apontador)malloc(sizeof(Celula));
	Pilha->Fundo  = Pilha->Topo;
	Pilha->Topo->Prox = NULL;
	Pilha->Tamanho = 0;
}

int Vazia(TipoPilha Pilha)
{
	return (Pilha.Topo == Pilha.Fundo);
}

void Empilha(TipoPilha* Pilha, TipoItem x)
{
	Apontador Aux;
	Aux = (Apontador) malloc(sizeof(Celula));
	Pilha->Topo->Item = x;
	Aux->Prox = Pilha->Topo;
	Pilha->Topo = Aux;
	Pilha->Tamanho++;
}

void Desempilha(TipoPilha *Pilha, TipoItem *item)
{
	Apontador q;
	if(Vazia(*Pilha)){
		printf("Pilha vazia\n"); 
	return;
	}
	q = Pilha->Topo;
	Pilha->Topo = q->Prox;
	*item = q->Prox->Item; 
	free(q);
	Pilha->Tamanho--;
}






