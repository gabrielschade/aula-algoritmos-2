// AplicacaoCPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void fibonacci()
{
	int primeiroValor = 0,
		segundoValor = 1,
		auxiliar,
		limite;

	cout << "Digite um número: ";
	cin >> limite;
	cout << "Série Fibonacci de " << limite << "." << endl;
	cout << primeiroValor << ", " << segundoValor;

	for (int contador = 0; contador < limite - 2; contador++) {
		auxiliar = primeiroValor + segundoValor;
		primeiroValor = segundoValor;
		segundoValor = auxiliar;

		cout << ", " << auxiliar;
	}

	cout << endl;
	system("pause");
}

void calcularMediaEExibirAcima() {
	const int TAMANHO = 10;
	int arrayInteiro[TAMANHO] = { 0 };
	int soma = 0,
		media = 0;

	cout << "Digite 10 valores: " << endl;
	for (int posicao = 0; posicao < TAMANHO; posicao++) {
		cin >> arrayInteiro[posicao];
		soma += arrayInteiro[posicao];
	}

	media = soma / TAMANHO;
	cout << endl << "Valores que estão acima da média: (" << media << ")" << endl;
	for (int posicao = 0; posicao < TAMANHO; posicao++)
		if (arrayInteiro[posicao] > media)
			cout << arrayInteiro[posicao] << ", ";

	cout << endl;
	system("pause");
}

void diagonalPrincipalComUm() {
	const int	
		LINHAS = 3,
		COLUNAS = 3;

	int matriz[3][3] = { 0 };

	for (int linha = 0; linha < LINHAS; linha++)
		for (int coluna = 0; coluna < COLUNAS; coluna++)
			if (linha == coluna)
				matriz[linha][coluna] = 1;
			else
				matriz[linha][coluna] = 0;

	for (int linha = 0; linha < LINHAS; linha++) {
		cout << " | ";

		for (int coluna = 0; coluna < COLUNAS; coluna++)
			cout << matriz[linha][coluna] << " | ";

		cout << endl;
	}
		
	cout << endl;
	system("pause");
}

int main()
{
	setlocale(LC_ALL, "Portuguese");
	//fibonacci();
	//calcularMediaEExibirAcima();
	//diagonalPrincipalComUm();
	return 0;
}

