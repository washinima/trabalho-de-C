#include "Main.h"
#include <string.h>

/*
 * Fun�ao que cria o Tabuleiro e mete as pe�as em cada jogador respetivamente
 *		Ainda nao esta acabada
 */
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


/*
 * Retorna o apontador para a pe�a se esta estiver numa lista 
 */
PecaPtr RetirarPeca(TabuleiroPtr board,  int x, int y, PecaPtr listaPecas)
{
	if (EncontraPeca((*board)[x][y], listaPecas) == true)
		return (*board)[x][y];
	return NULL;
}

/*
 * Fun�ao que verifica o se a jogada esta valida dependendo do tipo de pe�a
 *			Ainda nao esta acabada
 *				Falta verificar se ela sai do campo
 *				E o acrescentar o codigo para outros tipos de pe�a
 */
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

/*
 * Fun�ao que mexe a Pe�a.
 *		Falta meter a pe�a a comer outra, caso esteja la.
 */
TabuleiroPtr MexerPeca(TabuleiroPtr board, JogadasPtr jogada, PlayerPtr player)
{
	int x = jogada->peca->posicao.X, y = jogada->peca->posicao.Y;
	(*board)[x + jogada->movimento.X][y + jogada->movimento.Y] = (*board)[x][y];
	(*board)[x][y] = NULL;
	return board;
}

/*
 * Fun�ao que controla o jogo
 */
void Jogar()
{
	/*
	 * Fazer fun�ao para criar jogadores. 
	 * Criar os dois jogadores aqui.
	 * Modificar a CreateBoard para ter os dois jogadores.
	 * Fazer uma fun�ao que verifica se acabou o jogo.
	 * 
	 * 
	 * Montar a Jogar com as fun�oes que temos
	 * 
	 * Maquina de Estados a correr isto ate acabar o jogo
	 * Imprimir o Tabuleiro -> Escolher a Jogada -> Fazer a Jogada -> Passar o Turno
	 */
	TabuleiroPtr a = CreateBoard();
	ImprimirTabuleiro(a);
}
