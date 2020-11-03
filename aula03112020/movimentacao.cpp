//
// Created by leandro on 10/29/20.
//
#include <iomanip>
#include "movimentacao.h"

using std::setfill;
using std::setw;

Movimentacao::Movimentacao(string descricao, double valor, TipoMovimentacao tipo):
        descricao(descricao), valor(valor), tipo(tipo){}

Movimentacao::~Movimentacao(){}

string Movimentacao::getDescricao() const{
    return this->descricao;
}

double Movimentacao::getValor() const{
    return this->valor;
}

TipoMovimentacao Movimentacao::getTipo() const{
    return this->tipo;
}

std::ostream& operator<< (std::ostream &o, Movimentacao const m) {
    string type;
    if  (m.tipo==0){
        type = "Crédito";
    } else type = "Débito";

    o << setfill ('_') << setw (35) << m.descricao
        << setfill (' ') << setw (10) << " |  Valor: R$ "
         << m.valor << setfill (' ') << setw (3) <<"  |  " << type;
    return o;
}