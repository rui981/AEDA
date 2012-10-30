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

  Veiculo * c1 = new Veiculo("A", "hhyf", "Radaddas");
  Veiculo * c2 = new Veiculo("Jk", "hhyf", "Radaddas");
  Veiculo * c3 = new Veiculo("Jk", "hhyf", "Radaddas");
  Frota * fleet = new Frota();

  fleet->adicionaVeiculo(c1);
  fleet->adicionaVeiculo(c2);
  fleet->adicionaVeiculo(c3);

  fleet->lerVeiculos();
  fleet->escVeicFicheiro();

  //delete (fleet);
}
