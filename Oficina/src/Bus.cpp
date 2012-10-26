/*
 * Bus.cpp
 *
 *  Created on: Oct 25, 2012
 *      Author: ster
 */

#include "Bus.h"

Bus::Bus()
{}

Bus::Bus(int id, string mc, string mdl, string mt):Veiculo(id,mc,mdl,mt)
{}

Bus::~Bus()
{}

ostream & operator<<(ostream & o, const Bus & b){
      o << "!**************************Bus:***********************************!" << endl;
      o << "ID: " << b.getID() << endl;
      o << "Marca: " << b.getMarca() << endl;
      o << "Modelo: " << b.getModelo() << endl;
      o << "Matricula: " << b.getMatricula() << endl;

      return o;
}
