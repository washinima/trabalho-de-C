


typedef struct Coordenadas {
	int posicaoX;
	int posicaoY;
}Coordenadas;




typedef struct Peca {
	char* tipo; //peão, rei, peão "melhorado"
	Coordenadas posicao;
};




typedef struct Jogadas {

	JogadasPtr next;
}Jogadas;

typedef Jogadas *JogadasPtr;
