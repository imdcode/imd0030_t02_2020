#pragma once

#include "conta.hpp"

#include <vector>
#include <ostream>

using std::string;
using std::vector;
using std::ostream;


class ContaPoupanca : public Conta {
public:
	ContaPoupanca(string agencia, string numero, double saldo,
			tcTipo tipo, double taxa);
	~ContaPoupanca();
	double getTaxa() const;

	bool processarMovimentacao(Movimentacao* nova);
	bool atualizaSaldoNoAniversario();

	friend ostream& operator<< (ostream& o, ContaPoupanca& cc);
	ostream& imprimeDados(ostream& o) const;

private:
	double taxa;
};