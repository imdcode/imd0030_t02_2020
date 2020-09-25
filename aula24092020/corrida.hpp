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
public:
	Corrida(string titulo);
	~Corrida();
	string getTitulo();
	int getTotalConcorrentes();
	void AddConcorrente(Sapo* novo);
	void RemConcorrente(string id);
	void start();
};

#endif