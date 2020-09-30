#ifndef _CORRIDA_
#define _CORRIDA_

#include "sapo.hpp"

#include<iostream>

#define MAX_SAPOS 3

using namespace std;

class Corrida {
private:
	string titulo;
	Sapo* sapos[MAX_SAPOS];
	int concorrentes;
	Sapo* vencedor;
public:
	Corrida(string titulo);
	~Corrida();
	string getTitulo();
	int getTotalConcorrentes();
	Sapo* getVencedor();
	void AddConcorrente(Sapo* novo);
	void RemConcorrente(string id);
	void start();
};

#endif