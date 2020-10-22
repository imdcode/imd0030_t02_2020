#include "contacorrente.hpp"

ContaCorrente::ContaCorrente(string agencia, string numero, double saldo,
				TipoConta tipo, double limite):
				agencia(agencia),numero(numero),saldo(saldo),
				tipo(tipo),limite(limite){}
ContaCorrente::~ContaCorrente(){}
string 
ContaCorrente::getAgencia() const{
	return this->agencia;
}
string 
ContaCorrente::getNumero() const{
	return this->numero;
}
double 
ContaCorrente::getSaldo() const{
	return this->saldo;
}
TipoConta 
ContaCorrente::getTipoConta() const{
	return this->tipo;
}
double ContaCorrente::getLimite() const{
	return this->limite;
}
bool 
ContaCorrente::processaMovimentacao(Movimentacao& transacao){
	if (transacao.getTipo()==tipoCredito) {
		this->saldo += transacao.getValor();
	} else if (transacao.getTipo()==tipoDebito) {
		this->saldo -= transacao.getValor();
	}
	return true;
}
void 
ContaCorrente::mostraHistorico(){

}