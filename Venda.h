#ifndef _VENDA_H
#define _VENDA_H


#include <string>
#include <time.h>
#include "Sessao.h"
#include "enumpag.h"
#include "Data.h"
#include "gerenciarSala.h"

class Venda{
private:
	int sessao;
	string nomeFilme;
	string dtVenda;
	double valorTotal;
	int ingressosInteiro;
	int ingressosMeio;
	FormaPgto pgto;
public:
	Venda();
	double calculaValorTotal(int qtdInteiro, int qtdMeio);
	void emitirIngressos(gerenciarSala &salas);
	void addIngressos(gerenciarSala &salas);
	friend ostream& operator<<(ostream& os, const Venda& elem);
};

Venda::Venda():pgto(){
	ingressosInteiro = 0;
	ingressosMeio = 0;
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
	Sala *salaDesejada = NULL;
	Sessao *sessaoDesejada = NULL;
	salas.exibeSessoes();
	std::cout << "Escolha a sala e a sessao desejada" << endl;
	std::cin >> idSala >> idSessao;
	if(salas.buscarSala(idSala) == NULL){
		cout << "Sala nao existe!" << endl;
		return;
	}
	salaDesejada = &(salas.buscarSala(idSala)->elem);
	if(salaDesejada->buscarSessao(idSessao) == NULL){
		cout << "Sessao nao existe!" << endl;
		return;
	}
	sessaoDesejada = &(salaDesejada->buscarSessao(idSessao)->elem);

	nomeFilme = sessaoDesejada->getFilme();
	cout << "Filme escolhido: " << nomeFilme << endl;
	cout << "Escolha o Tipo do Ingresso:" << endl;
	cout << "1 - Inteiro" << endl << "2 - Meio" << endl;
	cin >> tipo;

	cout << "Escolha a quantidade de Ingressos:" << endl;
	cin >> qtdIng;
	if(tipo == 1){
		ingressosInteiro+=qtdIng;
	}else{
		ingressosMeio+=qtdIng;
	}
	valorTotal = valorTotal + calculaValorTotal(qtdIng, tipo);
	cout << "Valor Total: " << valorTotal << endl;
}


ostream& operator<<(ostream& os, const Venda& elem){
	os << "Filme: " << elem.nomeFilme << endl;
	os << "Quantidade de Ingressos: " << endl;
	os << "Valor: " << elem.valorTotal << endl;
	os << "Ingressos - Inteiro: " << elem.ingressosInteiro << " - Meio: " << elem.ingressosMeio << endl;
	os << "Data:" << elem.dtVenda << endl;
    return os;
}

#endif
