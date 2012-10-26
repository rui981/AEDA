/*
 * Veiculo.cpp
 *
 *  Created on: Sep 27, 2012
 *      Author: ster
 */

#include "Veiculo.h"
#include <fstream>

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

//Operador cout de veiculo
ostream & operator<<(ostream & o, const Veiculo & v){

  o << "!**************************Veiculo:***********************************!" << endl;
  o << "ID: " << v.getID() << endl;
  o << "Marca: " << v.getMarca() << endl;
  o << "Modelo: " << v.getModelo() << endl;
  o << "Matricula: " << v.getMatricula() << endl;

  return o;
}

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

Veiculo::~Veiculo()
{}


void Veiculo::escVeicFicheiro(Veiculo * v){

  int ID = v->getID();
  string marca = v->getMarca();
  string modelo = v->getModelo();
  string matricula = v->getMatricula();

  ofstream filestr;

  filestr.open("Veiculos.txt", ofstream::in | ofstream::app);

  if(filestr.is_open())
    {
      cout << "Abriu o ficheiro de veiculos" << endl;

      filestr << "ID: " << ID << endl;
      filestr << "Marca: " << marca << endl;
      filestr << "Modelo: " << modelo << endl;
      filestr << "Matricula: " << matricula << endl;

      filestr.close();
    }
  else
    cout << "Nao abre" << endl;
}


