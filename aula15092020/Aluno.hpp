#ifndef _ALUNO_
#define _ALUNO_

#include <iostream>

using namespace std;

class Aluno {
private:
	string nome;
	int idade;
	double altura;
	string matricula;
	string telefone;
public:
	string getNome();
	void setNome(string nome);
	int getIdade();
	void setIdade(int idade);
	double getAltura();
	void setAltura(double altura);
	string getMatricula();
	void setMatricula(string matricula);
	string getTelefone();
	void setTelefone(string telefone);
};

#endif