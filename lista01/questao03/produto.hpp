#pragma once

#include <iostream>

using std::string;
using std::ostream;

class Produto
{
public:
	Produto();
	Produto(string codigo, string descricao, double preco);
	virtual ~Produto();
protected:
	string cod_barras;
	string descricao;
	double preco;		
public:
	// getters
	string getCodBarras();
	string getDescricao();
	double getPreco();
	// setters
	void setCodBarras(string codigo);
	void setDescricao(string descricao);
	void setPreco(double preco);
	//
	friend ostream& operator<< (ostream &o, Produto const &t);  
private:
	virtual ostream& print(ostream&) const = 0;
};

