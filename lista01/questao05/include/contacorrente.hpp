#pragma once

#include "conta.hpp"

#include <vector>
#include <ostream>

using std::string;
using std::vector;
using std::ostream;


class ContaCorrente : public Conta {
public:
	ContaCorrente(string agencia, string numero, double saldo,
			tcTipo tipo, double limite);
	~ContaCorrente();
	double getLimite() const;

	bool processarMovimentacao(Movimentacao* nova);

	friend ostream& operator<< (ostream& o, ContaCorrente& cc);
	ostream& imprimeDados(ostream& o) const;

private:
	double limite;
};