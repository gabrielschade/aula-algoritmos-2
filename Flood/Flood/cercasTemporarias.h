#include "stdafx.h"
#include <iostream>
#include "Flood.h"
#include <time.h>

using namespace std;

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

		if  (((coluna <= 3 && linha <= 3) || (coluna >= QUANTIDADE_COLUNAS - 5 && linha <= 3)) ||
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