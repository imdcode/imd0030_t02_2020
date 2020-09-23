#include <iostream>

#include "turma.hpp"

using namespace std;

int main()
{
	Turma imd0030("Linguagem de Programacao I","IMD0030");

	Aluno* maria = new Aluno("Maria Antonietta",45,1.62,
						"121234","+351 987654 3456");

	imd0030.addAluno(maria);

	Aluno* bob = new Aluno("Bob Marley",25,1.75,
					"303033","34567 8908");

	imd0030.addAluno(bob);

	Aluno* joao = new Aluno("Joao Canabrava",42,1.80,
					"909080","2345 6789");

	imd0030.addAluno(joao);

	cout << imd0030.getId() << " - " << imd0030.getMatriculados() 
			<< "/" << CAPACIDADE_MAX << endl;
	imd0030.listarAlunos(); 

	imd0030.remAluno("Bob Marley");

	cout << imd0030.getId() << " - " << imd0030.getMatriculados() 
			<< "/" << CAPACIDADE_MAX << endl;
	imd0030.listarAlunos();

	return 0;
}