#include "Main.h"

void ImprimirTabuleiro(TabuleiroPtr board)
{
	printf("+---+---+---+---+---+---+---+---+\n");		//com printf d� erro????

	for (int x = 0; x < SIZE; x++)
	{
		for (int y = 0; y < SIZE; y++)
		{
			if ((*board)[x][y] != NULL)
				printf(" %d |", (*board)[x][y]->numPeca);
			else
				printf("     |");
		}
		printf("\n");
		printf("+---+---+---+---+---+---+---+---+\n");
	}
}