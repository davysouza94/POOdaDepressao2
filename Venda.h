#ifndef _VENDA_H
#define _VENDA_H

#include <iostream>
#include <string>
#include <time.h>
#include "Sessao.h"
#include "Ingresso.h"
#include "enumpag.h"
#include "Data.h"

class Venda{
private:
	string dtVenda;
	double valorTotal;
	FormaPgto pgto;
	Lista <Ingresso> ingressos;
public:
	Venda();
	double calculaValorTotal(int qtdInteiro, int qtdMeio);
	void emitirIngressos();
	void addIngressos();
	void removerIngressos();
};

Venda::Venda(){
	valorTotal = 0;
	dtVenda = __DATE__;
}

double Venda::calculaValorTotal(int qtdIng, int tipo){
	if(tipo == 1)
		return qtdIng * 3;
	return qtdIng * 1.5;
}

void Venda::emitirIngressos(){
	//diminuir vagas na sessao

	cout << "Sessao: x" << endl;
	cout << "Quantidade de Ingressos: " << endl;
	cout << "Valor: " << valorTotal << endl;
	cout << "Data:" << dtVenda << endl;
}

void Venda::addIngressos(){
	int tipo;

	cout << "Escolha o Tipo do Ingresso:" << endl;
	cout << "1 - Inteiro" << endl << "2 - Meio" << endl;
	cin >> tipo;

	int qtdIng;
	cout << "Escolha a quantidade de Ingressos:" << endl;
	cin >> qtdIng;

	valorTotal = valorTotal + calculaValorTotal(qtdIng, tipo);
	cout << "Valor Total: " << valorTotal << endl;

}

void Venda::removerIngressos(){
	int tipo;
	cout << "Qual tipo de ingresso voce deseja remover?" << endl;
	cout << "1 - Inteiro" << endl << "2 - Meio" << endl;

	int qtdIng;
	cout << "Escolha a quantidade de Ingressos que deseja Remover:" << endl;
	cin >> qtdIng;

	valorTotal = valorTotal - calculaValorTotal(qtdIng, tipo);
	cout << "Valor Total: " << valorTotal << endl; 
}
#endif