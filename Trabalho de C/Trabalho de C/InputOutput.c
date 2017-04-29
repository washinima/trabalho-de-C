#include "Main.h"

void ImprimirTabuleiro(TabuleiroPtr board)
{
	printf("+---+---+---+---+---+---+---+---+\n");		//com printf dá erro????

	for (int x = 0; x < SIZE; x++)
	{
		printf("|");
		for (int y = 0; y < SIZE; y++)
		{
			if ((*board)[x][y] != NULL)										//'\0' ocupa um espaço de caracter completo na consola para ficar um char "vazio"(nulo)
				printf("%c%c%c|", '\0',(*board)[x][y]->visualPeca, '\0');	//%c%c%c para a peça ficar no meio do quadrado do tabuleiro
			else
				printf("%3c|", '\0');
		}
		printf("\n");
		printf("+---+---+---+---+---+---+---+---+\n");
	}
}