#include "carro.hpp"

//Carro::Carro (volumePortaMalas(volumePortaMalas){}
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