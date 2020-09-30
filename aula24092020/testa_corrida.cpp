#include "corrida.hpp"

#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	Sapo* s1 = new Sapo("Senna",15);
	Sapo* s2 = new Sapo("Rubinho",6);
	Sapo* s3 = new Sapo("Massa",9);
	Sapo* s4 = new Sapo("Hamilton",14);
	//cout << s1->getId() << " max=" << s1->getMaxSalto() << " meta=" << Sapo::getDistanciaDaCorrida() << endl;
	//cout << s2->getId() << " max=" << s2->getMaxSalto() << " meta=" << Sapo::getDistanciaDaCorrida() << endl;
	//cout << s3->getId() << " max=" << s3->getMaxSalto() << " meta=" << Sapo::getDistanciaDaCorrida() << endl;
	//cout << s4->getId() << " max=" << s4->getMaxSalto() << " meta=" << Sapo::getDistanciaDaCorrida() << endl;
	int distancia_total = 100;
	if (argc==2) {
		distancia_total = atoi(argv[1]);
	}

	Corrida gpbrasil("Grande Prêmio de Interlagos",distancia_total);
	gpbrasil.AddConcorrente(s1);
	gpbrasil.AddConcorrente(s2);
	gpbrasil.AddConcorrente(s3);
	gpbrasil.AddConcorrente(s4);

	gpbrasil.start();

	cout << gpbrasil.getVencedor()->getId() << " é o vencedor com "
			<< gpbrasil.getVencedor()->getPulos() 
			<< " pulos, alcançando uma distância de "
			<< gpbrasil.getVencedor()->getDistancia() << endl;
	cout << gpbrasil.getVencedor()->getId() << " é o cara!" << endl;
	return 0;
}




