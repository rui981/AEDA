/*
 * main.cpp
 *
 *  Created on: Oct 28, 2012
 *      Author: ster
 */


#include "Veiculo.h"
#include "Carro.h"
#include "Camiao.h"
#include "Bus.h"
#include "Frota.h"

using namespace std;

int main(){
//Parte Paulo
  Veiculo * c1 = new Veiculo("A", "hhyf", "Radaddas");
  Veiculo * c2 = new Veiculo("Jk", "hhyf", "Radaddas");
  Veiculo * c3 = new Veiculo("Jk", "hhyf", "Radaddas");
  Frota * fleet = new Frota();

  fleet->adicionaVeiculo(c1);
  fleet->adicionaVeiculo(c2);
  fleet->adicionaVeiculo(c3);

  fleet->lerVeiculos();
  fleet->escVeicFicheiro();

//Parte Jo

	Funcionario *p1 = new Funcionario("joao", 122, "av cenas", "cenas", 2345, 3);

	Cliente *c1 =new Cliente("nome", 55415, "morada");
	Cliente *c2 =new Cliente("PILA", 55415, "mLAorada");

	Empresa *emp = new Empresa();
	emp->novoFuncionario(p1);

	emp->escreveFuncionarios();

  //delete (fleet);
}
