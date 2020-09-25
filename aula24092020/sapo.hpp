#ifndef _SAPO_
#define _SAPO_

#include<iostream>
#include<random>

using namespace std;

//#define MAX_SALTO 10

class Sapo {
private:
	string id;
	int max_salto;
	int distancia;
	int pulos;
	std::random_device rd; 
	std::default_random_engine gen; 
	std::uniform_int_distribution<> dis;
	static int distanciaDaCorrida; 
public:
	Sapo(string id, int max_salto);
	~Sapo();
	static int getDistanciaDaCorrida();
	string getId();
	int getMaxSalto();
	int getDistancia();
	int getPulos();
	void pular();
};

#endif