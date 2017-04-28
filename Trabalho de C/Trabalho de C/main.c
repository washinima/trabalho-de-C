#include "Main.h"
#include <stdio.h>

int main()
{
	Tabuleiro board;


	PecaPtr a = (PecaPtr)malloc(sizeof(Peca));

	a->numPeca = 10;

	board[1][1] = a;

	TabuleiroPtr board_ptr = &board;

	printf("%d",(*board_ptr)[1][1]->numPeca);

	return 0;
}
