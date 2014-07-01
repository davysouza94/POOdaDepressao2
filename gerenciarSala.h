#ifndef GERENCIAR_SALA_H
#define GERENCIAR_SALA_H

using namespace std;
//includes necessarios
#include "Sala.h"
#include "Lista.h"

/* CLASSE gerenciarSala */
class gerenciarSala {
private:
//Atributos
	Lista <Sala> salas; //Lista de objetos do tipo Sala

public:
//Metodos
	//Construtor
	gerenciarSala();

	void inserirSala();		//cria e insere sala na lista
	void exibeSalas();		//exibe salas da lista
	void situacao();		//altera situacao da sala
	No<Sala>* buscarSala(int chave);	//busca sala na lista, de acordo com chave determinada
	void ordenarSalas();	//ordena salas de acordo com o id
	void inserirSessao();	//insere sessao na sala
	void exibeSessoes();	//exibe sessoes

	void saveObject(ofstream &arquivo);	//salva objeto no arquivo
	void loadObject(ifstream &arquivo); //carrega objeto do arquivo

};

gerenciarSala::gerenciarSala():salas() {
}

//Metodo para inserir Salas
void gerenciarSala::inserirSala() {

	int numFileira, numAssentos; //auxiliares

	//Recebe Dados da sala a ser inserida
	cout << "Informe o numero de fileiras: ";
	cin >> numFileira;
	cout << "Informe o numero de assentos por fileira: ";
	cin >> numAssentos;

	//se sala nao existe, cria uma nova e insere na lista.
	Sala temp(0, numAssentos, numFileira);
	salas.insereFim(temp);
	std::cout << "Sala criada com sucesso" << std::endl << std::endl;
	salas.junta();
}

//Metodo para inserir sessao na sala.
void gerenciarSala::inserirSessao(){
	int id;
	No<Sala> *sala;

	//Recebe ID da sala
	std::cout << "Indique o ID da sala correspondente a sessao: ";
	std::cin >> id;
	sala = salas.busca(id); //busca sala indicada
	if (sala == NULL){ //se nao encontra sala..
		std::cout << "Sala nao encontrada" << std::endl;
		return;
	}//caso encontre, insere a sessao na lista de sessoes da sala
	sala->elem.inserirSessao();
}
//Exibe lista de Salas existentes
void gerenciarSala::exibeSalas() {
	salas.junta();
	salas.exibe();
}
//Exibe sessoes existentes
void gerenciarSala::exibeSessoes(){
	No<Sala> *aux;
	aux = salas.getPl();

	while(aux!=NULL){
		aux->elem.exibirSessoes();
		aux = aux->prox;
	}
}
//Metodo para alterar situacao da sala
void gerenciarSala::situacao() {
	int num, sit;
	No<Sala> *salaEncontrada;

	salas.exibe();
	cout << "Informe o Numero da Sala: ";
	cin >> num;
	cout << "Informe a Situacao da Sala: " << endl;
	cout << "  1 - Disponivel" << endl << "  2 - Manutencao de Equipamentos" << endl;
	cout << "  3 - Reforma" << endl << "  4 - Manutencao Geral" << endl;
	cout << "Situacao: ";
	cin >> sit;	sit--;

	salaEncontrada = salas.busca(num); //busca sala
	try {
		if (salaEncontrada == NULL)
			throw(-1);
		(salaEncontrada->elem).setSituacao(sit); //caso encontre a sala, altera-se a situacao
	} catch (int erro) {
		if (erro == -1)
			std::cout << "Sala Nao Existente" << std::endl;
	}
}

No<Sala>* gerenciarSala::buscarSala(int chave) {
	return salas.busca(chave);
}

void gerenciarSala::ordenarSalas(){
	salas.ordena();
}

void gerenciarSala::saveObject(ofstream &arquivo){
	salas.saveData(arquivo);
}
void gerenciarSala::loadObject(ifstream &arquivo){
	salas.loadData(arquivo);
}

#endif
