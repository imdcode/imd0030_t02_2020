//
// Created by leandro on 10/29/20.
//

#ifndef AGENCIA_BANCARIA_CONTACORRENTE_H
#define AGENCIA_BANCARIA_CONTACORRENTE_H

#include "movimentacao.h"

#include <string>
#include <vector>

using std::string;
using std::vector;

enum TipoConta{
    contaNormal,
    contaEspecial
};

class ContaCorrente
{
public:
    ContaCorrente(string agencia, string numero, double saldo, TipoConta tipo, double limite);
    ~ContaCorrente();
    string getAgencia() const;
    string getNumero() const;
    double getSaldo() const;
    TipoConta getTipoConta() const;
    double getLimite() const;
    bool processaMovimentacao(Movimentacao& transacao);
    void mostraHistorico();
private:
    string agencia;
    string numero;
    double saldo;
    TipoConta tipo;
    double limite;
    vector<Movimentacao> historico;
};

#endif //AGENCIA_BANCARIA_CONTACORRENTE_H
