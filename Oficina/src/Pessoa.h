#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>

using namespace std;


class Veiculo {

};

class Pessoa {
protected:
	string nome;
	double contacto;
	string morada;
public:
	Pessoa(string nome, double contacto, string morada);
	virtual ~Pessoa();
	virtual void imprime();

	string get_nome() const;
	void set_nome( string nome);

	double get_contacto() const;
	void set_contacto( double contacto);

	string get_morada() const;
	void set_morada(string morada);

};









#endif
