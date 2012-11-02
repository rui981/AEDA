#include "Empresa.h"
#include "Exception.h"
#include <fstream>
#include <stdlib.h>



Empresa::Empresa() {
	try{
		leClientes();
	}
	catch (FailLerClientes) {
		cout << "Leitura de clientes falhou" << endl; 
	}
	catch (FicheiroVazio){
		cout << "Nada para ler no ficheiro :(" << endl; 
	}
	
	leFuncionarios();

	leStandards();

	leBuses();
	leCamioes();
	leCarros();

	distribuiPessoas();
	distribuiVeiculos();

}

Empresa::~Empresa() {

}

///////////////////////Funcoes usadas em todos os menus ////////////////////
void Empresa::clear() {
	for (unsigned int i = 0; i < 40; i++) {
		cout << endl;
	}
}

void Empresa::pause() {
	cout << "prima qualquer tecla para continuar" << endl;
	cin.ignore(1000, '\n');
	cin.get();
}

////////////////////////////////////////////////////////////////////////

/////////////////////Acrescenta e remove objectos aos vectores respectivos ///////////////////

void Empresa::novoCliente(Cliente * c) {
	clientes.push_back(c);
}

void Empresa::novoFuncionario(Funcionario * f) {
	funcionarios.push_back(f);
}

void Empresa::removeFuncionario(int i) {
	funcionarios.erase(funcionarios.begin() + i);
}

void Empresa::removeCliente(int indice) {
	clientes.erase(clientes.begin() + indice);
}

void Empresa::novoCarro(Carro *c) {
	carros.push_back(c);
}

void Empresa::novoCamiao(Camiao *c) {
	camioes.push_back(c);
}

void Empresa::novoBus(Bus *b) {
	buses.push_back(b);
}

void Empresa::removeCarro(int indice) {
	carros.erase(carros.begin() + indice);
}

void Empresa::removeCamiao(int indice) {
	camioes.erase(camioes.begin() + indice);
}

void Empresa::removeBus(int indice) {
	buses.erase(buses.begin() + indice);
}

void Empresa::novoStandard(Standard *s) {
	standards.push_back(s);
}

void Empresa::removeStandard(int indice) {
	standards.erase(standards.begin() + indice);
}

//////////////////////////////////////////////////////////////////

////////////////////////////////// Passa os vectores filho para o vector pai respectivo

void Empresa::distribuiPessoas() {
	for (unsigned int i = 0; i < clientes.size(); i++) {
		pessoas.push_back(clientes[i]);
	}
	for (unsigned int i = 0; i < funcionarios.size(); i++) {
		pessoas.push_back(funcionarios[i]);
	}
}

void Empresa::distribuiVeiculos() {
	for (unsigned int i = 0; i < carros.size(); i++) {
		veiculos.push_back(carros[i]);
	}

	for (unsigned int i = 0; i < camioes.size(); i++) {
		veiculos.push_back(camioes[i]);
	}

	for (unsigned int i = 0; i < buses.size(); i++) {
		veiculos.push_back(buses[i]);
	}
}

/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////Escreve nos ficheiros respectivos////////

void Empresa::escreveClientes() {
	fstream ficheiro;
	ficheiro.open("Clientes.txt", fstream::out);

	if (ficheiro.is_open()) {
		for (unsigned int i = 0; i < clientes.size(); i++) {
			ficheiro << clientes[i]->getNome() << endl;
			ficheiro << clientes[i]->getContacto() << endl;
			ficheiro << clientes[i]->getMorada();
			if (i != clientes.size() - 1) {
				ficheiro << endl;
			}
		}
	}
	ficheiro.close();
}

void Empresa::escreveFuncionarios() {
	fstream ficheiro;
	ficheiro.open("Funcionarios.txt", fstream::out);

	if (ficheiro.is_open()) {
		for (unsigned int i = 0; i < funcionarios.size(); i++) {
			ficheiro << funcionarios[i]->getNome() << endl;
			ficheiro << funcionarios[i]->getContacto() << endl;
			ficheiro << funcionarios[i]->getMorada() << endl;
			ficheiro << funcionarios[i]->getTipo() << endl;
			ficheiro << funcionarios[i]->getSalario() << endl;
			ficheiro << funcionarios[i]->getHorasExtra() << endl;
			ficheiro << funcionarios[i]->getVeiculos().size();
			for (unsigned int j = 0; j < funcionarios[i]->getVeiculos().size();
					j++) {
				ficheiro << endl;
				ficheiro << funcionarios[i]->getVeiculos()[j]->getMarca()
						<< endl;
				ficheiro << funcionarios[i]->getVeiculos()[j]->getMatricula()
						<< endl;
				ficheiro << funcionarios[i]->getVeiculos()[j]->getModelo();
				if (j != funcionarios[i]->getVeiculos().size() - 1) {
					ficheiro << endl;
				}
			}
			if (i != funcionarios.size() - 1) {
				ficheiro << endl;
			}
		}
	}
	ficheiro.close();
}

void Empresa::escreveCarros() {
	fstream filestr;
	filestr.open("Carros.txt", fstream::out);

	if (filestr.is_open()) {
		for (unsigned int i = 0; i < carros.size(); i++) {
			filestr << carros[i]->getMarca() << endl;
			filestr << carros[i]->getModelo() << endl;
			filestr << carros[i]->getMatricula() << endl;
			filestr << carros[i]->getTipo() << endl;
			filestr << carros[i]->getStandards().size();

			for (unsigned int j = 0; j < carros[i]->getStandards().size();
					j++) {
				if(j==0) filestr << endl;
				filestr << carros[i]->getStandards()[j]->getNome() << endl;
				filestr << carros[i]->getStandards()[j]->getDescricao() << endl;
				filestr << carros[i]->getStandards()[j]->getPreco() << endl;
				filestr << carros[i]->getStandards()[j]->getDuracao() << endl;
				filestr << carros[i]->getStandards()[j]->getDataInicio()
						<< endl;
				filestr << carros[i]->getStandards()[j]->getDataFim();
				if (j != carros[i]->getStandards().size() - 1) {
					filestr << endl;
				}
			}

			if (i != carros.size() - 1) {
				filestr << endl;
			}

		}

	}
	filestr.close();
}

void Empresa::escreveBuses() {
	fstream filestr;
	filestr.open("Buses.txt", fstream::out);

	if (filestr.is_open()) {
		for (unsigned int i = 0; i < buses.size(); i++) {

				filestr << buses[i]->getMarca() << endl;
				filestr << buses[i]->getModelo() << endl;
				filestr << buses[i]->getMatricula()<< endl;
				filestr << buses[i]->getStandards().size();
				for (unsigned int j = 0; j < buses[i]->getStandards().size();
						j++) {
					if(j==0) filestr << endl;
					filestr << buses[i]->getStandards()[j]->getNome() << endl;
					filestr << buses[i]->getStandards()[j]->getDescricao()
							<< endl;
					filestr << buses[i]->getStandards()[j]->getPreco() << endl;
					filestr << buses[i]->getStandards()[j]->getDuracao()
							<< endl;
					filestr << buses[i]->getStandards()[j]->getDataInicio()
							<< endl;
					filestr << buses[i]->getStandards()[j]->getDataFim();

					if (j != buses[i]->getStandards().size() - 1) {
						filestr << endl;
					}

				}
				if (i != buses.size() - 1) {
					filestr << endl;
				}

		}

	}filestr.close();
}

void Empresa::escreveCamioes() {
	ofstream filestr;
	filestr.open("Camioes.txt");

	if (filestr.is_open()) {
		for (unsigned int i = 0; i < camioes.size(); i++) {
				filestr << camioes[i]->getMarca() << endl;
				filestr << camioes[i]->getModelo() << endl;
				filestr << camioes[i]->getMatricula() << endl;
				filestr << camioes[i]->getCategoria() << endl;
				filestr << camioes[i]->getStandards().size();
				for (unsigned int j = 0; j < camioes[i]->getStandards().size();
						j++) {
					if(j==0) filestr << endl;
					filestr << camioes[i]->getStandards()[j]->getNome() << endl;
					filestr << camioes[i]->getStandards()[j]->getDescricao()
							<< endl;
					filestr << camioes[i]->getStandards()[j]->getPreco()
							<< endl;
					filestr << camioes[i]->getStandards()[j]->getDuracao()
							<< endl;
					filestr << camioes[i]->getStandards()[j]->getDataInicio()
							<< endl;
					filestr << camioes[i]->getStandards()[j]->getDataFim();
					if (j != camioes[i]->getStandards().size() - 1) {
						filestr << endl;
					}

				}

				if (i != camioes.size() - 1) {
					filestr << endl;
				}

		}

	} filestr.close();
}

void Empresa::escreveStandards() {
	fstream ficheiro;
	ficheiro.open("Standards.txt", fstream::out);

	if (ficheiro.is_open()) {
		for (unsigned int i = 0; i < standards.size(); i++) {
			ficheiro << standards[i]->getNome() << endl;
			ficheiro << standards[i]->getDescricao() << endl;
			ficheiro << standards[i]->getDuracao() << endl;
			ficheiro << standards[i]->getPreco() << endl;
			ficheiro << standards[i]->getDataInicio() << endl;
			ficheiro << standards[i]->getDataFim();
			if (i != standards.size() - 1) {
				ficheiro << endl;
			}
		}
	}
	ficheiro.close();
}

//////////////////////////////////////////////////////////////////////////

////////////////////////////////Le ficheiros respectivos//////////////////////

void Empresa::leClientes() {
	fstream ficheiro;

	string nome, morada, contactoe;
	string contacto;

	ficheiro.open("Clientes.txt", ios::in);

	if (ficheiro.is_open()) {
		while (!ficheiro.eof()) {
			getline(ficheiro, nome);
			if (nome == " ") {
				//Se o ficheiro estiver vazio lança excepção
				FicheiroVazio fv;
				throw fv;
			}
			getline(ficheiro, contacto);
			getline(ficheiro, morada);

			Cliente * ce = new Cliente(nome, contacto, morada);
			clientes.push_back(ce);

		}
	}
	else {
			cout << "Ficheiro nao aberto, vou lancar excepcao\n";
			FailLerClientes fc;
			throw  fc;
		}
}

void Empresa::leFuncionarios() {
	vector<Veiculo*> vTemp;

	fstream ficheiro;
	int id, horasExtra, tmi;
	string nome, morada, contacto, tipo, salarioe, horasExtrae, temp, marca,
			modelo, matricula;
	double salario;

	ficheiro.open("Funcionarios.txt", fstream::in);

	if (ficheiro.is_open()) {
		while (!ficheiro.eof()) {

			getline(ficheiro, nome);
			if (nome == " ")
				return;
			getline(ficheiro, contacto);
			getline(ficheiro, morada);
			getline(ficheiro, tipo);
			getline(ficheiro, salarioe);
			getline(ficheiro, horasExtrae);
			getline(ficheiro, temp);
			tmi = atoi(temp.c_str());
			for (unsigned int i = 0; i < tmi; i++) {
				getline(ficheiro, marca);
				getline(ficheiro, modelo);
				getline(ficheiro, matricula);
				Veiculo *vec = new Veiculo(marca, modelo, matricula);
				vTemp.push_back(vec);
			}

			salario = atof(salarioe.c_str());
			horasExtra = atoi(horasExtrae.c_str());

			Funcionario * ce = new Funcionario(nome, contacto, morada, tipo,
					salario, horasExtra);
			ce->setVeiculos(vTemp);
			funcionarios.push_back(ce);

		}
	}

}

void Empresa::leCarros() {
	fstream file;
	string brand, model, lp, tip, nre, nome, descricao, precoe, duracaoe, datai,
			dataf;
	int nr;
	vector<Standard*> stand;

	double preco, duracao;
	file.open("Carros.txt");

	if (file.is_open()) {
		while (!file.eof()) {
			getline(file, brand);
			getline(file, model);
			getline(file, lp);
			getline(file, tip);
			getline(file, nre);
			nr = atoi(nre.c_str());
			for (unsigned int i = 0; i < nr; i++) {
				getline(file, nome);
				getline(file, descricao);
				getline(file, precoe);
				getline(file, duracaoe);
				getline(file, datai);
				getline(file, dataf);
				preco = atof(precoe.c_str());
				duracao = atof(duracaoe.c_str());
				Standard *s = new Standard(nome, descricao, preco, duracao,
						datai, dataf);
				stand.push_back(s);

			}

			Carro * v = new Carro(brand, model, lp, tip);
			v->setStandards(stand);
			novoCarro(v);
		}
	}

}

void Empresa::leBuses() {
	fstream file;
	string brand, model, lp, nre, nome, descricao, precoe, duracaoe, datai,
			dataf;
	double preco, duracao;
	int nr;
	vector<Standard*> stand;

	file.open("Buses.txt");

	if (file.is_open()) {
		while (!file.eof()) {
			getline(file, brand);
			getline(file, model);
			getline(file, lp);

			getline(file, nre);
			nr = atoi(nre.c_str());
			for (unsigned int i = 0; i < nr; i++) {
				getline(file, nome);
				getline(file, descricao);
				getline(file, precoe);
				getline(file, duracaoe);
				getline(file, datai);
				getline(file, dataf);
				preco = atof(precoe.c_str());
				duracao = atof(duracaoe.c_str());
				Standard *s = new Standard(nome, descricao, preco, duracao,
						datai, dataf);
				stand.push_back(s);

			}

			Bus * v = new Bus(brand, model, lp);
			v->setStandards(stand);
			novoBus(v);
		}
	}

}

void Empresa::leCamioes() {
	fstream file;
	string brand, model, lp, cat, nre, nome, descricao, precoe, duracaoe, datai,
			dataf;
	int nr;
	double preco, duracao;
	vector<Standard *> stand;
	file.open("Camioes.txt");

	if (file.is_open()) {
		while (!file.eof()) {
			getline(file, brand);
			getline(file, model);
			getline(file, lp);
			getline(file, cat);

			getline(file, nre);
			nr = atoi(nre.c_str());
			for (unsigned int i = 0; i < nr; i++) {
				getline(file, nome);
				getline(file, descricao);
				getline(file, precoe);
				getline(file, duracaoe);
				getline(file, datai);
				getline(file, dataf);
				preco = atof(precoe.c_str());
				duracao = atof(duracaoe.c_str());
				Standard *s = new Standard(nome, descricao, preco, duracao,
						datai, dataf);
				stand.push_back(s);

			}

			Camiao * v = new Camiao(brand, model, lp, cat);
			v->setStandards(stand);
			novoCamiao(v);

		}
	}
}

void Empresa::leStandards() {

	fstream file;
	string nome, descricao, duracaoe, precoe, dataI, dataF;
	double duracao, preco;
	file.open("Standards.txt");
	if (file.is_open()) {
		while (!file.eof()) {

			getline(file, nome);
			if (nome == " ")
				return;

			getline(file, descricao);
			getline(file, duracaoe);
			getline(file, precoe);
			getline(file, dataI);
			getline(file, dataF);

			duracao = atof(duracaoe.c_str());
			preco = atof(precoe.c_str());

			Standard * s = new Standard(nome, descricao, duracao, preco, dataI,
					dataF);
			novoStandard(s);
		}
	}

}

///////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////MENU geral////////////////////////////////////

void Empresa::menu() {
		int op;
	int opF, opC;
	string nomeCliente, moradaCliente, contactoCliente,ope;
	
	do {
		clear();
		cout << "Bemvindo a empresa Jopati" << endl << endl;
		cout << "Menu Funcionarios-------------1" << endl;
		cout << "Menu Cliente------------------2" << endl;
		cout << "Menu Veiculos-----------------3" << endl;
		cout << "Servicos----------------------4" << endl;
		cout << "Sair--------------------------0" << endl;
		cout << "Escolha a sua opcao" << endl;
		cout << "Opcao : ";
	
	
		try {		
			cin >> op;
				
			if(op < 0 || op > 4) {
					OFBOpcoes o;
					throw o;
			}			
		}
		
		catch (OpcoesExc){
			cout << "Opção Invalida" << endl;
			pause();
			clear();
			menu();
		}

		
		switch (op) {
		case 1: {

			clear();
			cout << "**************Menu Funcionarios***********************"
					<< endl << endl;
			cout << "Adicionar Funcionario----------------1" << endl;
			cout << "Remover Funcionario------------------2" << endl;
			cout << "Modificar Funcionario----------------3" << endl;
			cout << "Listar Funcionarios------------------4" << endl;
			cout << "Adicionar Veiculo a Funcionario------5" << endl;
			cout << "Remover Veiculo a Funcionario--------6" << endl;
			cout << "Sair---------------------------------0" << endl;
			try{	
				cin >> opF;
				
					if(opF < 0 || opF > 6) {
						OFBOpcoes ofb;
						throw ofb;
					}
				}
			catch (OpcoesExc) {
				cout << "Opçao invalida" << endl;
				pause();
				clear();
				menu();
			} 
								
			cin.ignore(1000, '\n');

			string nome, contacto, morada, tipo, salarioe;
			double salario;
			int horasExtra = 0;

			switch (opF) {
			case 1: {
				int confirmacao;
				do {
					clear();
				try {
					cout << "Insira nome de Funcionario" << endl;
					getline(cin, nome);
						if(nome.size() > 5){
						fNomeOFB nb;
						throw nb;
						}
									
					cout << "Insira contacto de Funcionario" << endl;
					getline(cin, contacto);
						if(contacto.size() > 5){
						fContactoOFB cb;
						throw cb;
						}
					
					cout << "Insira morada de Funcionario" << endl;
					getline(cin, morada);
					if(morada.size() > 5){
						fMoradaOFB mb;
						throw mb;
						}
					cout << "Insira tipo de Funcionario" << endl;
					getline(cin, tipo);
					if(tipo.size() > 5){
						fTipoOFB tb;
						throw tb;
						}
					cout << "Insira salario de Funcionario" << endl;
					getline(cin, salarioe);
					if(salarioe.size() > 5){
						fSalarioOFB sb;
						throw sb;
						}
				}
					catch (FuncionarioOFB) {
						cout << "String Overflow.... A relançar menu" << endl;
						pause();
						clear();
						menu();
					}
									
					salario = atof(salarioe.c_str());

					Funcionario * funcTemp = new Funcionario(nome, contacto,
							morada, tipo, salario, horasExtra);
					clear();
					funcTemp->imprime();

					cout << "Confirma os dados?" << endl;
					cout << "Sim----------------------1" << endl;
					cout << "Nao----------------------2" << endl;
					try {
						cin >> confirmacao;
						if(confirmacao < 1 || confirmacao > 2) {
							OFBOpcoes of;
							throw of;
						}
					}
					catch (OpcoesExc) {
						cout << "Opção Invalida" << endl;
						pause();
						clear();
						menu();
					}
						
					if (confirmacao == 1) {
						novoFuncionario(funcTemp);
					} else {
						cout << "Deseja inserir os dados de novo?" << endl;
						cout << "Nao-----------1" << endl;
						cout << "Sim-----------2" << endl;
						
						try {
						cin >> confirmacao;
						if(confirmacao < 1 || confirmacao > 2) {
							OFBOpcoes of;
							throw of;
							}
						}
						catch (OpcoesExc) {
							cout << "Opção Invalida" << endl;
							pause();
							clear();
							menu();
						}	
						cin.ignore(1000, '\n');
					}

				} while (confirmacao != 1);

			}
				break;
			case 2: {
				clear();
				int numeracao, conf;
				do {
					for (unsigned int i = 0; i < funcionarios.size(); i++) {
						cout << i + 1 << "   " << funcionarios[i]->getNome()
								<< endl;
					}
	//TODO excepcao remover
					cout << "Qual dos funcionarios deseja eliminar?" << endl;
					
					try {
						cin >> numeracao;
						if(numeracao < 1 || numeracao > funcionarios.size()) {
							FuncionarioInvalido iv;
							throw iv;
						}
					}
					catch (FuncionarioOFB){
							cout << "Funcionario que deseja remover não existe" << endl;
							pause();
							clear();
							menu();
						}

					clear();
					cout << *(funcionarios[numeracao - 1]) << endl;
					cout << "Tem a certeza que quer apagar este Funcionario?"
							<< endl;
					cout << "Sim --------------------------------------1"
							<< endl;
					cout << "Nao --------------------------------------2"
							<< endl;
					try {
						cin >> conf;
						if(conf < 1 || conf > 2){
							OFBOpcoes o;
							throw o;
						}
					}
					catch (OpcoesExc){
						cout << "Opcao Invalida" << endl;
						pause();
						clear();
						menu();
					}
						
					if (conf == 1) {
						removeFuncionario(numeracao - 1);
						cout << "Funcionario apagado do sistema" << endl;
						pause();
					} else {

						cout << "Deseja inserir os dados de novo?" << endl;
						cout << "Nao-----------1" << endl;
						cout << "Sim-----------2" << endl;
						
					try {
						cin >> conf;
						if(conf < 1 || conf > 2){
							OFBOpcoes o;
							throw o;
						}
					}
					catch (OpcoesExc){
							cout << "Opcao Invalida" << endl;
							pause();
							clear();
							menu();
						}

					}
				} while (conf != 1);
			}

				break;

			case 3: {
				modificaFunc();
			}
				break;

			case 4: {
				clear();
				int numeracao, conf;
				for (unsigned int i = 0; i < funcionarios.size(); i++) {
					cout << i + 1 << "   " << funcionarios[i]->getNome()
							<< endl;
				}
//TODO excepcao listar
				cout << "Qual dos funcionarios deseja examinar?" << endl;
			try {
				cin >> numeracao;
				
				if(numeracao > 1 || numeracao < funcionarios.size()) {
					FuncionarioInvalido iv;
					throw iv;
				}
			}
			catch (FuncionarioOFB) {
				cout << "Funcionario não existente" << endl;
				pause();
				clear();
				menu();
			}

				cout << *(funcionarios[numeracao - 1]) << endl;
				pause();
			}
				break;
			case 5: { //adiciona veiculos a um funcionario
				clear();
				adicionaVeiculoFuncionario();
				pause();
			}

			case 0: {
				opF = 0;
			}
				break;
			}

		}
			break;
		case 2: {
			clear();
			cout << "**************Menu Clientes***********************" << endl
					<< endl;
			cout << "Adicionar Cliente----------------1" << endl;
			cout << "Remover Cliente------------------2" << endl;
			cout << "Modificar Cliente----------------3" << endl;
			cout << "Listar Clientes------------------4" << endl;
			cout << "Sair---------------------------------0" << endl;
			
			try {
				cin >> opC;
				
				if(opC < 0 || opC > 4) {
					OFBOpcoes of;
					throw of;
				}
			}
			catch (OpcoesExc)  {
				cout << "Opção Invalida: " << endl;
				pause();
				clear();
				menu();
			}
				
			cin.ignore(1000, '\n');
		
			switch (opC) {
				
			case 1: {
				int confirmacao;
				do {
				 try{
					clear();
					cout << "insira nome do Cliente" << endl;
					getline(cin, nomeCliente);					
					if(nomeCliente.size() > 5) {
						cNomeOFB of;
						throw of;
					} 
					
					cout << "Insira morada do CLiente" << endl;
					getline(cin, moradaCliente);
					if(moradaCliente.size() > 5) {
						cMoradaOFB om;
						throw om;
					}
					
					cout << "Insira contacto cliente" << endl;
					getline(cin, contactoCliente);
					if(contactoCliente.size() > 5) {
						cContactoOFB oc;
						throw oc;
					}
				}
				catch (ClienteOFB) {
					cout << "String Overflow" << endl;
					pause();
					clear();
					menu(); 
				}
								
					Cliente * cliTemp = new Cliente(nomeCliente,
							contactoCliente, moradaCliente);
					clear();
					cout << *cliTemp << endl << endl;

					cout << "Confirma os dados?" << endl;
					cout << "Sim-----------1" << endl;
					cout << "Nao-----------2" << endl;
					
					try {
						cin >> confirmacao;
						if(confirmacao < 1 || confirmacao > 2) {
							OFBOpcoes o;
							throw o;
						}
					}
					catch(OpcoesExc) {
						cout << "Opçao Invalida" << endl;
					}
											
					cin.ignore(1000, '\n');

					if (confirmacao == 1) {
						novoCliente(cliTemp);
						cout << "Cliente adicionado" << endl;
						pause();
					} else {
						cout << "Deseja inserir os dados de novo?" << endl;
						cout << "Nao-----------1" << endl;
						cout << "Ŝim-----------2" << endl;
						
						try {
							cin >> confirmacao;
							if(confirmacao < 1 || confirmacao > 2) {
								OFBOpcoes o;
								throw o;
							}
						}
						catch(OpcoesExc) {
							cout << "Opçao Invalida" << endl;
						}

						pause();
					}
				} while (confirmacao != 1);

			}

				break;
			case 2: {

				clear();
				int numeracao, conf;
				do {
					for (unsigned int i = 0; i < clientes.size(); i++) {
						cout << i + 1 << "   " << clientes[i]->getNome()
								<< endl;
					}

					cout << "Qual dos clientes deseja eliminar?" << endl;
				try {
						cin >> numeracao;
						if(numeracao < 1 || numeracao > clientes.size()) {
							ClienteInvalido iv;
							throw iv;
						}
					}
				catch (ClienteOFB) {
					cout << "Tentou remover cliente não existente" << endl;
					pause();
					clear();
					menu();
				}
						
					cin.ignore(1000, '\n');

					clear();
					cout << *(clientes[numeracao - 1]) << endl;
					cout << "Tem a certeza que quer apagar este cliente?"
							<< endl;
					cout << "Sim --------------------------------------------1"
							<< endl;
					cout << "Nao --------------------------------------------2"
							<< endl;
					try {		
						cin >> conf;
						if(conf < 1 || conf > 2) {
							OFBOpcoes o;
							throw o;
						}
					}
					catch (OpcoesExc) {
						cout << "Opção Invalida" << endl;
						pause();
						clear();
						menu();
					} 
						
					cin.ignore(1000, '\n');

					if (conf == 1) {
						removeCliente(numeracao - 1);
						cout << "Cliente apagado do sistema" << endl;
						pause();
					} else {
						cout << "Deseja inserir os dados de novo?" << endl;
						cout << "Nao-----------1" << endl;
						cout << "Sim-----------2" << endl;
						
						try {		
							cin >> conf;
							if(conf < 1 || conf > 2) {
							OFBOpcoes o;
							throw o;
							}
						}
						catch (OpcoesExc) {
							cout << "Opção Invalida" << endl;
							pause();
							clear();
							menu();
						} 

						pause();
					}
				} while (conf != 1);
			}
				break;

			case 3: {
				modificaCli();
			}
				break;

			case 4: {
				clear();
				int opcao;
				for (unsigned int i = 0; i < clientes.size(); i++) {
					cout << i + 1 << "  " << clientes[i]->getNome() << endl;
				}
				cout << "Qual o cliente que deseja analisar?" << endl;
				
				try {
					cin >> opcao;
					
					if(opcao < 1 || opcao > clientes.size()) {
						ClienteInvalido inv;
						throw inv;
					}
				}
				catch (ClienteOFB){
						cout << "Cliente Invalido" << endl;
						pause();
						clear();
						menu();
					}
				cin.ignore(1000, '\n');

				cout << *(clientes[opcao - 1]) << endl;
				pause();
			}
				break;
			}
		}
			break;

		case 3: { //Menu Veiculos
			menuVeiculos();
		}
			break;
		case 4: {		//Menu Servicos
			clear();
			int opS;
			string datai, dataf, nome, descricao, precoe, duracaoe;
			double preco, duracao;
			cout << "**************Menu Servicos***********************" << endl
					<< endl;
			cout << "Adicionar Servico Standard----------------1" << endl;
			cout << "Remover Servico Standard------------------2" << endl;
			cout << "Modificar Servico Standard----------------3" << endl;
			cout << "Listar Servicos Standard------------------4" << endl;
			cout << "Adicionar Servico a veiculo---------------5" << endl;
			cout << "Retirar Servico a veiculo-----------------6" << endl;
			cout << "Sair---------------------------------0" << endl;
			
			try {
				cin >> opS;
				if(opS < 0 || opS > 6) {
					OFBOpcoes o;
					throw o;
				}
			}
			catch (OpcoesExc) {
				cout << "Opção invalida" << endl;
				pause();
				clear();
				menu();
			}
				
			cin.ignore(1000, '\n');
			clear();

			switch (opS) {
			case 1: {		// Adicionar Servico Standard
				int conf;
				do {
					
				try {	
					cout << "Insira data de inicio (XX-XX-XX)" << endl;
					getline(cin, datai);				
					if(datai.size() > 5) {
						DataIniExc di;
						throw di;
					}
					
					cout << "Insira data de fim (XX-XX-XX)" << endl;
					getline(cin, dataf);
					if(dataf.size() > 5) {
						DataFimExc df;
						throw df;
					}
					
					cout << "Insira nome do servico" << endl;
					getline(cin, nome);
					if(nome.size() > 5) {
						NomServExc ns;
						throw ns;	
					}
					
					cout << "Insira descricao do servico" << endl;
					getline(cin, descricao);
					if(descricao.size() > 5) {
						DescServExc dc;
						throw dc;	
					}
					
					cout << "Insira preco por hora do servico" << endl;
					getline(cin, precoe);
					if(precoe.size() > 5) {
						PrecoServExc ps;
						throw ps;
					}
					
					cout << "Insira duracao do servico" << endl;
					getline(cin, duracaoe);
					if(duracaoe.size() > 5) {
						DuracaoServExc ds;
						throw ds;
					}
				}
				catch (ServicosExc) {
						cout << "String Overflow" << endl;
						pause();
						clear();
						menu();
					}
					
					preco = atof(precoe.c_str());
					duracao = atof(duracaoe.c_str());
					Standard *s = new Standard(nome, descricao, preco, duracao,
							datai, dataf);
					cout << "Servico bem criado?" << endl;
					cout << "Sim----------------1" << endl;
					cout << "Nao----------------2" << endl;
					
					try {
						cin >> conf;
						if (conf < 1 || conf > 2) {
							OFBOpcoes o;
							throw o;
						}
					}
					catch (OpcoesExc) {
						cout << "Opção invalida" << endl;
						pause();
						clear();
						menu();
					}
						
					if (conf == 1) {
						novoStandard(s);
					} else {
						cout << "Deseja repetir os dados?" << endl;
						cout << "Nao----------------1" << endl;
						cout << "Sim----------------2" << endl;
						
						try {
							cin >> conf;
							if (conf < 1 || conf > 2) {
								OFBOpcoes o;
								throw o;
								}
							}
						catch (OpcoesExc) {
							cout << "Opção invalida" << endl;
							pause();
							clear();
							menu();
						}
							
						cin.ignore(1000, '\n');
					}
				} while (conf != 1);

			}
				break;
			case 2: { //Remover servicos standard
				int serv;
				int conf;
				do {
					for (unsigned int i = 0; i < standards.size(); i++) {
						cout << i + 1 << "  " << standards[i]->getNome()
								<< endl;
					}

					cout << "Qual o servico que deseja remover?" << endl;
					try {
						cin >> serv;
						if(serv < 1 || serv > standards.size()) {
							ServInvalido si;
							throw si;
						}
					}
					catch (ServicosExc) {
						cout << "Tentou remover serviço inexistente" << endl;
						pause();
						clear();
						menu();
					}
					
					
					cin.ignore(1000, '\n');
					cout << "Tem a certeza que quer remover o Servico "
							<< standards[serv - 1]->getNome() << endl;
					cout << "Sim----------------1" << endl;
					cout << "Nao----------------2" << endl;
					
					try {
						cin >> conf;
						if(conf < 1 || conf > 2) {
							OFBOpcoes o;
							throw o;
						}
					}
					catch (OpcoesExc) {
						cout << "Opção Invalida" << endl;
						pause();
						clear();				
						menu();
					}
					
					if (conf == 1) {
						removeStandard(serv - 1);

					} else {
						cout << "Deseja eliminar outro servico?" << endl;
						cout << "Nao----------------1" << endl;
						cout << "Sim----------------2" << endl;
						
						try {
							cin >> conf;
							if(conf < 1 || conf > 2) {
								OFBOpcoes o;
								throw o;
							}
						}
						catch (OpcoesExc) {
							cout << "Opção Invalida" << endl;
							pause();
							clear();				
							menu();
						}
					}
				} while (conf != 1);
			}
				break;

			case 3: { //Modifica servico standard
				modificaServ();

			}
				break;

			case 4: { //Lista servicos
				clear();
				int opcao;
				for (unsigned int i = 0; i < standards.size(); i++) {
					cout << i + 1 << "  " << standards[i]->getNome() << endl;
				}

				cout << "Qual o servico que deseja analisar?" << endl;
				
				try{
					cin >> opcao;
					if(opcao < 1 || opcao > standards.size()){
						ServInvalido si;
						throw si;
					}
				}
				catch (ServicosExc) {
					cout << "Serviço Inexistente" << endl;
					pause();
					clear();
					menu();
				}
				
				
				cin.ignore(1000, '\n');

				cout << *(standards[opcao - 1]) << endl;

			}
				break;

			case 5: { // adicionar servico ao veiculo
				clear();
				int opcao, opcao2, opcao3;
				cout << "A que veiculo deseja adicionar o servico?" << endl;
				for (unsigned int i = 0; i < veiculos.size(); i++) {
					cout << i + 1 << "  " << veiculos[i]->getMarca() << endl;
				}
				
				try {
					cin >> opcao;
					if(opcao < 1 || opcao > veiculos.size()){
						VeicInvalido vi;
						throw vi;
					}
				}
				catch (VeicExc){
					cout << "Veiculo Invalido" << endl;
					pause();
					clear();
					menu();
				}

				cout << "Deseja acrescentar um servico standart " << endl;
				cout << "Sim----------------1" << endl;
				cout << "Nao----------------2" << endl;
				
				try {
					cin >> opcao2;
					if(opcao2 < 1 || opcao2 > 2) {
						OFBOpcoes o;
						throw o;
					}
				}
				catch (OpcoesExc) {
					cout << "Opcao Invalida" << endl;
					pause();
					clear();
					menu();
				}
				
				cin.ignore(1000, '\n');

				if (opcao2 == 1) {
					cout << "Que servico deseja adicionar?" << endl;
					for (unsigned int i = 0; i < standards.size(); i++) {
						cout << i + 1 << "  " << standards[i]->getNome()
								<< endl;
					}
					
					try {
						cin >> opcao3;
						if(opcao3 < 1 || opcao3 > standards.size()) {
							ServInvalido si;
							throw si;
						}
					}
					catch (ServicosExc){
						cout << "Servico Invalido" << endl;
						pause();
						clear();
						menu();
					}
						
						
					veiculos[opcao - 1]->novoStandard(standards[opcao3 - 1]);
				} else if (opcao2 == 2) {
					int conf;
					do {
					  try {
						cout << "Insira data de inicio (XX-XX-XX)" << endl;
						getline(cin, datai);
						if(datai.size() > 5){
							DataIniExc di;
							throw di;
						}
						
						cout << "Insira data de fim (XX-XX-XX)" << endl;
						getline(cin, dataf);
						if(dataf.size() > 5){
							DataFimExc df;
							throw df;
						}
						
						cout << "Insira nome do servico" << endl;
						getline(cin, nome);
						if(nome.size() > 5){
							NomServExc ns;
							throw ns;
						}
						
						cout << "Insira descricao do servico" << endl;
						getline(cin, descricao);
						if(descricao.size() > 5) {
							DescServExc ds;
							throw ds;
						}
						
						cout << "Insira preco por hora do servico" << endl;
						getline(cin, precoe);
						if(precoe.size()) {
							PrecoServExc ps;
							throw ps;
						}
						
						cout << "Insira duracao do servico" << endl;
						getline(cin, duracaoe);
						if(duracaoe.size()) {
							DuracaoServExc ds;
							throw ds;
						}
					}					
					catch (ServicosExc){
							cout << "String overflow" << endl;
							pause();
							clear();
							menu();
						}
						
						
						preco = atof(precoe.c_str());
						duracao = atof(duracaoe.c_str());
						Standard *s = new Standard(nome, descricao, preco,
								duracao, datai, dataf);
						cout << "Servico bem criado?" << endl;
						cout << "Sim----------------1" << endl;
						cout << "Nao----------------2" << endl;
						
						try{
							cin >> conf;
							if(conf < 1 || conf > 2){
								OFBOpcoes o;
								throw o;
							}
						}
						catch (OpcoesExc){
							cout << "Opção Invalida" << endl;
							pause();
							clear();
							menu();
						}
						
						if (conf == 1) {
							veiculos[opcao - 1]->novoStandard(s);

						} else {
							cout << "Deseja repetir os dados?" << endl;
							cout << "Nao----------------1" << endl;
							cout << "Sim----------------2" << endl;
							
							try{
								cin >> conf;
								if(conf < 1 || conf > 2){
									OFBOpcoes o;
									throw o;
								}
							}
							catch (OpcoesExc){
								cout << "Opção Invalida" << endl;
								pause();
								clear();
								menu();
							}
							
							cin.ignore(1000, '\n');
						}
					} while (conf != 1);
				}
			}
				break;

			}
			pause();
		} //fim menu servicos
			break;
		case 0: {
			escreveStandards();
			escreveClientes();
			escreveFuncionarios();
			escreveBuses();
			escreveCamioes();
			escreveCarros();
			op = 0;
		}
			break;
		} //end 1st switch

	} while (op != 0);
}

void Empresa::modificaFunc() {
	int numeracao, conf;
	for (unsigned int i = 0; i < funcionarios.size(); i++) {
		cout << i + 1 << "   " << funcionarios[i]->getNome() << endl;
	}

	cout << "Qual o funcionario que deseja modificar" << endl;
	
	try {
		cin >> numeracao;
		if(numeracao < 1 || numeracao > funcionarios.size()){
			FuncionarioInvalido fi;
			throw fi;
		}
	}
	catch (FuncionarioOFB) {
		cout << "Funcionario não existente" << endl;
		pause();
		clear();
		menu();
	}
		
	cin.ignore(1000, '\n');

	clear();
	cout << *(funcionarios[numeracao - 1]) << endl;
	pause();
	cout << "o que deseja modificar ?" << endl;
	cout << "Nome---------------1" << endl;
	cout << "Contacto-----------2" << endl;
	cout << "Morada-------------3" << endl;
	cout << "Horas extra--------4" << endl;
	cout << "Salario------------5" << endl;
	cout << "Especializacao-----6" << endl;
	cout << "Alterar Veiculos---7" << endl;
	cout << "Sair---------------0" << endl;
	
	try {
		cin >> conf;
		if(conf < 0 || conf > 7){
			OFBOpcoes o;
			throw o;
		}
	}
	catch (OpcoesExc) {
		cout << "Opção Invalida" << endl;
		pause();
		clear();
		menu();
	}
	
	cin.ignore(1000, '\n');

	switch (conf) {
		
	case 1: {
	  try{
		clear();	
		string nome;
		cout << "Qual o novo nome?" << endl;
		getline(cin, nome);
			if(nome.size() > 5) {
				fNomeOFB n;
				throw n;
			}
			
		funcionarios[numeracao - 1]->setNome(nome);
		cout << "Nome alterado com sucesso" << endl;
		pause();
	}
		catch (FuncionarioOFB){
			cout << "String overflow" << endl;
			pause();
			clear();
			menu(); 
		}
			
		
	}
		break;

	case 2: {
	  try {
		clear();
		string contacto;
		cout << "Qual o novo contacto?" << endl;
		getline(cin, contacto);
		if(contacto.size() > 5) {
			fContactoOFB c;
			throw c;
		}
		funcionarios[numeracao - 1]->setContacto(contacto);
		cout << "Contacto alterado com sucesso" << endl;
		pause();
	}
		catch (FuncionarioOFB){
			cout << "String overflow" << endl;
			pause();
			menu();
			clear(); 
		}
	 	
		
	}
		break;
	case 3: {
	 try {
		clear();
		string morada;
		cout << "Qual a nova morada?" << endl;
		getline(cin, morada);
		if(morada.size() > 5) {
			fMoradaOFB m;
			throw m;
		}
		funcionarios[numeracao - 1]->setMorada(morada);
		cout << "Morada alterada com sucesso" << endl;
		pause();
	}
		catch (FuncionarioOFB){
			cout << "String overflow" << endl;
			pause();
			clear();
			menu(); 
		}
		
	}
		break;
	case 4: {
	  try {
		clear();
		string temp;
		int horasEx;
		cout << "Qual o numero das horas extra?" << endl;
		getline(cin, temp);
		if(temp.size() > 5) {
			fHorasExtraOFB h;
			throw h;
		}
		horasEx = atoi(temp.c_str());
		funcionarios[numeracao - 1]->setHorasExtra(horasEx);
		cout << "Horas extra alteradas com sucesso" << endl;
		pause();
	}
		catch (FuncionarioOFB){
			cout << "String overflow" << endl; 
			pause();
			menu();
			clear();
		}
			
	}
		break;
	case 5: {
	  try {
		clear();
		string temp;
		int salario;
		cout << "Qual o novo salario?" << endl;
		getline(cin, temp);
		if(temp.size()){
			fSalarioOFB s;
			throw s;
		}
		salario = atoi(temp.c_str());
		funcionarios[numeracao - 1]->setSalario(salario);
		cout << "Salario alterado com sucesso" << endl;
		pause();
	}
		catch (FuncionarioOFB){
			cout << "String overflow" << endl; 
			pause();
			menu();
			clear();
		}
		
	}
		break;
	case 6: {
	  try {
		clear();
		string especializacao;
		cout << "Qual a nova especializacao?" << endl;
		getline(cin, especializacao);
		if(especializacao.size() > 5){
			fEspecOFB esp;
			throw esp;
		}
		funcionarios[numeracao - 1]->setTipo(especializacao);
		cout << "Especializacao alterada com sucesso" << endl;
		pause();
	}
		catch (FuncionarioOFB){
			cout << "String overflow" << endl; 
			pause();
			menu();
			clear();
		}
	}
		break;
	//TODO A partir daqui :(	
	case 7: {
		clear();
		int opcao, nrvei;
		cout << "Adicionar veiculo--------1" << endl;
		cout << "Remover veiculo----------2" << endl;
		
		try {
			cin >> opcao;
			if (opcao < 1 || opcao > 2) {
				OFBOpcoes o;
				throw o;
			}
		}
		catch (OpcoesExc){
			cout << "Opção Invalida" << endl;
			pause();
			clear();
			menu();
		}
			
			
			cin.ignore(1000, '\n');

		if (opcao == 1) {
			clear();
			cout << "Veiculos disponiveis para adicionar" << endl;
			for (unsigned int i = 0; i < veiculos.size(); i++) {
				cout << i + 1 << "   " << veiculos[i]->getMarca() << endl;
			}
			cout << "Selecione veiculo para adicionar" << endl;
			
			try {
				cin >> nrvei;
				if(nrvei < 1 || nrvei > veiculos.size()) {
					VeicInvalido vi;
					throw vi;
				}
			}
			catch (VeicExc){
				cout << "Veiculo Inexistente" << endl;
				pause();
				clear();
				menu();
			}
			
			
			cin.ignore(1000, '\n');

			funcionarios[numeracao - 1]->adicionaVeiculo(veiculos[nrvei - 1]);
			cout << "Veiculo adicionado com sucesso" << endl;
			pause();

		} else {
			if (opcao == 2) {
				clear();
				cout << "Veiculos do funcionario para remover" << endl;
				for (unsigned int i = 0;
						i < funcionarios[numeracao - 1]->getVeiculos().size();
						i++) {
					cout << i + 1
							<< funcionarios[numeracao - 1]->getVeiculos()[i]->getMarca()
							<< endl;
				}
				cout << "Selecione veiculo para retirar" << endl;
				
				try {
					cin >> nrvei;
					if(nrvei < 1 || nrvei > veiculos.size()) {
					VeicInvalido vi;
					throw vi;
					}
				}
			catch (VeicExc){
				cout << "Veiculo Inexistente" << endl;
				pause();
				clear();
				menu();
			}
						
				cin.ignore(1000, '\n');

				funcionarios[numeracao - 1]->removeVeiculo(nrvei - 1);
				cout << "Veiculo removido com sucesso" << endl;
				pause();

			}

		}
	}
		break;

	case 0: {

	}
		break;

	}

}
//TODO FASE 2!!
void Empresa::modificaCli() {

	clear();
	int indice, temp;
	for (unsigned int i = 0; i < clientes.size(); i++) {
		cout << i + 1 << "  " << clientes[i]->getNome() << endl;
	}
	cout << "Qual o cliente que deseja modificar?" << endl;
	try {
		cin >> indice;
		if(indice < 1 || indice > clientes.size()){
			ClienteInvalido ci;
			throw ci;
		}
	}
	catch (ClienteOFB){
			cout << "Cliente Inexistente" << endl;
	}
		
	cin.ignore(1000, '\n');

	clear();
	cout << *(clientes[indice - 1]) << endl;
	pause();

	cout << "O que deseja modificar?" << endl;
	cout << "Nome ----------------1" << endl;
	cout << "Contacto ------------2" << endl;
	cout << "Morada---------------3" << endl;
	cout << "Sair-----------------0" << endl;
	
	try {
		cin >> temp;
		if(temp < 0 || temp > 3) {
			OFBOpcoes o;
			throw o;
		}
	}
	catch (OpcoesExc) {
		cout << "Opção invalida" << endl;
		pause();
		menu();
		clear();
	}
		
		
	cin.ignore(1000, '\n');

	switch (temp) {
	case 1: {
		clear();
		string nome;
		cout << "Qual o novo nome?" << endl;
		getline(cin, nome);
	try {
		if(nome.size() > 5){
			cNomeOFB cn;
			throw cn;
		}
	}
		catch(ClienteOFB) {
			cout << "String overflow" << endl;
			pause();
			menu();
			clear();
		}
		
		clientes[indice - 1]->setNome(nome);
		cout << "Nome alterado com sucesso" << endl;
		pause();
	}
		break;
	case 2: {
		clear();
		string contacto;
		cout << "Qual o novo contacto?" << endl;
		getline(cin, contacto);
	try {
		if(contacto.size() > 5){
			cContactoOFB ct;
			throw ct;
		}
	}
		catch(ClienteOFB) {
			cout << "String overflow" << endl;
			pause();
			menu();
			clear();
		}
		
		
		clientes[indice - 1]->setContacto(contacto);
		cout << "Contacto alterado com sucesso" << endl;
		pause();
	}
		break;
	case 3: {
		clear();
		string morada;
		cout << "Qual a nova morada?" << endl;
		getline(cin, morada);
	try {
		if(morada.size() > 5){
			cMoradaOFB md;
			throw md;
		}
	}
		catch(ClienteOFB) {
			cout << "String overflow" << endl;
			pause();
			menu();
			clear();
		}
		
		clientes[indice - 1]->setMorada(morada);
		cout << "Morada alterada com sucesso" << endl;
		pause();
	}
		break;
	case 0: {

	}
		break;

	}

}

void Empresa::menuVeiculos() {
	clear();
	int opcao;
	cout << "Seleccione uma opcão:" << endl;
	cout << "Adicionar Veiculo----------1" << endl;
	cout << "Remover Veiculo------------2" << endl;
	cout << "Modificar Veiculo----------3" << endl;
	cout << "Listar Veiculos------------4" << endl;
	cout << "Sair ----------------------0" << endl;
	
	try {
		cin >> opcao;
		if(opcao < 0 || opcao > 4){
			OFBOpcoes o;
			throw o;
		}
	}
	catch (OpcoesExc) {
		cout << "Opção Invalida" << endl;
		pause();
		clear();
		menu();
	}
		
	cin.ignore(1000, '\n');

	switch (opcao) {

	case 1: {
		clear();

		int i;
		string marca, modelo, matricula, tipo;
		cout << "Tipo de veiculo " << endl;
		cout << "Carro---------------1" << endl;
		cout << "Camiao--------------2" << endl;
		cout << "Bus-----------------3" << endl;
		cout << "Sair----------------0" << endl;
		
	try {
		cin >> i;
		if(i < 0 || i > 3){
			OFBOpcoes o;
			throw o;
		}
	}
	catch (OpcoesExc){
		cout << "Opção Invalida" << endl;
		pause();
		clear();
		menu();
	}
		
		cin.ignore(1000, '\n');

		switch (i) {
		case 1: {  //Carro
			clear();
			cout << "Insira marca" << endl;
			getline(cin, marca);
			try {
				if(marca.size() > 5) {
					CarMarcaExc cm;
					throw cm;
				}
			}
			catch(VeicExc) {
				cout << "String overflow" << endl;
				pause();
				clear();
				menu();
			}
			
			cout << "Insira modelo" << endl;
			getline(cin, modelo);
			try {
				if(modelo.size() > 5) {
					CarModeloExc cmd;
					throw cmd;
				}
			}
			catch(VeicExc) {
				cout << "String overflow" << endl;
				pause();
				clear();
				menu();
			}
			
			cout << "Insira Matricula (XX-XX-XX)" << endl;
			getline(cin, matricula);
			try {
				if(matricula.size() > 5) {
					CarMatrExc cmt;
					throw cmt;
				}
			}
			catch(VeicExc) {
				cout << "String overflow" << endl;
				pause();
				clear();
				menu();
			}
			
			
			cout << "Insira categoria" << endl;
			getline(cin, tipo);
			try {
				if(tipo.size() > 5) {
					CarCategoriaExc cg;
					throw cg;
				}
			}
			catch(VeicExc) {
				cout << "String overflow" << endl;
				pause();
				clear();
				menu();
			}
			

			Carro *c = new Carro(marca, modelo, matricula, tipo);
			veiculos.push_back(c);
			novoCarro(c);
			pause();

		}
			break;
		case 2: { //Camiao
			clear();
			cout << "Insira marca" << endl;
			getline(cin, marca);
			try {
				if(marca.size() > 5){
					CamiaoMarcaExc cm;
					throw cm;
				}
			}
			catch (VeicExc) {
				cout << "String overflow" << endl;
				pause();
				clear();
				menu();
			}
			
			cout << "Insira modelo" << endl;
			getline(cin, modelo);
			try {
				if(modelo.size() > 5){
					CamiaoModeloExc cmd;
					throw cmd;
				}
			}
			catch (VeicExc) {
				cout << "String overflow" << endl;
				pause();
				clear();
				menu();
			}
				
			cout << "Insira Matricula (XX-XX-XX)" << endl;
			getline(cin, matricula);
			try {
				if(matricula.size() > 5){
					CamiaoMatrExc cmt;
					throw cmt;
				}
			}
			catch (VeicExc) {
				cout << "String overflow" << endl;
				pause();
				clear();
				menu();
			}
			
			cout << "Insira categoria" << endl;
			getline(cin, tipo);
			try {
				if(tipo.size() > 5){
					CamiaoCategoriaExc cg;
					throw cg;
				}
			}
			catch (VeicExc) {
				cout << "String overflow" << endl;
				pause();
				clear();
				menu();
			}

			Camiao *c = new Camiao(marca, modelo, matricula, tipo);
			veiculos.push_back(c);
			novoCamiao(c);
			pause();

		}
			break;

		case 3: { //Bus

			clear();
			cout << "Insira marca" << endl;
			getline(cin, marca);
			try {
				if(marca.size() > 5) {
					BusMarcaExc bm;
					throw bm;
				}
			}
			catch (VeicExc) {
				cout << "String overflow" << endl;
				pause();
				clear();
				menu();
			}
			
			cout << "Insira modelo" << endl;
			getline(cin, modelo);
			try {
				if(modelo.size() > 5) {
					BusModeloExc bmd;
					throw bmd;
				}
			}
			catch (VeicExc) {
				cout << "String overflow" << endl;
				pause();
				clear();
				menu();
			}
			
			cout << "Insira Matricula (XX-XX-XX)" << endl;
			getline(cin, matricula);
			try {
				if(matricula.size() > 5) {
					BusMatrExc bmt;
					throw bmt;
				}
			}
			catch (VeicExc) {
				cout << "String overflow" << endl;
				pause();
				clear();
				menu();
			}
			
			Bus *b = new Bus(marca, modelo, matricula);
			veiculos.push_back(b);
			novoBus(b);
			pause();
		}
			break;

		}

	}
		break;
//TODO Tou aqui!
	case 2: {
		clear();
		int opcao, temp;
		cout << "Insira tipo que deseja remover" << endl;
		cout << "Carro-------------------1" << endl;
		cout << "Camiao------------------2" << endl;
		cout << "Bus---------------------3" << endl;
		cout << "Sair--------------------0" << endl;
		
		try{
			cin >> opcao;
			if(opcao < 0 || opcao > 3){
				OFBOpcoes o;
				throw o;
			}
		}
		catch (OpcoesExc) {
			cout << "Opção Invalida" << endl;
			pause();
			menu();
			clear();
		}
			
			
		cin.ignore(1000, '\n');

		switch (opcao) {
		case 1: {
			clear();
			for (unsigned int i = 0; i < carros.size(); i++) {
				cout << i + 1 << "   " << carros[i]->getMarca() << endl;
			}
			cout << "Selecione o carro que deseja eliminar" << endl;
			try{
				cin >> temp;
				if(temp < 1 || temp > carros.size()){
					CarInvalido ci;
					throw ci;
				}
			}
			catch (VeicExc){
				cout << "Carro inexistente" << endl;
				pause();
				menu();
				clear();
			}
				
				
			cin.ignore(1000, '\n');

			removeCarro(temp - 1);
			pause();
		}
			break;
		case 2: {
			clear();
			for (unsigned int i = 0; i < camioes.size(); i++) {
				cout << i + 1 << "   " << camioes[i]->getMarca() << endl;
			}
			cout << "Selecione o camiao que deseja eliminar" << endl;
					
			try{
				cin >> temp;
				if(temp < 1 || temp > camioes.size()){
					CamiaoInvalido ti;
					throw ti;
				}
			}
			catch (VeicExc){
				cout << "Camiao inexistente" << endl;
				pause();
				menu();
				clear();
			}
				
			cin.ignore(1000, '\n');

			removeCamiao(temp - 1);
			pause();
		}
			break;

		case 3: {
			clear();
			for (unsigned int i = 0; i < buses.size(); i++) {
				cout << i + 1 << "   " << buses[i]->getMarca() << endl;
			}
			cout << "Selecione o bus que deseja eliminar" << endl;
			
			try{
				cin >> temp;
				if(temp < 1 || temp > buses.size()){
					BusInvalido bi;
					throw bi;
				}
			}
			catch (VeicExc){
				cout << "Bus inexistente" << endl;
				pause();
				menu();
				clear();
			}
			
			cin.ignore(1000, '\n');

			removeBus(temp - 1);
			pause();
		}
			break;

		case 0: {

		}
			break;
		}
	}
		break;
	case 3: {
		modificaVeic();
	}
		break;
	case 4: { //listagem de veiculos
		clear();
		int op, car;
		cout << "O que deseja listar?" << endl;
		cout << "Carros----------------1" << endl;
		cout << "Camioes---------------2" << endl;
		cout << "Buses-----------------3" << endl;
		cout << "Todos-----------------4" << endl;
		cout << "Sair------------------0" << endl;
		
		try {
			cin >> op;
			if(op < 0 || op > 4){
				OFBOpcoes o;
				throw o;
			}
		}
		catch (OpcoesExc){
			cout << "Opção invalida" << endl;
		}
			
		cin.ignore(1000, '\n');

		switch (op) {
		case 1: { // listar carros
			clear();
			for (unsigned int i = 0; i < carros.size(); i++) {
				cout << i + 1 << "  " << carros[i]->getMarca() << endl;
			}
			cout << "Que carro deseja analizar?" << endl;
			try {
				cin >> car;
				if(car < 1 || car > carros.size()) {
					CarInvalido ci;
					throw ci;
				}
			}
			catch (VeicExc){
				cout << "Carro inexistente" << endl;
				pause();
				clear();
				menu();
			}
				
			cin.ignore(1000, '\n');

			cout << *(carros[car - 1]) << endl;
			listaVeiculosServicos(carros[car - 1]);
			pause();

		}
			break;
		case 2: { //listar camioes
			clear();
			for (unsigned int i = 0; i < camioes.size(); i++) {
				cout << i + 1 << "  " << camioes[i]->getMarca() << endl;
			}
			cout << "Que camiao deseja analizar?" << endl;
					
			try {
				cin >> car;
				if(car < 1 || car > camioes.size()) {
					CamiaoInvalido ti;
					throw ti;
				}
			}
			catch (VeicExc){
				cout << "Camião inexistente" << endl;
				pause();
				clear();
				menu();
			}
			
			cin.ignore(1000, '\n');
			cout << *(camioes[car - 1]) << endl;
			listaVeiculosServicos(camioes[car - 1]);
			pause();

		}
			break;
		case 3: { // listar buses
			clear();
			for (unsigned int i = 0; i < buses.size(); i++) {
				cout << i + 1 << "  " << buses[i]->getMarca() << endl;
			}
			cout << "Que bus deseja analizar?" << endl;
			
			try {
				cin >> car;
				if(car < 1 || car > buses.size()) {
					BusInvalido bi;
					throw bi;
				}
			}
			catch (VeicExc){
				cout << "Bus inexistente" << endl;
				pause();
				clear();
				menu();
			}
			
			cin.ignore(1000, '\n');
			cout << *(buses[car - 1]) << endl;
			listaVeiculosServicos(buses[car - 1]);
			pause();

		}
			break;

		case 4: { //listar todos
			clear();
			for (unsigned int i = 0; i < veiculos.size(); i++) {
				cout << i + 1 << "  " << veiculos[i]->getMarca() << endl;
			}
			cout << "Que veiculo deseja analizar?" << endl;
			
			try {
				cin >> car;
				if(car < 1 || car > veiculos.size()){
					VeicInvalido vi;
					throw vi;
				}
			}
			catch (VeicExc){
				cout << "Veiculo inexistente" << endl;
				pause();
				clear();
				menu();
			}
			
			
			cin.ignore(1000, '\n');
			cout << *(veiculos[car - 1]) << endl;
			pause();
		}
			break;
		case 0: {

		}
			break;

		}

	}
		break;

	}

}

//Case 3 do Menu Veiculos
void Empresa::modificaVeic() {
	clear();
	string marca, modelo, matricula, categoria;
	int indice;
	cout << "Que tipo de veiculo deseja alterar?" << endl;
	cout << "Carro-----------------------------1" << endl;
	cout << "Camiao----------------------------2" << endl;
	cout << "Bus-------------------------------3" << endl;
	cout << "Sair------------------------------0" << endl;
	
	try {
		cin >> indice;
		if(indice < 0 || indice > 3){
			OFBOpcoes o;
			throw o;
		}
	}
	catch (OpcoesExc) {
		cout << "Opção invalida" << endl;
		pause();
		clear();
		menu();
	}
				
	cin.ignore(1000, '\n');

	switch (indice) {
	case 1: {
		clear();
		int op, nCarro;
		for (unsigned int i = 0; i < carros.size(); i++) {
			cout << i + 1 << "   " << carros[i]->getMarca() << endl;
		}
		cout << "Insira carro que deseja alterar" << endl;
		try {
			cin >> nCarro;
			if(nCarro < 1 || nCarro > carros.size()) {
				CarInvalido ci;
				throw ci;
			}
		}
		catch (VeicExc) {
			cout << "Carro inexistente" << endl;
			pause();
			clear();
			menu();		
		}
			
		cin.ignore(1000, '\n');

		cout << "Que atributo deseja alterar?" << endl;
		cout << "Marca------------------------1" << endl;
		cout << "Modelo-----------------------2" << endl;
		cout << "Matricula--------------------3" << endl;
		cout << "Categoria--------------------4" << endl;
		cout << "Sair-------------------------0" << endl;
		
		try {
			cin >> op;
			if(op < 0 || op > 4){
				OFBOpcoes o;
				throw o;
			}
		}
		catch (OpcoesExc){
			cout << "Opção invalida" << endl;
			pause();
			clear();
			menu();
		}
		
		
		cin.ignore(1000, '\n');

		clear();

		switch (op) {
		case 1: {
			cout << "Insira nova marca" << endl;
			getline(cin, marca);
			try{
				if(marca.size() > 5) {
					CarMarcaExc cm;
					throw cm;
				}
			}
			catch (VeicExc) {
				cout << "String overflow" << endl;
				pause();
				clear();
				menu();
			}
			
			carros[nCarro - 1]->setMarca(marca);

		}
			break;
		case 2: {
			cout << "Insira novo modelo" << endl;
			getline(cin, modelo);
			try{
				if(modelo.size() > 5) {
					CarMarcaExc cmd;
					throw cmd;
				}
			}
			catch (VeicExc) {
				cout << "String overflow" << endl;
				pause();
				clear();
				menu();
			}
			
			carros[nCarro - 1]->setMarca(modelo);
		}
			break;
		case 3: {
			cout << "Insira nova matricula" << endl;
			getline(cin, matricula);
			try{
				if(matricula.size() > 5) {
					CarMatrExc cmt;
					throw cmt;
				}
			}
			catch (VeicExc) {
				cout << "String overflow" << endl;
				pause();
				clear();
				menu();
			}
			
			carros[nCarro - 1]->setMatricula(matricula);
		}
			break;
		case 4: {
			cout << "Insira nova categoria" << endl;
			getline(cin, categoria);
			try{
				if(categoria.size() > 5) {
					CarCategoriaExc cg;
					throw cg;
				}
			}
			catch (VeicExc) {
				cout << "String overflow" << endl;
				pause();
				clear();
				menu();
			}
			
			camioes[nCarro - 1]->setCategoria(categoria);
		}
			break;
		case 0: {

		}
			break;
		}
		pause();
	}
		break;
	case 2: { /*modificar camioes*/

		int op, nCarro;
		for (unsigned int i = 0; i < camioes.size(); i++) {
			cout << i + 1 << "   " << camioes[i]->getMarca() << endl;
		}
		cout << "Insira camiao que deseja alterar" << endl;
		
		try {
			cin >> nCarro;
			if(nCarro < 1 || nCarro > camioes.size()) {
				CamiaoInvalido ti;
				throw ti;
			}
		}
		catch (VeicExc) {
			cout << "Camiao inexistente" << endl;
			pause();
			clear();
			menu();
		}
		
		cin.ignore(1000, '\n');

		cout << "Que atributo deseja alterar?" << endl;
		cout << "Marca------------------------1" << endl;
		cout << "Modelo-----------------------2" << endl;
		cout << "Matricula--------------------3" << endl;
		cout << "Categoria--------------------4" << endl;
		cout << "Sair-------------------------0" << endl;
		
		try {
			cin >> op;
			if(op < 0 || op > 4) {
				OFBOpcoes o;
				throw o;
			}
		}
		catch (OpcoesExc) {
			cout << "Opção Invalida" << endl;
			pause();
			clear();
			menu();
		}
		
		cin.ignore(1000, '\n');

		clear();
		switch (op) {
		case 1: {
			cout << "Insira nova marca" << endl;
			getline(cin, marca);
			try{
				if(marca.size() > 5){
					CamiaoMarcaExc cm;
					throw cm;
				}
			}
			catch (VeicExc) {
				cout << "String overflow" << endl;
			}
			
			camioes[nCarro - 1]->setMarca(marca);

		}
			break;
		case 2: {
			cout << "Insira novo modelo" << endl;
			getline(cin, modelo);
			try{
				if(modelo.size() > 5){
					CamiaoModeloExc cmd;
					throw cmd;
				}
			}
			catch (VeicExc) {
				cout << "String overflow" << endl;
			}
			
			camioes[nCarro - 1]->setMarca(modelo);
		}
			break;
		case 3: {
			cout << "Insira nova matricula" << endl;
			getline(cin, matricula);
			try{
				if(matricula.size() > 5){
					CamiaoMatrExc cmt;
					throw cmt;
				}
			}
			catch (VeicExc) {
				cout << "String overflow" << endl;
			}
			
			camioes[nCarro - 1]->setMatricula(matricula);
		}
			break;
		case 4: {
			cout << "Insira nova categoria" << endl;
			getline(cin, categoria);
			try{
				if(categoria.size() > 5){
					CamiaoCategoriaExc cg;
					throw cg;
				}
			}
			catch (VeicExc) {
				cout << "String overflow" << endl;
			}
			
			camioes[nCarro - 1]->setCategoria(categoria);
		}
			break;
		case 0: {

		}
			break;
		}
		pause();
	}
		break;

	case 3: { /*Modifica bus  */
		clear();

		int opcao, nBus;
		for (unsigned int i = 0; i < buses.size(); i++) {
			cout << i + 1 << "   " << buses[i]->getMarca() << endl;
		}
		cout << "Selecione qual o bus que deseja modificar" << endl;
		try {
			cin >> nBus;
			if(nBus < 1 || nBus > buses.size()) {
				BusInvalido bi;
				throw bi;
			}
		}
		catch (VeicExc) {
			cout << "Bus inexistente" << endl;
			pause();
			clear();
			menu();
		}
			
			
		cin.ignore(1000, '\n');

		clear();
		cout << "Que atributo deseja alterar?" << endl;
		cout << "Marca------------------------1" << endl;
		cout << "Modelo-----------------------2" << endl;
		cout << "Matricula--------------------3" << endl;
		cout << "Sair-------------------------0" << endl;
		
		try {
			cin >> opcao;
			if(opcao < 0 || opcao > 3){
				OFBOpcoes o;
				throw o;
			}
		}
		catch (OpcoesExc){
			cout << "Opção Invalida" << endl;
			pause();
			clear();
			menu();
		}
		
		cin.ignore(1000, '\n');

		clear();

		switch (opcao) {
		case 1: {
			cout << "Insira nova marca" << endl;
			getline(cin, marca);
			try {
				if(marca.size() > 5) {
					BusMarcaExc bm;
					throw bm;
				}
			}
			catch (VeicExc){
				cout << "String overflow" << endl;
				pause();
				clear();
				menu();
			}
			
			buses[nBus - 1]->setMarca(marca);

		}
			break;
		case 2: {
			cout << "Insira novo modelo" << endl;
			getline(cin, modelo);
				try {
				if(modelo.size() > 5) {
					BusModeloExc bmt;
					throw bmt;
				}
			}
			catch (VeicExc){
				cout << "String overflow" << endl;
				pause();
				clear();
				menu();
			}
			
			buses[nBus - 1]->setMarca(modelo);
		}
			break;
		case 3: {
			cout << "Insira nova matricula" << endl;
			getline(cin, matricula);
				try {
				if(matricula.size() > 5) {
					BusMatrExc bmp;
					throw bmp;
				}
			}
			catch (VeicExc){
				cout << "String overflow" << endl;
				pause();
				clear();
				menu();
			}
			
			buses[nBus - 1]->setMatricula(matricula);
			pause();
		}
			break;
		case 0: {

		}
			break;

		}
		pause();
		break;

	}
		break;
	}
}

void Empresa::modificaServ() {
	clear();
	int escolha, opS;
	for (unsigned int i = 0; i < standards.size(); i++) {
		cout << i + 1 << "  " << standards[i]->getNome() << endl;
	}
	string nome, descricao, dataI, dataF, precoe, duracaoe;
	double preco, duracao;

	cout << "Qual dos servicos deseja alterar?" << endl;
	try {
		cin >> escolha;
		if(escolha < 1 || escolha > standards.size()) {
			ServInvalido si;
			throw si;
		}
	}
	catch (ServicosExc) {
		cout << "Servico Inixestente" << endl;
		pause();
		clear();
		menu();
	}
		
	cin.ignore(1000, '\n');

	cout << "Que atributo deseja alterar?" << endl;
	cout << "Data de inicio---------------------1" << endl;
	cout << "Data de fim------------------------2" << endl;
	cout << "Nome-------------------------------3" << endl;
	cout << "Descricao--------------------------4" << endl;
	cout << "Preco por hora---------------------5" << endl;
	cout << "Duracao----------------------------6" << endl;
	cout << "Sair-------------------------------0" << endl;
	
	try {
		cin >> opS;
		if(opS < 0 || opS > 6) {
			OFBOpcoes o;
			throw o;
		}
	}
	catch (OpcoesExc) {
		cout << "Opção invalida" << endl;
		pause();
		clear();
		menu();
	}
		
	cin.ignore(1000, '\n');

	clear();
	switch (opS) {

	case 1: {
		cout << "Insira nova Data de inicio " << endl;
		getline(cin, dataI);
		try {
			if(dataI.size() > 5) {
				DataIniExc di;
				throw di;
			}
		}
		catch (ServicosExc) {
			cout << "String overflow" << endl;
			pause();
			clear();
			menu();
		}
		
		standards[escolha - 1]->setDataInicio(dataI);

	}
		break;

	case 2: {
		cout << "Insira nova Data de fim " << endl;
		getline(cin, dataF);
		try {
			if(dataF.size() > 5) {
				DataFimExc df;
				throw df;
			}
		}
		catch (ServicosExc) {
			cout << "String overflow" << endl;
			pause();
			clear();
			menu();
		}
		
		cin.ignore(1000, '\n');
		standards[escolha - 1]->setDataFim(dataF);
	}
		break;

	case 3: {
		cout << "Insira novo Nome " << endl;
		getline(cin, nome);
		try {
			if(nome.size() > 5) {
				NomServExc ns;
				throw ns;
			}
		}
		catch (ServicosExc) {
			cout << "String overflow" << endl;
			pause();
			clear();
			menu();
		}
		
		cin.ignore(1000, '\n');
		standards[escolha - 1]->setNome(nome);
	}
		break;

	case 4: {
		cout << "Insira nova Descricao " << endl;
		getline(cin, descricao);
		try {
			if(descricao.size() > 5) {
				DescServExc ds;
				throw ds;
			}
		}
		catch (ServicosExc) {
			cout << "String overflow" << endl;
			pause();
			clear();
			menu();
		}
		
		cin.ignore(1000, '\n');
		standards[escolha - 1]->setDescricao(descricao);
	}
		break;

	case 5: {
		cout << "Insira novo Preco " << endl;
		getline(cin, precoe);
		try {
			if(dataI.size() > 5) {
				PrecoServExc ps;
				throw ps;
			}
		}
		catch (ServicosExc) {
			cout << "String overflow" << endl;
			pause();
			clear();
			menu();
		}
		
		cin.ignore(1000, '\n');
		preco = atof(precoe.c_str());
		standards[escolha - 1]->setPreco(preco);
	}
		break;

	case 6: {
		cout << "Insira nova Duracao (Em horas) " << endl;
		getline(cin, duracaoe);
		try {
			if(duracaoe.size() > 5) {
				DuracaoServExc dse;
				throw dse;
			}
		}
		catch (ServicosExc) {
			cout << "String overflow" << endl;
			pause();
			clear();
			menu();
		}
		
		cin.ignore(1000, '\n');
		duracao = atof(duracaoe.c_str());
		standards[escolha - 1]->setDuracao(duracao);
	}
		break;

	case 0: {

	}
		break;
	} //fecha primeiro switch

}

void Empresa::listaVeiculosServicos(Veiculo *v) {
	int opcao;
	cout << "Deseja listar os servicos associados a este veiculo?" << endl;
	cout << "Sim-------------------1" << endl;
	cout << "Nao-------------------2" << endl;
	cin >> opcao;

	if (opcao == 1) {
		for (unsigned int i = 0; i < v->getStandards().size(); i++) {
			cout << *(v->getStandards()[i]) << endl;
		}

	}
}

void Empresa::adicionaVeiculoFuncionario() {
	int opcao, opcao2;
	cout << "Qual o Funcionario?" << endl;
	for (unsigned int i = 0; i < funcionarios.size(); i++) {
		cout << i + 1 << "   " << funcionarios[i]->getNome() << endl;
	}
	cin >> opcao;

	cout << "Qual o veiculo que quer adicionar? " << endl;
	for (unsigned int i = 0; i < veiculos.size(); i++) {
		cout << i + 1 << "   " << veiculos[i]->getMarca() << endl;
	}
	cin >> opcao2;

	funcionarios[opcao - 1]->adicionaVeiculo(veiculos[opcao2 - 1]);

}

