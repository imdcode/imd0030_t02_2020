#ifndef _CORRIDA_
#define _CORRIDA_

#include "sapo.hpp"

#include<iostream>

#define MAX_SAPOS 4

using namespace std;

class Corrida {
private:
	string titulo;
	int distancia;
	Sapo* sapos[MAX_SAPOS];
	int concorrentes;
	Sapo* vencedor;
public:
	Corrida(string titulo, int distancia);
	~Corrida();
	string getTitulo();
	int getDistancia();
	int getTotalConcorrentes();
	Sapo* getVencedor();
	void AddConcorrente(Sapo* novo);
	void RemConcorrente(string id);
	void start();
};

#endif