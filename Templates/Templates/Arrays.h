#pragma once

const int ORDENACAO_CRESCENTE = 1;
const int ORDENACAO_DECRESCENTE = 2;
const int MENOR_INDICE = 0;
const int MAIOR_INDICE = 1;
const int MENOR_VALOR = 2;
const int MAIOR_VALOR = 3;

template <typename T>
void meuSwap(T &valor1, T &valor2)
{
	T auxiliar = valor1;
	valor1 = valor2;
	valor2 = auxiliar;
}

template <typename T>
void bubblesort(T array[], int tamanho, int ordenacao)
{
	for (int repeticoes = 0; repeticoes < tamanho -1; repeticoes++)
		for (int indice = 0; indice < tamanho -1; indice++)
			if ( 
				(ordenacao ==  ORDENACAO_CRESCENTE 
				&& array[indice] > array[indice + 1])
				|| 
				(ordenacao == ORDENACAO_DECRESCENTE
				&& array[indice] < array[indice + 1]) )				
					meuSwap(array[indice], array[indice + 1]);
		
}

template <typename T>
void inverterArray(T array[], int tamanho)
{
	int indiceFinal = tamanho - 1;
	for (int indice = 0; indice < tamanho / 2; indice++)
	{
		meuSwap(array[indice], array[indiceFinal]);
		indiceFinal--;
	}
		
}

template <typename T>
void bubblesort2(T array[], int tamanho, int ordenacao)
{
	for (int repeticoes = 0; repeticoes < tamanho - 1; repeticoes++)
		for (int indice = 0; indice < tamanho - 1; indice++)
			if (array[indice] > array[indice + 1])
				meuSwap(array[indice], array[indice + 1]);

	if (ordenacao == ORDENACAO_DECRESCENTE)
		inverterArray(array, tamanho);
}

template <typename T>
T encontrarMaiorValor(T array[], int tamanho)
{
	T maior;
	for (int indice = 0; indice < tamanho; indice++)
		if (indice == 0 || array[indice] > maior)
			maior = array[indice];

	return maior;
}
















template <typename T>
void encontrarValores(T array[], int tamanho, int resultados[2])
{
	T maior, menor;
	int maiorIndice, menorIndice;

	for (int indice = 0; indice < tamanho; indice++)
	{
		if (indice == 0 || array[indice] > maior)
		{
			maior = array[indice];
			maiorIndice = indice;
		}

		if (indice == 0 || array[indice] < menor)
		{
			menor = array[indice];
			menorIndice = indice;
		}
	}

	resultados[MENOR_INDICE] = menorIndice;
	resultados[MAIOR_INDICE] = maiorIndice;
}

template <typename T>
int encontrarIndice(T array[], int tamanho, int indice)
{
	int resultados[2] = { 0 };
	encontrarValores(array, tamanho, resultados);
	return resultados[indice];
}

template <typename T>
int encontrarMaiorIndice(T array[], int tamanho)
{
	return encontrarIndice(array, tamanho, MAIOR_INDICE);
}

template <typename T>
T encontrarMaiorValor2(T array[], int tamanho)
{
	int indiceDoMaiorValor = encontrarMaiorIndice;
	return array[indiceDoMaiorValor];
}

template <typename T>
int encontrarMenorIndice(T array[], int tamanho)
{
	return encontrarIndice(array, tamanho, MENOR_INDICE);
}

template <typename T>
T encontrarMenorValor(T array[], int tamanho)
{
	int indiceDoMaiorValor = encontrarMenorIndice(array, tamanho);
	return array[indiceDoMaiorValor];
}