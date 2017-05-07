#include "Main.h"
#include <string.h>


/*
Função que inicializa a lista de jogadas
*/
JogadasPtr IniciaLista()
{
	JogadasPtr head = NULL;
	return head;
}


/*
Função que aloca memória para uma nova jogada
*/
JogadasPtr NovaJogada(PecaPtr peca, Vetor movimento)
{
	JogadasPtr nova = (JogadasPtr)malloc(sizeof(Jogadas));
	nova->peca = peca;
	nova->movimento = movimento;
	nova->next = NULL;
	return nova;
}

bool ComparaPecas(PecaPtr peca1, PecaPtr peca2)
{
	if (peca1->posicao.X == peca2->posicao.X)
		if (peca1->posicao.Y == peca2->posicao.Y)
			if (strcmp(peca1->tipo, peca2->tipo) == 0)
				return true;
	return false;
}


bool EncontraPeca(PecaPtr peca, PecaPtr head)
{
	PecaPtr aux = head;
	while(!aux)
	{
		if (ComparaPecas(peca, aux) == true)
			return true;
		aux = aux->next;
	}
	return false;
}



/*
Funcão que insere a jogada mais recente na última posição da lista de jogadas
*/
JogadasPtr Inserir(JogadasPtr head, JogadasPtr novo)
{
	JogadasPtr aux = head;
	if (head == NULL) head = novo;
	else
	{
		while (aux->next != NULL)
		{
			aux = aux->next;
		}
		aux->next = novo;
	}

	return head;
}


/*
Função para libertar a lista de jogadas da memória
*/
void FreeLista(JogadasPtr head)
{
	JogadasPtr aux = head;
	JogadasPtr aux2 = aux;
	while (aux->next != NULL)
	{
		aux = aux->next;
		free(aux2);
		aux2 = aux;
	}
	free(aux);

	//return NULL;
}