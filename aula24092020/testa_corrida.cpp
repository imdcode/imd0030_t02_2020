#include "corrida.hpp"

#include<iostream>

using namespace std;

int Sapo::distanciaDaCorrida = 75;

int main(int argc, char const *argv[])
{
	Sapo* s1 = new Sapo("Senna",15);
	Sapo* s2 = new Sapo("Rubinho",6);
	Sapo* s3 = new Sapo("Massa",9);
	Sapo* s4 = new Sapo("Hamilton",12);
	//cout << s1->getId() << " max=" << s1->getMaxSalto() << " meta=" << Sapo::getDistanciaDaCorrida() << endl;
	//cout << s2->getId() << " max=" << s2->getMaxSalto() << " meta=" << Sapo::getDistanciaDaCorrida() << endl;
	//cout << s3->getId() << " max=" << s3->getMaxSalto() << " meta=" << Sapo::getDistanciaDaCorrida() << endl;
	//cout << s4->getId() << " max=" << s4->getMaxSalto() << " meta=" << Sapo::getDistanciaDaCorrida() << endl;
	Corrida gpbrasil("Grande Prêmio de Interlagos");
	gpbrasil.AddConcorrente(s1);
	gpbrasil.AddConcorrente(s2);
	gpbrasil.AddConcorrente(s3);
	gpbrasil.AddConcorrente(s4);

	gpbrasil.start();
	return 0;
}