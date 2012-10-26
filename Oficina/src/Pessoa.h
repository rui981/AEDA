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
//	virtual string imprime(const Pessoa & peeps);
	virtual bool sabe(){
		return false;
	}


	string getNome() const;
	void setNome( string nome);

	double getContacto() const;
	void setContacto( double contacto);
	string getMorada() const;
	void setMorada(string morada);
	friend ostream& operator<< (ostream &out, const Pessoa &Pess);


};









#endif
