#include "carro.hpp"

int main(int argc, char const *argv[])
{
	Carro c("vermelho","Toyota Corolla","2010",
			"ABC-1234","Wesley Safadao",22.50); 
	c.ligar();


	Veiculo* v = &c;

	cout << v->getPlaca() << endl;
	cout << v->getModelo() << endl;
	//cout << v->getVolumePortaMalas() << endl;
	v->ligar(); 
	
	Veiculo* v1 = new Veiculo;
	Carro* c1 = (Carro*)(v1); 
	c1->setModelo("Fiat Uno"); 
	c1->setPlaca("ABC-1234"); 
	c1->setVolumePortaMalas(22.50); 
	c1->ligar();

	delete c1;

	return 0;
}