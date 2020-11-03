//
// Created by leandro on 10/29/20.
//

#ifndef AGENCIA_BANCARIA_MOVIMENTACAO_H
#define AGENCIA_BANCARIA_MOVIMENTACAO_H

#include <string>

using std::string;

enum TipoMovimentacao
{
    tipoCredito,
    tipoDebito
};

class Movimentacao
{
private:
    string descricao;
    double valor;
    TipoMovimentacao tipo;
public:
    Movimentacao(string descricao, double valor, TipoMovimentacao tipo);
    ~Movimentacao();
    string getDescricao() const;
    double getValor() const;
    TipoMovimentacao getTipo() const;
    friend std::ostream& operator<< (std::ostream &o, Movimentacao const m);
};

#endif //AGENCIA_BANCARIA_MOVIMENTACAO_H
