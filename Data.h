#ifndef DATA_H
#define DATA_H

#include<string>

class Data{
private:
//horario
	int horaInic[2];
	int horaFim[2];
//data
	int dtInic[3];
	int dtFim[3];

//venda
	string dtVenda;

public:
	string getHoraInic();
	void setHoraInic(int h, int min);

	string getHoraFim();
	void setHoraFim(int h, int min);

	int* getDtInic();
	void setDtInic(int dia, int mes, int ano);

	int* getDtFim();
	void setDtFim(int dia, int mes, int ano);

	string getDtVenda();
	void setDtVenda(string data);
};

string Data::getHoraInic(){
	string inicio;
	inicio = horaInic[0] + ':' + horaInic[1];
	return inicio;
}

void Data::setHoraInic(int h, int min){
	horaInic[0] = h;
	horaInic[1] = min;
}

string Data::getHoraFim(){
	string fim;
	fim = horaFim[0] + ':' + horaFim[1];
	return fim;
}
void Data::setHoraFim(int h, int min){
	horaFim[0] = h;
	horaFim[1] = min;
}

int* Data::getDtInic(){
	return dtInic;
}
void Data::setDtInic(int dia, int mes, int ano){
	dtInic[0] = dia;
	dtInic[1] = mes;
	dtInic[2] = ano;
}

int* Data::getDtFim(){
	return dtFim;
}
void Data::setDtFim(int dia, int mes, int ano){
	dtFim[0] = dia;
	dtFim[1] = mes;
	dtFim[2] = ano;
}

string Data::getDtVenda(){
	return dtVenda;
}
void Data::setDtVenda(string data){
	dtVenda = data;
}

#endif