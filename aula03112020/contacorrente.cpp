//
// Created by leandro on 10/29/20.
//

#include "contacorrente.h"
#include <iostream>

ContaCorrente::ContaCorrente(string agencia, string numero, double saldo, TipoConta tipo, double limite):
        agencia(agencia),numero(numero),saldo(saldo), tipo(tipo), limite(limite){}

ContaCorrente::~ContaCorrente(){}

string ContaCorrente::getAgencia() const{
    return this->agencia;
}

string ContaCorrente::getNumero() const{
    return this->numero;
}

double ContaCorrente::getSaldo() const{
    return this->saldo;
}

TipoConta ContaCorrente::getTipoConta() const{
    return this->tipo;
}

double ContaCorrente::getLimite() const{
    return this->limite;
}

bool ContaCorrente::processaMovimentacao(Movimentacao& transacao){

    if (transacao.getTipo()==tipoCredito) {

        this->saldo += transacao.getValor();
        this->historico.push_back(transacao);
        return true;

    } else if (transacao.getTipo()==tipoDebito && (this->saldo + this->limite >= transacao.getValor())) {

        this->saldo -= transacao.getValor();
        this->historico.push_back(transacao);
        return true;
    }
    return false;
}

void ContaCorrente::mostraHistorico(){
    for (auto &mov : this->historico){
        std::cout << mov << std::endl;
    }
}