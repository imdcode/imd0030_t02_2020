#include "agencia.hpp"

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

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

bool 
Agencia::criarConta() {
	string cc_numero;
	double cc_saldo;
	string strTipo;
	tcTipo cc_tipo;
	double cc_limite;

	cout << "Agencia: " << this->numero << endl;
	cout << "Numero: ";
	cin >> cc_numero;
	cout << "Saldo: ";
	cin >> cc_saldo;
	cout << "Tipo (N - normal | E - especial): ";
	cin >> strTipo;
	cc_tipo = (strTipo=="N") ? tcNormal : tcEspecial;
	cout << "Limite: ";
	cin >> cc_limite;

	ContaCorrente* criada = new ContaCorrente(
		this->numero,
		cc_numero,
		cc_saldo,
		cc_tipo,
		cc_limite);

	this->adicionarConta(criada);

	return true;
}

bool 
Agencia::adicionarConta(ContaCorrente* nova) {
	this->contas.push_back(nova);
	return true;
}

bool 
Agencia::removerConta(string numero) {
	return true;
}

bool 
Agencia::saque(string numero, double valor) {
	return true;
}

bool 
Agencia::deposito(string numero, double valor) {
	return true;
}

void 
Agencia::imprimeSaldo(string numero) {}

void 
Agencia::imprimeExtrato(string numero) {}

bool 
Agencia::transferencia(string cc_origem, string cc_destino, 
		double valor) {
	return true;
}

void Agencia::listarContas() {
	for (auto& conta : this->contas)
	{
		cout << (*conta) << endl;
	}
}