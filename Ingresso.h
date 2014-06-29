#ifndef INGRESSO_H
#define INGRESSO_H

#include <iostream>

#include "Sessao.h"
#include "Tipo.h"
#include "Data.h"

class Ingresso{
private:
	double valor;
	Data dtIngresso;

	Sessao sessao;
	Tipo tipo;

public:
	Ingresso(Tipo tipo);
	double getValor();
	void setDtIngresso(Data data);
	void setValor(double v);
};

Ingresso::Ingresso(Tipo tip){
	tipo = tip;
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
