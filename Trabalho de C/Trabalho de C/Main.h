


typedef struct Coordenadas {
	int posicaoX;
	int posicaoY;
}Coordenadas;




typedef struct Peca {
	char* tipo; //pe�o, rei, pe�o "melhorado"
	Coordenadas posicao;
};




typedef struct Jogadas {

	JogadasPtr next;
}Jogadas;

typedef Jogadas *JogadasPtr;
