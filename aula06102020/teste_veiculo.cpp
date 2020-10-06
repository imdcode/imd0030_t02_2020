#include "carro.hpp"

int main(int argc, char const *argv[])
{
	Carro c;
	c.setModelo("Toyota Corolla"); 
	c.setPlaca("ABC-1234"); 
	c.setVolumePortaMalas(22.50); 
	c.ligar();

	Veiculo* v = &c;

	cout << v->getPlaca() << endl;
	cout << v->getModelo() << endl;
	v->ligar(); 
	//cout << v->getVolumePortaMalas() << endl;

	Veiculo* v1 = new Veiculo;
	Carro* c1 = (Carro*)(v1); 
	c1->setModelo("Toyota Corolla"); 
	c1->setPlaca("ABC-1234"); 
	c1->setVolumePortaMalas(22.50); 
	c1->ligar();

	return 0;
}