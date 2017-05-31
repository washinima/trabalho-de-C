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
Função para criar uma peça Peão
*/
PecaPtr CriarPeao(int numPeca, int x, int y, bool isPlayer)
{
	PecaPtr peao = (PecaPtr)malloc(sizeof(Peca));
	peao->numPeca = numPeca;
	peao->posicao.X = x;
	peao->posicao.Y = y;
	char* a = "Peao";
	peao->tipo = a;
	visualChange(peao,isPlayer);
	peao->next = NULL;
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
	char* a = "Rei";
	rei->tipo = a;
	visualChange(rei, isPlayer);
	rei->next = NULL;

	return rei;
}

/*
 * Retorna o apontador para a peça se esta estiver numa lista 
 */
PecaPtr RetirarPeca(TabuleiroPtr board,  int x, int y, PecaPtr listaPecas)
{
	if (EncontraPeca((*board)[x][y], listaPecas))
		return (*board)[x][y];
	return NULL;
}

/*
 * Funçao que verifica o se o movimento da peça e valido dependendo do tipo de peça
 */
bool VerificaMovimento(PecaPtr peca, Vetor movimento)
{
	if (movimento.X == 0  && movimento.Y == 0)
		return false;
	if (peca->posicao.X + movimento.X >= SIZE || peca->posicao.X + movimento.X < 0)
		return false;
	if (peca->posicao.Y + movimento.Y >= SIZE || peca->posicao.Y + movimento.Y < 0)
		return false;

	//Peoes e Rei
	if (strcmp(peca->tipo, "Peao") == 0 || strcmp(peca->tipo, "Rei") == 0)
	{
		if (movimento.X == 1 || (movimento.X == -1 || movimento.X == 0))
			if (movimento.Y == 1 || (movimento.Y == -1 || movimento.Y == 0))
				return true;
	}
	//Rainha
	else if(strcmp((peca->tipo), "Rainha"))
	{
		if (movimento.Y == movimento.X || movimento.X == -movimento.Y)
				return true;
		if (movimento.X != 0 && movimento.Y == 0)
			return true;
		if (movimento.X == 0 && movimento.Y != 0)
			return true;
	}
	//BISPO
	else if (strcmp((peca->tipo), "Bispo"))
	{
		if (movimento.Y == movimento.X || movimento.X == -movimento.Y)
			return true;
	}
	//Torre
	else if (strcmp((peca->tipo), "Torre"))
	{
		if (movimento.X != 0 && movimento.Y == 0)
			return true;
		if (movimento.X == 0 && movimento.Y != 0)
			return true;
	}
	return false;
}

/*
 * Funçao que verifica o se a jogada e valida dependendo do tipo de peça. 
 *		So para as peças que podem Atacar
 */
bool VerificarJogada(TabuleiroPtr board, Vetor movimento, PecaPtr peca)
{
	int x = peca->posicao.X, y = peca->posicao.Y;
	int x1 = x + movimento.X, y1 = y + movimento.Y;
	int i;
	if(!VerificaMovimento(peca, movimento))
		return false;

	if(strcmp(peca->tipo, "Peao") == 0)
	{
		if(movimento.X == movimento.Y || movimento.X == -movimento.Y) 
		{
			return true;
		}
		if(movimento.X == 0)
		{
			if(movimento.Y == 1)
			{
				if ((*board)[x][y + 1] == NULL)
					return true;
			}
			else if (movimento.Y == -1)
			{
				if ((*board)[x][y - 1] == NULL)
					return true;
			}
		}
		else if (movimento.Y == 0)
		{
			if (movimento.X == 1)
			{
				if ((*board)[x +1][y] == NULL)
					return true;
			}
			else if (movimento.X == -1)
			{
				if ((*board)[x-1][y] == NULL)
					return true;
			}
		}
	}
	else if (strcmp(peca->tipo, "Rainha") == 0)
	{
		if(movimento.X != 0 && movimento.Y == 0)
		{
			if (movimento.X > 0)
			{
				for (i = 1; i < movimento.X; i++)
				{
					if ((*board)[x + i][y] != NULL)
						break;
				}
				if (i == movimento.X)
					return true;
			}
			else if (movimento.X < 0)
			{
				for (i = -1; i > movimento.X ; i--)
				{
					if ((*board)[x + i][y] != NULL)
						break;
				}
				if (i == movimento.X)
					return true;
			}
		}
		else if (movimento.Y != 0 && movimento.X == 0)
		{
			if (movimento.Y > 0)
			{
				for (i = 1; i < movimento.Y; i++)
				{
					if ((*board)[x][y+i] != NULL)
						break;
				}
				if (i == movimento.Y)
					return true;
			}
			else if (movimento.Y < 0)
			{
				for (i = -1; i > movimento.Y; i--)
				{
					if ((*board)[x ][y+i] != NULL)
						break;
				}
				if (i == movimento.Y)
					return true;
			}
		}
		else if (movimento.Y == movimento.X || movimento.X == -movimento.Y)
		{
			if (movimento.Y > 0)
			{
				for (i = 1; i < movimento.Y; i++)
				{
					if ((*board)[x+i][y + i] != NULL)
						break;
				}
				if (i == movimento.Y)
					return true;
			}
			if (movimento.Y < 0)
			{
				for (i = -1; i > movimento.Y; i--)
				{
					if ((*board)[x+i][y + i] != NULL)
						break;
				}
				if (i == movimento.Y)
					return true;
			}
		}
	}
	else if (strcmp(peca->tipo, "Torre") == 0)
	{
		if (movimento.X != 0 && movimento.Y == 0)
		{
			if (movimento.X > 0)
			{
				for (i = 1; i < movimento.X; i++)
				{
					if ((*board)[x + i][y] != NULL)
						break;
				}
				if (i == movimento.X)
					return true;
			}
			else if (movimento.X < 0)
			{
				for (i = -1; i > movimento.X; i--)
				{
					if ((*board)[x + i][y] != NULL)
						break;
				}
				if (i == movimento.X)
					return true;
			}
		}
		else if (movimento.Y != 0 && movimento.X == 0)
		{
			if (movimento.Y > 0)
			{
				for (i = 1; i < movimento.Y; i++)
				{
					if ((*board)[x][y + i] != NULL)
						break;
				}
				if (i == movimento.Y)
					return true;
			}
			else if (movimento.Y < 0)
			{
				for (i = -1; i > movimento.Y; i--)
				{
					if ((*board)[x][y + i] != NULL)
						break;
				}
				if (i == movimento.Y)
					return true;
			}
		}
	}
	else if (strcmp(peca->tipo, "Bispo") == 0)
	{
		if (movimento.Y == movimento.X || movimento.X == -movimento.Y)
		{
			if (movimento.Y > 0)
			{
				for (i = 1; i < movimento.Y; i++)
				{
					if ((*board)[x + i][y + i] != NULL)
						break;
				}
				if (i == movimento.Y)
					return true;
			}
			if (movimento.Y < 0)
			{
				for (i = -1; i > movimento.Y; i--)
				{
					if ((*board)[x + i][y + i] != NULL)
						break;
				}
				if (i == movimento.Y)
					return true;
			}
		}
	}
	return false;

}

/*
 * Funçao que mexe a Peça.
 */
TabuleiroPtr MexerPeca(TabuleiroPtr board, JogadasPtr jogada, PlayerPtr player, PlayerPtr playerInimigo)
{
	int x = jogada->posicao.X, y = jogada->posicao.Y;
	int x1 = x + jogada->movimento.X, y1 = y + jogada->movimento.Y;

	PecaPtr comida = (*board)[x1][y1];

	if (EncontraPeca(comida, player->listaPecas))
	{
		(*board)[x][y] = Evolui((*board)[x][y], comida, player->player);
		player->listaPecas = EliminarPeca(comida, player->listaPecas);
	}
	else if (EncontraPeca(comida, playerInimigo->listaPecas))
	{
		playerInimigo->listaPecas = EliminarPeca(comida, playerInimigo->listaPecas);
	}

	(*board)[x][y]->posicao.X = x1; (*board)[x][y]->posicao.Y = y1;
	
	if(strcmp ((*board)[x][y]->tipo , "Peao") == 0)
	{
		checkPeaoRainha((*board)[x][y], player);
	}

	(*board)[x1][y1] = (*board)[x][y];
	(*board)[x][y] = NULL;

	return board;
}


/*
 * Evolui o peao se Chegar ao fim do tabuleiro
 */
void checkPeaoRainha(PecaPtr aux, PlayerPtr player)
{
	if (player->player)
	{
		if (aux->posicao.X == 0)
		{
			aux->tipo = "Rainha";
			visualChange(aux, player->player);
		}
	}
	else
	{
		if(aux->posicao.X == 7)
		{
			aux->tipo = "Rainha";
			visualChange(aux, player->player);
		}
	}
}

/*
 * Funçao que muda o visual de cada peca
 */
void visualChange(PecaPtr peca, bool isPlayer)
{
	if(strcmp(peca->tipo, "Peao") == 0)
	{
		if (!isPlayer)
			peca->visualPeca = '¢';
		else peca->visualPeca = 'c';
	}
	else if(strcmp(peca->tipo, "Rei") == 0)
	{
		if (!isPlayer) peca->visualPeca = 'Ø';		//157 em ASCII		alt+157
		else peca->visualPeca = 'O';
	}
	else if (strcmp(peca->tipo, "Torre") == 0)
	{
		if (!isPlayer) peca->visualPeca = 't';
		else peca->visualPeca = 'T';
	}
	else if (strcmp(peca->tipo, "Bispo") == 0)
	{
		if (!isPlayer) peca->visualPeca = 'b';
		else peca->visualPeca = 'B';
	}
	else if (strcmp(peca->tipo, "Rainha") == 0)
	{
		if (!isPlayer) peca->visualPeca = 'r';
		else peca->visualPeca = 'R';
	}
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
 * Funçao que verifica o fim do jogo. Ou seja um jogador nao ter rei.
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
 * Funçao que "evolui" uma peça dependendo do que ela comeu.
 *			Peao come peao -> 50/50 entre Bispo e Torre
 *			Bispo come Torre -> Rainha
 *			Torre come Bispo -> Rainha
 */
PecaPtr Evolui(PecaPtr peca, PecaPtr comida, bool isPlayer)
{
	int random = rand();
	if (strcmp(peca->tipo, "Peao") == 0)
	{
		if (strcmp(comida->tipo, "Peao") == 0)
			if (random > 5)
			{
				peca->tipo = "Torre";
				visualChange(peca, isPlayer);
			}
			else
			{
				peca->tipo = "Bispo"; 
				visualChange(peca, isPlayer);
			}
	}
	else if (strcmp(peca->tipo, "Bispo") == 0)
	{
		if (strcmp(comida->tipo, "Torre") == 0)
		{
			peca->tipo = "Rainha"; 
			visualChange(peca, isPlayer);
		}
	}
	else if (strcmp(peca->tipo, "Torre") == 0)
	{
		if (strcmp(comida->tipo, "Bispo") == 0)
		{
		peca->tipo = "Rainha";
		visualChange(peca, isPlayer);
		}
	}

	return peca;
}

/*
 * Funçao que supostamente atualizava a posiçao das peças (nao funciona). 
 * Ja fazemos nisso quando mexemos uma peça. 
 */
TabuleiroPtr AtualizaPosicoes(TabuleiroPtr board)
{
	for (int x = 0; x < SIZE; x++)
	{
		for (int y = 0; y < SIZE; y++)
		{
			if ((*board)[x][y] != NULL)
			{
				(*board)[x][y]->posicao.X = x;
				(*board)[x][y]->posicao.X = y;
			}
		}
	}

	return board;
}
