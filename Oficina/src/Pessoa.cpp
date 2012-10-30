#include "Pessoa.h"

int Pessoa::I =1;

Pessoa::Pessoa (string nome, double contacto, string morada){
	this->nome=nome;
	this->contacto=contacto;
	this->morada=morada;
	id=I;
	I++;
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

int Pessoa::getId() const{
	return id;
}


/*
string Pessoa::imprime(const Pessoa & peeps){
	stringstream ss;
	ss << nome<< endl;
	ss << contacto << endl;
	ss << morada <<endl;
	return ss;
}*/



