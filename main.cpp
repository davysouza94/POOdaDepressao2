/* ================================================================== *
Universidade Federal de Sao Carlos - UFSCar
 
Projeto Integrado - ED1 e POO
    Profa. Katti Faceli
	Profa. Tiemi Christine Sakata
 
    Rede de Cinemas - Fase Final
 
    Data: 29/06/2014
 
* ================================================================== *
 
Alunos: Bruno Henrique Pereira  				552097  
		Caio Henrique Rainha Cones				511277  
		Davy Alves de Souza 					552658 
		Guilherme Augusto Moreira Baldissera 	552232 
		Gustavo Eugênio Oliveira Munhoz 		552623 

 
* ================================================================== */

//Includes necessarios
#include <iostream>
#include <fstream>
#include <string>
#include "gerenciarSala.h"
#include "Venda.h"
#include "Filme.h"

using namespace std;
#include<string>

//Declarando Funcoes
void gerenciaSala(gerenciarSala &salas, Lista<Filme> &filmes);		//Funcao responsavel por gerenciar salas
void gerenciaSessao(gerenciarSala &salas, Lista<Filme> &filmes);		//Funcao responsavel por gerenciar sessoes
void gerenciaVenda(Lista <Venda> &vendas, gerenciarSala &salas, Lista<Filme> &filmes);  //Funcao responsavel por gerenciar vendas
void saveData(Lista <Venda> &vendas, gerenciarSala &salas, Lista<Filme> &filmes);
void loadData(Lista<Venda> &vendas, gerenciarSala &salas, Lista<Filme> &filmes);
void gerenciaFilme(Lista<Filme> &filmes);

/* ---------------- */
/* ROTINA PRINCIPAL */
/* ---------------- */
int main() {
	//Declarando objetos
	gerenciarSala salas;	//Objeto para gerenciamento de salas e sessoes
	Lista <Venda> vendas;	//Lista encadeada que armazenará objetos do tipo venda
	Lista <Filme> filmes;


	//Carrega Dados
	loadData(vendas, salas, filmes);
	//While para manter o programa em execução
	int opcao = 1;
	while (opcao != 0){
		//Escolhe opcoes no menu principal
		cout << "Escolha uma das opcoes: " << endl;
		cout << "  0 - Finalizar Programa" << endl;
		cout << "  1 - Gerenciar Salas" << endl;
		cout << "  2 - Gerenciar Sessoes" << endl;
		cout << "  3 - Gerenciar Filmes" << endl;
		cout << "  4 - Gerenciar Vendas" << endl;
		cout << "  5 - Exibir Relatorio de Vendas" << endl;
		cout << "Opcao: ";
		cin >> opcao;
		cout << endl;

		switch (opcao) {
		case 0:
			saveData(vendas, salas, filmes);
			cout << "Programa Finalizado" << endl;
			return 0;
		case 1:
			gerenciaSala(salas, filmes);
			break;
		case 2:
			gerenciaSessao(salas, filmes);
			break;
		case 3:
			gerenciaFilme(filmes);
			break;
		case 4:
			gerenciaVenda(vendas, salas, filmes);
			break;
		case 5:
			vendas.exibe();
			break;
		case 6:
			break;
		default:
			break;
		}
	}
}

/*Funcao Responsavel pelo gerenciamento das Salas*/
void gerenciaSala(gerenciarSala &salas, Lista<Filme> &filmes){

	//Switch para menu de Gerenciamento de Salas
	int opcao = 0;

	cout << "Escolha uma das opcoes: " << endl;
	cout << "  0 - Voltar" << endl;
	cout << "  1 - Criar Sala" << endl;
	cout << "  2 - Exibe Salas" << endl;
	cout << "  3 - Remove Sala" << endl;
	cout << "  4 - Mudar Situacao" << endl;
	cout << "Opcao: ";
	cin >> opcao;
	cout << endl;
	switch (opcao) {
	case 0:
		return;
	case 1:
		salas.inserirSala();
		salas.ordenarSalas();
		break;
	case 2:
		salas.exibeSalas();
		break;
	case 3:
		salas.removeSala();
		break;
	case 4:
		salas.situacao();
		break;
		break;
	default:
		break;
	}
}

/*Funcao Responsavel pelo gerenciamento das Sessoes*/
void gerenciaSessao(gerenciarSala &salas, Lista<Filme> &filmes){

	//Switch para menu de Gerenciamento de Sessoes
	int opcao = 0;
	cout << "Escolha uma das opcoes: " << endl;
	cout << "  0 - Voltar" << endl;
	cout << "  1 - Inserir Sessão" << endl;
	cout << "  2 - Exibir Sessoes" << endl;
	cout << "  3 - Remover Sessão" << endl;
	cout << "Opcao: ";
	cin >> opcao;
	cout << endl;

	switch (opcao) {
	case 0:
		return;
	case 1:
		salas.exibeSalas();
		salas.inserirSessao(filmes);
		break;
	case 2:
		salas.exibeSessoes();
		break;
	case 3:
		salas.removeSessao();
		break;
	case 4:
		break;
	case 5:
		break;
	default:
		break;
	}
}

void gerenciaFilme(Lista<Filme> &filmes){
	int opcao = 0;
	int idDel;
	std::string nomeFilme;
	cout << "Escolha uma das opcoes: " << endl;
	cout << "  0 - Voltar" << endl;
	cout << "  1 - Novo Filme" << endl;
	cout << "  2 - Exibir Filmes" << endl;
	cout << "  3 - Remover Filmes" << endl;
	cout << "Opcao: ";
	cin >> opcao;
	cout << endl;

	switch (opcao) {
	case 0:
		return;
	case 1:
		Filme *f;
		cout << "Nome do Filme:" << endl;
		cin.ignore();
		std::getline(cin, nomeFilme);
		f = new Filme(nomeFilme, 0);
		filmes.insereFim(*f);
		filmes.junta();
		break;
	case 2:
		filmes.exibe();
		break;
	case 3:
		filmes.exibe();
		cout << "Digite o id do filme que deseja deletar:" << endl;
		cin >> idDel;
		filmes.deletaValor(idDel);
		filmes.junta();
		break;
	case 4:
		break;
	case 5:
		break;
	default:
		break;
	}


}

void gerenciaVenda(Lista <Venda> &vendas, gerenciarSala &salas, Lista<Filme> &filmes){
	Venda *v = NULL; //Ponteiro auxiliar do tipo venda
	
	//While para menu de Gerenciamento de Salas
	int opcao = 0;
	while(opcao != -1){
		cout << "Escolha uma das opcoes: " << endl;
		cout << "  0 - Voltar" << endl;
		cout << "  1 - Adicionar Ingresso" << endl;
		cout << "  2 - Remover Ingresso" << endl;
		cout << "  3 - Emitir Ingresso" << endl;
		cout << "Opcao: ";
		if(v != NULL){
			cout << "Ingressos - Inteiro: " << v->getIngressosInteiro() << " - Meio: " << v->getIngressosMeio() << endl;
		}

		//Switch para menu de Gerenciamento de Salas
		cin >> opcao;
		cout << endl;
		switch (opcao) {
			case 0:
				return;
			case 1: //Adicionar ingressos
				if(v == NULL) //aloca um objeto venda se necessario
					v = new Venda();
					try{
						v->addIngressos(salas); //Chama addIngresso
					}
					catch(int num){
						delete(v); //desaloca variavel
						v = NULL;
					}
				break;
			case 2:
				delete(v);
				v = NULL;
				break;
			case 3:
				//Verifica se foram adicioados ingressos
				if(v == NULL){
					std::cout << "Nenhum ingresso adicionado, a compra sera cancelada." << endl;
					return;
				}
				try{
					v->emitirIngressos(salas);
				}catch(int n){
					if(n == 0) return;
				}
				vendas.insereFim(*v);
				return;
			default:
				break;
		}
	}
}


void saveData(Lista <Venda> &vendas, gerenciarSala &salas, Lista<Filme> &filmes){
	ofstream arquivo;
	std::cout << "Salvando Dados..." << std::endl;
	arquivo.open("save.txt");
	salas.saveObject(arquivo);
	filmes.saveData(arquivo);
	vendas.saveData(arquivo);
	arquivo.close();
	std::cout << "Dados Salvos Com Sucesso!" << std::endl;
}

void loadData(Lista<Venda> &vendas, gerenciarSala &salas, Lista<Filme> &filmes){
	ifstream arquivo;
	std::cout << "Carregando Dados..." << std::endl;
	arquivo.open("save.txt");
	salas.loadObject(arquivo);
	filmes.loadData(arquivo);
	vendas.loadData(arquivo);
	std::cout << "Dados Carregados Com Sucesso!" << std::endl;
	arquivo.close();
}














