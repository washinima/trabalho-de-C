#include "Main.h"
#include <string.h>

/*
 * Funçao que cria o Tabuleiro e mete as peças em cada jogador respetivamente
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
					player2->listaPecas = InserirPeca(rei, player2);
				}
				else
				{
					rei = CriarRei(numPeca, x, y, true);
					(*board)[x][y] = rei;
					player1->listaPecas = InserirPeca(rei, player1);
				}
				numPeca++;
			}

			else if (x <= 1 || x >= 6)
			{
				if (x <= 1)
				{
					peao = CriarPeao(numPeca, x, y, false);
					(*board)[x][y] = peao;
					player2->listaPecas = InserirPeca(peao, player2);
				}
				else
				{
					peao = CriarPeao(numPeca, x, y, true);
					(*board)[x][y] = peao;
					player1->listaPecas= InserirPeca(peao, player1);
				}
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
PecaPtr CriarPeao(int numPeca, int x, int y, bool isPlayer)
{
	PecaPtr peao = (PecaPtr)malloc(sizeof(Peca));
	peao->numPeca = numPeca;
	peao->posicao.X = x;
	peao->posicao.Y = y;
	if (!isPlayer) peao->visualPeca = '¢';		//189 em ASCII		alt+189
	else peao->visualPeca = 'c';
	char* a = "Peao";
	peao->tipo = a;

	return peao;
}


/*
Função para criar a peça Rei
*/
PecaPtr CriarRei(int numPeca, int x, int y, bool isPlayer)
{
	PecaPtr rei = (PecaPtr)malloc(sizeof(Peca));
	rei->numPeca = numPeca;
	rei->posicao.X = x;
	rei->posicao.Y = y;
	if (!isPlayer) rei->visualPeca = 'Ø';		//157 em ASCII		alt+157
	else rei->visualPeca = 'O';
	char* a = "Rei";
	rei->tipo = a;

	return rei;
}


/*
 * Retorna o apontador para a peça se esta estiver numa lista 
 */
PecaPtr RetirarPeca(TabuleiroPtr board,  int x, int y, PecaPtr listaPecas)
{
	if (EncontraPeca((*board)[x][y], listaPecas) == true)
		return (*board)[x][y];
	return NULL;
}

/*
 * Funçao que verifica o se a jogada esta valida dependendo do tipo de peça
 *			Ainda nao esta acabada
 *				Falta verificar se ela sai do campo
 *				E o acrescentar o codigo para outros tipos de peça
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
 * Funçao que mexe a Peça.
 *		Falta meter a peça a comer outra, caso esteja la.
 */
TabuleiroPtr MexerPeca(TabuleiroPtr board, JogadasPtr jogada, PlayerPtr player, PlayerPtr playerInimigo)
{
	int x = jogada->peca->posicao.X, y = jogada->peca->posicao.Y;
	(*board)[x + jogada->movimento.X][y + jogada->movimento.Y] = (*board)[x][y];
	(*board)[x][y] = NULL;
	return board;
}

/*
 * Funçao que cria o jogador
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
 * Funçao que controla o jogo
 */
void Jogar()
{
	/*
	 * Fazer funçao para criar jogadores - done
	 * Criar os dois jogadores aqui - done 
	 * Modificar a CreateBoard para ter os dois jogadores - done
	 * Fazer uma funçao que verifica se acabou o jogo.
	 * 
	 * Montar a Jogar com as funçoes que temos
	 * 
	 * Maquina de Estados a correr isto ate acabar o jogo
	 * Imprimir o Tabuleiro -> Escolher a Jogada -> Fazer a Jogada -> Passar o Turno
	 */
	PlayerPtr player1 = CriarJogador(true);
	PlayerPtr player2 = CriarJogador(false);

	TabuleiroPtr a = CreateBoard(player1,player2);
	ImprimirTabuleiro(a);
}
