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

//Excepções Ficheiros
class FailLerClientes {};
class FailEscreverClientes {};
class FicheiroVazio {};
class FileClose {};
//Excepções menu Funcionario
class FuncionarioOFB {};
class fNomeOFB: public FuncionarioOFB{};
class fContactoOFB: public FuncionarioOFB{};
class fMoradaOFB: public FuncionarioOFB{};
class fTipoOFB: public FuncionarioOFB{};
class fSalarioOFB: public FuncionarioOFB{};
class FuncionarioInvalido: public FuncionarioOFB{};
//Excepções menu Cliente
class ClienteOFB {};
class cNomeOFB: public ClienteOFB {};
class cMoradaOFB: public ClienteOFB {};
class cContactoOFB: public ClienteOFB {};
class ClienteInvalido: public ClienteOFB {};
//Excepções menu Serviços
class ServicosExc{};
class DataIniExc: public ServicosExc {};
class DataFimExc: public ServicosExc {};
class NomServExc: public ServicosExc {};
class DescServExc: public ServicosExc {};
class PrecoServExc: public ServicosExc {};
class DuracaoServExc: public ServicosExc {};
//Excepções Opcões
class OpcoesExc {};
class OFBOpcoes: public OpcoesExc {}; //Opcao out of bounds

#endif /* EXCEPTION_H_ */
