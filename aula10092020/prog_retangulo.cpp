#include <iostream>
#include "retangulo.hpp"

//using namespace std;
using std::cout;
using std::endl;

int main()
{
	Retangulo x;
	x.setLargura(3);
	x.setAltura(4);
	cout << "Area: " << x.area() << endl;

	Retangulo* y = new Retangulo();
	y->setLargura(5);
	y->setAltura(5);
	cout << "Area: " << y->area() << endl;

	return 0;
}