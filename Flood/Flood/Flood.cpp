// Flood.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Flood.h"

using namespace std;

int main()
{
	escreverUmDosCampos(TAMANHO_PEQUENO);
	cout << endl;
	
	escreverUmDosCampos(TAMANHO_MEDIO);
	cout << endl;

	escreverUmDosCampos(TAMANHO_GRANDE);
	cout << endl;

	system("pause");
    return 0;
}

