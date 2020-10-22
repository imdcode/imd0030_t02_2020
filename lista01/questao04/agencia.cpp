#include "agencia.hpp"

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

Agencia::Agencia(string nome, string numero, string banco):
			nome(nome),numero(numero),banco(banco){}
Agencia::~Agencia(){}
string 
Agencia::getNome() const{
	return this->nome;
}
string 
Agencia::getNumero() const{
	return this->numero;
}
string 
Agencia::getBanco() const{
	return this->banco;
}
int 
Agencia::getTotalContas() const{
	return this->contas.size();
}
bool 
Agencia::adicionaConta(ContaCorrente* nova){
	this->contas.push_back(nova);
	return true;
}
bool Agencia::criarConta(){
	string numero;
	double saldo;
	TipoConta tipo = contaNormal;
	double limite;
	char ctipo = 0;

	cout << "Numero: ";
	cin >> numero;
	cout << "Saldo: ";
	cin >> saldo;
	cout << "Tipo (N/E): ";
	cin >> ctipo;
	if (ctipo=='N') {
		tipo = contaNormal;
	} else if (ctipo=='E') {
		tipo = contaEspecial;
	}
	cout << "Limite: ";
	cin >> limite;
	return adicionaConta(new ContaCorrente(this->numero,numero,saldo,tipo,limite));
}
bool Agencia::excluirConta(){
	return true;
}
bool Agencia::saque(string numero_conta, double valor){
	return true;
}
bool Agencia::deposito(string numero_conta, double valor){
	return true;
}
bool Agencia::saldo(string numero_conta) const{
	return true;
}
bool Agencia::extrato(string numero_conta) const{
	return true;
}
bool Agencia::tranferencia(string conta_origem, string conta_destino, double valor){
	return true;
}
void 
Agencia::listaContas() const{
	for (auto& conta: this->contas)
	{
		cout << conta->getNumero() << endl;
	}
}