#pragma once

#include <string>

using std::string;

enum TipoMovimentacao
{
	tipoCredito,
	tipoDebito
};

class Movimentacao
{
public:
	Movimentacao(string descricao, double valor, TipoMovimentacao tipo);
	~Movimentacao();
	string getDescricao() const;
	double getValor() const;
	TipoMovimentacao getTipo() const;
private:
	string descricao;
	double valor;
	TipoMovimentacao tipo;
};