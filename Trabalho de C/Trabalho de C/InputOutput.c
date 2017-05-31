#include "Main.h"



/*
 * Fun�ao que pede ao jogador a sua jogada;
 */
JogadasPtr EscolherJogada(TabuleiroPtr board, PlayerPtr player)
{
	int x, y, x1, y1, tmp, tmp2;
	Vetor movimento;
	PecaPtr aux;
	bool auxBool = false;
	while (auxBool == false)
	{
		do
		{
			printf("Que Pe�a quer mexer? \nEscreva as Coordenadas\n");
			fflush(stdin);
			scanf(" %d", &y);
			fflush(stdin);
			scanf(" %d", &x);

			aux = RetirarPeca(board, x, y, player->listaPecas);
			if (aux == NULL)
			{
				printf("Peca nao Premitida\n");
			}
			else if (strcmp(aux->tipo, "Rei") == 0)
			{
				tmp = AjudaJogadas(board, x, y);

				if (tmp == 0)
				{
					printf("Nao ha jogadas possiveis\n");
					aux = NULL;
				}
			}
		} while (aux == NULL);

		do
		{
			printf("Para onde a quer mexer?\nEscreva as Coordenadas\n");
			printf("Para escolher uma peça diferente, Escreva -1 -1 \n");
			fflush(stdin);
			scanf(" %d", &y1);
			fflush(stdin);
			scanf(" %d", &x1);


			if (y1 == -1 && x1 == -1)
			{
				break;
			}


			int x2 = x1 - x;
			int y2 = y1 - y;
			movimento.X = x2;
			movimento.Y = y2;
			auxBool = VerificarJogada(board, movimento, aux);
			if (auxBool == false)
			{
				printf("Jogada Invalida. Escreva outravez\n");
			}


		} while (auxBool == false);
	}
	
	//printf("JOGADA");

	JogadasPtr jogada = NovaJogada(aux->posicao, movimento);

	player->listaJogadas = InserirJogada(player->listaJogadas, jogada);

	return jogada;
}

/*
 * Programa que escreve na consola jogadas possiveis e devolve o n� delas
 */
int AjudaJogadas(TabuleiroPtr board, int x, int y)
{
	//REI
	/*
	* -1 -1 | -1  1 | -1  0 | 0 -1 | 0  1 | 1  0 | 1 -1 | 1  1
	*/
	int tmp = 0;
	//printf("Possiveis Jogadas:\n");
	if (strcmp((*board)[x][y]->tipo, "Rei") == 0)
	{
		for (int i = -1; i < 2; i++)
			for (int j = -1; j < 2; j++)
				if ((*board)[x + i][y + j] == NULL)
				{
					tmp++;
					//printf("-> %d %d \n", x+i, j+j);
				}
	}
	//if(strcmp((*board)[x][y]->tipo, "Rainha"))
	return tmp;
}

/*
 * Fun�ao que imprime o tabuleiro
 */
void ImprimirTabuleiro(TabuleiroPtr board)
{
	int row = 0;
	printf("     0   1   2   3   4   5   6   7   X\n");
	printf("   +---+---+---+---+---+---+---+---+\n");

	for (int x = 0; x < SIZE; x++)
	{
		printf(" %d ", row);
		row++;
		printf("|");
		for (int y = 0; y < SIZE; y++)
		{
			if ((*board)[x][y] != NULL)										//'\0' ocupa um espa�o de caracter completo na consola para ficar um char "vazio"(nulo)
				printf("%c%c%c|", '\0', (*board)[x][y]->visualPeca, '\0');	//%c%c%c para a pe�a ficar no meio do quadrado do tabuleiro
			else
				printf("%3c|", '\0');
		}
		printf("\n");
		printf("   +---+---+---+---+---+---+---+---+\n");
		
	}
	printf(" Y\n\n");
}


/*
 * Fun�ao que Imprime as Regras do Jogo
 */
void Regras()
{
	printf("Este jogo � uma vers�o do Xadrez em que o jogador come�a s� com Pe�es e o Rei.\n");
	printf("Principais Diferen�as:\n");
	printf("O Rei n�o pode atacar.\nOs Pe�es podem mover-se para todos os lados mas s� podem comer na diagonal.\n");
	printf("O jogador pode comer as suas pr�prias pe�as para for�ar uma evolu��o.\n");
}


/*
* Fun�ao que controla o jogo
*/
void Jogar()
{
	/*
	* Fazer fun�ao para criar jogadores - done
	* Criar os dois jogadores aqui - done
	* Modificar a CreateBoard para ter os dois jogadores - done
	* Fazer uma fun�ao que verifica se acabou o jogo - done
	*
	* Montar a Jogar com as fun�oes que temos
	*
	* Maquina de Estados a correr isto ate acabar o jogo
	* Imprimir o Tabuleiro -> Escolher a Jogada -> Fazer a Jogada -> Passar o Turno
	*/
	PlayerPtr player1 = CriarJogador(true);
	PlayerPtr player2 = CriarJogador(false);

	TabuleiroPtr board = CreateBoard(player1, player2);
	bool playing = true;

	////////////////////////////////////////////////////////////////////
	PlayerPtr currentPlayer = player1, nextPlayer = player2, aux;

	while (playing)
	{
		ImprimirTabuleiro(board);
		if (currentPlayer->player)
			printf("Player1\n");
		else printf("Player2\n");

		fflush(stdin);
		JogadasPtr jog = EscolherJogada(board, currentPlayer);
		fflush(stdin);
		board = MexerPeca(board,jog , currentPlayer, nextPlayer);

		/*aux = currentPlayer;
		currentPlayer = nextPlayer;
		nextPlayer = aux;*/

		if (VerificaFim(player1, player2))
		{
			playing = false;

			if (!EncontraRei(player1->listaPecas))
				printf("Ganhou o Player2");
			else
			{
				printf("Ganhou o Player1");
			}
		}

		//board = AtualizaPosicoes(board);
	}
}


/*
 * Fun�ao que controla o Menu de Jogo
 */
void Menu()
{
	int opcao = 0;
	while (opcao != 3)
	{
		system("cls");
		printf("#####################\n");
		printf("#    1 - Jogar      #\n");
		printf("#    2 - Regras     #\n");
		printf("#    3 - Imprime    #\n");
		printf("#    4 - Sair       #\n");
		printf("#####################\n");
		scanf_s("%d", &opcao);

		switch (opcao)
		{
		case 1:
			system("cls");
			Jogar();
			break;
		case 2:
			system("cls");
			Regras();
			break;
		default:
			break;
		}
	}
}

