
#ifndef ASSENTO_H
#define ASSENTO_H

#include <iostream>

class Assento{
private:
	int idAssento;
	int livre;
	char idFileira;

public:
	Assento();
	Assento(int assento, int idfila);
	bool getLivre();
	void setLivre(int val);
	bool operator==(const int num);
	~Assento();

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
	std::cout <<"CriandoAssento" << idAssento << "-" << idFileira << "-" << std::endl;

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

#endif
