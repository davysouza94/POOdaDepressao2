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

using namespace std;

//Declarando Funcoes
void gerenciaSala(gerenciarSala &salas);		//Funcao responsavel por gerenciar salas
void gerenciaSessao(gerenciarSala &salas);		//Funcao responsavel por gerenciar sessoes
void gerenciaVenda(Lista <Venda> &vendas, gerenciarSala &salas);  //Funcao responsavel por gerenciar vendas
bool loadData(gerenciarSala &salas, Lista<Venda> &vendas);
void saveData(Lista <Venda> &vendas, gerenciarSala &salas);
void load(Lista<Venda> &vendas, gerenciarSala &salas);

/* ---------------- */
/* ROTINA PRINCIPAL */
/* ---------------- */
int main() {
	//Declarando objetos
	gerenciarSala salas;	//Objeto para gerenciamento de salas e sessoes
	Lista <Venda> vendas;	//Lista encadeada que armazenará objetos do tipo venda


	//Carrega Dados
	//loadData(salas, vendas);
	//While para manter o programa em execução
	int opcao = 1;
	while (opcao != 0){
		//Escolhe opcoes no menu principal
		cout << "Escolha uma das opcoes: " << endl;
		cout << "  0 - Finalizar Programa" << endl;
		cout << "  1 - Gerenciar Salas" << endl;
		cout << "  2 - Gerenciar Sessoes" << endl;
		cout << "  3 - Gerenciar Vendas" << endl;
		cout << "  4 - Exibir Relatorio de Vendas" << endl;
		cout << " 5 - save" << endl;
		cout << "6 - load" << endl;
		cout << "7 - loadInput" << endl;
		//cout << "  5 - Carregar Dados" << endl;
		cout << "Opcao: ";
		cin >> opcao;
		cout << endl;

		switch (opcao) {
		case 0:
			return 0;
		case 1:
			gerenciaSala(salas);
			break;
		case 2:
			gerenciaSessao(salas);
			break;
		case 3:
			gerenciaVenda(vendas, salas);
			break;
		case 4:
			vendas.exibe();
			break;
		case 5:
			saveData(vendas, salas);
			break;
		case 6:
			load(vendas, salas);
			break;
		case 7:
			loadData(salas, vendas);
			break;
		default:
			break;
		}
	}
}

/*Funcao Responsavel pelo gerenciamento das Salas*/
void gerenciaSala(gerenciarSala &salas){

	//Switch para menu de Gerenciamento de Salas
	int opcao = 0;
	cout << "Escolha uma das opcoes: " << endl;
	cout << "  0 - Voltar" << endl;
	cout << "  1 - Criar Sala" << endl;
	cout << "  2 - Set Situacao" << endl;
	cout << "  3 - Exibir Salas" << endl;
	cout << "  4 - Capacidade" << endl;
	cout << "  5 - Situacao" << endl;
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
		salas.situacao();
		break;
	case 3:
		salas.exibeSalas();
		break;
	case 4:
		break;
	case 5:
		salas.situacao();
		break;
	default:
		break;
	}
}

/*Funcao Responsavel pelo gerenciamento das Sessoes*/
void gerenciaSessao(gerenciarSala &salas){
	
	//Switch para menu de Gerenciamento de Sessoes
	int opcao = 0;
	cout << "Escolha uma das opcoes: " << endl;
	cout << "  0 - Voltar" << endl;
	cout << "  1 - Inserir Sessão" << endl;
	cout << "  2 - Exibir Sessoes" << endl;
	cout << "Opcao: ";
	cin >> opcao;
	cout << endl;

	switch (opcao) {
	case 0:
		return;
	case 1:
		salas.inserirSessao();
		break;
	case 2:
		salas.exibeSessoes();
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	default:
		break;
	}
}


void gerenciaVenda(Lista <Venda> &vendas, gerenciarSala &salas){
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

bool loadData(gerenciarSala &salas, Lista<Venda> &vendas){
	string word;
	//redireciona std::cin para ler do arquivo input.in
    std::ifstream in("input.in");
    std::streambuf *cinbuf = std::cin.rdbuf();
    std::cin.rdbuf(in.rdbuf());


	int opcao = 1;
	while (opcao != 0){
		cin >> opcao;
		cout << endl;

		switch (opcao) {
		case 0:
			//redireciona cin para ler entradas no console
			std::cin.rdbuf(cinbuf);
			cout << "------Carregando-Dados----------";
			cout << "\n\n\n\n\n";
			cout << "Dados carregados com sucesso" << "\n\n";
			return 1;
		case 1:
			gerenciaSala(salas);
			break;
		case 2:
			gerenciaSessao(salas);
			break;
		case 3:
			gerenciaVenda(vendas, salas);
			break;
		case 4:
			vendas.exibe();
			break;
		case 5:
			break;
		default:
			break;
		}
	}



    return 1;
}




void saveData(Lista <Venda> &vendas, gerenciarSala &salas){
	ofstream arquivo;
	std::cout << "salvando" << std::endl;
	arquivo.open("save.txt");
	try{
		salas.saveObject(arquivo);
		vendas.saveData(arquivo);
	}catch(...){
		cout << "BLEH";
	}
	arquivo.close();
}

void load(Lista<Venda> &vendas, gerenciarSala &salas){
	ifstream arquivo;
	std::cout << "loading..." << std::endl;
	arquivo.open("save.txt");
	salas.loadObject(arquivo);
	vendas.loadData(arquivo);
	arquivo.close();
}














