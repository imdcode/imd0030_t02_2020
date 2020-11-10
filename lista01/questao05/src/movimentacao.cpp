#include "movimentacao.hpp"

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

Movimentacao::Movimentacao(string descricao, double valor, 
		tmTipo tipo):descricao(descricao),
		valor(valor),tipo(tipo){
	Debug("Movimentacao (" << (*this) << ") - [" << this << "] foi criada." << endl);
}

Movimentacao::~Movimentacao() {
	Debug("Movimentacao (" << (*this) << ") - [" << this << "] foi destruída." << endl);
}

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
	o << left << setfill('.') << setw(30) << mov.descricao
		<< right << setfill(' ') << setw(10) 
		<< fixed << setprecision(2) << mov.valor
		<< setfill(' ') << setw(10) << strTipo;
	return o;
}