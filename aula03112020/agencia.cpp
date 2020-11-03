//
// Created by leandro on 10/29/20.
//

#include "agencia.h"
#include <iostream>
#include <vector>


using std::vector;
using std::cin;
using std::cout;
using std::endl;

Agencia::Agencia(string nome, string numero, string banco): nome(nome),numero(numero),banco(banco){
    this->menuPrincipal();
}

Agencia::~Agencia(){}

string Agencia::getNome() const{
    return this->nome;
}

string Agencia::getNumero() const{
    return this->numero;
}

string Agencia::getBanco() const{
    return this->banco;
}

int Agencia::getTotalContas() const{
    return this->contas.size();
}

bool Agencia::adicionaConta(ContaCorrente* nova){
    this->contas.push_back(nova);
    return true;
}

bool Agencia::criarConta(){
    string numero;
    double saldo;
    TipoConta tipo = contaNormal;
    double limite;
    char ctipo;

    cout << "Número da conta: ";
    cin >> numero;
    cout << "Saldo inicial: ";
    cin >> saldo;
    do{
        cout << "Conta Normal ou Especial? (N/E): ";
        cin >> ctipo;
        if (ctipo == 'N' || ctipo == 'n') {
            tipo = contaNormal;
        } else if (ctipo == 'E' || ctipo == 'e') {
            tipo = contaEspecial;
        }
    } while (ctipo != 'e' && ctipo != 'n' && ctipo != 'N' && ctipo != 'E');
    cout << "Limite autorizado: ";
    cin >> limite;
    return adicionaConta(new ContaCorrente(this->numero,numero,saldo,tipo,limite));
}

bool Agencia::excluirConta(string numero_conta){

    int index = 0;
    auto pos = this->contas.begin();
    for (auto &conta : this->contas) {
        if (conta->getNumero()==numero_conta) {
            this->contas.erase(pos+index);
            return true;
        }
        index++;
    }
    return false;
}

bool Agencia::saque(string numero_conta, double valor){

    for (auto &conta : this->contas) {
        if (conta->getNumero()==numero_conta) {
            Movimentacao saque("Saque no terminal",valor,tipoDebito);
            if (conta->processaMovimentacao(saque)) {
                cout << "Saque de R$" << valor << " realizado com sucesso" << endl;
                saldo(conta->getNumero());
                return true;
            }
        }
    }
    cout << "ERRO: Você não possui limite para realizar esta transação." << endl;
    return false;
}

bool Agencia::deposito(string numero_conta, double valor){

    for (auto &conta : this->contas) {
        if (conta->getNumero()==numero_conta) {
            Movimentacao deposito("Depósito em conta",valor,tipoCredito);
            if (conta->processaMovimentacao(deposito)) {
                cout << "Depósito de R$" << valor << " realizado com sucesso" << endl;
                saldo(conta->getNumero());
                return true;
            }
        }
    }
    cout << "ERRO: Transação não realizada" << endl;
    cout << endl;
    return false;
}

bool Agencia::saldo(string numero_conta) const{
    for (auto &conta : this->contas) {
        if (conta->getNumero()==numero_conta) {
            cout << "Saldo em conta: R$ " << conta->getSaldo() << endl;
            cout << "Limite autorizado: R$ " << conta->getLimite() << endl;
            cout << "Limite total disponível: R$ " << (conta->getSaldo()+conta->getLimite()) << endl;
            cout << endl;
        }
    }
    return true;
}

bool Agencia::extrato(string numero_conta) const{
    for (auto &conta : this->contas) {
        if (conta->getNumero()==numero_conta) {
            cout << "Extrato da conta [" << conta->getNumero() << "]:" << endl;
            conta->mostraHistorico();
            saldo(conta->getNumero());
        }
    }
    return true;
}

bool Agencia::tranferencia(string conta_origem, string conta_destino, double valor){

    for (auto &conta : this->contas) {
        if (conta->getNumero()==conta_origem) {
            Movimentacao transferencia("Transferência entre contras",valor,tipoDebito);
            if (conta->processaMovimentacao(transferencia)) {
                cout << "Transferência de R$" << valor << " realizada com sucesso" << endl;
                saldo(conta->getNumero());
            } else{
                cout << "ERRO: Você não possui limite para realizar esta transação." << endl;
                cout << endl;
                return false;
            }
            break;
        }
    }

    for (auto &conta : this->contas) {
        if (conta->getNumero()==conta_destino) {
            Movimentacao transferencia("Transferência entre contras",valor,tipoCredito);
            conta->processaMovimentacao(transferencia);
        }
    }
    return true;
}

bool Agencia::listaContas() const{

    if (contas.size() == 0){
        cout << "Nenhuma conta cadastrada" << endl << endl;
        return false;
    } else {
        cout << "Contas cadastradas:" << endl;
        for (auto &conta: this->contas) {
            cout << "Agência [" << conta->getAgencia() << "] - Conta [" << conta->getNumero() << "]" << endl;
        }
        cout << endl;
        return true;
    }
}

int Agencia::menuPrincipal(){
    int op;
    char acessar;

    cout << "==============================================" << endl;
    cout << this->banco << " - " << this->nome << " [" << this->numero << "]" << endl << endl;

    do {

        cout << "Menu Principal:" << endl
             << "(1) Acessar minha conta" << endl
             << "(2) Mostrar contas cadastradas" << endl
             << "(3) Abrir conta" << endl
             << "(4) Sair do sistema" << endl;

        cin >> op;

        string n_conta;
        switch (op) {
            case 1:
                if (this->listaContas()) {
                    cout << "Digite o número da conta: ";
                    cin >> n_conta;
                    while (op = this->menuConta(n_conta) == 0){
                        cout << "Conta não encontrada" << endl
                        << "Digite o número da conta: " << endl;
                        cin >> n_conta;
                    }
                }
                break;

            case 2:
                this->listaContas();
                break;

            case 3:
                if (this->criarConta()){
                    cout << "Conta criada com sucesso" << endl
                    << "Deseja acessar sua nova conta? (S|N)" << endl;
                    cin >> acessar;
                    if(acessar=='s' || acessar=='S'){
                        op = this->menuConta(contas.back()->getNumero());
                    }
                }
                break;

            case 4:
                cout << "===================" << endl
                    << "Sessão encerrada" << endl
                    << "===================" << endl;
                return 0;

            default:
                cout << "Opção inválida" << endl << endl;

        }
    } while (op!=4);
    return 0;
}

int Agencia::menuConta(string n_conta){

    int opcao;
    int valor;
    int flag = 0;
    string destino;

    for (auto &conta : this->contas) {
        if (conta->getNumero()==n_conta) {
            flag = 1;
            do {
                cout << "Menu - Conta [" << conta->getNumero() << "]" << endl
                    << "(1) Saque" << endl
                    << "(2) Depósito" << endl
                    << "(3) Transferência" << endl
                    << "(4) Saldo" << endl
                    << "(5) Extrato" << endl
                    << "(6) Fechar minha conta" << endl
                    << "(7) Voltar ao menu principal" << endl
                    << "(8) Encerrar sessão" << endl;

                cin >> opcao;
                switch (opcao) {
                    case 1:
                        cout << "Digite o valor: ";
                        cin >> valor;
                        this->saque(n_conta, valor);
                        break;

                    case 2:
                        cout << "Digite o valor: ";
                        cin >> valor;
                        this->deposito(n_conta, valor);
                        break;

                    case 3:
                        cout << "Digite o valor: ";
                        cin >> valor;
                        cout << "Digite a conta destino:";
                        cin >> destino;
                        this->tranferencia(n_conta, destino, valor);
                        break;

                    case 4:
                        this->saldo(n_conta);
                        break;

                    case 5:
                        this->extrato(n_conta);
                        break;

                    case 6:
                        if (this->excluirConta(n_conta)){
                            cout << "Conta excluída com sucesso" << endl << endl;
                        } else{
                            cout << "Erro ao excluir conta" << endl;
                        }
                        return 1;
                    case 7:
                        return 1;
                    case 8:
                        return 4;
                    default:
                        cout << "Opção inválida" << endl << endl;
                }
            } while (opcao!=7);

            break;

        }

    }
    return flag;
}