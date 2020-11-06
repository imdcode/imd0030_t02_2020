#include "movimentacao.hpp"

#include <iomanip>

using std::setfill;
using std::setw;
using std::fixed;
using std::setprecision;

Movimentacao::Movimentacao(string descricao, double valor, 
		tmTipo tipo):descricao(descricao),
		valor(valor),tipo(tipo){}

Movimentacao::~Movimentacao() {}

string 
Movimentacao::getDescricao() const {
	return this->descricao;
}

double 
Movimentacao::getValor() const {
	return this->valor;
}

tmTipo 
Movimentacao::getTipo() const {
	return this->tipo;
}

ostream& 
operator<< (ostream& o, Movimentacao& mov) {
	string strTipo = (mov.tipo == tmCredito) ? "C":"D";
	o << setfill('.') << setw(30) << mov.descricao
		<< setfill(' ') << setw(10) 
		<< fixed << setprecision(2) << mov.valor
		<< setfill(' ') << setw(10) << strTipo;
	return o;
}