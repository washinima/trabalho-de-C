#include "Main.h"
#include <string.h>

/*
 * Fun�ao que cria o Tabuleiro e mete as pe�as em cada jogador respetivamente
 */
TabuleiroPtr CreateBoard(PlayerPtr player1, PlayerPtr player2)
{

	TabuleiroPtr board = (TabuleiroPtr)malloc(sizeof(Tabuleiro));
	int numPeca = 1;
	PecaPtr rei, peao;
	//(*board)[1][1] = a;

	for (int x = 0; x < SIZE; x++)					//x = linhas
	{
		for (int y = 0; y < SIZE; y++)				//y = colunas
		{
			if ((x == 0 || x == 7) && y == 4)
			{
				if (x == 0)
				{
					rei = CriarRei(numPeca, x, y, false);
					(*board)[x][y] = rei;
					player2->listaPecas = InserirPeca(rei, player2->listaPecas);
				}
				else
				{
					rei = CriarRei(numPeca, x, y, true);
					(*board)[x][y] = rei;
					player1->listaPecas = InserirPeca(rei, player1->listaPecas);
				}
				numPeca++;
			}
			else if (x <= 1 || x >= 6)
			{
				if (x <= 1)
				{
					peao = CriarPeao(numPeca, x, y, false);
					(*board)[x][y] = peao;
					player2->listaPecas = InserirPeca(peao, player2->listaPecas);
				}
				else
				{
					peao = CriarPeao(numPeca, x, y, true);
					(*board)[x][y] = peao;
					player1->listaPecas= InserirPeca(peao, player1->listaPecas);
				}
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
	peao->next = NULL;
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
	rei->next = NULL;

	return rei;
}


/*
 * Retorna o apontador para a pe�a se esta estiver numa lista 
 */
PecaPtr RetirarPeca(TabuleiroPtr board,  int x, int y, PecaPtr listaPecas)
{
	if (EncontraPeca((*board)[x][y], listaPecas))
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
	if (strcmp(peca->tipo, "Peao") == 0 || strcmp(peca->tipo, "Rei") == 0)
	{
		if (movimento.X == 1 || (movimento.X == -1 || movimento.X == 0))
			if (movimento.Y == 1 || (movimento.Y == -1 || movimento.Y == 0))
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
TabuleiroPtr MexerPeca(TabuleiroPtr board, JogadasPtr jogada, PlayerPtr player, PlayerPtr playerInimigo)
{
	/*
	 * Retirar a peca a ser comida do board; Verificar de que jogador e. Se for do inimigo simplesmente come. Se for uma propria come e Verifica a evolu�ao
	 */
	int x = jogada->peca->posicao.X, y = jogada->peca->posicao.Y;

	PecaPtr comida = (*board)[x + jogada->movimento.X][y + jogada->movimento.Y];

	if(EncontraPeca(comida, player->listaPecas))
	{
		jogada->peca = Evolui(jogada->peca, comida);
		player->listaPecas = EliminarPeca(comida, player->listaPecas);
	}
	else if(EncontraPeca(comida, playerInimigo->listaPecas))
	{
		playerInimigo->listaPecas = EliminarPeca(comida, playerInimigo->listaPecas);
	}

	(*board)[x + jogada->movimento.X][y + jogada->movimento.Y] = (*board)[x][y];
	(*board)[x][y] = NULL;

	return board;
}

/*
 * Fun�ao que cria o jogador
 */
PlayerPtr CriarJogador(bool isPlayer)
{
	PlayerPtr a = (PlayerPtr)malloc(sizeof(Player));
	a->listaJogadas = NULL;
	a->listaPecas = NULL;
	a->player = isPlayer;

	return a;
}

/*
 * Fun�ao que verifica o fim do jogo. Ou seja um jogador nao ter rei.
 */
bool VerificaFim(PlayerPtr pl1, PlayerPtr pl2)
{
	if(!EncontraRei(pl1->listaPecas) || !EncontraRei(pl2->listaPecas))
	{
		return true;
	}
	return false;
}

/*
 * Fun�ao que "evolui" uma pe�a dependendo do que ela comeu.
 *			Peao come peao -> 50/50 entre Bispo e Torre
 *			Bispo come Torre -> Rainha
 *			Torre come Bispo -> Rainha
 */
PecaPtr Evolui(PecaPtr peca, PecaPtr comida)
{
	srand(time(NULL));
	int random = rand();
	if (strcmp(peca->tipo, "Peao") == 0)
	{
		if (strcmp(comida->tipo, "Peao") == 0)
			if (random == 1)
				peca->tipo = "Torre";
			else peca->tipo = "Bispo";
	}
	else if (strcmp(peca->tipo, "Bispo") == 0)
	{
		if (strcmp(comida->tipo, "Torre") == 0)
			peca->tipo = "Rainha";
	}
	else if (strcmp(peca->tipo, "Torre") == 0)
	{
		if (strcmp(comida->tipo, "Bispo") == 0)
			peca->tipo = "Rainha";
	}

	return peca;
}
