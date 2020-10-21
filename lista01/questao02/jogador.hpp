#pragma once

#include <iostream>
#include "dado.hpp"

using std::string;

enum StatusJogador{ATIVO,PARADO,EXCLUIDO};

class Jogador
{
private:
	string nome;
	int pontos;

	StatusJogador status;

	static int alvo;

public:

	Jogador();
	Jogador(string nome);
	~Jogador();

	void Jogar(Dado &d1, Dado &d2);
	bool podeJogar();

	int getPontos();
	string getNome();
	StatusJogador getStatus();

	static int getAlvo();
	
};

