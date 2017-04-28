#include <stdlib.h>

#define SIZE 8

typedef struct Coordenadas {
	int X;
	int Y;
}Coordenadas;

//Coordenadas	= Posição
//Vetor			= Movimento		//para entender melhor o código
typedef Coordenadas Vetor;


typedef struct Peca {
	int numPeca;				//1  2  3  4  5  6  7  8 / 9  10 11 12 13 14 15 16 <--- demonstração dos números de cada peça no tabuleiro
	char* tipo;					//peão, rei, peão "melhorado"
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