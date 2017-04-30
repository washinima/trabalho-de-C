#include "Main.h"

JogadasPtr EscolherJogada(TabuleiroPtr board, PlayerPtr player)
{
	if(player->player == false)
	{
		
	}




	return NULL;
}



void ImprimirTabuleiro(TabuleiroPtr board)
{
	printf("+---+---+---+---+---+---+---+---+\n");		//com printf d� erro????

	for (int x = 0; x < SIZE; x++)
	{
		printf("|");
		for (int y = 0; y < SIZE; y++)
		{
			if ((*board)[x][y] != NULL)										//'\0' ocupa um espa�o de caracter completo na consola para ficar um char "vazio"(nulo)
				printf("%c%c%c|", '\0', (*board)[x][y]->visualPeca, '\0');	//%c%c%c para a pe�a ficar no meio do quadrado do tabuleiro
			else
				printf("%3c|", '\0');
		}
		printf("\n");
		printf("+---+---+---+---+---+---+---+---+\n");
	}
}

void Regras()
{
	printf("Este jogo e uma versao do Xadrez em que o jogador come�a so com Peoes e o Rei\n");
	printf("Principais Diferen�as:\n");
	printf("O Rei nao pode atacar.\nOs Peoes podem mover-se para todos os lados mas so podem comer na diagonal\n");
	printf("O jogador pode comer as suas proprias pe�as para for�ar uma evolu�ao\n");
}



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

