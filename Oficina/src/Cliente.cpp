#include "Cliente.h"
#include <sstream>
#include <iostream>
#include <string>
using namespace std;


Cliente::Cliente(int id,string nome, double contacto, string morada)
		:Pessoa(nome, contacto, morada)
{
	this->id=id;

}

Cliente::Cliente(string nome, double contacto, string morada):Pessoa(nome, contacto, morada){


}



Cliente::~Cliente(){

}

int Cliente::getId() const {
	return id; }

void Cliente::setId(int id){
	this->id=id;
}

vector<Veiculo*> Cliente::getVeiculos() const {
	return veiculos;
}

void Cliente::setVeiculos(vector <Veiculo*> veiculos){
	this->veiculos=veiculos;
}




ostream& operator<< (ostream &out,const Cliente &clie){
	out << "Nome: " << clie.nome << endl;
	out << "Contacto: " << clie.contacto << endl;
	out << "Morada: " << clie.morada << endl;

	out << "Id: " << clie.getId() << endl;
	out << "Veiculos: "<< endl;
	for(unsigned int i=0; i<clie.getVeiculos().size(); i++){
		out << clie.getVeiculos()[i] << endl;
	}

return out;}


string Cliente::imprime(const Cliente & clie){
	stringstream ss;
		string retorno;

		ss << clie.nome<< endl;
		ss << clie.contacto << endl;
		ss << clie.morada <<endl;

		ss << clie.id<< endl;

		for(unsigned int i=0; i<clie.veiculos.size(); i++){
				ss <<i << ": " << clie.veiculos[i] << endl;
			}

	retorno = ss.str();
	return retorno;
}




