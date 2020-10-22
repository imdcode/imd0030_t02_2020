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
	string getCodBarras() const;
	string getDescricao() const;
	double getPreco() const;
	// setters
	void setCodBarras(string codigo);
	void setDescricao(string descricao);
	void setPreco(double preco);
	
	double operator+ (const Produto &outro) const;
	double operator- (const Produto &outro) const; 
	double operator+ (const double &valor) const;
	double operator- (const double &valor) const;
	bool operator== (const Produto &outro) const;
	friend ostream& operator<< (ostream &o, Produto const &t);  
private:
	virtual ostream& print(ostream&) const = 0;
};

