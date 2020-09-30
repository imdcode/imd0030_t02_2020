#include "corrida.hpp"

Corrida::Corrida(string titulo, int distancia):titulo(titulo), 
		distancia(distancia),concorrentes(0){}
Corrida::~Corrida(){}
string 
Corrida::getTitulo(){
	return this->titulo;
}
int Corrida::getDistancia(){
	return this->distancia;
}
int 
Corrida::getTotalConcorrentes(){
	return this->concorrentes;
}
Sapo* Corrida::getVencedor(){
	return this->vencedor;
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
	
	do {
		for (int i = 0; i < this->concorrentes; ++i)
		{
			this->sapos[i]->pular();
			//cout << this->sapos[i]->getId() << " dist=" 
			//	<< this->sapos[i]->getDistancia() << " meta=" 
			//	<< Sapo::getDistanciaDaCorrida() << endl;
			if (this->sapos[i]->getDistancia()>this->distancia) {
				this->vencedor = sapos[i];
				fim = true;
				break;
			}
		}
	} while(!fim);
}
