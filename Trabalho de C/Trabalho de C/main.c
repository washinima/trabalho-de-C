#include "Main.h"

int main()
{
	setlocale(LC_ALL, "Portuguese");
	TabuleiroPtr board = CreateBoard();
	ImprimirTabuleiro(board);
	//PecaPtr a = CriarPeao();
	//printf("%s", a->tipo);

	return 0;
}
