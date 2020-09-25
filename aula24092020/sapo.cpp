#include "sapo.hpp"

Sapo::Sapo(string id, int max_salto):id(id),max_salto(max_salto),
			distancia(0),pulos(0),
			rd(),gen(rd()),dis(1,max_salto){}
Sapo::~Sapo(){}
string 
Sapo::getId(){
	return this->id;
}
int  
Sapo::getMaxSalto(){
	return this->max_salto;
}
int 
Sapo::getDistancia(){
	return this->distancia;
}
int 
Sapo::getDistanciaDaCorrida(){
	return distanciaDaCorrida;
}
int 
Sapo::getPulos(){
	return this->pulos;
}
void 
Sapo::pular(){
	this->pulos++;
	this->distancia += round(dis(gen));
}

