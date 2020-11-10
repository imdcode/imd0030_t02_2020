#include "conta.hpp"

#include <iomanip>
#include <iostream>

using std::setfill;
using std::setw;
using std::fixed;
using std::setprecision;
using std::left;
using std::right;
using std::cout;
using std::endl;

#ifdef DEBUG
#define Debug(x) std::cout << x
#else
#define Debug(x) 
#endif 

Conta::Conta(string agencia, string numero, 
			double saldo, tcTipo tipo):
			agencia(agencia), numero(numero),
			saldo(saldo), tipo(tipo) {
	Debug("Conta " << this->numero << " [" << this << "] foi criada." << endl);
}

Conta::~Conta() {
	
	for (auto& movimentacao : this->historico)
	{
		delete movimentacao;
	}
	Debug("Conta " << this->numero << " [" << this << "] foi destruída." << endl);
}

string 
Conta::getAgencia() const {
	return this->agencia;
}

string 
Conta::getNumero() const {
	return this->numero;
}

double 
Conta::getSaldo() const {
	return this->saldo;
}

tcTipo 
Conta::getTipo() const {
	return this->tipo;
}

vector<Movimentacao*> 
Conta::getHistorico() const {
	return this->historico;
}

ostream& operator<< (ostream& o, Conta& c) {
	return c.imprimeDados(o);
}

bool 
Conta::operator==(const Conta& outro) const {
	return (this->numero == outro.numero);
}