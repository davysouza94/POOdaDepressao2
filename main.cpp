#include <iostream>
#include "gerenciarSala.h"
#include "Venda.h"

using namespace std;
void gerenciaSala(gerenciarSala &salas);
void gerenciaSessao(gerenciarSala &salas);
void gerenciaVenda(Lista <Venda> &vendas, gerenciarSala &salas);

int main() {
	gerenciarSala salas;
	Lista <Venda> vendas;

	int opcao = 1;

	while (opcao != 0) {
		cout << "Escolha uma das opcoes: " << endl;
		cout << "0 - Finalizar Programa" << endl;
		cout << "1 - Gerenciar Salas" << endl;
		cout << "2 - Gerenciar Sessoes" << endl;
		cout << "3 - Gerenciar Vendas" << endl;
		cout << "4 - Exibir Relatorio de Vendas" << endl;
		cout << "5 - " << endl;
		cin >> opcao;

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
			break;
		default:
			break;
		}
	}
}


void gerenciaSala(gerenciarSala &salas){
	int opcao;
	opcao = 0;
	cout << "Escolha uma das opcoes: " << endl;
			cout << "0 - Voltar" << endl;
			cout << "1 - Criar Sala" << endl;
			cout << "2 - Set Situacao" << endl;
			cout << "3 - Exibir Salas" << endl;
			cout << "4 - Capacidade" << endl;
			cout << "5 - Situacao" << endl;
			cin >> opcao;

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

void gerenciaSessao(gerenciarSala &salas){
	int opcao;
	cout << "Escolha uma das opcoes: " << endl;
			cout << "0 - Voltar" << endl;
			cout << "1 - Inserir Sess�o" << endl;
			cout << "2 - Exibir Sessoes" << endl;
			cout << "3 - " << endl;
			cout << "4 - " << endl;
			cout << "5 - " << endl;
			cin >> opcao;

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
				salas.situacao();
				break;
			default:
				break;
			}
}

void gerenciaVenda(Lista <Venda> &vendas, gerenciarSala &salas){
	Venda *v = NULL;
	int opcao = 0;

	while(opcao != -1){
		cout << "Escolha uma das opcoes: " << endl;
		cout << "0 - Voltar" << endl;
		cout << "1 - Adicionar Ingresso" << endl;
		cout << "2 - Remover Ingresso" << endl;
		cout << "3 - Emitir Ingresso" << endl;
		if(v!=NULL){
			cout << "Ingressos - Inteiro: " << v->getIngressosInteiro() << " - Meio: " << v->getIngressosMeio() << endl;
		}
		cin >> opcao;


		switch (opcao) {
			case 0:
				return;
			case 1:
				if(v == NULL)
					v = new Venda();
					try{
						v->addIngressos(salas);
					}
					catch(int num){
						delete(v);
						v = NULL;
					}
				break;
			case 2:
				delete(v);
				v = NULL;
				break;
			case 3:
				if(v == NULL){
					std::cout << "Nenhum ingresso adicionado, a compra ser� cancelada.";
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



