#include "funcionario.hpp"

#include <iostream>
#include <iomanip>
#include <cassert>

using std::cout;
using std::endl;

#ifdef DEBUG
#define Debug(x) std::cout << x
#else
#define Debug(x) 
#endif 

Funcionario::Funcionario(string nome, double salario, 
					date nascimento, date admissao):
					nome(nome), salario(salario), 
					nascimento(nascimento), admissao(admissao){
	ativos++;
	Debug(this->nome << " foi criado.[" << this << "]" << endl);
}
Funcionario::Funcionario(const Funcionario &copia){
	this->nome = copia.nome;
	this->salario = copia.salario;
	this->admissao = copia.admissao;
	ativos++;
	Debug(this->nome << " foi criado via copia.[" << this << "]" << endl);
}
Funcionario::~Funcionario(){
	ativos--;
	Debug(this->nome << " foi removido da memória.[" << this << "]" << endl);
}
string 
Funcionario::getNome() const {
	return this->nome;
}
double 
Funcionario::getSalario() const {
	return this->salario;
}
date 
Funcionario::getAdmissao() const {
	return this->admissao;
}
date 
Funcionario::getNascimento() const {
	return this->nascimento;
}
void 
Funcionario::setSalario(double salario){
	assert(salario>0);
	this->salario = salario;
}
std::ostream& operator<< (std::ostream &o, Funcionario const f) { 
	o << f.nome << " - " << fixed << setprecision(2) << f.salario << " - " << f.admissao;
	return o;
}
int 
Funcionario::getAtivos(){
	return ativos;
}
bool 
Funcionario::operator==(const Funcionario& outro) const {
	return this->nome == outro.getNome();
}




