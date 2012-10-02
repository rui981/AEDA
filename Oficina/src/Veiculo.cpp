/*
 * Veiculo.cpp
 *
 *  Created on: Sep 27, 2012
 *      Author: ster
 */

#include "Veiculo.h"

Veiculo::Veiculo()
{
  ID = 0;
  marca = "";
  modelo = "";
  matricula = "";
}

Veiculo::Veiculo(int id, string mc, string mdl, string mt)
{
  ID = id;
  marca = mc;
  modelo = mdl;
  matricula = mt;
}

/*
ostream & Veiculo::operator<<(ostream & o, const Veiculo & v)
{
  o < v.ID;
  return o;
}*/

Carro::Carro(int id, string mc, string mdl, string mt, string tp):Veiculo(id,mc,mdl,mt)
{
  tipo = tp;
}

Camiao::Camiao(int id, string mc, string mdl, string mt, string cat):Veiculo(id,mc,mdl,mt)
{
  categoria = cat;
}

Bicicleta::Bicicleta(int id, string mc, string mdl, string mt):Veiculo(id,mc,mdl,mt)
{}

//Veiculo class methods implementation
int Veiculo::getID() const
{
  return ID;
}

string Veiculo::getMarca() const
{
  return marca;
}

string Veiculo::getModelo() const
{
  return modelo;
}

string Veiculo::getMatricula() const
{
  return matricula;
}

void Veiculo::setID(int id)
{
  ID=id;
}

void Veiculo::setMarca(string mc) 
{
  marca=mc;
}

void Veiculo::setModelo(string md) 
{
  modelo=md;
}

void Veiculo::setMatricula(string mt)
{
  matricula=mt;
}

//Carro class methods implementation
string Carro::getTipo() const
{
  return tipo;
}

void Carro::setTipo(string tp)
{
  tipo = tp;
}

//Camiao class methods implementation
string Camiao::getCategoria() const
{
  return categoria;
}

void Camiao::setCategoria(string cat)
{
  categoria = cat;
}

Veiculo::~Veiculo()
{}

Carro::~Carro()
{}

Camiao::~Camiao()
{}

Bicicleta::~Bicicleta()
{}

