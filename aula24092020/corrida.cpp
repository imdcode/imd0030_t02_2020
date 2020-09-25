#include "corrida.hpp"

Corrida::Corrida(string titulo):titulo(titulo),concorrentes(0){}
Corrida::~Corrida(){}
string 
Corrida::getTitulo(){
	return this->titulo;
}
int 
Corrida::getTotalConcorrentes(){
	return this->concorrentes;
}
void 
Corrida::AddConcorrente(Sapo* novo){
	if (this->concorrentes<MAX_SAPOS) {
		this->sapos[this->concorrentes++] = novo;
	} else {
		cout << "Corrida lotada. Sapo " << novo->getId() 
				<< " ficou de fora." << endl; 
	}
}
void 
Corrida::RemConcorrente(string id){
	// TODO
}
void Corrida::start(){
	bool fim = false;

	while(!fim) {
		for (int i = 0; i < this->concorrentes; ++i)
		{
			this->sapos[i]->pular();
			cout << this->sapos[i]->getId() << " dist=" 
				<< this->sapos[i]->getDistancia() << " meta=" 
				<< Sapo::getDistanciaDaCorrida() << endl;
			if (this->sapos[i]->getDistancia()>Sapo::getDistanciaDaCorrida()) {
				fim = true;
			}
		}
	}
}
