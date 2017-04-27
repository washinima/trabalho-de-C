#include <stdlib.h>
#include "Main.h"


/*
Fun��o que aloca mem�ria para uma nova jogada
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
Fun��o que insere a jogada mais recente na �ltima posi��o da lista de jogadas
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