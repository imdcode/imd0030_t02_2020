#include <iomanip>
#include "fruta.hpp"

using std::setfill;
using std::setw;

Fruta::Fruta() {}

Fruta::Fruta(string codigo, string descricao, double preco, 
	string data_lote, string validade):
	Produto(codigo, descricao, preco), data_lote(data_lote), validade(validade) {}

Fruta::~Fruta() {}

string 
Fruta::getDataLote() {
	return this->data_lote;
}

string 
Fruta::getValidade() {
	return this->validade;
}

void 
Fruta::setDataLote(string data_lote) {
	this->data_lote = data_lote;
}

void 
Fruta::setValidade(string validade) {
	this->validade = validade;
}

ostream& 
Fruta::print(ostream &o) const {
	o << setfill (' ') << setw (10) << this->cod_barras << " | " 
		<< setfill ('.') << setw (20) << this->descricao << " | " 
		<< setfill (' ') << setw (5) << this->preco << " | "
		<< setfill (' ') << setw (10) << this->data_lote << " | " 
		<< setfill (' ') << setw (3) << this->validade;
	return o;
}