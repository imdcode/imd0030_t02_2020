#include <iomanip>
#include "bebida.hpp"

using std::setfill;
using std::setw;

Bebida::Bebida() {}

Bebida::Bebida(string codigo, string descricao, double preco, 
	double teor_alcoolico):
	Produto(codigo, descricao, preco), teor_alcoolico(teor_alcoolico) {}

Bebida::~Bebida() {}

double
Bebida::getTeorAlcoolico() {
	return this->teor_alcoolico;
}

void 
Bebida::setTeorAlcoolico(double teor_alcoolico) {
	this->teor_alcoolico = teor_alcoolico;
}

ostream& 
Bebida::print(ostream &o) const {
	o << setfill (' ') << setw (10) << this->cod_barras << " | " 
		<< setfill ('.') << setw (20) << this->descricao << " | " 
		<< setfill (' ') << setw (5) << this->preco << " | "
		<< setfill (' ') << setw (10) << this->teor_alcoolico;
	return o;
}