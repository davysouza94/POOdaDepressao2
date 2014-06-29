#ifndef FILEIRA_H
#define FILEIRA_H


#include "Assento.h"
#include "Lista.h"

class Fileira{
private:
	char idFileira;
	int numAssentos;


public:
	int disponiveis;
	Lista < Assento > assentos;
	
	Fileira();
	Fileira(int n,char idfila);
	~Fileira();

	int insereAssento();
	int getAssentosLivres();


};

Fileira::Fileira(){
	idFileira = 0;
	numAssentos = 0;
	disponiveis = 0;
}
Fileira::Fileira(int n,char idfila){
	numAssentos = n;
	disponiveis = n;
	idFileira = idfila;
	cout << "CriandoFila - " << idfila << std::endl;
	int i;
	Assento *a, aIn;
	for(i=0;i<numAssentos;i++){
		a = new Assento(i, idfila);
		aIn = *a;
		delete(a);
		assentos.insereFim(aIn);
	}
}

Fileira::~Fileira(){

}
int Fileira::getAssentosLivres(){
	No<Assento> *aux;
	disponiveis = 0;
	aux = assentos.getPl();
	while(aux!=NULL){
		if(aux->elem.getLivre() == 1){
			disponiveis++;
		}
		aux = aux->prox;
	}
	return disponiveis;
}
#endif
