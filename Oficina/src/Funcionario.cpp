#include "Funcionario.h"
#include <sstream>

using namespace std;

Funcionario::Funcionario(int id,string nome, double contacto, string morada,
		string tipo, double salario, int horasExtra):
							Pessoa(nome, contacto, morada){
	this->id=id;
	this->tipo=tipo;
	this->salario=salario;
	this->horasExtra=horasExtra;

}

Funcionario::Funcionario(string nome, double contacto, string morada, string tipo, double salario, int horasExtra):
	Pessoa(nome, contacto, morada){
	this->tipo=tipo;
		this->salario=salario;
		this->horasExtra=horasExtra;


}


Funcionario::~Funcionario(){

}

int Funcionario::getId() const{
	return id;
}

void Funcionario::setId(int id){
	this->id=id;
}

string Funcionario::getTipo() const{
	return tipo;
}

void Funcionario::setTipo(string tipo){
	this->tipo=tipo;
}

double Funcionario::getSalario() const{
	return salario;
}


void Funcionario::setSalario(double salario){
	this->salario=salario;
}

int Funcionario::getHorasExtra() const{
	return horasExtra;
}


void Funcionario::setHorasExtra(int horasExtra){
	this->horasExtra=horasExtra;
}

vector <Veiculo*> Funcionario::getVeiculos() const{
	return veiculos;
}

void Funcionario::setVeiculos(vector <Veiculo*> veiculos){
	this->veiculos=veiculos;
}



string Funcionario::imprime(const Funcionario & func){
	stringstream ss;
	string retorno;

	ss << func.nome<< endl;
	ss << func.contacto << endl;
	ss << func.morada <<endl;

	ss << func.tipo << endl;
	ss << func.salario << endl;
	ss << func.horasExtra << endl;

	for(unsigned int i=0; i<func.veiculos.size(); i++){
			ss <<i << ": " << func.veiculos[i] << endl;
		}

retorno = ss.str();
return retorno;
}


ostream& operator<< (ostream &out, const Funcionario &func){


	out << "Nome: " << func.nome << endl;
	out << "Contacto: " << func.contacto << endl;
	out << "Morada: " << func.morada << endl;

	out << "Id: " << func.getId() << endl;
	out << "Tipo: " << func.getTipo() << endl;
	out << "Salario: " << func.getSalario() << endl;
	out << "Numero horas extra: " << func.getHorasExtra() << endl;
	out << "Veiculos: " ;

	for(unsigned int i=0; i<func.getVeiculos().size(); i++){
		out <<i << ": " << func.getVeiculos()[i] << endl;
	}

	return out;}


