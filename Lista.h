#include <iostream>
#include "No.h"
using namespace std;

#ifndef LISTA_H_
#define LISTA_H_

template <class Tinfo>
class Lista{

public:
	Lista();
	virtual ~Lista();

	bool listaVazia();
	void insereInicio(Tinfo elem);
	void insereFim(Tinfo elem);
	bool removeInicio();
	bool removeFim();
	bool deletaValor(int elem);
	void libera();
	void exibe();
	void ordena();
	No<Tinfo>* busca(int chave);
	No<Tinfo>* getPl();
private:
	No<Tinfo> *pl;
};


template <class TInfo>
Lista<TInfo>::Lista(){
	pl = NULL;
}

template <class Tinfo>
Lista<Tinfo>::~Lista(){
	//libera();
}
template <class Tinfo>
bool Lista<Tinfo>::listaVazia(){
	if(pl == NULL){
		return 1;
	}
	return 0;
}

template <class Tinfo>
void Lista<Tinfo>::insereInicio(Tinfo info){
	No<Tinfo> *aux, *novo;
	aux = pl;
	try{
		novo = new No<Tinfo>(info);
	}catch(std::bad_alloc& bad) {
		std::cout << "Memória insuficiente" << std::endl;
	}
	pl = novo;
	pl->prox = aux;
}
template <class Tinfo>
void Lista<Tinfo>::insereFim(Tinfo info){
	No<Tinfo> *novo, *aux;

	try{
		novo = new No<Tinfo>(info);
	}catch(std::bad_alloc& bad) {
		std::cout << "Memória insuficiente" << std::endl;
	}

	if(listaVazia()){
		insereInicio(info);
		return;
	}

	aux = pl;
	while(aux->prox!=NULL){
		aux = aux->prox;
	}
	aux->prox = novo;
	novo->prox = NULL;
}

template <class Tinfo>
bool Lista<Tinfo>::removeInicio(){
	No<Tinfo> *aux;

	if(!listaVazia()){
		aux = pl;
		pl = pl->prox;
		delete(aux);
		return 1;
	}

	return 0;
}

template <class Tinfo>
bool Lista<Tinfo>::removeFim(){
	No<Tinfo> *auxIt;

	//caso lista vazia
	if(listaVazia()){
		return 0;
	}

	//caso existir 1 elemento
	if(pl->prox == NULL){
		delete (pl->prox);
		pl->prox = NULL;
		pl = NULL;
		return 1;
	}

	//caso mais de um elemento
	auxIt = pl;
	while(auxIt->prox->prox != NULL){
		auxIt = auxIt->prox;
	}

	delete(auxIt->prox);
	auxIt->prox = NULL;
	return 1;
}

template <class Tinfo>
bool Lista<Tinfo>::deletaValor(int info){
	No<Tinfo> *auxIt, *auxDel;

	//caso lista vazia
	if(listaVazia())
		return 0;

	if(pl->elem == info){
		auxDel = pl;
		pl = pl->prox;
		delete (auxDel);
		return 1;
	}

	auxIt = pl;
	while(auxIt->prox->prox!=NULL && auxIt->prox->elem!=info)
		auxIt = auxIt->prox;

	if(auxIt->prox!=NULL  && auxIt->prox->elem == info){
		auxDel = auxIt->prox;
		auxIt->prox = auxIt->prox->prox;
		delete(auxDel);
	}
	return 0;
}

template <class Tinfo>
void Lista<Tinfo>::libera(){
	while(pl!=NULL){
		removeInicio();
	}
}

template <class Tinfo>
void Lista<Tinfo>::exibe(){
	No<Tinfo> *aux;
	aux = pl;
	while(aux!=NULL){
		aux->exibe();
		aux=aux->prox;
	}
}

template <class Tinfo>
No<Tinfo>* Lista<Tinfo>::busca(int chave){
	No<Tinfo> *aux;
	if(listaVazia())
		return 0;
	aux = pl;
	while(aux!=NULL){
		if(aux->elem == chave)
			return aux;
		aux = aux->prox;
	}
	return NULL;
}



template <class Tinfo>
void Lista<Tinfo>::ordena(){
	No<Tinfo> *aux1, *aux2;
	Tinfo swap;

	aux1 = pl;
	while(aux1!=NULL){
		aux2 = aux1;
		while(aux2 != NULL){
			if(aux1->elem > aux2->elem){
				swap = aux1->elem;
				aux1->elem = aux2->elem;
				aux2->elem = swap;
			}
			aux2 = aux2->prox;
		}
		aux1 = aux1->prox;
	}

}

template <class Tinfo>
No<Tinfo>* Lista<Tinfo>::getPl(){
	return pl;
}




#endif
