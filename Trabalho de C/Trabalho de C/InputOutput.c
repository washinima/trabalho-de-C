#include "Main.h"


/*
 * Funçao que pede ao jogador a sua jogada;
 */
JogadasPtr EscolherJogada(TabuleiroPtr board, PlayerPtr player)
{
	int x, y, x1, y1;
	Vetor movimento;
	PecaPtr aux;

	do
	{
		printf("Que Peça quer mexer?\nEscreva as Coordenadas\n");
		scanf_s("%d %d", &x, &y);

		aux = RetirarPeca(board, x, y, player->listaPecas);
		if(aux == NULL)
		{
			printf("Peca nao Premitida");
		}
	}
	while (aux != NULL);

	do 
	{
		printf("Para onde a quer mexer?\nEscreva as Coordenadas\n");
		scanf_s("%d %d", &x1, &y1);

		movimento.X = x1;
		movimento.Y = y1;
		if (!VerificarJogada(aux, movimento))
		{
			printf("Jogada Invalida. Escreva outravez");
		}
	}while(!VerificarJogada(aux, movimento));

	JogadasPtr jogada = NovaJogada(aux, movimento);

	player->listaJogadas = Inserir(player->listaJogadas, jogada);

	return jogada;
}


/*
 * Funçao que imprime o tabuleiro
 */
void ImprimirTabuleiro(TabuleiroPtr board)
{
	printf("+---+---+---+---+---+---+---+---+\n");		//com printf dá erro????

	for (int x = 0; x < SIZE; x++)
	{
		printf("|");
		for (int y = 0; y < SIZE; y++)
		{
			if ((*board)[x][y] != NULL)										//'\0' ocupa um espaço de caracter completo na consola para ficar um char "vazio"(nulo)
				printf("%c%c%c|", '\0', (*board)[x][y]->visualPeca, '\0');	//%c%c%c para a peça ficar no meio do quadrado do tabuleiro
			else
				printf("%3c|", '\0');
		}
		printf("\n");
		printf("+---+---+---+---+---+---+---+---+\n");
	}
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
 * Funçao que controla o Menu de Jogo
 */
void Menu()
{
	printf("####################\n");
	printf("#    1 - Jogar     #\n");
	printf("#    2 - Regras    #\n");
	printf("#    3 - Sair      #\n");
	printf("####################\n");
	int opcao = 0;
	while (opcao != 3)
	{
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

