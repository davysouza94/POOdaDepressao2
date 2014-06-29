
#ifndef ASSENTO_H
#define ASSENTO_H

#include <iostream>

class Assento{
private:
	int idAssento;
	int disponibilidade;
	char idFileira;

public:
	Assento();
	Assento(int assento, int idfila);
	bool verificaDisponibilidade();
	~Assento();

};

Assento::Assento(){
	idAssento = 0;
	disponibilidade = 0;
	idFileira = 0;
}
Assento::Assento(int assento,int idfila){
	idAssento = assento;
	disponibilidade = 0;
	idFileira = idfila;
	std::cout <<"CriandoAssento" << idAssento << "-" << idFileira << "-" << std::endl;

}
Assento::~Assento(){

}
bool Assento::verificaDisponibilidade(){
	if(disponibilidade == 0) //se esta disponivel, retorna 1;
		return 1;
	return 0;
}

#endif
