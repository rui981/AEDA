/*
 * Carro.cpp
 *
 *  Created on: Oct 25, 2012
 *      Author: ster
 */

#include "Carro.h"

Carro::Carro()
{}

Carro::Carro(int id, string mc, string mdl, string mt, string tp):Veiculo(id,mc,mdl,mt)
{
  tipo = tp;
}

Carro::~Carro()
{}

string Carro::getTipo() const
{
  return tipo;
}

void Carro::setTipo(string tp)
{
  tipo = tp;
}

ostream & operator<<(ostream & o, const Carro & c){
      o << "!**************************Carro:***********************************!" << endl;
      o << "ID: " << c.getID() << endl;
      o << "Marca: " << c.getMarca() << endl;
      o << "Modelo: " << c.getModelo() << endl;
      o << "Matricula: " << c.getMatricula() << endl;
      o << "Tipo: " << c.getTipo() << endl;

      return o;
}

