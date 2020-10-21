#pragma once

#include "funcionario.hpp"

#include <string>
#include <vector>

using std::string;
using std::vector;

class Empresa {
public:
	Empresa(string nome, string cnpj);
	Empresa(const Empresa &copia);
	~Empresa();
	string getNome() const;
	string getCnpj() const;
	Funcionario* adicionaEmpregado(Funcionario* novo);
	Funcionario* removeEmpregado(string nome);
	void listaEmpregados();
	void listarEmpregadosEmExperiencia(date referencia);
	int aplicarAumento(double percentual);
	static int getAtivas();

	friend std::ostream& operator<< (std::ostream &o, Empresa const e);
private:
	string nome;
	string cnpj;
	vector<Funcionario*> empregados;
	static int ativas;
};



