#include "contapoupanca.hpp"

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

ContaPoupanca::ContaPoupanca(string agencia, string numero, 
			double saldo, tcTipo tipo, double taxa):
			Conta(agencia,numero,saldo,tipo), taxa(taxa) {}

ContaPoupanca::~ContaPoupanca() {}

double 
ContaPoupanca::getTaxa() const {
	return this->taxa;
}

bool ContaPoupanca::processarMovimentacao(Movimentacao* nova){
	if (nova->getTipo()==tmCredito) {
		this->saldo += nova->getValor();
		this->historico.push_back(nova);
		return true;
	} else if (nova->getTipo()==tmDebito) {
		if (this->saldo >= nova->getValor()) {
			this->saldo -= nova->getValor();
			this->historico.push_back(nova);
			return true;
		}
	}
	return false;
}

ostream& 
ContaPoupanca::imprimeDados(ostream& o) const {
	o << setfill(' ') << setw(10) << this->agencia
		<< setfill(' ') << setw(10) << this->numero
		<< setfill(' ') << setw(6) << "P"
		<< right << setfill(' ') << setw(15) 
		<< fixed << setprecision(2) << this->saldo
		<< setfill(' ') << setw(15)
		<< fixed << setprecision(2) << this->taxa;
	return o;
}

bool 
ContaPoupanca::atualizaSaldoNoAniversario() {
	if (this->saldo <= 0) {
		return false;
	}
	double rendimento = this->saldo * (this->taxa/100);
	Movimentacao* credito = new Movimentacao(
			"Rendimento mensal.",
			rendimento, tmCredito);
	return this->processarMovimentacao(credito);
}