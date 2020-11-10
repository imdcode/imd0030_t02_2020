#pragma once

#include "contacorrente.hpp"
#include "contapoupanca.hpp"

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
	vector<Conta*> getContas() const;
	
	/** Métodos criados para ler dados do usuário.
	*  	Esses métodos invocam os métodos internos
	*	que irão efetivar as operações. 
	**/
	void criarConta(); // Interface com o usuário
	void removeConta(); // Interface com o usuário
	void saque(); // Interface com o usuário
	void deposito(); // Interface com o usuário
	void saldo(); // Interface com o usuário
	void extrato(); // Interface com o usuário
	void transferencia(); // Interface com o usuário
	void listarContas();

	/*
	 * Métodos internos para realizar as operações.
	 */
	bool adicionarConta(Conta* nova);
	Conta* removerConta(string numero);
	bool saque(string numero, double valor);
	bool deposito(string numero, double valor);
	void imprimeSaldo(string numero);
	void imprimeExtrato(string numero);
	bool transferencia(string cc_origem, string cc_destino, 
			double valor);
	bool atualizarPoupancas();
	
private:
	/**
	 * Método de busca de uma Conta Corrente pelo número.
	 * Usado apenas internamente e, por isso, privado.
	 */
	Conta* findConta(string numero);
	double leValor(string str_prompt);
	string leNumeroDaConta(string str_prompt);
	bool numeroValido(string numero);
	void printTitle(string title, int largura);

private:
	string banco;
	string nome;
	string numero;
	vector<Conta*> contas;
};