#include "questao01.hpp"

Questao01::Questao01(){
	this->empresas.clear();
}
Questao01::~Questao01(){
	for (auto &empresa : this->empresas) {
        delete empresa;
    }
}
void 
Questao01::listarEmpresas(){
	for (const auto &empresa : this->empresas) {
        cout << *empresa << endl;
    }
}
bool 
Questao01::adicionaEmpresa(Empresa* nova){
	this->empresas.push_back(nova);
	return true;
}
bool 
Questao01::removeEmpresa(string nome){
	return true;
}
void 
Questao01::aumento(){}
void 
Questao01::addEmpresa(){}
void 
Questao01::remEmpresa(){}
void 
Questao01::listarFuncionariosEmExperiencia(){

}
void 
Questao01::listarMediaDeFuncionariosPorEmpresa(){}
void 
Questao01::testar(){
	Empresa* vought = new Empresa("Vought International",
							"870001/23");
	vought->adicionaEmpregado(
			new Funcionario("The Homelander",250000.00,
							date(2,11,1980),date(26,7,2019)));
	vought->adicionaEmpregado(
			new Funcionario("Black Noir",200000.00,date(25,7,1985),
							date(26,7,2019)));
	vought->adicionaEmpregado(
			new Funcionario("Queen Mave",200000.00,
							date(18,4,1991),date(26,7,2019)));
	vought->adicionaEmpregado(
			new Funcionario("A-Train",150000.00,date(2,12,1995),
							date(26,7,2019)));
	vought->adicionaEmpregado(
			new Funcionario("The Deep",100000.00,date(15,9,1990),
							date(26,7,2019)));
	vought->adicionaEmpregado(
			new Funcionario("Starlight",100000.00,date(12,5,1999),
							date(26,7,2019)));
	vought->adicionaEmpregado(
			new Funcionario("Stormfront",150000.00,date(1,8,1950),
							date(4,9,2020)));

	this->adicionaEmpresa(vought);
	this->listarEmpresas();

	vought->listaEmpregados();
	
	vought->aplicarAumento(0.20);

	Funcionario* coitado = vought->removeEmpregado("The Deep");
	if (coitado != nullptr) {
		cout << "R.I.P. " << coitado->getNome() << endl;
		delete coitado;
	}
	vought->listarEmpregadosEmExperiencia(date(11,7,2020));

	Empresa* OTabajara = new Empresa("Organizações Tabajara","990001/44");

	OTabajara->listaEmpregados();

	cout << "Total de empresas: " << Empresa::getAtivas() << endl;
	cout << "Total de funcionarios: " << Funcionario::getAtivos() << endl;

	cout << "Media de funcionarios por empresa: " 
				<< Funcionario::getAtivos()/Empresa::getAtivas() << endl; 

}




