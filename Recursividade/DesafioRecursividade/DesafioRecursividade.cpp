// DesafioRecursividade.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

const int QUANTIDADE_BAUS = 6;

void obterCaminho(
	bool baus[QUANTIDADE_BAUS][QUANTIDADE_BAUS],
	bool bausVisitados[QUANTIDADE_BAUS],
	int bauAtual)
{
	bool todosVisitados = true;
	bool bausVisitadosCopia[QUANTIDADE_BAUS] = { false };

	for (int indice = 0; indice < QUANTIDADE_BAUS; indice++)
		bausVisitadosCopia[indice] = bausVisitados[indice];

	for (int bau = 0; bau < QUANTIDADE_BAUS; bau++)
	{
		obterCaminho(baus, bausVisitadosCopia, bau);
		todosVisitados = true;
		for (int indice = 0; indice < QUANTIDADE_BAUS; indice++)
			todosVisitados &= bausVisitadosCopia[indice];


	}
		
	
	

}

int main()
{
	bool baus[QUANTIDADE_BAUS][QUANTIDADE_BAUS] = {
		{ false, true, true, false,false,false},
		{ false, false, true, true,true,false },
		{ true, true, false, false,true,false },
		{ false, false, false, false,false,true},
		{ false, true, false, false,false,false },
		{ false, false, false, false, true, false },
	};
	bool bausVisitados[QUANTIDADE_BAUS] = { false, false, false, false, false, false };
	return 0;
}

