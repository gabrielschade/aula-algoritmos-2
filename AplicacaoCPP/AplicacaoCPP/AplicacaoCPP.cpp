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

int numeroGlobal = 10;

int somaCom10(int numero) {
	int valor = 10;
	return numero + 10;
}

int somaComTres(int numero)
{
	return numero + 3;
}


int valor = 5;

void escreverValor(int valor2 = 0, int valor3 = 10)
{
	cout << "Valor escrito pela funcao: " << valor2 << endl;
}

void escreverValor(bool teste)
{
	cout << teste;
}

int funcao();
int funcao(int a);
float funcao(double a);
int funcao(int a, double b);


template <typename T>
T Maior(T valor1, T Valor2) {
	T maior;
	if (valor1 > valor2)
		maior = valor1;
	else
		maior = valor2;

	return maior;
}

template <typename T>
void escreva(T valor) {
	cout << valor;
}

template <typename T>
void leia(T &valor) {
	cin >> valor;
}

template <typename T>
T maior(T valor1, T valor2){
	T maiorValor;
	if (valor1 > valor2)
		maiorValor = valor1;
	else
		maiorValor = valor2;

	return maiorValor;
}

template <typename T>
T bubblesort(T array[], int tamanho) {
	return array[0];
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

