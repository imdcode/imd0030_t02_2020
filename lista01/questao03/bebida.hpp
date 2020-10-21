#pragma once

#include "produto.hpp"

class Bebida : public Produto
{
public:
	Bebida();
	Bebida(string codigo, string descricao, double preco, 
			double teor_alcoolico);
	~Bebida();
private:
	double teor_alcoolico;
public:
	// getters
	double getTeorAlcoolico();
	// setters
	void setTeorAlcoolico(double teor_alcoolico);
private:
	ostream& print(ostream &o) const;
};

