#ifndef GERENCIAR_SALA_H
#define GERENCIAR_SALA_H

using namespace std;

#include "Sala.h"
#include "Lista.h"

class gerenciarSala {
private:
	Lista <Sala> salas;

public:
	gerenciarSala();
	void inserirSala();
	void exibeSalas();
	void situacao();
	No<Sala>* buscarSala(int chave);
	void ordenarSalas(); //ordena salas de acordo com o id
	void inserirSessao();
	void exibeSessoes();
};

gerenciarSala::gerenciarSala():salas() {
}

void gerenciarSala::inserirSala() {

	int num, numFileira, numAssentos;
	char opc;
	cout << "Informe o Numero da Sala: " << endl;
	cin >> num;
	cout << "Informe o numero de fileiras: " << endl;
	cin >> numFileira;
	cout << "Informe o numero de assentos por fileira:" << endl;
	cin >> numAssentos;

	if (salas.busca(num) == NULL) {
		Sala temp(num, numAssentos, numFileira);
		salas.insereFim(temp);
		std::cout << "Sala criada com sucesso" << std::endl << std::endl;
	} else {
		while (opc != 'S' && opc != 's' && opc != 'N' && opc != 'n') {
			std::cout << "Sala " << num << " já existe, deseja substituir?"
					<< std::endl;
			std::cout << "<S/N>";
			std::cin >> opc;
			if (opc == 'S' || opc == 's') {
				Sala temp(num, numAssentos, numFileira);
				salas.deletaValor(num);
				salas.insereFim(temp);
				std::cout << "Sala alterada com sucesso" << std::endl << std::endl;
			} else if (opc == 'N' || opc == 'n') {
				std::cout << "Sala não foi alterada" << std::endl << std::endl;
			} else {
				std::cout << "Insira 'S' para Sim, 'N' para Nao" << endl;
			}
		}
	}
}

void gerenciarSala::inserirSessao(){
	int id;
	No<Sala> *sala;
	std::cout << "Indique o id da sala correspondente a sessão" << std::endl;
	std::cin >> id;
	sala = salas.busca(id);
	if (sala == NULL){
		std::cout << "Sala não encontrada" << std::endl;
		return;
	}
	sala->elem.inserirSessao();
}

void gerenciarSala::exibeSalas() {
	salas.exibe();
}
void gerenciarSala::exibeSessoes(){
	No<Sala> *aux;
	aux = salas.getPl();

	while(aux!=NULL){
		aux->elem.exibirSessoes();
		aux = aux->prox;
	}
}

void gerenciarSala::situacao() {
	int num, sit;
	No<Sala> *salaEncontrada;

	salas.exibe();
	cout << "Informe o Numero da Sala: " << endl;
	cin >> num;
	cout << "Informe a Situacao da Sala: " << endl;
	cin >> sit;

	salaEncontrada = salas.busca(num);
	try {
		if (salaEncontrada == NULL)
			throw(-1);
		(salaEncontrada->elem).setSituacao(sit);
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
#endif
