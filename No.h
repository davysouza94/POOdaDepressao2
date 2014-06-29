#include <iostream>
#include "Sala.h"

#ifndef NO_H
#define NO_H

template <class Tinfo>
class No{

private:


public:
	No<Tinfo> *prox;
	Tinfo elem;

	No();
	No(Tinfo e);
	int getInfo();
	void setProx(No *p);
	No *getProx();
	void exibe();
};


template <class Tinfo>
No<Tinfo>::No(Tinfo e){
	elem = e;
	prox = NULL;
}

template <class Tinfo>
int No<Tinfo>::getInfo(){
	return elem;
}

template <class Tinfo>
void No<Tinfo>::setProx(No *p){
	prox = p;
}

template <class Tinfo>
No<Tinfo> * No<Tinfo>::getProx()
{
	return prox;
}

template <class Tinfo>
void No<Tinfo>::exibe(){
	std::cout << elem << std::endl;
}

#endif
