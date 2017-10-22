// Structs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <ctime>

using namespace std;

#pragma region Exercicio 3

const int CADASTRAR = 1, LISTAR_TODOS = 2, LISTAR_PROMOCOES = 3, SAIR = 0;
const int TAMANHO_ESTOQUE = 10;

struct Produto {
	string codigo;
	string nome;
	double preco;
	double percentualDesconto;
	bool ativo;
};



void exibirMenu() {
	cout << "########### MENU PRINCIPAL ###########" << endl;
	cout << "[1] - Cadastrar Produtos" << endl;
	cout << "[2] - Listar todos os produtos" << endl;
	cout << "[3] - Listar produtos em promoção" << endl;
	cout << "[0] - Sair" << endl;
}

int obterOpcaoMenuEscolhidaPeloUsuario() {
	exibirMenu();
	int opcaoSelecionada = 0;
	cin >> opcaoSelecionada;
	return opcaoSelecionada;
}

void listarProdutos(Produto estoque[TAMANHO_ESTOQUE], bool somentePromocao)
{
	cout << endl << endl;

	for (int indice = 0; indice < TAMANHO_ESTOQUE; indice++) {
		Produto produto = estoque[indice];
		if (produto.ativo
			&& (!somentePromocao
				|| somentePromocao && produto.percentualDesconto > 0
				)
			)
		{
			cout << "Nome: " << produto.nome;
			cout << " | Código: " << produto.codigo;
			cout << " | Preço: " << produto.preco;
			cout << " | Desconto de: " << produto.percentualDesconto << "%";
			cout << " | Preço com desconto: " << produto.preco * (1 - (produto.percentualDesconto / 100));
			cout << endl;
		}
	}
}

void listarTodosOsProdutos(Produto estoque[TAMANHO_ESTOQUE]) {
	listarProdutos(estoque, false);
}

void listarProdutosEmPromocao(Produto estoque[TAMANHO_ESTOQUE]) {
	listarProdutos(estoque, true);
}

void listarTodosOsProdutosAntigo(Produto estoque[TAMANHO_ESTOQUE])
{
	for (int indice = 0; indice < TAMANHO_ESTOQUE; indice++) {
		Produto produto = estoque[indice];
		if (produto.ativo)
		{
			cout << "Nome: " << produto.nome;
			cout << " | Código: " << produto.codigo;
			cout << " | Preço: " << produto.preco;
			cout << " | Desconto de: " << produto.percentualDesconto << "%";
			cout << " | Preço com desconto: " << produto.preco * 100 / produto.percentualDesconto;
			cout << endl;
		}
	}
}

void listarProdutosEmPromocaoAntigo(Produto estoque[TAMANHO_ESTOQUE])
{
	for (int indice = 0; indice < TAMANHO_ESTOQUE; indice++) {
		Produto produto = estoque[indice];
		if (produto.ativo && produto.percentualDesconto > 0)
		{
			cout << "Nome: " << produto.nome;
			cout << " | Código: " << produto.codigo;
			cout << " | Preço: " << produto.preco;
			cout << " | Desconto de: " << produto.percentualDesconto << "%";
			cout << " | Preço com desconto: " << produto.preco * 100 / produto.percentualDesconto;
			cout << endl;
		}
	}
}

int obterEspacoLivreNoEstoque(Produto estoque[TAMANHO_ESTOQUE])
{
	int posicaoLivre = INT32_MAX;
	for (int indice = 0; indice < TAMANHO_ESTOQUE; indice++)
	{
		Produto produto = estoque[indice];
		if (!produto.ativo && posicaoLivre == INT32_MAX)
			posicaoLivre = indice;
	}
	return posicaoLivre;
}

void efetuarCadastroDeProduto(Produto estoque[TAMANHO_ESTOQUE], int espacoNoEstoque)
{
	cout << "Nome do produto: ";
	cin >> estoque[espacoNoEstoque].nome;
	cout << "Código do produto: ";
	cin >> estoque[espacoNoEstoque].codigo;
	cout << "Preço do produto: ";
	cin >> estoque[espacoNoEstoque].preco;
	cout << "Percentual de descontos do produto: ";
	cin >> estoque[espacoNoEstoque].percentualDesconto;
	estoque[espacoNoEstoque].ativo = true;

	cout << endl << "Produto cadastrado com sucesso!";
}

void cadastrarNovoProduto(Produto estoque[TAMANHO_ESTOQUE])
{
	cout << "Bem-vindo ao cadastro de produto..." << endl;
	int espacoNoEstoque = obterEspacoLivreNoEstoque(estoque);
	if (espacoNoEstoque == INT32_MAX)
		cout << "Infelizmente não há mais espaço no estoque..." << endl;
	else
		efetuarCadastroDeProduto(estoque, espacoNoEstoque);
}

bool solicitarAoUsuarioEscolhaDaFuncionalidade(Produto estoque[TAMANHO_ESTOQUE]) {
	int opcao = obterOpcaoMenuEscolhidaPeloUsuario();
	switch (opcao)
	{
	case CADASTRAR:
		cadastrarNovoProduto(estoque);
		break;
	case LISTAR_TODOS:
		listarTodosOsProdutos(estoque);
		break;
	case LISTAR_PROMOCOES:
		listarProdutosEmPromocao(estoque);
		break;
	case SAIR:
		break;
	default:
		cout << endl << "Opção inválida..." << endl;
		opcao = solicitarAoUsuarioEscolhaDaFuncionalidade(estoque);
		break;
	}

	cout << endl << endl;
	
	return opcao;
}

void zerarEstoque(Produto estoque[TAMANHO_ESTOQUE]) {
	for (int indice = 0; indice < TAMANHO_ESTOQUE; indice++)
		estoque[indice].ativo = false;
}

void exercicioTres() {
	Produto estoque[TAMANHO_ESTOQUE];
	zerarEstoque(estoque);
	int opcao = SAIR;
	do {
		opcao = solicitarAoUsuarioEscolhaDaFuncionalidade(estoque);
	} while (opcao != SAIR);

}

#pragma endregion

#pragma region Exercicio 2
const int TAMANHO_MATRIZ = 5;

struct Elemento {
	int valor;
	int linha;
	int coluna;
};

int inserirValorAleatorio(int matriz[TAMANHO_MATRIZ][TAMANHO_MATRIZ], int linha, int coluna, bool numeroSeraImpar)
{
	int valor = rand() % 90 + 10;
	bool valorPar = valor % 2 == 0;

	if (valorPar && numeroSeraImpar
		|| !valorPar && !numeroSeraImpar)
		valor += 1;

	matriz[linha][coluna] = valor;
	return valor;
}

void preencherMatriz(int matriz[TAMANHO_MATRIZ][TAMANHO_MATRIZ])
{
	for (int linha = 0; linha < TAMANHO_MATRIZ; linha++)
		for (int coluna = 0; coluna < TAMANHO_MATRIZ; coluna++)
			inserirValorAleatorio(matriz, linha, coluna, true);
}

void escreverMatriz(int matriz[TAMANHO_MATRIZ][TAMANHO_MATRIZ])
{
	for (int linha = 0; linha < TAMANHO_MATRIZ; linha++)
	{
		cout << " | ";
		for (int coluna = 0; coluna < TAMANHO_MATRIZ; coluna++)
			cout << matriz[linha][coluna] << " | ";

		cout << endl;
	}

}

Elemento obterElementoPar(int matriz[TAMANHO_MATRIZ][TAMANHO_MATRIZ]) {
	Elemento elementoPar;
	for (int linha = 0; linha < TAMANHO_MATRIZ; linha++)
		for (int coluna = 0; coluna < TAMANHO_MATRIZ; coluna++)
			if (matriz[linha][coluna] % 2 == 0)
			{
				elementoPar.valor = matriz[linha][coluna];
				elementoPar.linha = linha;
				elementoPar.coluna = coluna;
			}

	return elementoPar;
}

void exercicioDois() {
	srand(time(0));

	int matriz[TAMANHO_MATRIZ][TAMANHO_MATRIZ] = { 0 };
	preencherMatriz(matriz);

	int linhaParaValorPar = rand() % 5;
	int colunaParaValorPar = rand() % 5;
	int valorInserido = inserirValorAleatorio(matriz, linhaParaValorPar, colunaParaValorPar, false);

	Elemento elementoPar = obterElementoPar(matriz);

	escreverMatriz(matriz);
	cout << endl;
	cout << "Valor esperado: " << valorInserido << " | Valor obtido: " << elementoPar.valor << endl;
	cout << "Linha esperada: " << linhaParaValorPar << " | Linha obtida: " << elementoPar.linha << endl;
	cout << "Coluna esperada: " << colunaParaValorPar << " | Coluna obtida: " << elementoPar.coluna << endl;

	system("pause");
}
#pragma endregion

#pragma region Exercicio 1

struct Cliente {
	string	nome;
	string 	cpf;
	int	idade;
};

void exercicioUm() {
	Cliente cliente;
	cout << "Nome do cliente: ";
	cin >> cliente.nome;
	cout << endl << "CPF do cliente: ";
	cin >> cliente.cpf;
	cout << endl << "Idade do cliente: ";
	cin >> cliente.idade;

	cout << endl << "Informações do cliente: " << endl;
	cout << "Nome: " << cliente.nome << " | CPF: " << cliente.cpf << " | Idade: " << cliente.idade << endl;

	system("pause");
}
#pragma endregion





int main()
{
	setlocale(LC_ALL, "Portuguese");
	//exercicioUm();
	//exercicioDois();
	exercicioTres();
	return 0;
}

