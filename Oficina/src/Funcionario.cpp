#include "Funcionario.h"

using namespace std;

Funcionario::Funcionario(string nome, double contacto, string morada, int id,
			string tipo, double salario, int horas_extra, vector <Veiculo*> veiculos):
					Pessoa(nome, contacto, morada){
	this->id=id;
	 this->tipo=tipo;
	 this->salario=salario;
	 this->horas_extra=horas_extra;
	 this->veiculos=veiculos;
}
	Funcionario::~Funcionario(){

	}

	int Funcionario::get_id() const{
		return id;
	}

	void Funcionario::set_id(int id){
		this->id=id;
	}

	string Funcionario::get_tipo() const{
		return tipo;
	}

	void Funcionario::set_tipo(string tipo){
		this->tipo=tipo;
	}

	double Funcionario::get_salario() const{
		return salario;
	}


	void Funcionario::set_salario(double salario){
		this->salario=salario;
	}

	int Funcionario::get_horas_extra() const{
		return horas_extra;
	}


	void Funcionario::set_horas_extra(int horas_extra){
		this->horas_extra=horas_extra;
	}

	vector <Veiculo*> Funcionario::get_veiculos() const{
		return veiculos;
	}

	void Funcionario::set_veiculos(vector <Veiculo*> veiculos){
		this->veiculos=veiculos;
	}


	void Funcionario::imprime(){
		cout << "Nome: " << nome << endl;
		cout << "Contacto: " << contacto << endl;
		cout << "Morada: " << morada << endl;
		cout << "Id: " << id << endl;
		cout << "Tipo: " << tipo << endl;
		cout << "Salario: " << salario << endl;
		cout << "Numero horas extra: " << horas_extra << endl;
		cout << "Veiculos: " ;

		for(unsigned int i=0; i<veiculos.size(); i++){
			cout << veiculos[i] << endl;
		}
}




