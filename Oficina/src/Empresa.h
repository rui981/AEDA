#ifndef EMPRESA_H
#define EMPRESA_H

#include "Pessoa.h"
#include "Cliente.h"
#include "Funcionario.h"
#include <iostream>
#include <vector>
using namespace std;



class Empresa{
private:
	vector<Pessoa*> pessoas;
	vector <Cliente*> clientes;
	vector <Funcionario*> funcionarios;

public:
	Empresa();
	~Empresa();
	void novoFuncionario(Funcionario* func);
	void novoCliente(Cliente* c);
	bool removeFuncionario(Funcionario* func);
	bool removeCliente(Cliente* clie);


	void escreveClientes();
	void escreveFuncionarios();
	void leClientes();
	void leFuncionarios();

	void distribui();


};



#endif
