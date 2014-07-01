#ifndef ASSENTO_H
#define ASSENTO_H

#include <iostream>

class Assento{
private:
//Atributos
	int idAssento;		//identificador do assento
	int livre;			//flag disponibilidade do assento
	char idFileira;		//identificador da fileira

public:
//Metodos
	//Construtores e Destrutor
	Assento();
	Assento(int assento, int idfila);
	~Assento();

	//GETTERS
	bool getLivre();
	void setLivre(int val);

	//Operador sobrecarregado
	bool operator==(const int num);
	void saveObject(ofstream &arquivo);	//salva objeto no arquivo
	void loadObject(ifstream &arquivo); //carrega objeto do arquivo
};

Assento::Assento(){
	idAssento = 0;
	livre = 1;
	idFileira = 0;
}
Assento::Assento(int assento,int idfila){
	idAssento = assento;
	livre = 1;
	idFileira = idfila;

}
Assento::~Assento(){

}
bool Assento::getLivre(){
	if(livre == 1) //se esta disponivel, retorna 1;
		return 1;
	return 0;
}

void Assento::setLivre(int val){
	livre = val;
}

bool Assento::operator==(const int num){
  if(num == livre)
    return true;
  return false;
}

void Assento::saveObject(ofstream &arquivo){
	arquivo << idAssento << "\n";
	arquivo << livre << "\n";
	arquivo << idFileira << "\n";
}

void Assento::loadObject(ifstream &arquivo){
	arquivo >> idAssento;
	arquivo >> livre;
	arquivo >> idFileira;
}
#endif
