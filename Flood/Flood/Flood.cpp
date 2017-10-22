// Flood.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Flood.h"

using namespace std;
bool linhaEcolunaDentroDosLimitesDaMatriz(int linha, int quantidadeLinhas, int coluna, int quantidadeColunas)
{
	return linha < 0
		|| linha >= quantidadeLinhas
		|| coluna < 0
		|| coluna >= quantidadeColunas;
}

bool areaVaziaNoCampo(char campo[][QUANTIDADE_COLUNAS], int linha, int coluna)
{
	return campo[linha][coluna] == VAZIO;
}

void infestarVirus(
	char campo[][QUANTIDADE_COLUNAS],
	int quantidadeLinhas, 
	int linha, 
	int coluna,
	bool exibirPassoAPasso)
{
	if (linhaEcolunaDentroDosLimitesDaMatriz(linha, quantidadeLinhas, coluna, QUANTIDADE_COLUNAS)
		|| !areaVaziaNoCampo(campo, linha,coluna))
		return;

	campo[linha][coluna] = VIRUS;
	if (exibirPassoAPasso)
		escreverCampo(campo, quantidadeLinhas);

	for (int desvioLinha = -1; desvioLinha <= 1; desvioLinha++)
		for (int desvioColuna = -1; desvioColuna <= 1; desvioColuna++)
			infestarVirus(campo, quantidadeLinhas, linha + desvioLinha, coluna + desvioColuna, exibirPassoAPasso);
}

void iniciarInfestacaoVirus(
	char campo[][QUANTIDADE_COLUNAS],
	int quantidadeLinhas,
	int linha,
	int coluna,
	bool exibirPassoAPasso
)
{
	infestarVirus(campo, quantidadeLinhas, linha, coluna, exibirPassoAPasso);

	cout << endl;
	if(!exibirPassoAPasso)
		escreverCampo(campo, quantidadeLinhas);
}



int main()
{
	iniciarInfestacaoVirus(campoGrande, QUANTIDADE_LINHAS_PARA_GRANDES, 5, 3, false);
	/*escreverUmDosCampos(TAMANHO_PEQUENO);
	cout << endl;
	
	escreverUmDosCampos(TAMANHO_MEDIO);
	cout << endl;

	escreverUmDosCampos(TAMANHO_GRANDE);
	cout << endl;*/

	system("pause");
    return 0;
}

