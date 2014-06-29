#ifndef SESSAO_H
#define SESSAO_H

#include "Fileira.h"
#include "Lista.h"
#include <string>
#include "Data.h"

class Sessao{
private:
	int numvendido;
	int lugaresVagos;
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
	int setDisponivel(int qt, int opc);
	void setNumVendido(int numVendido);
	string getFilme();
	void setFilme(string nomeFilme);
	friend ostream& operator<<(ostream& os, const Sessao& elem);
	bool operator==(const int num);
	bool operator!=(const int num);
};

Sessao::Sessao(){
	inicio = " ";
	fim = " ";
	idSala = 0;
	numvendido = 0;
	lugaresVagos = 1;
	idSessao = 0;
}

Sessao::Sessao(int idsala, int idsessao, string inic, string theEnd, string nomeFilme, int qtFileira, int numAssento){
	inicio = inic;
	fim = theEnd;
	idSala = idsala;
	numvendido = 0;
	lugaresVagos = 1;
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
	getDisponivel();
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
	return lugaresVagos;
}

string Sessao::getInicio(){
	return inicio;
}
string Sessao::getFim(){
	return fim;
}

int Sessao::getDisponivel(){
	No<Fileira> *aux;
	lugaresVagos=0;
	aux = fileiras.getPl();
	while(aux!=NULL){
		lugaresVagos += aux->elem.getAssentosLivres();
		aux = aux->prox;
	}
	return lugaresVagos;
}

int Sessao::setDisponivel(int qt, int opc){
	if(opc == 0){
		No<Fileira> *aux;
		No<Assento> *assentoVago;
		int i;
		aux = fileiras.getPl();
		while(aux!=NULL){
			if(aux->elem.disponiveis < qt)
				aux = aux->prox;
			else break;
		}
		if(aux == NULL){ //retorna 0 se nao encontrou lugares adjacentes
			getDisponivel();
			return 0;
		}

		assentoVago = aux->elem.assentos.busca(1); //retorna endere�o do n� do assento disponivel
		for(i=0;i<=qt;i++){
			if(assentoVago == NULL){//nao deve ocorrer
				cout << "erro!" << endl;
				return -1;
			}
			assentoVago->elem.setLivre(0);
			assentoVago = assentoVago->prox;
		}
		getDisponivel();
		return 1; //retorna 1 se for possivel ocupar o assento
	}else if(opc == 1){
		No<Fileira> *aux;
		No<Assento> *assentoVago;
		int i;

		aux = fileiras.getPl();
		for(i=0;i<qt && aux!=NULL;){
			while(aux!=NULL){
				if(aux->elem.disponiveis == 0)
					aux = aux->prox;
				else break;
			}
			if(aux == NULL){ //nao deve acontecer
				cout << "erro";
				return -1;
			}
			assentoVago = aux->elem.assentos.busca(1); //retorna endere�o do n� do assento disponivel
			while(assentoVago!=NULL && i<qt){
				assentoVago->elem.setLivre(0);
				assentoVago = assentoVago->prox;
				i++;
			}
			getDisponivel();
		}



	}
	return 1;
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
	os << "ID da sala: " << elem.idSala << std::endl << "ID da sess�o: " << elem.idSessao << std::endl;
	os << "Filme: " << elem.filme << std::endl;
	os << "Inicio: " << elem.inicio << " - Termino: " << elem.fim << std::endl;
	os << "Disponibilidade: " << elem.lugaresVagos << std::endl;
    return os;
}


#endif
