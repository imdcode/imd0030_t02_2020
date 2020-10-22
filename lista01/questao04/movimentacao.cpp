#include "movimentacao.hpp"

Movimentacao::Movimentacao(string descricao, double valor, TipoMovimentacao tipo):
						descricao(descricao), valor(valor), tipo(tipo){}
Movimentacao::~Movimentacao(){}
string 
Movimentacao::getDescricao() const{
	return descricao;
}
double 
Movimentacao::getValor() const{
	return valor;
}
TipoMovimentacao 
Movimentacao::getTipo() const{
	return tipo;
}