#ifndef _FILME_H
#define _FILME_H

//includes necessarios
#include <iostream>
#include <string>

/* CLASSE Venda */
class Filme{
private:
//Atributos
	int idFilme;				//ID da sessao
	std::string nomeFilme;			//Nome do filme

public:
	Filme();
	Filme(std::string nomeFilme, int id);
	std::string getFilme();
	void setFilme(std::string filme);
	int getId();
	void setId(int id);
	friend ostream& operator<<(ostream& os, const Filme& elem);
	bool operator==(const int num);
	bool operator!=(const int num);

	void saveObject(ofstream &arquivo);	//salva objeto no arquivo
	void loadObject(ifstream &arquivo); //carrega objeto do arquivo

};

Filme::Filme(){
	idFilme = 0;
}
Filme::Filme(std::string nome, int id){
	nomeFilme = nome;
	idFilme = id;
}

void Filme::setFilme(std::string filme){
	nomeFilme = filme;
}
std::string Filme::getFilme(){
	return nomeFilme;
}

int Filme::getId(){
	return idFilme;
}
void Filme::setId(int id){
	idFilme = id;
}


ostream& operator<<(ostream& os, const Filme& elem){
	os << elem.idFilme << " - " << elem.nomeFilme << endl;

    return os;
}

bool Filme::operator==(const int num){
  if(num == idFilme)
    return true;
  return false;
}

bool Filme::operator!=(const int num){
  if(num != idFilme)
    return true;
  return false;
}


void Filme::saveObject(ofstream &arquivo){
	arquivo << idFilme << "\n";
	arquivo << nomeFilme << "\n";
}
void Filme::loadObject(ifstream &arquivo){
	arquivo >> idFilme;
	arquivo.ignore();
	getline(arquivo, nomeFilme);
}






#endif
