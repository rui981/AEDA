#include "Empresa.h"
#include <fstream>
#include <stdlib.h>





Empresa::Empresa(){
	leClientes();
	leFuncionarios();
	distribui();
}

Empresa::~Empresa(){

}



void Empresa::escreveClientes(){
	fstream ficheiro;
	ficheiro.open("Clientes.txt", ios::out);

	if(ficheiro.is_open()){
		for(unsigned int i=0; i<clientes.size(); i++){
			ficheiro << clientes[i]->getId() << endl;
			ficheiro << clientes[i]->getNome() << endl;
			ficheiro << clientes[i]->getContacto()<< endl;
			ficheiro << clientes[i]->getMorada();
			if(i!=clientes.size()-1){
				ficheiro << endl;
			}
		}
	}
	ficheiro.close();
}


void Empresa::escreveFuncionarios(){
	fstream ficheiro;
	ficheiro.open("Funcionarios.txt", ios::out);

	if(ficheiro.is_open()){
		for(unsigned int i=0; i<funcionarios.size(); i++){
			ficheiro << funcionarios[i]->getId() << endl;
			ficheiro << funcionarios[i]->getNome() << endl;
			ficheiro << funcionarios[i]->getContacto()<< endl;
			ficheiro << funcionarios[i]->getMorada() << endl;
			ficheiro << funcionarios[i]->getTipo() << endl;
			ficheiro << funcionarios[i]->getSalario() << endl;
			ficheiro << funcionarios[i]->getHorasExtra();
			if(i!=funcionarios.size()-1){
				ficheiro << endl;
			}
		}
	}
	ficheiro.close();
}





void Empresa::novoCliente(Cliente * c){
	clientes.push_back(c);

}


void Empresa::novoFuncionario(Funcionario * f){
	funcionarios.push_back(f);
}

void Empresa::leClientes(){
	fstream ficheiro;
	int id;
	string nome, morada, ide, contactoe;
	double contacto;

	ficheiro.open("Clientes.txt", ios::in);

	if(ficheiro.is_open()){
		while(!ficheiro.eof()){
			getline(ficheiro,ide);
			getline(ficheiro, nome);
			getline(ficheiro, contactoe);
			getline(ficheiro, morada);
			id=atoi(ide.c_str());
			contacto=atof(contactoe.c_str());
			Cliente * ce= new Cliente(id, nome, contacto, morada);
			clientes.push_back(ce);

		}
	}


}


void Empresa::leFuncionarios(){

		fstream ficheiro;
		int id, horasExtra;
		string nome, morada, ide, contactoe, tipo, salarioe, horasExtrae;
		double contacto,salario;

		ficheiro.open("Funcionarios.txt", ios::in);

		if(ficheiro.is_open()){
			while(!ficheiro.eof()){
				getline(ficheiro,ide);
				getline(ficheiro, nome);
				getline(ficheiro, contactoe);
				getline(ficheiro, morada);
				getline(ficheiro, tipo);
				getline(ficheiro, salarioe);
				getline(ficheiro, horasExtrae);

				id=atoi(ide.c_str());
				contacto=atof(contactoe.c_str());
				salario=atof(salarioe.c_str());
				horasExtra=atoi(horasExtrae.c_str());

				Funcionario * ce= new Funcionario(id, nome, contacto, morada, tipo, salario, horasExtra);
				funcionarios.push_back(ce);

			}
		}

}


void Empresa::distribui(){
	for(unsigned int i =0; i<clientes.size(); i++){
		pessoas.push_back(clientes[i]);
	}
	for (unsigned int i=0;i< funcionarios.size();i++){
		pessoas.push_back(funcionarios[i]);
	}
}



