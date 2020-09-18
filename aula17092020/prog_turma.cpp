#include <iostream>

#include "Turma.hpp"

using namespace std;

int main()
{
	Turma imd0030;
	imd0030.setNome("Linguagem de Programacao I");
	imd0030.setId("IMD0030");

	Aluno* maria = new Aluno();
	maria->setNome("Maria Antonietta");
	maria->setIdade(45);
	maria->setAltura(1.62);
	maria->setMatricula("121234");
	maria->setTelefone("+351 987654 3456");

	imd0030.addAluno(maria);

	Aluno* bob = new Aluno();
	bob->setNome("Bob Marley");
	bob->setIdade(25);
	bob->setAltura(1.75);
	bob->setMatricula("303033");
	bob->setTelefone("34567 8908");

	imd0030.addAluno(bob);

	Aluno* joao = new Aluno();
	joao->setNome("Joao Canabrava");
	joao->setIdade(42);
	joao->setAltura(1.80);
	joao->setMatricula("909080");
	joao->setTelefone("2345 6789");

	imd0030.addAluno(joao);

	cout << imd0030.getId() << " - " << imd0030.getMatriculados() 
			<< "/" << CAPACIDADE_MAX << endl;
	imd0030.listarAlunos(); 

	imd0030.remAluno("Faustão");

	cout << imd0030.getId() << " - " << imd0030.getMatriculados() 
			<< "/" << CAPACIDADE_MAX << endl;
	imd0030.listarAlunos();

	return 0;
}