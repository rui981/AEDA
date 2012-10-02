/*
 * Veiculo.h
 *
 *  Created on: Sep 27, 2012
 *      Author: ster
 */

#ifndef Veiculo_H_
#define Veiculo_H_
#include <string>
#include <vector>

using namespace std;

/*
 *
 */
class Veiculo
{
private:
  int ID;
  string marca;
  string modelo;
  string matricula;
public:
  Veiculo();
  Veiculo(int id, string mc, string mdl, string mt);
  int getID() const;
  string getMarca() const;
  string getModelo() const;
  string getMatricula() const;
  void setID(int id);
  void setMarca (string mc);
  void setModelo (string mdl);
  void setMatricula (string mt);
 // friend ostream & operator<<(ostream & o, const Veiculo & d);

  virtual
  ~Veiculo();
};

/*
 *
 */
class Carro: public Veiculo
{
private:
  string tipo;
public:
  Carro();
  Carro(int id, string mc, string mdl, string mt, string tp);
  string getTipo() const;
  void setTipo(string tp);
  virtual
  ~Carro();
};


/*
 *
 */
class Camiao: public Veiculo
{
private:
  string categoria;
public:
  Camiao();
  Camiao(int id, string mc, string mdl, string mt, string cat);
  string getCategoria() const;
  void setCategoria(string cat);
  virtual
  ~Camiao();
};


/*
 *
 */
class Bicicleta: public Veiculo
{
public:
  Bicicleta();
  Bicicleta(int id, string mc, string mdl, string mt);
  virtual
  ~Bicicleta();
};


#endif /* Veiculo_H_ */
