#include "stdafx.h"
#include <iostream>
#include "Flood.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Portuguese");

	int opcao_escolhida;

	cout << "\t\t CAMPO DE TESTES \n\n"
		 << "Entre com o valor correspondente ao tamanho do campo desejado:\n"
		 << "1 - Pequeno \t 2 - Médio \t 3 - Grande"
		 << endl;
	cin  >> opcao_escolhida;


	/*
	escreverUmDosCampos(TAMANHO_PEQUENO);
	cout << endl;
	
	escreverUmDosCampos(TAMANHO_MEDIO);
	cout << endl;

	escreverUmDosCampos(TAMANHO_GRANDE);
	cout << endl;
	*/

	system("pause");
    return 0;
}

