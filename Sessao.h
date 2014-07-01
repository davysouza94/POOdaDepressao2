#ifndef SESSAO_H
#define SESSAO_H

//Includes necessarios
#include "Fileira.h"
#include "Lista.h"
#include <string>

/* CLASSE SESSAO */
class Sessao{
private:
//Atributos
	int numvendido;			//igressos vendidos
	int lugaresVagos;		//lugares vagos
	string horarioFilme;	//armazena horarios do filme (Inicio e termino)
	string filme;			//armazena nome do filme
	int idSala;				//identificador da Sala
	int idSessao;			//identificador da Sessao
	Lista <Fileira> fileiras;  //Lista de objetos do tipo fileiras


public:
//Metodos

	//Construtores
	Sessao();
	Sessao(int idsala, string horario, string nomeFilme, int qtFileira, int numAssento);

	//Metodos Gerais
	void setStatus(int encerrado);
	int getStatus();
	int getHorario();
	void setHorario(int hor, int min);
	int getDisponivel();
	int setDisponivel(int qt, int opc);
	void setId(int id);
	void setNumVendido(int numVendido);
	string getFilme();
	void setFilme(string nomeFilme);

	void saveObject(ofstream &arquivo);	//salva objeto no arquivo
	void loadObject(ifstream &arquivo); //carrega objeto do arquivo

	//Operadores sobrecarregados
	friend ostream& operator<<(ostream& os, const Sessao& elem);
	bool operator==(const int num);
	bool operator!=(const int num);
};

//Construtor Padrao, inicializa com 'zero' os atributos de sessao
Sessao::Sessao(){
	idSala = 0;
	numvendido = 0;
	lugaresVagos = 1;
	idSessao = 0;
}


Sessao::Sessao(int idsala, string horario, string nomeFilme, int qtFileira, int numAssento){
	horarioFilme = horario;
	idSala = idsala;
	numvendido = 0;
	lugaresVagos = 1;
	filme = nomeFilme;
	idSessao = 0;

	Fileira *f, fIn;
	int i;
	for(i=0;i<qtFileira;i++){
		f = new Fileira(numAssento, 65+i);
		fIn = *f;

		delete(f);
		fileiras.insereFim(fIn);

	}
	getDisponivel();
}

void Sessao::setStatus(int encerrado){
	int capacidade;
	capacidade = 0;
	if(capacidade - numvendido == 0){
		encerrado = 0;
	}
	else
		encerrado = 1;
}
int Sessao::getStatus(){
	return lugaresVagos;
}

int Sessao::getDisponivel(){
	No<Fileira> *aux;
	lugaresVagos=0;
	aux = fileiras.getPl();
	while(aux!=NULL){
		lugaresVagos += aux->elem.getAssentosLivres();
		aux = aux->prox;
	}
	return lugaresVagos;
}

void Sessao::setId(int id){
	idSessao = id;
}
int Sessao::setDisponivel(int qt, int opc){
	if(opc == 0){
		No<Fileira> *aux;
		No<Assento> *assentoVago;
		int i;
		aux = fileiras.getPl();
		while(aux!=NULL){
			if(aux->elem.disponiveis < qt)
				aux = aux->prox;
			else break;
		}
		if(aux == NULL){ //retorna 0 se nao encontrou lugares adjacentes
			getDisponivel(); //atualiza disponibilidade
			return 0;
		}

		assentoVago = aux->elem.assentos.busca(1); //retorna endereço do nó do assento disponivel
		for(i=0;i<=qt;i++){
			if(assentoVago == NULL){//nao deve ocorrer
				cout << "erro!" << endl;
				return -1;
			}
			assentoVago->elem.setLivre(0);
			assentoVago = assentoVago->prox;
		}
		getDisponivel();
		return 1; //retorna 1 se for possivel ocupar o assento
	}else if(opc == 1){
		No<Fileira> *aux;
		No<Assento> *assentoVago;
		int i;

		aux = fileiras.getPl();
		for(i=0;i<qt && aux!=NULL;){
			while(aux!=NULL){
				if(aux->elem.disponiveis == 0)
					aux = aux->prox;
				else break;
			}
			if(aux == NULL){ //nao deve acontecer
				cout << "erro";
				return -1;
			}
			assentoVago = aux->elem.assentos.busca(1); //retorna endereço do nó do assento disponivel
			while(assentoVago!=NULL && i<qt){
				assentoVago->elem.setLivre(0);
				assentoVago = assentoVago->prox;
				i++;
			}
			getDisponivel();//atualiza disponibilidade
		}



	}
	return 1;
}
void Sessao::setNumVendido(int numVendido){
	numvendido = numVendido;
}

string Sessao::getFilme(){
	return filme;
}

void Sessao::setFilme(string nomeFilme){
	filme = nomeFilme;
}

bool Sessao::operator==(const int num){
  if(num == idSessao)
    return true;
  return false;
}

bool Sessao::operator!=(const int num){
  if(num != idSessao)
    return true;
  return false;
}

//Sobrecarga do operador << para impressao de todos os dados necessarios da sessao
ostream& operator<<(ostream& os, const Sessao& elem){
	os << "ID da sala: " << elem.idSala << std::endl << "ID da sessao: " << elem.idSessao << std::endl;
	os << "Filme: " << elem.filme << std::endl;
	os << "Horario: " << elem.horarioFilme << std::endl;
	os << "Disponibilidade: " << elem.lugaresVagos << std::endl;
    return os;
}

void Sessao::saveObject(ofstream &arquivo){
	fileiras.saveData(arquivo);
	arquivo << numvendido << "\n";
	arquivo << lugaresVagos << "\n";
	arquivo << horarioFilme << "\n";
	arquivo << filme << "\n";
	arquivo << idSala << "\n";
	arquivo << idSessao << "\n";

}
void Sessao::loadObject(ifstream &arquivo){
	fileiras.loadData(arquivo);
	arquivo >> numvendido;
	arquivo >> lugaresVagos;
	arquivo.ignore();
	getline(arquivo, horarioFilme);
	getline(arquivo, filme);
	arquivo >> idSala;
	arquivo >> idSessao;
}


#endif
