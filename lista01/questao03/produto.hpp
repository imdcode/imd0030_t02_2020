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
	//Fruta a,b; // a.preco = 5.50 | b.preco = 3.25
	//a + b --> a.operator+(b) --> 8.75
	double operator- (const Produto &outro) const; 
	//a - b --> a.operator-(b) --> 2.25
	double operator+ (const double &valor) const;
	//a + 1.30 --> a.operator+(1.30) --> 6.80
	double operator- (const double &valor) const;
	bool operator== (const Produto &outro) const;
	friend ostream& operator<< (ostream &o, Produto const &t);  
private:
	virtual ostream& print(ostream&) const = 0;
};

