#ifndef _VENDA_H
#define _VENDA_H


#include <string>
#include <time.h>
#include "Sessao.h"
#include "Ingresso.h"
#include "enumpag.h"
#include "Data.h"
#include "gerenciarSala.h"

class Venda{
private:
	int sessao;
	string nomeFilme;
	string dtVenda;
	double valorTotal;
	FormaPgto pgto;
	Lista <Ingresso> ingressos;
public:
	Venda();
	double calculaValorTotal(int qtdInteiro, int qtdMeio);
	void emitirIngressos(gerenciarSala &salas);
	void addIngressos(gerenciarSala &salas);
};

Venda::Venda():pgto(){
	sessao = 0;
	nomeFilme = " ";
	valorTotal = 0;
	dtVenda = __DATE__;
}

double Venda::calculaValorTotal(int qtdIng, int tipo){
	if(tipo == 1)
		return qtdIng * 3;
	return qtdIng * 1.5;
}

void Venda::emitirIngressos(gerenciarSala &salas){
	//diminuir vagas na sessao

	cout << "Filme: " << nomeFilme << endl;
	cout << "Quantidade de Ingressos: " << endl;
	cout << "Valor: " << valorTotal << endl;
	cout << "Data:" << dtVenda << endl;
}

void Venda::addIngressos(gerenciarSala &salas){
	int tipo;
	int qtdIng;
	int idSala;
	int idSessao;
	Sala *salaDesejada;
	Sessao *sessaoDesejada;
	salas.exibeSessoes();
	std::cout << "Escolha a sala e a sessao desejada" << endl;
	std::cin >> idSala >> idSessao;

	salaDesejada = &(salas.buscarSala(idSala)->elem);
	if(salaDesejada == NULL){
		cout << "Sala nao encontrada";
		return;
	}
	sessaoDesejada = &(salaDesejada->buscarSessao(idSessao)->elem);
	if(sessaoDesejada == NULL){
		cout << "Sessao nao encontrada";
		return;
	}
	nomeFilme = sessaoDesejada->getFilme();
	cout << "Filme escolhido: " << nomeFilme << endl;
	cout << "Escolha o Tipo do Ingresso:" << endl;
	cout << "1 - Inteiro" << endl << "2 - Meio" << endl;
	cin >> tipo;

	cout << "Escolha a quantidade de Ingressos:" << endl;
	cin >> qtdIng;

	valorTotal = valorTotal + calculaValorTotal(qtdIng, tipo);
	cout << "Valor Total: " << valorTotal << endl;

}

#endif
