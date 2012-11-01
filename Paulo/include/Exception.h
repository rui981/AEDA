/*
 * Exception.h
 *
 *  Created on: Oct 28, 2012
 *      Author: ster
 */

#ifndef EXCEPTION_H_
#define EXCEPTION_H_

#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

class IdInvalido {};
class FailLerClientes {};
class FailEscreverClientes {};
class FicheiroVazio {};
class FileClose {};
class FuncionarioOBF {};
class NomeOFB: public FuncionarioOBF{};
class ContactoOFB: public FuncionarioOBF{};
class MoradaOFB: public FuncionarioOBF{};
class TipoOFB: public FuncionarioOBF{};
class SalarioOFB: public FuncionarioOBF{};

#endif /* EXCEPTION_H_ */
