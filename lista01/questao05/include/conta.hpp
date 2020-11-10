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
	tcEspecial,
	tcPoupanca
};

class Conta {
public:
	Conta(string agencia, string numero, double saldo,
			tcTipo tipo);
	virtual ~Conta();
	string getAgencia() const;
	string getNumero() const;
	double getSaldo() const;
	tcTipo getTipo() const;

	vector<Movimentacao*> getHistorico() const;

	virtual bool processarMovimentacao(Movimentacao* nova) = 0;
	virtual ostream& imprimeDados(ostream& o) const = 0;

	bool operator==(const Conta& outro) const;

	friend ostream& operator<< (ostream& o, Conta& cc);

protected:
	string agencia;
	string numero;
	double saldo;
	tcTipo tipo;
	vector<Movimentacao*> historico;
};