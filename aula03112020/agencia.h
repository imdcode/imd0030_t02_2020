//
// Created by leandro on 10/29/20.
//

#ifndef AGENCIA_BANCARIA_AGENCIA_H
#define AGENCIA_BANCARIA_AGENCIA_H

#include "contacorrente.h"

#include <vector>
#include <string>

using std::vector;
using std::string;

class Agencia{
private:
    string nome;
    string numero;
    string banco;
    vector<ContaCorrente*> contas;
public:
    Agencia(string nome, string numero, string banco);
    ~Agencia();
    string getNome() const;
    string getNumero() const;
    string getBanco() const;
    int getTotalContas() const;
    bool adicionaConta(ContaCorrente* nova);
    bool criarConta();
    bool excluirConta(string numero_conta);
    bool saque(string numero_conta, double valor);
    bool deposito(string numero_conta, double valor);
    bool saldo(string numero_conta) const;
    bool extrato(string numero_conta) const;
    bool tranferencia(string conta_origem, string conta_destino, double valor);
    bool listaContas() const;
    int menuPrincipal();
    int menuConta(string conta);
};

#endif //AGENCIA_BANCARIA_AGENCIA_H
