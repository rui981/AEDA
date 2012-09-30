#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <vector>
#include "Pessoa.h"

using namespace std;



class Cliente : public Pessoa {

	private:
	int id;
	vector <Veiculo*> veiculos;

	public:

	Cliente(string nome, double contacto, string morada, int id, vector <Veiculo*> veiculos);
	~Cliente();

	int get_id() const;
	void set_id(int id);

	vector<Veiculo*> get_veiculos() const;
	void set_veiculos (vector <Veiculo*> Veiculos);
	void imprime();



};



#endif
