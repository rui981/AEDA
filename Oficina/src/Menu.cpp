/*
 * Menu.cpp
 *
 *  Created on: Oct 25, 2012
 *      Author: ster
 */

#include "Menu.h"

int Menu::menu(){

  cout << "|......................GESTAO DE FROTA...........................|" << endl << endl;
  cout << "Seleccione uma opcão:" << endl;
  cout << "1: Listar Veiculos" << endl;
  cout << "2: Adicionar Veiculo" << endl;
  cout << "3: Remover Veiculo" << endl;

  int opcao = 0;
  cin >> opcao;

  switch(opcao){

  case 1: {
    cout << "1" << endl;
  }break;

  case 2: {
     cout << "2" << endl;
   }break;

  case 3: {
     cout << "3" << endl;
   }break;

  default: {
    cout << "Opção invalida" << endl;
  }break;

  }

  cout << "|......................CLOSING...........................|" << endl;
  return 0;
}

