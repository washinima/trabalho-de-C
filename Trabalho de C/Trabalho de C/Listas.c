#include <stdio.h>
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
}


/*
Fun��o que insere a jogada mais recente na lista de jogadas
*/
JogadasPtr Inserir(JogadasPtr head, Jogadas novo)
{

}