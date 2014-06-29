#ifndef SESSAO_H
#define SESSAO_H

#include "Fileira.h"
#include "Lista.h"
#include <string>
#include "Data.h"

class Sessao{
private:
	int numvendido;
	int encerrado;
	string inicio, fim;
	string filme;
	int idSala;
	int idSessao;
	Lista <Fileira> fileiras;

public:
	Sessao();
	Sessao(int idsala, int idsessao, string inic, string theEnd, string nomeFilme, int qtFileira, int numAssento);
	void setStatus(int encerrado);
	int getStatus();
	string getInicio();
	string getFim();
	int getHorario();
	void setHorario(int hor, int min);
	int getDisponivel();
	void setNumVendido(int numVendido);
	string getFilme();
	void setFilme(string nomeFilme);
	friend ostream& operator<<(ostream& os, const Sessao& elem);
	bool operator==(const int num);
	bool operator!=(const int num);
};

Sessao::Sessao(){
	//inicio = ;
	//fim = 0;
	idSala = 0;
	numvendido = 0;
	encerrado = 1;
	idSessao = 0;
}

Sessao::Sessao(int idsala, int idsessao, string inic, string theEnd, string nomeFilme, int qtFileira, int numAssento){
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

string Sessao::getInicio(){
	return inicio;
}
string Sessao::getFim(){
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

bool Sessao::operator==(const int num){
  if(num == idSessao)
    return true;
  return false;
}

bool Sessao::operator!=(const int num){
  if(num != idSessao)
    return true;
  return false;
}


ostream& operator<<(ostream& os, const Sessao& elem){
	os << "ID da sala: " << elem.idSala << std::endl << "ID da sessão: " << elem.idSessao << std::endl;
	os << "Filme: " << elem.filme << std::endl;
	os << "Inicio: " << elem.inicio << " - Termino: " << elem.fim << std::endl;
	os << "Disponibilidade: " << elem.encerrado << std::endl;
    return os;
}


#endif
