#include "Main.h"
#include <string.h>


TabuleiroPtr CreateBoard()
{

	TabuleiroPtr board = (TabuleiroPtr)malloc(sizeof(Tabuleiro));
	int numPeca = 1;
	//(*board)[1][1] = a;

	for (int x = 0; x < SIZE; x++)					//x = linhas
	{
		for (int y = 0; y < SIZE; y++)				//y = colunas
		{
			if ((x == 0 || x == 7) && y == 4)
			{
				if(x == 0)
					(*board)[x][y] = CriarRei(numPeca, x, y, false);
				else
					(*board)[x][y] = CriarRei(numPeca, x, y, true);
				numPeca++;
			}

			else if (x <= 1 || x >= 6)
			{
				if (x <= 1)
					(*board)[x][y] = CriarPeao(numPeca, x, y, false);
				else
					(*board)[x][y] = CriarPeao(numPeca, x, y, true);
				
				numPeca++;
			}

			else (*board)[x][y] = NULL;

		}
	}

	return board;
}


/*
Fun��o para criar uma pe�a Pe�o
*/
PecaPtr CriarPeao(int numPeca, int x, int y, bool isPlayer)
{
	PecaPtr peao = (PecaPtr)malloc(sizeof(Peca));
	peao->numPeca = numPeca;
	peao->posicao.X = x;
	peao->posicao.Y = y;
	if (!isPlayer) peao->visualPeca = '�';		//189 em ASCII		alt+189
	else peao->visualPeca = 'c';
	char* a = "Peao";
	peao->tipo = a;

	return peao;
}


/*
Fun��o para criar a pe�a Rei
*/
PecaPtr CriarRei(int numPeca, int x, int y, bool isPlayer)
{
	PecaPtr rei = (PecaPtr)malloc(sizeof(Peca));
	rei->numPeca = numPeca;
	rei->posicao.X = x;
	rei->posicao.Y = y;
	if (!isPlayer) rei->visualPeca = '�';		//157 em ASCII		alt+157
	else rei->visualPeca = 'O';
	char* a = "Rei";
	rei->tipo = a;

	return rei;
}

void Jogar()
{
	TabuleiroPtr a = CreateBoard();
	ImprimirTabuleiro(a);
}


PecaPtr RetirarPeca(TabuleiroPtr board,  int x, int y, PecaPtr listaPecas)
{
	if (EncontraPeca((*board)[x][y], listaPecas) == true)
		return (*board)[x][y];
	return NULL;
}

bool VerificarJogada(PecaPtr peca, Vetor movimento)
{
	//Peoes e Rei
	if (strcmp(peca->tipo, "peao") == 0 || strcmp(peca->tipo, "rei") == 0)
	{
		if (movimento.X == 1 || movimento.X == -1 || movimento.X == 0)
			if (movimento.Y == 1 || movimento.Y == -1 || movimento.Y == 0)
				return true;
		return false;
	}
	/*else if(strcmp((peca->tipo), "rainha"))
	{
		if(movimento.X == 0)
			if(movimento.Y > )
	}*/
	return false;
}


TabuleiroPtr MexerPeca(TabuleiroPtr board, JogadasPtr jogada)
{

	return board;
}