#pragma once

#include <string>
#include <ostream>

using std::string;
using std::ostream;

enum tmTipo
{
	tmCredito, 
	tmDebito
};

class Movimentacao {
public:
	Movimentacao(string descricao, double valor, tmTipo tipo);
	~Movimentacao();
	string getDescricao() const;
	double getValor() const;
	tmTipo getTipo() const;

	friend ostream& operator<< (ostream& o, Movimentacao& mov);
private:
	string descricao;
	double valor;
	tmTipo tipo; 
};
