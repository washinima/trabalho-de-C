#include "Main.h"
#include <string.h>


TabuleiroPtr CreateBoard()
{

	TabuleiroPtr board = (TabuleiroPtr)malloc(sizeof(Tabuleiro));

	//(*board)[1][1] = a;

	return board;
}


/*
Função para criar uma peça peão com apenas o tipo inicializado a Peão

O número da peça e posição são inicializadas no CreateBoard()
*/
PecaPtr CriarPeao()
{
	PecaPtr peao = (PecaPtr)malloc(sizeof(Peca));
	peao->numPeca = NULL;
	peao->posicao.X = NULL;
	peao->posicao.Y = NULL;
	char* a = "Peao";
	peao->tipo = a;

	return peao;
}


