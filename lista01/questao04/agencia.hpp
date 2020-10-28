#pragma once

#include "contacorrente.hpp"

#include <vector>
#include <string>

using std::vector;
using std::string;

class Agencia
{
public:
	Agencia(string nome, string numero, string banco);
	~Agencia();
	string getNome() const;
	string getNumero() const;
	string getBanco() const;
	int getTotalContas() const;
	bool adicionaConta(ContaCorrente* nova);
	bool criarConta();
	bool excluirConta();
	bool saque(string numero_conta, double valor);
	bool deposito(string numero_conta, double valor);
	bool saldo(string numero_conta) const;
	bool extrato(string numero_conta) const;
	bool tranferencia(string conta_origem, string conta_destino, 
					double valor);
	void listaContas() const;
private:
	string nome;
	string numero;
	string banco;
	vector<ContaCorrente*> contas;
};