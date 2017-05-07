#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <stdbool.h>


#define SIZE 8

//---------------------------------------------------------

typedef struct Coordenadas {
	int X;
	int Y;
}Coordenadas;

typedef Coordenadas Vetor;


//Coordenadas	= Posição
//Vetor			= Movimento		//para entender melhor o código

//---------------------------------------------------------

typedef struct Peca {
	int numPeca;				//1  2  3  4  5  6  7  8 / 9  10 11 12 13 14 15 16 <--- demonstração dos números de cada peça no tabuleiro
	char* tipo;					//peão, rei, peão "melhorado"
	char visualPeca;
	Coordenadas posicao;		// o peao melhorado eu estava a pensar transformar tipo num cavalo e ser sempre a melhorar
	struct Peca *next;
}Peca;

typedef Peca *PecaPtr;
typedef PecaPtr Tabuleiro[SIZE][SIZE];
typedef Tabuleiro *TabuleiroPtr;

//---------------------------------------------------------

typedef struct Jogadas {
	PecaPtr peca;
	Coordenadas movimento;
	struct Jogadas *next;
}Jogadas;

typedef Jogadas *JogadasPtr;

//---------------------------------------------------------

typedef struct Player {
	char* nome;
	bool player; // True para Player1 e false para Player2
	JogadasPtr listaJogadas;
	PecaPtr listaPecas;
}Player;

typedef Player *PlayerPtr;

//---------------------------------------------------------


//BOARD
TabuleiroPtr CreateBoard();
PecaPtr CriarPeao(int numPeca, int x, int y, bool isPlayer1);
PecaPtr CriarRei(int numPeca, int x, int y, bool isPlayer1);
PecaPtr RetirarPeca(TabuleiroPtr board, int x, int y, PecaPtr listaPecas);
TabuleiroPtr MexerPeca(TabuleiroPtr board, JogadasPtr jogada);
bool VerificarJogada(PecaPtr peca, Vetor movimento);
void Jogar();


//LISTAS
JogadasPtr IniciaLista();
JogadasPtr NovaJogada(PecaPtr peca, Coordenadas movimento);
JogadasPtr Inserir(JogadasPtr head, JogadasPtr novo);
void FreeLista(JogadasPtr head);
bool EncontraPeca(PecaPtr peca, PecaPtr head);


//IMPRESSÃO

JogadasPtr EscolherJogada(TabuleiroPtr board, PlayerPtr player);
void ImprimirTabuleiro(TabuleiroPtr board);
void Regras();
void Menu();