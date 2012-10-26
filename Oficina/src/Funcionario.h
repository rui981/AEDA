#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <iostream>
#include "Pessoa.h"
#include <vector>


using namespace std;

class Funcionario : public Pessoa {
private:
	int id;
	string tipo;
	double salario;
	int horasExtra;
	vector <Veiculo*> veiculos;

public:
	Funcionario(string nome, double contacto, string morada, int id,
			string tipo, double salario, int horasExtra, vector <Veiculo*> veiculos );
	~Funcionario();

	int getId() const;
	void setId(int id);

	string getTipo() const;
	void setTipo(string tipo);

	double getSalario() const;
	void setSalario(double salario);

	int getHorasExtra() const;
	void setHorasExtra(int horasExtra);

	vector <Veiculo*> getVeiculos() const;
	void setVeiculos(vector <Veiculo*> veiculos);
	friend ostream& operator<< (ostream &out,const Funcionario &func);
	string imprime(const Funcionario & func);

	bool sabe(){
		return false;
	}

};





#endif
