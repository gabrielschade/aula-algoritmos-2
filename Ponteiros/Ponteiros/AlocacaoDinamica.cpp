// Ponteiros.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void escreverArray(int *array, int tamanho)
{
	for (int indice = 0; indice < tamanho; indice++)
		cout << array[indice] << ", ";
	cout << endl;
}

void preencherArray(int *array, int tamanho)
{
	for (int indice = 0; indice < tamanho; indice++)
		array[indice] = indice * 2;
}

void copiarArray(int *arrayOrigem, int *arrayDestino, int tamanho)
{
	for (int indice = 0; indice < tamanho; indice++)
		arrayDestino[indice] = arrayOrigem[indice];
}

int main()
{
	setlocale(LC_ALL, "Portuguese");
	int *arrayPrincipal = new int[0];
	int *array1, *array2;
	int tamanho;

	cout << "Qual o tamanho do array que será gerado?" << endl;
	cin >> tamanho;
	
	cout << "Primeiro array criado:" << endl;

	array1 = new int[tamanho];
	preencherArray(array1, tamanho);
	escreverArray(array1, tamanho);
	copiarArray(array1, arrayPrincipal, tamanho);

	cout << "Cópia para o array principal:" << endl;
	escreverArray(arrayPrincipal, tamanho);

	tamanho += 1;
	array2 = new int[tamanho];
	preencherArray(array2, tamanho);
	escreverArray(array2, tamanho);
	copiarArray(array2, arrayPrincipal, tamanho);

	cout << "Cópia para o array principal:" << endl;
	escreverArray(arrayPrincipal, tamanho);

	system("pause");
	return 0;
}

