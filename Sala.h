#ifndef SALA_H
#define SALA_H

//Includes necessarios
#include "Situacao.h"
#include "Sessao.h"
#include "Lista.h"
#include <string>
#include "Filme.h"


/* CLASSE SALA */
class Sala{
private:
//Atributos
	int numSala;		//Numero da Sala (ID)
	int capacidade;		//Capacidade
	int qtFileiras;		//Quantidade de Fileiras
	int qtAssentos;		//Quantidade de Assentos
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
	void inserirSessao(Lista<Filme> &filmes);
	void setId(int id);
	void removeSessao();
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

	void saveObject(ofstream &arquivo);	//salva objeto no arquivo
	void loadObject(ifstream &arquivo); //carrega objeto do arquivo

};
//construtor padrao
Sala::Sala():sessoes(){
	qtAssentos = 10;
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
	capacidade = numAssento*qtFileiras;
	situacao = disponivel;
}
//Metodo para inserir sessao na lista de sessoes pertencentes a sala
void Sala::inserirSessao(Lista<Filme> &filmes){
	string horario;
	No<Filme> *f;
	Sessao *s, sIn; //auxiliares
	string nome;	//nome do filme
	int id;
	cin.ignore();
	filmes.exibe();
	std::cout << "Insira o Id do Filme: " << std::endl;
	cin >> id;
	f = filmes.busca(id);
	if(f == NULL){
		cout << "O id não existe" << endl;
		return;
	}
	nome = f->elem.getFilme();
	//Insere horarios do filme
	std::cout << "Insira o horario do inicio e fim do filme: ";
	cin.ignore();
	getline(cin, horario);
	string inicio, fim;

	try{//Tratamento de erro para inserir sessao
		s = new Sessao(numSala, horario, nome, qtFileiras, qtAssentos);
		sIn = *s;
		sessoes.insereFim(sIn);
	}catch(...){
		std::cout << "Erro" << std::endl;
	}
	sessoes.junta();
}

void Sala::removeSessao(){
	int id;
	cout << "Digite o id da sessao:" << endl;
	cin >> id;
	if(sessoes.deletaValor(id)){
		cout << "Sessao removida." << endl;
		return;
	}
	cout << "Sessao não encontrada" << endl;
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
	string sit;

	switch(elem.situacao){
		case 0:
			sit = "Disponivel";
			break;
		case 1:
			sit = "Manutencao de Equipamento";
			break;
		case 2:
			sit = "Reforma";
			break;
		case 3:
			sit = "Manutencao Geral";
			break;
	}

	os << "Sala: " << elem.numSala << " - Capacidade: " <<elem.capacidade<< " - Situacao: "<< sit;
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


void Sala::saveObject(ofstream &arquivo){
	sessoes.saveData(arquivo);
	arquivo << numSala << "\n";
	arquivo << capacidade << "\n";
	arquivo << qtFileiras << "\n";
	arquivo << qtAssentos << "\n";
	switch(situacao){
	case disponivel:
		arquivo << "0" << "\n";
		break;
	case manuEquipamento:
		arquivo << "1" << "\n";
		break;
	case reforma:
		arquivo << "2" << "\n";
		break;
	case manuGeral:
		arquivo << "3" << "\n";
		break;
	}
}
void Sala::loadObject(ifstream &arquivo){
	int opc;
	sessoes.loadData(arquivo);
	arquivo >> numSala;
	arquivo >> capacidade;
	arquivo >> qtFileiras;
	arquivo >> qtAssentos;
	arquivo >> opc;
	switch(opc){
	case 0:
		situacao = disponivel;
		break;
	case 1:
		situacao = manuEquipamento;
		break;
	case 2:
		situacao = reforma;
		break;
	case 3:
		situacao = manuGeral;
		break;
	}
}

void Sala::setId(int id){
	numSala = id;
}
#endif
