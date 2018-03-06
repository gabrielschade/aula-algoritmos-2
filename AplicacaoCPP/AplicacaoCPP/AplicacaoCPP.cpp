// AplicacaoCPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>

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

void bubblesortEmMatriz()
{
	srand(time(0));
	const int TAMANHO = 5;
	int matriz[TAMANHO][TAMANHO] = { 0 };
	int vetorAuxiliar[TAMANHO * TAMANHO];

	for (int linha = 0; linha < TAMANHO; linha++) {
		cout << "| ";
		for (int coluna = 0; coluna < TAMANHO; coluna++) {
			matriz[linha][coluna] = rand() % 101;
			cout << matriz[linha][coluna] << "| ";
		}
		cout << endl;
	}

	cout << endl << "Em ordem crescente" << endl;
	for (int linha = 0; linha < TAMANHO; linha++)
		for (int coluna = 0; coluna < TAMANHO; coluna++)
			vetorAuxiliar[(linha * TAMANHO) + coluna] = matriz[linha][coluna];

	for (int contador = 0; contador < TAMANHO * TAMANHO - 1; contador++)
		for (int indice = 0; indice < TAMANHO * TAMANHO - 1; indice++)
			if (vetorAuxiliar[indice] > vetorAuxiliar[indice + 1]) {
				int auxiliar = vetorAuxiliar[indice];
				vetorAuxiliar[indice] = vetorAuxiliar[indice + 1];
				vetorAuxiliar[indice + 1] = auxiliar;
			}

	for (int linha = 0; linha < TAMANHO; linha++)
		for (int coluna = 0; coluna < TAMANHO; coluna++)
			matriz[linha][coluna] = vetorAuxiliar[(linha * TAMANHO) + coluna];

	for (int linha = 0; linha < TAMANHO; linha++) {
		cout << "| ";
		for (int coluna = 0; coluna < TAMANHO; coluna++) {
			cout << matriz[linha][coluna] << "| ";
		}
		cout << endl;
	}

	cout << endl << "Em ordem decrescente" << endl;

	for (int contador = 0; contador < TAMANHO * TAMANHO - 1; contador++)
		for (int indice = 0; indice < TAMANHO * TAMANHO - 1; indice++)
			if (vetorAuxiliar[indice] < vetorAuxiliar[indice + 1]) {
				int auxiliar = vetorAuxiliar[indice];
				vetorAuxiliar[indice] = vetorAuxiliar[indice + 1];
				vetorAuxiliar[indice + 1] = auxiliar;
			}

	for (int linha = 0; linha < TAMANHO; linha++)
		for (int coluna = 0; coluna < TAMANHO; coluna++)
			matriz[linha][coluna] = vetorAuxiliar[(linha * TAMANHO) + coluna];

	for (int linha = 0; linha < TAMANHO; linha++) {
		cout << "| ";
		for (int coluna = 0; coluna < TAMANHO; coluna++) {
			cout << matriz[linha][coluna] << "| ";
		}
		cout << endl;
	}


	cout << endl;
}

void bubblesortEmVetor()
{
	srand(time(0));
	const int TAMANHO = 50;
	int valores[TAMANHO] = { 0 };

	for (int indice = 0; indice < TAMANHO; indice++) {
		valores[indice] = rand() % 101;
		cout << valores[indice] << ", ";
	}

	cout << endl << "Em ordem crescente" << endl;

	for (int contador = 0; contador < TAMANHO - 1; contador++)
		for (int indice = 0; indice < TAMANHO - 1; indice++)
			if (valores[indice] > valores[indice + 1]) {
				int auxiliar = valores[indice];
				valores[indice] = valores[indice + 1];
				valores[indice + 1] = auxiliar;
			}

	for (int indice = 0; indice < TAMANHO; indice++) {
		cout << valores[indice] << ", ";
	}

	cout << endl << "Em ordem decrescente" << endl;

	for (int contador = 0; contador < TAMANHO - 1; contador++)
		for (int indice = 0; indice < TAMANHO - 1; indice++)
			if (valores[indice] < valores[indice + 1]) {
				int auxiliar = valores[indice];
				valores[indice] = valores[indice + 1];
				valores[indice + 1] = auxiliar;
			}

	for (int indice = 0; indice < TAMANHO; indice++) {
		cout << valores[indice] << ", ";
	}


	cout << endl;
}



int main()
{
	maior<int>(1, 10);
	maior<double>(3.5, 3.9);
	maior<string>("a", "b");
	
	int array[] = { 1,2,3 };
	bubblesort<int>(array, 3);
	bubblesort<string>(array, 3);

	escreva(10);
	escreva("teste");
	int x = 0;
	leia<int>(x);
	double resultado = maior(1.5, 1.9);

	return 0;
}

