#pragma once

#include "produto.hpp"

class Fruta : public Produto
{
public:
	Fruta();
	Fruta(string codigo, string descricao, double preco, 
			string data_lote, string validade);
	~Fruta();
private:
	string data_lote;
	string validade;
public:
	// getters
	string getDataLote() const;
	string getValidade() const;
	// setters
	void setDataLote(string data_lote);
	void setValidade(string validade);
private:
	ostream& print(ostream &o) const;
};

