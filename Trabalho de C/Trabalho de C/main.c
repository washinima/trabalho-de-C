#include "Main.h"
#include <stdio.h>

int main()
{
	PecaPtr a = CriarPeao();
	printf("%s", a->tipo);

	return 0;
}
