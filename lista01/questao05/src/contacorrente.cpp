#include "contacorrente.hpp"

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

ContaCorrente::ContaCorrente(string agencia, string numero, 
			double saldo, tcTipo tipo, double limite):
			Conta(agencia,numero,saldo,tipo), limite(limite) {}

ContaCorrente::~ContaCorrente() {}

double 
ContaCorrente::getLimite() const {
	return this->limite;
}

bool ContaCorrente::processarMovimentacao(Movimentacao* nova){
	if (nova->getTipo()==tmCredito) {
		this->saldo += nova->getValor();
		this->historico.push_back(nova);
		return true;
	} else if (nova->getTipo()==tmDebito) {
		if ((this->saldo + this->limite) >= nova->getValor()) {
			this->saldo -= nova->getValor();
			this->historico.push_back(nova);
			return true;
		}
	}
	return false;
}

ostream& 
ContaCorrente::imprimeDados(ostream& o) const {
	o << setfill(' ') << setw(10) << this->agencia
		<< setfill(' ') << setw(10) << this->numero
		<< setfill(' ') << setw(6) 
		<< (this->tipo==tcNormal ? "CC.N" : "CC.E")
		<< right << setfill(' ') << setw(15) 
		<< fixed << setprecision(2) << this->saldo
		<< setfill(' ') << setw(15)
		<< fixed << setprecision(2) << this->limite;
	return o;
}
