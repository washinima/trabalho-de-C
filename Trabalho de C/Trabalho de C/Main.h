


typedef struct Coordenadas {
	int posicaoX;
	int posicaoY;
}Coordenadas;


typedef struct Peca {
	int numPeca;				//1  2  3  4  5  6  7  8 / 9  10 11 12 13 14 15 16 <--- demonstra��o dos n�meros de cada pe�a no tabuleiro
	char* tipo;					//pe�o, rei, pe�o "melhorado"
	Coordenadas posicao;
}Peca;

typedef Peca *PecaPtr;


typedef struct Jogadas {
	PecaPtr peca;
	Coordenadas movimento;
	JogadasPtr next;
}Jogadas;

typedef Jogadas *JogadasPtr;
