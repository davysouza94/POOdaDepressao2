#ifndef _VENDER_ING_H
#define _VENDER_ING_H


using namespace std;

#include "Venda.h"
#include "Lista.h"

class venderIngresso {
private:
	Lista <Venda> vendas;

public:
	void gerencia();
};

void venderIngresso::gerencia(){
	Venda v;
	int opcao = -1;
	char a = 'S';

	while(opcao != 0){
		cout << "Escolha uma das opcoes: " << endl;
		cout << "0 - Voltar" << endl;
		cout << "1 - Adicionar Ingresso" << endl;
		cout << "2 - Remover Ingresso" << endl;
		cout << "3 - Emitir Ingresso" << endl;
		cin >> opcao;

		switch (opcao) {
			case 0:
				return;
			case 1:
				v.addIngressos();
				break;
			case 2:
				v.removerIngressos();
				break;
			case 3:
				v.emitirIngressos();
				vendas.insereFim(v);
				return;
				break;
			default:
				break;
		}
	}
}

#endif