#ifndef SALA_H
#define SALA_H

#include "Situacao.h"
#include "Sessao.h"
#include "Lista.h"
#include <string>

class Sala{
private:
	int numSala;
	int capacidade;
	int qtFileira;
	int qtSessoes;
	Situacao situacao;
	Lista < Sessao > sessoes;

public:
	Sala();
	Sala(int nsala, int numAssento, int qtFil);

	int getNumSala();
	int getCapacidade();
	void setNumSala(int nSala);
	void setCapacidade(int cap);
	void setSituacao(int sit);
	void inserirSessao();
	void exibirSessoes();
	friend ostream& operator<<(ostream& os, const Sala& elem);
	bool operator==(const int num);
	bool operator!=(const int num);
	bool operator>(const int num);
	bool operator>(const Sala elem);
	bool operator<(const int num);
	bool operator<(const Sala elem);
};

Sala::Sala():sessoes(){
	qtSessoes = 0;
	qtFileira = 10;
	numSala = 0;
	capacidade = qtFileira*10;
	situacao = disponivel;
}
Sala::Sala(int nsala, int numAssento, int qtFil):sessoes(){
	qtSessoes = 0;
	numSala = nsala;
	qtFileira = qtFil;
	capacidade = numAssento*qtFileira;
	situacao = disponivel;
}

void Sala::inserirSessao(){
	Sessao *s, sIn;
	string nome;
	int inicio, fim;
	std::cout << "Insira o nome do filme: " << std::endl;
	std::cin >> nome;
	std::cout << "Insira o inicio e o fim do filme: " << std::endl;
	std::cin >> inicio >> fim;

	try{
		s = new Sessao(numSala, qtSessoes, inicio, fim, nome, 10, 10);
		sIn = *s;
		sessoes.insereFim(sIn);
		qtSessoes++;
	}catch(...){
		std::cout << "Erro" << std::endl;
	}

}

void Sala::exibirSessoes(){
	sessoes.exibe();
}
int Sala::getNumSala(){
	return numSala;
}

int Sala::getCapacidade(){
	return capacidade;
}

void Sala::setNumSala(int nSala){
	numSala = nSala;
}

void Sala::setCapacidade(int cap){
	capacidade = cap;
}

void Sala::setSituacao(int sit){
	situacao = (Situacao)sit;
}

ostream& operator<<(ostream& os, const Sala& elem){
	os << "Sala: " << elem.numSala << " - Capacidade: " <<elem.capacidade<< " - Situacao: "<< elem.situacao;
    return os;
}

bool Sala::operator==(const int num){
  if(num == numSala)
    return true;
  return false;
}

bool Sala::operator!=(const int num){
  if(num != numSala)
    return true;
  return false;
}

bool Sala::operator>(const int num){
  if(numSala > num)
    return true;
  return false;
}

bool Sala::operator>(const Sala elem){
  if(numSala > elem.numSala)
    return true;
  return false;
}

bool Sala::operator<(const int num){
  if(numSala < num)
    return true;
  return false;
}

bool Sala::operator<(const Sala elem){
  if(numSala < elem.numSala)
    return true;
  return false;
}

#endif
