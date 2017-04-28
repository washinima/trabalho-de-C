#include "Main.h"
#include <stdio.h>

int main()
{
	TabuleiroPtr board = CreateBoard();
	// (*board)[1][1];
	PecaPtr a = CriarPeao();
	printf("%s", (*(a->tipo)));

	return 0;
}
