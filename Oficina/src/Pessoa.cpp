#include "Pessoa.h"

Pessoa::Pessoa (string nome, double contacto, string morada){
	this->nome=nome;
	this->contacto=contacto;
	this->morada=morada;
}

Pessoa::~Pessoa(){

}




string Pessoa::get_nome() const {
	return nome;
}

void Pessoa::set_nome(string nome){
	this->nome=nome;
}


double Pessoa::get_contacto() const{
	return contacto;
}

void Pessoa::set_contacto(double contacto){
	this->contacto=contacto;
}

string Pessoa::get_morada() const{
	return morada;
}

void Pessoa::set_morada(string morada){
	this->morada=morada;
}

