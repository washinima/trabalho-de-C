#include "Main.h"



/*
 * Funçao que pede ao jogador a sua jogada;
 */
JogadasPtr EscolherJogada(TabuleiroPtr board, PlayerPtr player)
{
	int x, y, x1, y1, tmp;
	Vetor movimento;
	PecaPtr aux;
	bool auxBool;

	do
	{
		printf("Que Peça quer mexer? \nEscreva as Coordenadas\n");
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
	}
	while (aux == NULL);

	do 
	{
		printf("Para onde a quer mexer?\nEscreva as Coordenadas\n");
		fflush(stdin);
		scanf(" %d", &y1);
		fflush(stdin);
		scanf(" %d", &x1);
		int x2 = x1 - x;
		int y2 = y1 - y;
		movimento.X = x2;
		movimento.Y = y2;
		auxBool = VerificarJogada(board, movimento, aux);
		if (auxBool == false)
		{
			printf("Jogada Invalida. Escreva outravez\n");
		}
	}while(auxBool == false);
	
	//printf("JOGADA");

	JogadasPtr jogada = NovaJogada(aux->posicao, movimento);

	player->listaJogadas = InserirJogada(player->listaJogadas, jogada);

	return jogada;
}

/*
 * Programa que escreve na consola jogadas possiveis e devolve o nº delas
 */
int AjudaJogadas(TabuleiroPtr board, int x, int y)
{
	//REI
	/*
	* -1 -1 | -1  1 | -1  0 | 0 -1 | 0  1 | 1  0 | 1 -1 | 1  1
	*/
	int tmp = 0;
	printf("Possiveis Jogadas:\n");
	if (strcmp((*board)[x][y]->tipo, "Rei"))
	{
		for (int i = -1; i < 2; i++)
			for (int j = -1; j < 2; j++)
				if ((*board)[x + i][y + j] == NULL)
				{
					tmp++;
					printf("-> %d %d", i, j);
				}
	}
	//if(strcmp((*board)[x][y]->tipo, "Rainha"))
	return tmp;
}

/*
 * Funçao que imprime o tabuleiro
 */
void ImprimirTabuleiro(TabuleiroPtr board)
{
	int row = 0;
	printf("     0   1   2   3   4   5   6   7   X\n");
	printf("   +---+---+---+---+---+---+---+---+\n");		//com printf dá erro????

	for (int x = 0; x < SIZE; x++)
	{
		printf(" %d ", row);
		row++;
		printf("|");
		for (int y = 0; y < SIZE; y++)
		{
			if ((*board)[x][y] != NULL)										//'\0' ocupa um espaço de caracter completo na consola para ficar um char "vazio"(nulo)
				printf("%c%c%c|", '\0', (*board)[x][y]->visualPeca, '\0');	//%c%c%c para a peça ficar no meio do quadrado do tabuleiro
			else
				printf("%3c|", '\0');
		}
		printf("\n");
		printf("   +---+---+---+---+---+---+---+---+\n");
		
	}
	printf(" Y\n\n");
}


/*
 * Funçao que Imprime as Regras do Jogo
 */
void Regras()
{
	printf("Este jogo e uma versao do Xadrez em que o jogador começa so com Peoes e o Rei\n");
	printf("Principais Diferenças:\n");
	printf("O Rei nao pode atacar.\nOs Peoes podem mover-se para todos os lados mas so podem comer na diagonal\n");
	printf("O jogador pode comer as suas proprias peças para forçar uma evoluçao\n");
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
	* Fazer uma funçao que verifica se acabou o jogo - done
	*
	* Montar a Jogar com as funçoes que temos
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
 * Funçao que controla o Menu de Jogo
 */
void Menu()
{
	srand(time(NULL));
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
			Jogar();
			break;
		case 2:
			Regras();
			break;
		default:
			break;
		}
	}
}

