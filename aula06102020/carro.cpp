#include "carro.hpp"

Carro::Carro (string cor, string modelo, string ano,
			string placa, string proprietario,
			double volumePortaMalas):
			Veiculo(cor,modelo,ano,placa,proprietario),
			volumePortaMalas(volumePortaMalas){
	cout << "Carro " << this->modelo << " construído." << endl;
}
Carro::~Carro(){
	cout << "Carro " << this->modelo << " destruido." << endl;
}
double 
Carro::getVolumePortaMalas(){
	return this->volumePortaMalas;
}
void 
Carro::setVolumePortaMalas(double v){
	this->volumePortaMalas = v;
}
void 
Carro::ligar(){
	cout << "O carro foi ligado." << endl;
}
void 
Carro::andar(){
	cout << "O carro andou." << endl;
}
void 
Carro::parar(){
	cout << "O carro parou." << endl;
}