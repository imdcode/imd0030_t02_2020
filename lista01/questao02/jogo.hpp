#pragma once

#include <iostream>

#include "jogador.hpp"

#define MAX_JOGADORES 10

class Jogo
{
private:
	Jogador * jogadores[MAX_JOGADORES];
	int total_jogadores;
	Jogador * vencedor = nullptr;
	int rodadas;
	Dado dado1;
	Dado dado2;
public:
	Jogo();
	~Jogo();

	void novaRodada();
	int totalEmJogo();
	void run();
	void addJogador(Jogador * novo);

	int getAtivos();
	void mostrarResultado();
	
};
