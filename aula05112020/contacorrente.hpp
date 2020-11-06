#pragma once

#include "movimentacao.hpp"

#include <vector>
#include <ostream>

using std::string;
using std::vector;
using std::ostream;

enum tcTipo
{
	tcNormal,
	tcEspecial
};

class ContaCorrente {
public:
	ContaCorrente(string agencia, string numero, double saldo,
			tcTipo tipo, double limite);
	~ContaCorrente();
	string getAgencia() const;
	string getNumero() const;
	double getSaldo() const;
	tcTipo getTipo() const;
	double getLimite() const;
	vector<Movimentacao*> getHistorico() const;

	bool processarMovimentacao(Movimentacao* nova);

	friend ostream& operator<< (ostream& o, ContaCorrente& cc);
private:
	string agencia;
	string numero;
	double saldo;
	tcTipo tipo;
	double limite;
	vector<Movimentacao*> historico;
};