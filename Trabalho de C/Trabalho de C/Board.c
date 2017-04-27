#include "Main.h"
#include <stdlib.h>

PecaPtr CreateBoard(int x, int y)
{
	PecaPtr board = (PecaPtr) malloc (sizeof(Peca[SIZE][SIZE]));

	return board;
}
