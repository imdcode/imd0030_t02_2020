#include "agencia.hpp"

#include <sstream>
#include <iostream>
#include <iomanip>

#include <cstring> // Para usar a função strspn()

using std::setfill;
using std::setw;
using std::fixed;
using std::setprecision;
using std::cout;
using std::endl;
using std::cin;
using std::left;
using std::right;
using std::getline;


Agencia::Agencia(string banco, string nome, string numero):
		banco(banco), nome(nome), numero(numero) {}

Agencia::~Agencia(){}

string 
Agencia::getBanco() const {
	return this->banco;
}

string 
Agencia::getNome() const {
	return this->nome;
}

string 
Agencia::getNumero() const {
	return this->numero;
}

vector<ContaCorrente*> 
Agencia::getContas() const {
	return this->contas;
}

void 
Agencia::criarConta() {
	string cc_numero;
	double cc_saldo;
	string strTipo;
	tcTipo cc_tipo;
	double cc_limite;

	this->printTitle("Criar Conta Corrente");

	cout << "Agencia: " << this->numero << endl;
	
	cc_numero = leNumeroDaConta("Numero: ");
	
	if (cc_numero=="0") {
		cout << "Operação cancelada pelo usuário." << endl;
		return;
	}

	if (this->findConta(cc_numero)!=nullptr) {
		cout << "Conta já cadastrada." << endl;
		return;
	}

	cc_saldo = leValor("Saldo: ");
	
	do {
		cout << "Tipo (N - normal | E - especial): ";
		cin >> strTipo;
		if (strTipo!="N" && strTipo!="n" 
			&& strTipo!="E" && strTipo!="e") {
			cout << "Opção inválida! Tente novamente." << endl;
		}
	} while (strTipo!="N" && strTipo!="n" 
			&& strTipo!="E" && strTipo!="e");

	cc_tipo = (strTipo=="N") ? tcNormal : tcEspecial;

	cc_limite = leValor("Limite: ");

	ContaCorrente* criada = new ContaCorrente(
		this->numero,
		cc_numero,
		0,
		cc_tipo,
		cc_limite);
	Movimentacao* mov = new Movimentacao(
			"Abertura de conta.",
			cc_saldo,tmCredito);
	criada->processarMovimentacao(mov);

	if (this->adicionarConta(criada)) {
		cout << "Operação realizada com sucesso." << endl;
	} else {
		cout << "Erro!! Operação cancelada." << endl;
	}
}

bool 
Agencia::adicionarConta(ContaCorrente* nova) {
	this->contas.push_back(nova);
	return true;
}

void 
Agencia::removeConta() {
	this->printTitle("Remover Conta Corrente");
	string cc_numero;
	do {
		cc_numero = leNumeroDaConta("Numero da conta: ");
	} while (this->findConta(cc_numero)==nullptr);

	if (this->removerConta(cc_numero)) {
		cout << "Operação realizada com sucesso." << endl;
	} else {
		cout << "Erro!! Operação cancelada." << endl;
	}
}

ContaCorrente* 
Agencia::removerConta(string numero) {
	int index = 0;
	for (auto& conta : this->contas)
	{
		if (conta->getNumero()==numero)
		{
			ContaCorrente* removido = conta;
			this->contas.erase(this->contas.begin()+index);
			return removido;
		}
		index++;
	}
	return nullptr;
}

void 
Agencia::saque() {
	this->printTitle("Saque em Conta Corrente");
	string cc_numero;
	double cc_valor_saque;
	do {
		cc_numero = leNumeroDaConta("Numero da conta: ");
	} while (this->findConta(cc_numero)==nullptr);

	cc_valor_saque = leValor("Valor: ");

	if (this->saque(cc_numero,cc_valor_saque)) {
		cout << "Operação realizada com sucesso." << endl;
	} else {
		cout << "Erro!! Operação cancelada." << endl;
	}
}

bool 
Agencia::saque(string numero, double valor) {
	ContaCorrente* conta = this->findConta(numero);
	if (conta!=nullptr) {
		Movimentacao* debito = new Movimentacao(
			"Saque em conta.",
			valor, tmDebito);
		return conta->processarMovimentacao(debito);
	}
	return false;
}

void
Agencia::deposito() {
	this->printTitle("Depósito em Conta Corrente");
	string cc_numero;
	double cc_valor_deposito;
	do {
		cc_numero = leNumeroDaConta("Numero da conta: ");
	} while (this->findConta(cc_numero)==nullptr);

	cc_valor_deposito = leValor("Valor: ");

	if (this->deposito(cc_numero,cc_valor_deposito)) {
		cout << "Operação realizada com sucesso." << endl;
	} else {
		cout << "Erro!! Operação cancelada." << endl;
	}
}

bool 
Agencia::deposito(string numero, double valor) {
	ContaCorrente* conta = this->findConta(numero);
	if (conta!=nullptr) {
		Movimentacao* credito = new Movimentacao(
			"Credito em conta.",
			valor, tmCredito);
		return conta->processarMovimentacao(credito);
	}
	return false;
}

void 
Agencia::saldo() {
	this->printTitle("Saldo de Conta Corrente");
	string cc_numero;
	do {
		cc_numero = leNumeroDaConta("Numero da conta: ");
	} while (this->findConta(cc_numero)==nullptr);

	this->imprimeSaldo(cc_numero);
}

void 
Agencia::imprimeSaldo(string numero) {
	ContaCorrente* conta = this->findConta(numero);
	if (conta!=nullptr) {
		cout << "Conta Corrente [" 
			<< conta->getNumero() << "]"
			<< endl
			<< "Saldo atual: "
			<< conta->getSaldo() << endl;
	}
}

void 
Agencia::extrato() {
	this->printTitle("Extrato de Conta Corrente");
	string cc_numero;
	do {
		cc_numero = leNumeroDaConta("Numero da conta: ");
	} while (this->findConta(cc_numero)==nullptr);

	this->imprimeExtrato(cc_numero);
}

void 
Agencia::imprimeExtrato(string numero) {
	ContaCorrente* conta = this->findConta(numero);
	if (conta!=nullptr) {
		cout << "Conta Corrente [" 
			<< conta->getNumero() << "]"
			<< endl;
		for (auto& mov : conta->getHistorico())
		{
			cout << (*mov) << endl;
		}
		cout << "Saldo atual: "
			<< conta->getSaldo() << endl;
	}
}

void 
Agencia::transferencia() {
	this->printTitle("Transferência entre Contas");
	string cc_origem;
	do {
		cc_origem = leNumeroDaConta("Numero da conta origem: ");
	} while (this->findConta(cc_origem)==nullptr);

	string cc_destino;
	do {
		cc_destino = leNumeroDaConta("Numero da conta destino: ");
	} while (this->findConta(cc_destino)==nullptr);
	
	double cc_valor_transferencia;
	cc_valor_transferencia = leValor("Valor: ");

	if (this->transferencia(cc_origem, cc_destino, cc_valor_transferencia)) {
		cout << "Transferência realizada com sucesso." << endl;
	} else {
		cout << "Erro na transferência. Operação cancelada." << endl;
	}
}

bool 
Agencia::transferencia(string cc_origem, string cc_destino, 
		double valor) {
	ContaCorrente* origem = this->findConta(cc_origem);
	ContaCorrente* destino = this->findConta(cc_destino);

	if (origem==nullptr || destino==nullptr) {
		return false;
	}

	Movimentacao* debito = new Movimentacao(
		"Transferência para CC " + destino->getNumero() + ".",
		valor, tmDebito);
	if (!origem->processarMovimentacao(debito)) {
		return false;
	}

	Movimentacao* credito = new Movimentacao(
		"Transferência da CC " + origem->getNumero() + ".",
		valor, tmCredito);
	if (!destino->processarMovimentacao(credito)) {
		// Aqui teria que ter um processo de cancelamento do
		// debito na cc origem (devolução)
		return false;
	}
	return true;
}

void Agencia::listarContas() {
	this->printTitle("Listagem de Contas");
		
	if (this->contas.size()==0) {
		cout << "Não há contas cadastradas." << endl;
	} else {
		cout << right << setfill(' ') << setw(10) << "Ag"
			<< setfill(' ') << setw(10) << "CC"
			<< setfill(' ') << setw(15) 
			<< fixed << setprecision(2) << "Saldo (R$)"
			<< setfill(' ') << setw(15)
			<< fixed << setprecision(2) << "Limite (R$)" << endl;
		for (auto& conta : this->contas)
		{
			cout << (*conta) << endl;
		}
	}
}

ContaCorrente* 
Agencia::findConta(string numero) {
	for (auto& conta : this->contas)
	{
		if (conta->getNumero()==numero)
		{
			return conta;
		}
	}
	return nullptr;
}

double 
Agencia::leValor(string str_prompt) {
	double val = 0.00;
	string linha;
	getline(cin, linha); // apenas para limpar a entrada
	cout << str_prompt;
    while (getline(cin, linha))
    {
        std::stringstream ss(linha);
        if (ss >> val)
        {
            if (ss.eof())
            {
                break;
            }
        }
        cout << "Valor inválido." << endl;
        cout << str_prompt;
    }
    return val;
}

string 
Agencia::leNumeroDaConta(string str_prompt) {
	string numero;
	bool valido = false;
	do {
		cout << str_prompt;
		cin >> numero;
		valido = numeroValido(numero);
		if (numero!="0" && !valido) {
			cout << "Número de conta inválido." << endl;
		}
	} while(numero!="0" && !valido);
	return numero;
}

bool 
Agencia::numeroValido(string numero) {
	// Verifica se o string está vazio
	if (numero.length()==0) {
		return false;
	}
	// Verifica se o hyphen não é o primeiro ou último caracter
	int posHyphen = numero.find("-");
	if (posHyphen == 0 || posHyphen+1 == numero.length()) {
		return false;
	}
	// Verifica se há mais de um hyphen 
	int moreHyphen = numero.find("-", posHyphen+1);
	if (moreHyphen != -1) {
		return false;
	}
	// Caso queira forçar o uso de um hyphen
	//if (posHyphen == -1) {
	//	return false;
	//}

	// Verifica se foram usados apenas os caracteres permitidos
	string validChars = "0123456789-";
	int res = strspn(numero.c_str(), validChars.c_str());
	if (res == 0 || res != numero.length()) {
		return false;
	}

	// Se passou por todos os testes, está ok!
	return true;
}

void 
Agencia::printTitle(string title) {
	int spaceTotal = 50;
	int spaceOnLeft = (spaceTotal-title.length())/2;
	int spaceExtra = title.length()%2;
	cout << setfill('*') << setw(spaceTotal) << ""<< endl;
	cout << "**" 
		<< setfill(' ') << setw(spaceOnLeft-2) << ""
		<< title 
		<< setfill(' ') << setw(spaceOnLeft-2+spaceExtra) << ""
		<< "**" << endl;
	cout << setfill('*') << setw(spaceTotal) << "" << endl;
}