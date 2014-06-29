#include <iostream>
#include "gerenciarSala.h"
#include "venderIngresso.h"

using namespace std;
void gerenciaSala(gerenciarSala &salas);
void gerenciaSessao(gerenciarSala &salas);
void gerenciaVenda(venderIngresso &vendas);

int main() {
	gerenciarSala salas;
	venderIngresso vendas;

	int opcao = 1;

	while (opcao != 0) {
		cout << "Escolha uma das opcoes: " << endl;
		cout << "0 - Finalizar Programa" << endl;
		cout << "1 - Gerenciar Salas" << endl;
		cout << "2 - Gerenciar Sessoes" << endl;
		cout << "3 - Gerenciar Vendas" << endl;
		cout << "4 - " << endl;
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
			gerenciaVenda(vendas);
			break;
		case 4:
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
			cout << "1 - Inserir Sessão" << endl;
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

void gerenciaVenda(venderIngresso &vendas){
	vendas.gerencia();
}



