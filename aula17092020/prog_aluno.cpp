#include <iostream>

#include "aluno.hpp"

using namespace std;

int main()
{
	Aluno novo("Wesley Safadão",32,1.75,"12345","(85) 8119-9366");

	Aluno* outro = new Aluno("Marília Mendonça",25,1.68,
			"98765",novo.getTelefone());

	cout << "Temos um novo aluno: " << novo.getNome() 
			<< " Tel: " << novo.getTelefone() << endl;
	cout << "Temos uma nova aluna: " << outro->getNome() 
			<< " Tel: " << outro->getTelefone() << endl;
	
	delete outro;

	return 0;
}