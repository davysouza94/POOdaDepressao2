#ifndef SESSAO_H
#define SESSAO_H

#include "Fileira.h"
#include "Lista.h"
#include <string>

class Sessao{
private:
	int numvendido;
	int encerrado;
	int inicio, fim;
	string filme;
	int idSala;
	int idSessao;
	Lista <Fileira> fileiras;

public:
	Sessao();
	Sessao(int idsala, int idsessao, int inic, int theEnd, string nomeFilme, int qtFileira, int numAssento);
	void setStatus(int encerrado);
	int getStatus();
	int getInicio();
	int getFim();
	int getHorario();
	void setHorario(int hor, int min);
	int getDisponivel();
	void setNumVendido(int numVendido);
	string getFilme();
	void setFilme(string nomeFilme);
	friend ostream& operator<<(ostream& os, const Sessao& elem);
};

Sessao::Sessao(){
	inicio = 0;
	fim = 0;
	idSala = 0;
	numvendido = 0;
	encerrado = 1;
	idSessao = 0;
}

Sessao::Sessao(int idsala, int idsessao, int inic, int theEnd, string nomeFilme, int qtFileira, int numAssento){
	inicio = inic;
	fim = theEnd;
	idSala = idsala;
	numvendido = 0;
	encerrado = 1;
	filme = nomeFilme;
	idSessao = idsessao;

	Fileira *f, fIn;
	int i;
	for(i=0;i<qtFileira;i++){
		f = new Fileira(numAssento, 65+i);
		fIn = *f;

		delete(f);
		fileiras.insereFim(fIn);

	}

}

void Sessao::setStatus(int encerrado){
	int capacidade;
	capacidade = 0;
	if(capacidade - numvendido == 0){
		encerrado = 0;
	}
	else
		encerrado = 1;
}
int Sessao::getStatus(){
	return encerrado;
}

int Sessao::getInicio(){
	return inicio;
}
int Sessao::getFim(){
	return fim;
}

int Sessao::getDisponivel(){
	return encerrado;
}

void Sessao::setNumVendido(int numVendido){
	numvendido = numVendido;
}

string Sessao::getFilme(){
	return filme;
}

void Sessao::setFilme(string nomeFilme){
	filme = nomeFilme;
}

ostream& operator<<(ostream& os, const Sessao& elem){
	os << "ID da sessao: " << elem.idSessao << "ID da sala: " << elem.idSala << std::endl;
	os << "Filme: " << elem.filme << std::endl;
	os << "Inicio: " << elem.inicio << " - Termino: " << elem.fim << std::endl;
	os << "Disponibilidade: " << elem.encerrado << std::endl << std::endl;
    return os;
}


#endif
