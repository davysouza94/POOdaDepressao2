#ifndef INGRESSO_H
#define INGRESSO_H

#include <iostream>

#include "Sessao.h"
#include "Assento.h"
#include "Tipo.h"
#include "Data.h"

class Ingresso{
private:
	double valor;
	Data dtIngresso;

	Sessao sessao;
	Tipo tipo;
	Assento assento;

public:
	Ingresso(Tipo tipo);
	Ingresso::Ingresso(Tipo tipo, Assento a);
	double getValor();
	void setDtIngresso(Data data);
	void setValor(double v);
};

Ingresso::Ingresso(Tipo tipo, Assento a){
	assento = a;
	if(tipo == 0)
		valor = 3.00;
	else
		valor = 1.50;
}

Ingresso::Ingresso(Tipo tipo){
	if(tipo == 0)
		valor = 3.00;
	else
		valor = 1.50;
}

double Ingresso::getValor(){
	return valor;
}

void Ingresso::setDtIngresso(Data data){
	dtIngresso = data;
}

void Ingresso::setValor(double v){
	valor = v;
}

#endif