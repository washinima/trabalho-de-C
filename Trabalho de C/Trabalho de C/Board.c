#include "Main.h"


TabuleiroPtr CreateBoard()
{

	TabuleiroPtr board = (TabuleiroPtr)malloc(sizeof(Tabuleiro));

	//(*board)[1][1] = a;

	return board;
}


PecaPtr CriarPeao()
{
	PecaPtr peao = (PecaPtr)malloc(sizeof(Peca));
	peao->numPeca = NULL;
	peao->posicao.posicaoX = NULL;
	peao->posicao.posicaoY = NULL;
	char* a = (char*)malloc(sizeof("Peao"));
	*a = "Peao";
	peao->tipo = a;

	return peao;
}