#include "Main.h"
#include <string.h>


TabuleiroPtr CreateBoard()
{

	TabuleiroPtr board = (TabuleiroPtr)malloc(sizeof(Tabuleiro));

	//(*board)[1][1] = a;

	return board;
}


/*
Fun��o para criar uma pe�a pe�o com apenas o tipo inicializado a Pe�o

O n�mero da pe�a e posi��o s�o inicializadas no CreateBoard()
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


