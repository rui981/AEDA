#include "Cliente.h"
#include <iostream>
#include <string>
using namespace std;

Cliente::Cliente(string nome, double contacto, string morada, int id, vector <Veiculo*> veiculos)
		:Pessoa(nome, contacto, morada)
{
	this->id=id;
	this->veiculos=veiculos;
}

Cliente::~Cliente(){

}

int Cliente::get_id() const {
	return id; }

void Cliente::set_id(int id){
	this->id=id;
}

vector<Veiculo*> Cliente::get_veiculos() const {
	return veiculos;
}

void Cliente::set_veiculos(vector <Veiculo*> veiculos){
	this->veiculos=veiculos;
}

void Cliente::imprime(){
	cout << "Nome: " << nome << endl;
	cout << "Contacto: " << contacto << endl;
	cout << "Morada: " << morada << endl;
	cout << "Id: " << id << endl;
	cout << "Veiculos: ";
	for(unsigned int i=0;i<veiculos.size();i++){
		 cout << veiculos[i] << endl;
	}

}



