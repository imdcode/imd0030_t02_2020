#include "formas.hpp"

#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	Poligono* r = new Retangulo(1, 2);
	Poligono* t = new Triangulo(3, 4);
	//Poligono* p = new Poligono(2, 1);
  
  	cout << "Área do retângulo: " << r->area() << endl;
  	cout << "Área do triângulo: " << t->area() << endl;
  	//cout << "Área do polígono: " << p->area() << endl;
	return 0;
}