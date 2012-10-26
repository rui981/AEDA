#include "Pessoa.h"

Pessoa::Pessoa (string nome, double contacto, string morada){
	this->nome=nome;
	this->contacto=contacto;
	this->morada=morada;
}

Pessoa::~Pessoa(){

}

string Pessoa::getNome() const {
	return nome;
}

void Pessoa::setNome(string nome){
	this->nome=nome;
}


double Pessoa::getContacto() const{
	return contacto;
}

void Pessoa::setContacto(double contacto){
	this->contacto=contacto;
}

string Pessoa::getMorada() const{
	return morada;
}

void Pessoa::setMorada(string morada){
	this->morada=morada;
}

/*
string Pessoa::imprime(const Pessoa & peeps){
	stringstream ss;
	ss << nome<< endl;
	ss << contacto << endl;
	ss << morada <<endl;
	return ss;
}*/


