#include <iostream>

#include "Aluno.hpp"

using namespace std;

int main()
{
	Aluno novo;
	novo.setNome("Wesley Safadão");
	novo.setIdade(32);
	novo.setAltura(1.75);
	novo.setMatricula("12345");
	novo.setTelefone("(85) 8119-9366");

	Aluno* outro = new Aluno();
	outro->setNome("Marília Mendonça");
	outro->setIdade(25);
	outro->setAltura(1.68);
	outro->setMatricula("98765");
	//outro->setTelefone("(62) 9930-8908");
	outro->setTelefone(novo.getTelefone());

	cout << "Temos um novo aluno: " << novo.getNome() 
			<< " Tel: " << novo.getTelefone() << endl;
	cout << "Temos uma nova aluna: " << outro->getNome() 
			<< " Tel: " << outro->getTelefone() << endl;
	return 0;
}