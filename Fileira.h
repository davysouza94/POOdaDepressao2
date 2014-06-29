#ifndef FILEIRA_H
#define FILEIRA_H


#include "Assento.h"
#include "Lista.h"

class Fileira{
private:
	char idFileira;
	int numAssentos;
	Lista < Assento > assentos;
	
public:
	Fileira();
	Fileira(int n,char idfila);
	~Fileira();

	int insereAssento();
	bool verificaDisponibilidade();

};

Fileira::Fileira(){
	idFileira = 0;
	numAssentos = 0;
}
Fileira::Fileira(int n,char idfila){
	numAssentos = n;
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
bool Fileira::verificaDisponibilidade(){
	return 0;
}
#endif
