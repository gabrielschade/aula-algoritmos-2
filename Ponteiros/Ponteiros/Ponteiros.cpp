// Ponteiros.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void trocar(int *ponteiro1, int *ponteiro2)
{
	int valor1 = *ponteiro1;
	valor1 += 10; 
}

//int main()
//{
//	int valor = 10;
//	int *ponteiro = &valor;
//	int valor2 = 20;
//	int *p2 = &valor2;
//	trocar(ponteiro, p2);
//	
//	int valorPegoPeloPonteiro;
//	
//	ponteiro = &valor;
//	valorPegoPeloPonteiro = *ponteiro;
//
//	cout << valor << endl;
//	cout << ponteiro << endl;
//	cout << valorPegoPeloPonteiro << endl;
//
//	system("pause");
//	return 0;
//}

