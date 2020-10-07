#ifndef _CARRO_
#define _CARRO_

#include "veiculo.hpp"

#include <iostream>

using namespace std;

class Carro : public Veiculo {
private:
    double volumePortaMalas;
public:
	Carro (string cor, string modelo, string ano,
			string placa, string proprietario,
			double volumePortaMalas);
	~Carro();
    double getVolumePortaMalas();
    void setVolumePortaMalas(double v);
    void ligar();
    void andar();
    void parar();
};

#endif