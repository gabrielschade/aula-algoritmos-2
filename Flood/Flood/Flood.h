#include <iostream>
#include <string>
#include <time.h>
#include "stdafx.h"

using namespace std;

/*
Constante para identificar as cercas
*/
const char CERCA = '#';

/*
Constante para identiciar um espaço vazio
*/
const char VAZIO = '\0';

/*
Constante para identificar um vírus
*/
const char VIRUS = 'X';

/*
Constante para identificar um vírus
*/
const char CERCA_TEMPORARIA = '$';



/*
Constante para identificar o tamanho de campo pequeno
*/
const int TAMANHO_PEQUENO = 1;

/*
Constante para identificar o tamanho de campo médio
*/
const int TAMANHO_MEDIO = 2;

/*
Constante para identificar o tamanho de campo grande
*/
const int TAMANHO_GRANDE = 3;



/*
Valor constante referente ao máximo de cercas disponíveis para o mapa pequeno.
*/
const int MAXIMO_PARA_PEQUENO = 25;

/*
Valor constante referente ao máximo de cercas disponíveis para os mapas médio e grande.
*/
const int MAXIMO_PARA_MEDIO_GRANDE = 20;



/*
Constante para definir a quantidade de colunas de todos os campos
*/
const int QUANTIDADE_COLUNAS = 20;

/*
Constante para definir a quantidade de linhas dos campos pequenos
*/
const int QUANTIDADE_LINHAS_PARA_MENORES = 10;

/*
Constante para definir a quantidade de linhas dos campos médios
*/
const int QUANTIDADE_LINHAS_PARA_MEDIOS = 15;

/*
Constante para definir a quantidade de linhas dos campos grandes
*/
const int QUANTIDADE_LINHAS_PARA_GRANDES = 25;



/*
Constante para definir o raio maximo de alcance do virus
*/
const int LIMITE_MAX_LINHA_COLUNA_VIRUS = 1;

/*
Constante para definir o raio minimo de alcance do virus
*/
const int LIMITE_MIN_LINHA_COLUNA_VIRUS = -1;



/*
Campo pequeno com os valores inciais
*/
char campoPequeno[QUANTIDADE_LINHAS_PARA_MENORES][QUANTIDADE_COLUNAS] = {
	{ CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA,CERCA, CERCA, CERCA, CERCA, CERCA,CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA },
	{ CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO,VAZIO, VAZIO, VAZIO, VAZIO, VAZIO,VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, CERCA },
	{ CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO,VAZIO, VAZIO, VAZIO, VAZIO, VAZIO,VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, CERCA },
	{ CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO,VAZIO, VAZIO, VAZIO, VAZIO, VAZIO,VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, CERCA },
	{ CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO,VAZIO, VAZIO, VAZIO, VAZIO, VAZIO,VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, CERCA },
	{ CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO,VAZIO, VAZIO, VAZIO, VAZIO, VAZIO,VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, CERCA },
	{ CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO,VAZIO, VAZIO, VAZIO, VAZIO, VAZIO,VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, CERCA },
	{ CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO,VAZIO, VAZIO, VAZIO, VAZIO, VAZIO,VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, CERCA },
	{ CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO,VAZIO, VAZIO, VAZIO, VAZIO, VAZIO,VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, CERCA },
	{ CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA,CERCA, CERCA, CERCA, CERCA, CERCA,CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA }
};

/*
Campo médio com os valores inciais
*/
char campoMedio[QUANTIDADE_LINHAS_PARA_MEDIOS][QUANTIDADE_COLUNAS] = {
	{ CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA },
	{ CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, CERCA },
	{ CERCA, CERCA, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, CERCA },
	{ CERCA, VAZIO, CERCA, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, CERCA },
	{ CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, CERCA },
	{ CERCA, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, CERCA, CERCA, CERCA, VAZIO, VAZIO, CERCA },
	{ CERCA, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, CERCA },
	{ CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, CERCA, CERCA, CERCA },
	{ CERCA, VAZIO, VAZIO, CERCA, VAZIO, CERCA, VAZIO, VAZIO, CERCA, CERCA, CERCA, CERCA, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, CERCA },
	{ CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, CERCA, CERCA, VAZIO, VAZIO, CERCA, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, CERCA },
	{ CERCA, VAZIO, CERCA, VAZIO, CERCA, VAZIO, CERCA, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, CERCA },
	{ CERCA, VAZIO, VAZIO, CERCA, CERCA, VAZIO, CERCA, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, CERCA },
	{ CERCA, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, CERCA },
	{ CERCA, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, CERCA },
	{ CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA }
};

/*
Campo grande com os valores inciais
*/
char campoGrande[QUANTIDADE_LINHAS_PARA_GRANDES][QUANTIDADE_COLUNAS] = {
	{ CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA },
	{ CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, CERCA },
	{ CERCA, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, CERCA },
	{ CERCA, VAZIO, VAZIO, CERCA, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, CERCA },
	{ CERCA, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, CERCA },
	{ CERCA, VAZIO, CERCA, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, CERCA },
	{ CERCA, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, CERCA },
	{ CERCA, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, CERCA },
	{ CERCA, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, CERCA, VAZIO, CERCA, VAZIO, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, VAZIO, CERCA },
	{ CERCA, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, CERCA },
	{ CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, CERCA },
	{ CERCA, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, CERCA },
	{ CERCA, VAZIO, VAZIO, CERCA, CERCA, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, CERCA },
	{ CERCA, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, CERCA },
	{ CERCA, CERCA, CERCA, CERCA, VAZIO, CERCA, CERCA, CERCA, CERCA, VAZIO, CERCA, VAZIO, CERCA, CERCA, CERCA, CERCA, VAZIO, CERCA, CERCA, CERCA },
	{ CERCA, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, CERCA },
	{ CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, CERCA },
	{ CERCA, VAZIO, VAZIO, CERCA, CERCA, CERCA, CERCA, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, CERCA },
	{ CERCA, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, CERCA },
	{ CERCA, VAZIO, CERCA, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, CERCA, VAZIO, CERCA, VAZIO, CERCA },
	{ CERCA, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, CERCA },
	{ CERCA, CERCA, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, CERCA, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, CERCA },
	{ CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, CERCA },
	{ CERCA, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, VAZIO, CERCA, VAZIO, VAZIO, VAZIO, CERCA },
	{ CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA, CERCA }
};



/*
Função para escrever os valores contidos em um campo, deve ser utilizado para exibir o campo para o usuário
*/
void escreverCampo(char campo[][QUANTIDADE_COLUNAS], int tamanhoCampo){
	for (int linha = 0; linha < tamanhoCampo; linha++)
	{
		for (int coluna = 0; coluna < QUANTIDADE_COLUNAS; coluna++)
			cout << campo[linha][coluna] << "";
		cout << endl;
	}
}



/*
Função para escrever os valores de um dos campos, de acordo com o parâmetro
Utilize as constantes de TAMANHO na biblioteca para selecionar o campo que deve ser escrito
*/
void escreverUmDosCampos(int tamanho){
	switch (tamanho){
	case TAMANHO_PEQUENO:
		escreverCampo(campoPequeno, QUANTIDADE_LINHAS_PARA_MENORES);
		break;
	case TAMANHO_MEDIO:
		escreverCampo(campoMedio, QUANTIDADE_LINHAS_PARA_MEDIOS);
		break;
	case TAMANHO_GRANDE:
		escreverCampo(campoGrande, QUANTIDADE_LINHAS_PARA_GRANDES);
		break;
	}
}



/*
Função para verificar se a posição escolhida está livre e dentro dos limites do mapa escolhido.
Utilize as constantes de TAMANHO da biblioteca
*/
bool verificarPosicaoLivre(int linha, int coluna, int tamanho) {
	switch (tamanho){
	case TAMANHO_PEQUENO:
		if (campoPequeno[linha][coluna] == VAZIO && linha < QUANTIDADE_LINHAS_PARA_MENORES && coluna < QUANTIDADE_COLUNAS) {
			campoPequeno[linha][coluna] = CERCA_TEMPORARIA;
			return true;
		}
		return false;
		break;

	case TAMANHO_MEDIO:
		if (campoMedio[linha][coluna] == VAZIO && linha < QUANTIDADE_LINHAS_PARA_MEDIOS && coluna < QUANTIDADE_COLUNAS) {
			campoMedio[linha][coluna] = CERCA_TEMPORARIA;
			return true;
		}
		return false;
		break;

	case TAMANHO_GRANDE:
		if (campoGrande[linha][coluna] == VAZIO && linha < QUANTIDADE_LINHAS_PARA_GRANDES && coluna < QUANTIDADE_COLUNAS) {
			campoGrande[linha][coluna] = CERCA_TEMPORARIA;
			return true;
		}
		return false;
		break;

	default:
		cout << "ERRO GRAVE! Fechando..." << endl;
		return 0;
		break;
	}
}



/*
Função que posiciona uma cerca por vez.
*/
void colocarCercaTemporaria(int linha, int coluna, char campo[][QUANTIDADE_COLUNAS]) {
	campo[linha][coluna] = CERCA_TEMPORARIA;
}



/*
Algoritmo que posiciona cercas por si só (modo de simulação 2). Sorteia um número aleatório
*/
void colocarCercasTemporarias(char campo[][QUANTIDADE_COLUNAS], int quantidadeCercas, int quantidadeLinhas) {
	srand(time(NULL));

	const int quantidadeTestes = 100;
	int usadas[quantidadeTestes][25] = {};

	cout << quantidadeCercas << endl;

	while (quantidadeCercas > 0) {
		int linha = rand() % quantidadeLinhas;
		int coluna = rand() % QUANTIDADE_COLUNAS;

		if (((coluna <= 3 && linha <= 3) || (coluna >= QUANTIDADE_COLUNAS - 5 && linha <= 3)) ||
			((coluna <= 3 && linha >= quantidadeLinhas - 5) || (coluna >= 21 && linha >= quantidadeLinhas - 5)) ||
			(((coluna >= 9 && coluna <= 12) && (linha <= quantidadeLinhas / 2 + 1 && linha >= quantidadeLinhas / 2 - 1)))) {

			if (campo[linha][coluna] == VAZIO) {
				colocarCercaTemporaria(linha, coluna, campo);
				quantidadeCercas--;
			}
		}
	}

	cout << quantidadeCercas << endl;
}



int quantasCasasVirusInfectou(char campo[][QUANTIDADE_COLUNAS], int quantidadeLinhas) {
	int quantidade = 0;

	for (int i = 0; i < quantidadeLinhas; i++) {
		for (int j = 0; j < QUANTIDADE_COLUNAS; j++) {
			if (campo[i][j] == VIRUS) {
				quantidade++;
			}
		}
	}

	return quantidade;
}



/*
Função para verificar se a posição do array é igual a VAZIO, retorno verdadeiro ou falso.
*/
bool posicaoVazio(int linha, int coluna, char campo[][QUANTIDADE_COLUNAS]) {
	return campo[linha][coluna] == VAZIO;
}



/*
Função recursiva para fazer a proliferação do vírus no array, utilizando a proliferação natural (casa por casa).
Precisa da linha, coluna e o array com coluna fixa na constante QUANTIDADE_COLUNA.
*/
void virus(int linha, int coluna, char campo[][QUANTIDADE_COLUNAS], int velocidade, int tamanho) {
	if (velocidade == 1) {
		for (int linhaAux = LIMITE_MIN_LINHA_COLUNA_VIRUS; linhaAux <= LIMITE_MAX_LINHA_COLUNA_VIRUS; linhaAux++) {
			for (int colunaAux = LIMITE_MIN_LINHA_COLUNA_VIRUS; colunaAux <= LIMITE_MAX_LINHA_COLUNA_VIRUS; colunaAux++) {
				if (posicaoVazio(linha + linhaAux, coluna + colunaAux, campo)) {
					campo[linha + linhaAux][coluna + colunaAux] = VIRUS;
					_sleep(100);
					virus(linha + linhaAux, coluna + colunaAux, campo, velocidade, tamanho);
					cout << "\n\n\n" << endl;
					escreverUmDosCampos(tamanho);
				}
			}
		}
	}
	else {
		for (int linhaAux = LIMITE_MIN_LINHA_COLUNA_VIRUS; linhaAux <= LIMITE_MAX_LINHA_COLUNA_VIRUS; linhaAux++) {
			for (int colunaAux = LIMITE_MIN_LINHA_COLUNA_VIRUS; colunaAux <= LIMITE_MAX_LINHA_COLUNA_VIRUS; colunaAux++) {
				if (posicaoVazio(linha + linhaAux, coluna + colunaAux, campo)) {
					campo[linha + linhaAux][coluna + colunaAux] = VIRUS;
					virus(linha + linhaAux, coluna + colunaAux, campo, velocidade, tamanho);
				}
			}
		}
	}
}



/*
Função para marcar o VIRUS em uma posição determinada (Apenas para testar a função virus).
*/
void  marcarVirus(int linha, int coluna, char campo[][QUANTIDADE_COLUNAS]) {
	campo[linha][coluna] = VIRUS;
}



/*

*/
void rodarVirusNosPontosAleatorios(char campo[][QUANTIDADE_COLUNAS], int quantidadeLinhas, int velocidade, int tamanho) {
	srand(time(NULL));

	int linha = rand() % 3;
	int coluna = rand() % 3;

	virus(linha, coluna, campo, velocidade, tamanho);

	linha = rand() % 3;
	coluna = rand() % 20 + 16;

	virus(linha, coluna, campo, velocidade, tamanho);

	linha = rand() % quantidadeLinhas + (quantidadeLinhas - 4);
	coluna = rand() % 3;

	virus(linha, coluna, campo, velocidade, tamanho);

	linha = rand() % quantidadeLinhas + (quantidadeLinhas - 4);
	coluna = rand() % 20 + 16;

	virus(linha, coluna, campo, velocidade, tamanho);

	linha = rand() % (QUANTIDADE_COLUNAS / 2 + 2) + (QUANTIDADE_COLUNAS / 2 - 2);
	coluna = rand() % (quantidadeLinhas / 2 + 2) + (quantidadeLinhas / 2 - 2);;

	virus(linha, coluna, campo, velocidade, tamanho);
}