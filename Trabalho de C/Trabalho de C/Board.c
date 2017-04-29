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
				(*board)[x][y] = CriarRei(numPeca, x, y);
				numPeca++;
			}

			else if (x <= 1 || x >= 6)
			{
				(*board)[x][y] = CriarPeao(numPeca, x, y);
				numPeca++;
			}

			else (*board)[x][y] = NULL;

		}
	}

	return board;
}


/*
Função para criar uma peça Peão
*/
PecaPtr CriarPeao(int numPeca, int x, int y)
{
	PecaPtr peao = (PecaPtr)malloc(sizeof(Peca));
	peao->numPeca = numPeca;
	peao->posicao.X = x;
	peao->posicao.Y = y;
	if (numPeca < 17) peao->visualPeca = '¢';		//189 em ASCII		alt+189
	else peao->visualPeca = 'c';
	char* a = "Peao";
	peao->tipo = a;

	return peao;
}


/*
Função para criar a peça Rei
*/
PecaPtr CriarRei(int numPeca, int x, int y)
{
	PecaPtr rei = (PecaPtr)malloc(sizeof(Peca));
	rei->numPeca = numPeca;
	rei->posicao.X = x;
	rei->posicao.Y = y;
	if (numPeca == 5) rei->visualPeca = 'Ø';		//157 em ASCII		alt+157
	else rei->visualPeca = 'O';
	char* a = "Rei";
	rei->tipo = a;

	return rei;
}