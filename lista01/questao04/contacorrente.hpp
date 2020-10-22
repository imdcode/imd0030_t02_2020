#pragma once

#include "movimentacao.hpp"

#include <string>
#include <vector>

using std::string;
using std::vector;

enum TipoConta
{
	contaNormal,
	contaEspecial
};
class ContaCorrente
{
public:
	ContaCorrente(string agencia, string numero, double saldo,
				TipoConta tipo, double limite);
	~ContaCorrente();
	string getAgencia() const;
	string getNumero() const;
	double getSaldo() const;
	TipoConta getTipoConta() const;
	double getLimite() const;
	bool processaMovimentacao(Movimentacao& transacao);
	void mostraHistorico();
private:
	string agencia;
	string numero;
	double saldo;
	TipoConta tipo;
	double limite;
	vector<Movimentacao*> historico;
};