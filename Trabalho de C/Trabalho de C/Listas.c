#include <stdlib.h>
#include "Main.h"


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
JogadasPtr NovaJogada(PecaPtr peca, Coordenadas movimento)
{
	JogadasPtr nova = (JogadasPtr)malloc(sizeof(Jogadas));
	nova->peca = peca;
	nova->movimento = movimento;
	nova->next = NULL;
	return nova;
}


/*
Funcão que insere a jogada mais recente na última posição da lista de jogadas
*/
JogadasPtr Inserir(JogadasPtr head, JogadasPtr novo)
{
	JogadasPtr aux = head;
	if (aux == NULL) aux = novo;
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