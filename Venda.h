#ifndef _VENDA_H
#define _VENDA_H

//includes necessarios
#include <string>
#include <time.h>
#include "Sessao.h"
#include "enumpag.h"
#include "Data.h"
#include "gerenciarSala.h"
#include <iomanip>

/* CLASSE Venda */
class Venda{
private:
//Atributos
	int idSessao;					//ID da sessao
	string nomeFilme;			//Nome do filme
	string dtVenda;				//Data da venda
	double valorTotal;			//Valor Total da Venda
	int ingressosInteiro;		//qtd de ingressos Inteiros
	int ingressosMeio;			//qtd de ingressos Meio
	FormaPgto pgto;				//enum forma de pagamento
	Sala *salaDesejada;			//ponteiro para sala desejada
	Sessao *sessaoDesejada;		//ponteiro para sessao desejada


public:
//Metodos
	//construtor
	Venda();

	//Metodos Gerais
	double calculaValorTotal(int qtdInteiro, int qtdMeio); //Calcula o valor total da venda
	void emitirIngressos(gerenciarSala &salas);			   //Emite ingressos (Finaliza venda)
	void addIngressos(gerenciarSala &salas);			   //Adiciona ingressos
	//Sobrecarga de Operador
	friend ostream& operator<<(ostream& os, const Venda& elem);

	void saveObject(ofstream &arquivo);	//salva objeto no arquivo
	void loadObject(ifstream &arquivo); //carrega objeto do arquivo
	//SET
	void setFormPgto(int pag);

	int getIngressosMeio() const {
		return ingressosMeio;
	}

	int getIngressosInteiro() const {
		return ingressosInteiro;
	}
};

Venda::Venda():pgto(){
	salaDesejada = NULL;
	sessaoDesejada = NULL;
	ingressosInteiro = 0;
	ingressosMeio = 0;
	idSessao = 0;
	nomeFilme = " ";
	valorTotal = 0;
	dtVenda = __DATE__;
}

//Metodo para o calculo do valor total da Venda
double Venda::calculaValorTotal(int qtdIng, int tipo){
	if(tipo == 1)
		return qtdIng * 3;
	return qtdIng * 1.5;
}
//Funcao Emitir ingresso
void Venda::emitirIngressos(gerenciarSala &salas){
	int pag;
	char opc = 'x';

	//Escolhe a forma de pagamento
	cout << "Forma de pagamento: " << endl;
	cout << "  1 - Dinheiro" << endl << "  2 - Cartao" << endl;
	cout << "Opcao: ";
	cin >> pag;
	setFormPgto(pag);

	//verifica se existem lugares adjacentes
	if(sessaoDesejada->setDisponivel(ingressosInteiro+ingressosMeio, 0) == 0){
		cout << "Lugares adjacentes nao disponiveis." << endl;
		cout << "Desejam sentar separados? <S/N>: ";
		while(opc!='S' && opc!='s' && opc!='n' && opc!='N'){
			cin >> opc;
		}
		if(opc == 'S' || opc == 's'){
			sessaoDesejada->setDisponivel(ingressosInteiro+ingressosMeio, 1);
		}else{
			cout << "Venda nao efetuada" << endl;
			throw 0;
			return;
		}
	}

	cout << "Filme: " << nomeFilme << endl;
	cout << "Ingressos - Inteiro: " << ingressosInteiro << " - Meio: " << ingressosMeio << endl;
	cout << "Valor: " << valorTotal << endl;
	cout << "Data:" << dtVenda << endl << endl;
	if(pgto == 1)
		cout << "Forma de Pagamento: Dinheiro" <<endl;
	else if(pgto == 2)
		cout << "Forma de Pagamento: Cartao" <<endl;
}

//Funcao para adicionar ingressos
void Venda::addIngressos(gerenciarSala &salas){
	//variaveis auxiliares
	int tipo;
	int qtdIng;
	int idSala;
	int idSessao;
	int lugares;

	salas.exibeSessoes(); //Exibe sessoes existentes
	std::cout << "Escolha a sala e a sessao desejada: ";
	std::cin >> idSala >> idSessao; //escolhe sala e sessao
	if(salas.buscarSala(idSala) == NULL){ //busca sala
		cout << "Sala nao existe!" << endl;	//tratamento de erro para sala nao existente
		throw -1;
		return;
	}
	salaDesejada = &(salas.buscarSala(idSala)->elem);
	if(salaDesejada->buscarSessao(idSessao) == NULL){//tratamento de erro para sessao nao existente
		cout << "Sessao nao existe!" << endl;
		throw -1;
		return;
	}
	sessaoDesejada = &(salaDesejada->buscarSessao(idSessao)->elem);
	lugares = sessaoDesejada->getDisponivel(); //obtem disponibilidade da sessao
	if(lugares == 0){ //tratamento para sessao lotada
		cout << "Sessao lotada" << endl;
		throw -1;
		return;
	}
	nomeFilme = sessaoDesejada->getFilme();
	//escolhe tipo de ingresso
	cout << "Filme escolhido: " << nomeFilme << endl;
	cout << "Escolha o Tipo do Ingresso:" << endl;
	cout << " 1 - Inteiro" << endl << " 2 - Meio" << endl;
	cout << "Tipo: ";
	cin >> tipo;
	//escolhe qtd de ingressos
	cout << "Escolha a quantidade de Ingressos: ";
	cin >> qtdIng;
	if(qtdIng + ingressosInteiro + ingressosMeio > lugares){
		cout << "Nao existem lugares suficientes" << endl;
	}
	if(tipo == 1){
		ingressosInteiro+=qtdIng;
	}else{
		ingressosMeio+=qtdIng;
	}
	//calcula valor total
	valorTotal = valorTotal + calculaValorTotal(qtdIng, tipo);
	cout << "Valor Total: " << std::fixed << std::setprecision(2) << valorTotal << endl;
}


ostream& operator<<(ostream& os, const Venda& elem){
	os << "Filme: " << elem.nomeFilme << endl;
	os << "Quantidade de Ingressos: " << endl;
	os << "Valor: " << elem.valorTotal << endl;
	os << "Ingressos - Inteiro: " << elem.ingressosInteiro << " - Meio: " << elem.ingressosMeio << endl;
	os << "Data:" << elem.dtVenda << endl;
	if((int)elem.pgto == 1)
		os << "Forma de Pagamento: Dinheiro" <<endl;
	if((int)elem.pgto == 2)
		os << "Forma de Pagamento: Cartao" <<endl;
    return os;
}

void Venda::setFormPgto(int pag){
	pgto = (FormaPgto)pag;
}

void Venda::saveObject(ofstream &arquivo){
	arquivo << idSessao << "\n";
	arquivo << ingressosInteiro << "\n";
	arquivo << ingressosMeio << "\n";
	arquivo << nomeFilme << "\n";
	arquivo << valorTotal << "\n";
	arquivo << dtVenda << "\n";
}

void Venda::loadObject(ifstream &arquivo){
	arquivo >> idSessao;
	cout << idSessao << " - 1" << endl;
	arquivo >> ingressosInteiro;
	cout << ingressosInteiro << " - 2" << endl;
	arquivo >> ingressosMeio;
	cout << ingressosMeio << " - 3" << endl;
	arquivo.ignore();
	getline(arquivo, nomeFilme);
	cout << nomeFilme << " - 4" << endl;
	arquivo >> valorTotal;
	cout << valorTotal << " - 5" << endl;
	arquivo.ignore();
	getline(arquivo, dtVenda);
	cout << dtVenda << " - 6" << endl;

}
#endif
