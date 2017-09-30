// Recursividade.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;
const int TAMANHO = 6;

void escreverNumeros(int de, int ate)
{
	cout << de << endl;

	if (de == ate)
		return;

	if (de > ate)
		escreverNumeros(de - 1, ate);
	else
		escreverNumeros(de + 1, ate);
}

string realizarConversaoBinaria(int numero)
{
	if (numero == 1)
		return to_string(1);

	int resultado = numero % 2;
	return to_string(resultado) + realizarConversaoBinaria(numero / 2);
}

string decimalParaBinario(int numero)
{
	string binarioInvertido = realizarConversaoBinaria(numero);
	reverse(binarioInvertido.begin(), binarioInvertido.end());
	return binarioInvertido;
}

int somarValores(int array[], int posicao)
{
	int valorNaPosicaoAtual = array[posicao];
	if (posicao == 0)
		return valorNaPosicaoAtual;
	
	return valorNaPosicaoAtual + somarValores(array, posicao - 1);
}

bool palindromo(string palavra)
{
	int tamanho = palavra.length();
	string inicial, final;

	if (tamanho == 1 || tamanho == 0)
		return true;

	inicial = palavra.substr(0, 1);
	final = palavra.substr(tamanho - 1, 1);

	if (inicial == final)
		return palindromo(palavra.substr(1, tamanho - 2));
	else
		return false;
}

int main()
{
	int valores[] = { 1,2,4,10,3 };
	//escreverNumeros(20, 10);
	//cout << endl << "binario: "<< decimalParaBinario(10) << endl;
	//cout << endl << "soma do array: " << somarValores(valores, 4) << endl;
	cout << endl << palindromo("abba") << endl;
	system("pause");
	return 0;
}

