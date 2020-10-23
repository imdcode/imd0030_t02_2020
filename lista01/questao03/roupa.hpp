#pragma once

#include "produto.hpp"

enum TipoSexo
{
	MASCULINO,
	FEMININO
};

enum TipoTamanho {
	PP,
	P,
	M,
	G,
	GG,
	XXG
};

class Roupa : public Produto
{
public:
	Roupa();
	Roupa(string codigo, string descricao, double preco, 
			string marca, TipoSexo sexo, TipoTamanho tamanho);
	~Roupa();
private:
	string marca;
	TipoSexo sexo;
	TipoTamanho tamanho;
public:
	// getters
	string getMarca();
	TipoSexo getSexo(); 
	TipoTamanho getTamanho();

	// setters
	void setMarca(string marca);
	void setSexo(TipoSexo sexo);
	void setTamanho(TipoTamanho tamanho);
private:
	ostream& print(ostream &o) const;
};

