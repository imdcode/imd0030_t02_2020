#pragma once

#include "contacorrente.hpp"

#include <vector>
#include <string>

using std::vector;
using std::string;

class Agencia {
public:
	Agencia(string banco, string nome, string numero);
	~Agencia();
	string getBanco() const;
	string getNome() const;
	string getNumero() const;
	vector<ContaCorrente*> getContas() const;
	bool criarConta();
	bool adicionarConta(ContaCorrente* nova);
	bool removerConta(string numero);
	bool saque(string numero, double valor);
	bool deposito(string numero, double valor);
	void imprimeSaldo(string numero);
	void imprimeExtrato(string numero);
	bool transferencia(string cc_origem, string cc_destino, 
			double valor);
	void listarContas();
private:
	string banco;
	string nome;
	string numero;
	vector<ContaCorrente*> contas;
};