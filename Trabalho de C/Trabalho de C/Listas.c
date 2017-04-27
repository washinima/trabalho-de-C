#include <stdio.h>
#include "Main.h"


/*
Função que aloca memória para uma nova jogada
*/
JogadasPtr NovaJogada(PecaPtr peca, Coordenadas movimento)
{
	JogadasPtr nova = (JogadasPtr)malloc(sizeof(Jogadas));
	nova->peca = peca;
	nova->movimento = movimento;
	nova->next = NULL;
}


/*
Função que insere a jogada mais recente na lista de jogadas
*/
JogadasPtr Inserir(JogadasPtr head, Jogadas novo)
{

}