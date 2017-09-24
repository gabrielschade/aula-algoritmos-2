// Templates.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "Arrays.h"

using namespace std;

template <typename T>
T leia()
{
	T valor;
	cin >> valor;
	return valor;
}

template <typename T>
void escreva(T valor)
{
	cout << valor;
}

void exercicio1()
{
	int numero1 = 4, numero2 = 5;
	cout << "Swap" << endl;
	cout << numero1 << ", " << numero2 << endl;
	meuSwap(numero1, numero2);
	cout << numero1 << ", " << numero2;
	cout << endl;
}

void exercicio2e3() 
{
	cout << "Leia e escreva" << endl;
	int valor = leia<int>();
	string texto = leia<string>();

	escreva<int>(valor);
	escreva<string>(texto);
	cout << endl;
}

void testarBiblioteca() 
{
	int array[] = { 5,10,2,1,99 };
	bubblesort2(array, 5, ORDENACAO_CRESCENTE);
	bubblesort2(array, 5, ORDENACAO_DECRESCENTE);
	inverterArray(array, 5);
	int maior = encontrarMaiorValor(array, 5);
	int menor = encontrarMenorValor(array, 5);
	int indiceMaior = encontrarMaiorIndice(array, 5);
	int indiceMenor = encontrarMenorIndice(array, 5);
}

int main()
{
	exercicio1();
	exercicio2e3();
	testarBiblioteca();
	

	system("pause");
    return 0;
}

