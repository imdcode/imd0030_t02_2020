#pragma once

#include "date.hpp"

#include <string>

using std::string;

class Funcionario {
public:
	Funcionario(string nome, double salario, 
			date nascimento, date admissao);
	Funcionario(const Funcionario &copia);
	~Funcionario();
	string getNome() const;
	double getSalario() const;
	date getAdmissao() const;
	date getNascimento() const;
	void setSalario(double salario);

	static int getAtivos();

	friend std::ostream& operator<< (std::ostream &o, Funcionario const f);

	bool operator==(const Funcionario& outro) const;
	// Nota: poderia ser implementado como uma função esterna:
	// friend bool operator==(const Funcionario & lhs, const Funcionario & rhs);
private:
	string nome;
	double salario;
	date nascimento;
	date admissao;

	static int ativos;
};






