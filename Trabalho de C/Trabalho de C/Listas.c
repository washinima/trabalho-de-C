#include "Main.h"
#include <string.h>


/*
Função que inicializa a lista de jogadas
*/
JogadasPtr IniciaLista()
{
	JogadasPtr head = NULL;
	return head;
}


/*
Função que aloca memória para uma nova jogada
*/
JogadasPtr NovaJogada(Coordenadas posicao, Vetor movimento)
{
	JogadasPtr nova = (JogadasPtr)malloc(sizeof(Jogadas));
	nova->posicao = posicao;
	nova->movimento = movimento;
	nova->next = NULL;
	return nova;
}

/*
 * Funçao que compara duas peças
 */
bool ComparaPecas(PecaPtr peca1, PecaPtr peca2)
{
	if (peca1->posicao.X == peca2->posicao.X)
		if (peca1->posicao.Y == peca2->posicao.Y)
			if (strcmp(peca1->tipo, peca2->tipo) == 0)
				return true;
	return false;
}

/*
 * Funçao que encontra uma peça numa lista
 */
bool EncontraPeca(PecaPtr peca, PecaPtr head)
{
	if (head == NULL || peca == NULL) return false;
		
		
	while (head != NULL)
	{
		if (ComparaPecas(peca, head) == true)
			return true;
		head = head->next;
	}
	return false;
}


/*
 * Funçao que encontra o rei na lista. Serve para verificar se acabou o jogo
 */
bool EncontraRei(PecaPtr head)
{
	while (head != NULL)
	{
		if (strcmp(head->tipo,"Rei") == 0)
			return true;
		head = head->next;
	}
	return false;
}

/*
 * Calcula o Tamanho de Uma Lista de Jogadas
 */
int TamanhoLista(PecaPtr head)
{
	int tmp = 0;
	if (head == NULL) return tmp;

	while (head->next != NULL)
	{
			tmp++;
			head = head->next;
	}

	return tmp;
}


/*
Funcão que insere a jogada mais recente na última posição da lista de jogadas
*/
JogadasPtr InserirJogada(JogadasPtr head, JogadasPtr novo)
{
	JogadasPtr aux = head;
	if (head == NULL) head = novo;
	else
	{
		while (aux->next != NULL)
		{
			aux = aux->next;
		}
		aux->next = novo;
	}

	return head;
}

/*
Funcão que insere a peça mais recente na última posição da lista de peças dos jogadores
*/
PecaPtr InserirPeca(PecaPtr peca, PecaPtr head)
{	
	if (head == NULL) head = peca;
	else
	{
		PecaPtr aux = head;
		while (aux->next != NULL)
		{
			aux = aux->next;
		}
		aux->next = peca;
	}
	return head;
}


/*
 * Funçao para Eliminar uma peça da lista do jogador
 */
PecaPtr EliminarPeca(PecaPtr peca, PecaPtr head)
{
	if (!head)	
	{
		return head;
	}
	else {
		PecaPtr aux = head;
		PecaPtr aux2 = aux;
		//Procura onde eliminar		
		while (aux != NULL && !ComparaPecas(peca, aux))
		{
			aux2 = aux;
			aux = aux->next;
		}

		//se é no início
		if (aux == head)
		{
			aux = head;
			head = head->next;
			free(aux);
		}
		//se é no meio
		else
		{
			if (aux != NULL) {
				aux2->next = aux->next;
				free(aux);
			}

		}
	}

	return head;
}

/*
Função para libertar a lista de jogadas da memória
*/
void FreeLista(JogadasPtr head)
{
	JogadasPtr aux = head;
	JogadasPtr aux2 = aux;
	while (aux->next != NULL)
	{
		aux = aux->next;
		free(aux2);
		aux2 = aux;
	}
	free(aux);

	//return NULL;
}