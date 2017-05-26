#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#ifndef A
#define A


#define RAND_MAX 10

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
	Coordenadas posicao;
	Vetor movimento;
	struct Jogadas *next;
}Jogadas;

typedef Jogadas *JogadasPtr;

//---------------------------------------------------------

typedef struct Player {
	bool player; // True para Player1 e false para Player2
	JogadasPtr listaJogadas;
	PecaPtr listaPecas;
}Player;

typedef Player *PlayerPtr;

//---------------------------------------------------------


//BOARD
TabuleiroPtr CreateBoard(PlayerPtr player1, PlayerPtr player2);
PecaPtr CriarPeao(int numPeca, int x, int y, bool isPlayer1);
PecaPtr CriarRei(int numPeca, int x, int y, bool isPlayer1);
PecaPtr RetirarPeca(TabuleiroPtr board, int x, int y, PecaPtr listaPecas);
TabuleiroPtr MexerPeca(TabuleiroPtr board, JogadasPtr jogada, PlayerPtr player, PlayerPtr playerInimigo);
bool VerificarJogada(PecaPtr peca, Vetor movimento);
PlayerPtr CriarJogador(bool isPlayer);
bool VerificaFim(PlayerPtr pl1, PlayerPtr pl2);
PecaPtr Evolui(PecaPtr peca, PecaPtr comida, bool isPlayer);
void visualChange(PecaPtr peca, bool isPlayer);
TabuleiroPtr AtualizaPosicoes(TabuleiroPtr board);


//LISTAS
JogadasPtr IniciaLista();
JogadasPtr NovaJogada(Coordenadas posicao, Vetor movimento);
JogadasPtr InserirJogada(JogadasPtr head, JogadasPtr novo);
PecaPtr InserirPeca(PecaPtr peca, PecaPtr head);
void FreeLista(JogadasPtr head);
bool EncontraPeca(PecaPtr peca, PecaPtr head);
bool EncontraRei(PecaPtr head);
PecaPtr EliminarPeca(PecaPtr peca, PecaPtr head);


//IMPRESSÃO

JogadasPtr EscolherJogada(TabuleiroPtr board, PlayerPtr player);
int AjudaJogadas(TabuleiroPtr board, int x, int y);
void ImprimirTabuleiro(TabuleiroPtr board);
void Regras();
void Jogar();
void Menu();

#endif
