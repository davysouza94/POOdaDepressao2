#ifndef FILEIRA_H
#define FILEIRA_H

//includes necessarios
#include "Assento.h"
#include "Lista.h"

class Fileira{
private:
//Atributos privados
	char idFileira;		//identificador da fileira
	int numAssentos;	//numero de assentos na fileira

public:
//Metodos e Atributos publicos

	int disponiveis;		//qtd de lugares disponiveis na fileira
	Lista < Assento > assentos;		//Lista de objetos do tipo Assento
	
	//Construtores e Destrutor
	Fileira();
	Fileira(int n,char idfila);
	~Fileira();

	int insereAssento();	  //Insere o assento na lista de assentos - chamado no construtor
	int getAssentosLivres();  //Obtem quntidade de assentos livres


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
