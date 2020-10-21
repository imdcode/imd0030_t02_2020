#include <iostream>
#include "produto.hpp"

Produto::Produto() {}

Produto::~Produto(){}

Produto::Produto(string codigo, string descricao, double preco):
	cod_barras(codigo), descricao(descricao), preco(preco) {}

string 
Produto::getCodBarras() {
	return this->cod_barras;
}
	
string 
Produto::getDescricao() {
	return this->descricao;
}

double 
Produto::getPreco() {
	return this->preco;
}
	
void 
Produto::setCodBarras(string codigo) {
	this->cod_barras = codigo;
}

void 
Produto::setDescricao(string descricao) {
	this->descricao = descricao;
}

void 
Produto::setPreco(double preco) {
	this->preco = preco;
}

ostream& operator<< (ostream &o, Produto const &p) {
	return p.print(o);
}
