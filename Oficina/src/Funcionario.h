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
	int horas_extra;
	vector <Veiculo*> veiculos;

public:
	Funcionario(string nome, double contacto, string morada, int id,
			string tipo, double salario, int horas_extra, vector <Veiculo*> veiculos );
	~Funcionario();

	int get_id() const;
	void set_id(int id);

	string get_tipo() const;
	void set_tipo(string tipo);

	double get_salario() const;
	void set_salario(double salario);

	int get_horas_extra() const;
	void set_horas_extra(int horas_extra);

	vector <Veiculo*> get_veiculos() const;
	void set_veiculos(vector <Veiculo*> veiculos);

	void imprime();
};



#endif
