/*
 * Frota.cpp
 *
 *  Created on: Oct 25, 2012
 *      Author: ster
 */

#include "Frota.h"

Frota::Frota()
{
  frota.clear();
}

Frota::~Frota()
{}

void Frota::adicionaVeiculo(Veiculo * v){

  frota.push_back(v);
}

void Frota::removeVeiculo(Veiculo * v){

  vector<Veiculo*>::iterator it;

  for(it = frota.begin(); it != frota.end(); it++){
      if((*it)->getID() == v->getID()){
          it = frota.erase(it);
      }
  }
}

int Frota::numVeiculos(){

  return frota.size();
}


