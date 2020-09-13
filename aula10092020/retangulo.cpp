#include <iostream>
#include "retangulo.hpp"

using std::cout;
using std::endl;

int Retangulo::getLargura() {
	return largura;
}

void Retangulo::setLargura(int largura_) {
	if (largura_ < 0) {
		cout << "O valor da largura deve ser maior ou igual a zero." << endl;
	} else {
		largura = largura_;
	}	
}

int Retangulo::getAltura() {
	return altura;
}
void Retangulo::setAltura(int altura_) {
	altura = altura_;
}

int Retangulo::area() {
	return altura*largura;
}

int Retangulo::perimetro() {
	return (2*altura + 2*largura);
}