#include "empresa.hpp"

#include <iostream>

using std::cout;
using std::endl;

#ifdef DEBUG
#define Debug(x) std::cout << x
#else
#define Debug(x) 
#endif 

Empresa::Empresa(string nome, string cnpj):
			nome(nome),cnpj(cnpj){
	this->empregados.clear();
	ativas++;
	Debug("A empresa " << this->nome << " foi criada." << endl);
}
Empresa::Empresa(const Empresa &copia){
	this->nome = copia.nome;
	this->cnpj = copia.cnpj;
	//BUG: this->empregados = copia.empregados;
	ativas++;
	Debug("A empresa " << this->nome << " foi criada via cópia." << endl);
}
Empresa::~Empresa(){
	for (auto &empregado : this->empregados) {
        delete empregado;
    }
    ativas--;
	Debug("A empresa " << this->nome << " foi removida da memória." << endl);
}
string 
Empresa::getNome() const {
	return this->nome;
}
string 
Empresa::getCnpj() const {
	return this->cnpj;
}
Funcionario* 
Empresa::adicionaEmpregado(Funcionario *novo){
	this->empregados.push_back(novo);
	return novo;
}
Funcionario* 
Empresa::removeEmpregado(string nome){
	int index = 0;
	//vector<Funcionario*>::iterator 
	//	pos = this->empregados.begin();
	auto pos = this->empregados.begin();
	Funcionario* removido = nullptr; 
	for (const auto &empregado : this->empregados) {
        if (empregado->getNome()==nome) {
        	removido = empregado;
        	this->empregados.erase(pos+index);
        	break;
        }
        index++;
    }
	return removido;
}
void 
Empresa::listaEmpregados(){
	for (const auto &empregado : this->empregados) {
        cout << *empregado << endl;
    }
}
void 
Empresa::listarEmpregadosEmExperiencia(date referencia){
	for (const auto &empregado : this->empregados) {
		if (empregado->getAdmissao()>referencia) {
			cout << *empregado << endl;
		}
    }
}
int 
Empresa::aplicarAumento(double percentual){
	for (Funcionario* &empregado : this->empregados) {
        empregado->setSalario(empregado->getSalario()
        					*(percentual+1));
    }
    return this->empregados.size();
}
int 
Empresa::getAtivas(){
	return ativas;
}
std::ostream& operator<< (std::ostream &o, Empresa const e) { 
	o << e.nome << " - " << e.cnpj << " [" << e.empregados.size() << " funcionários]";
	return o;
}


