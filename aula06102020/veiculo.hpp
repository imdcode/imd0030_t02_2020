#ifndef _VEICULO_
#define _VEICULO_

#include<iostream>

using namespace std;

class Veiculo { 
protected:
    string cor;
    string modelo;
    string ano;
    string placa;
    string proprietario;
public:
	Veiculo ();
	Veiculo (string cor, string modelo, string ano,
			string placa, string proprietario);
	~Veiculo();
	string getCor();
	string getModelo();
	string getAno();
	string getPlaca();
	string getProprietario();

	void setCor(string cor);
	void setModelo(string modelo);
	void setAno(string ano);
	void setPlaca(string placa);
	void setProprietario(string proprietario);

    void ligar();
    void andar();
    void parar();
};

#endif