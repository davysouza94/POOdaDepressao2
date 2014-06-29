#ifndef SALA_H
#define SALA_H

//Includes necessarios
#include "Situacao.h"
#include "Sessao.h"
#include "Lista.h"
#include <string>
#include "Data.h"


/* CLASSE SALA */
class Sala{
private:
//Atributos
	int numSala;		//Numero da Sala (ID)
	int capacidade;		//Capacidade
	int qtFileiras;		//Quantidade de Fileiras
	int qtAssentos;		//Quantidade de Assentos
	int qtSessoes;		//Quantidade de Sessoes
	Data hora;			//Horario da Sessao (Inicio e Termino)
	Situacao situacao;	//enum Situacao, que indica o estado da sala
	Lista < Sessao > sessoes;  //Lista para objetos do tipo Sessao

public:
//Metodos

	//Construtores
	Sala();
	Sala(int nsala, int numAssento, int qtFil);

	//GETERS AND SETTER
	int getNumSala();
	int getCapacidade();
	void setNumSala(int nSala);
	void setCapacidade(int cap);
	void setSituacao(int sit);
	void inserirSessao();

	//Metodos Gerais
	No<Sessao>* buscarSessao(int chave);  //Busca Sessao na lista de sessoes, de acordo com a chave Inserida
	void exibirSessoes();  //Exibe Lista de sessoes

	//Sobrecarga de Operadores
	friend ostream& operator<<(ostream& os, const Sala& elem);
	bool operator==(const int num);
	bool operator!=(const int num);
	bool operator>(const int num);
	bool operator>(const Sala elem);
	bool operator<(const int num);
	bool operator<(const Sala elem);
};
//construtor padrao
Sala::Sala():sessoes(){
	qtAssentos = 10;
	qtSessoes = 0;
	qtFileiras = 10;
	numSala = 0;
	capacidade = qtFileiras*10;
	situacao = disponivel;
}
//costrutor com valores especificos
Sala::Sala(int nsala, int numAssento, int qtFil):sessoes(){
	numSala = nsala;
	qtAssentos = numAssento;
	qtFileiras = qtFil;
	qtSessoes = 0;
	capacidade = numAssento*qtFileiras;
	situacao = disponivel;
}
//Metodo para inserir sessao na lista de sessoes pertencentes a sala
void Sala::inserirSessao(){
	Sessao *s, sIn; //auxiliares
	string nome;	//nome do filme
	int h, m;		//horario
	char aux;		//auxiliar

	std::cout << "Insira o nome do filme: " << std::endl;
	std::getline(cin, nome);

	//Insere horarios do filme
	std::cout << "Insira os horarios de inicio e fim do filme: " << std::endl;
	std::cin >> h >> aux >> m;
	hora.setHoraInic(h,m);
	std::cin >> h >> aux >> m;
	hora.setHoraFim(h,m);
	string inicio, fim;
	inicio = hora.getHoraInic();
	fim = hora.getHoraFim();

	try{//Tratamento de erro para inserir sessao
		s = new Sessao(numSala, qtSessoes, inicio, fim, nome, qtFileiras, qtAssentos);
		sIn = *s;
		sessoes.insereFim(sIn);
		qtSessoes++;
	}catch(...){
		std::cout << "Erro" << std::endl;
	}

}

No<Sessao>* Sala::buscarSessao(int chave) {
	return sessoes.busca(chave);
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
