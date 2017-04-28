#include <stdlib.h>

#define SIZE 8

typedef struct Coordenadas {
	int posicaoX;
	int posicaoY;
}Coordenadas;


typedef struct Peca {
	int numPeca;				//1  2  3  4  5  6  7  8 / 9  10 11 12 13 14 15 16 <--- demonstra��o dos n�meros de cada pe�a no tabuleiro
	char* tipo;					//pe�o, rei, pe�o "melhorado"
	Coordenadas posicao;			// o peao melhorado eu estava a pensar transformar tipo num cavalo e ser sempre a melhorar
}Peca;

typedef Peca *PecaPtr;
typedef PecaPtr Tabuleiro[SIZE][SIZE];
typedef Tabuleiro *TabuleiroPtr;

typedef struct Jogadas {
	PecaPtr peca;
	Coordenadas movimento;
	struct Jogadas *next;
}Jogadas;

typedef Jogadas *JogadasPtr;

//BOARD
TabuleiroPtr CreateBoard();
PecaPtr CriarPeao();

//LISTAS
JogadasPtr IniciaLista();
JogadasPtr NovaJogada(PecaPtr peca, Coordenadas movimento);
JogadasPtr Inserir(JogadasPtr head, JogadasPtr novo);
void FreeJogada(JogadasPtr head);