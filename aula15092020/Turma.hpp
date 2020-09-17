#ifndef _TURMA_
#define _TURMA_

#include "Aluno.hpp"

#define CAPACIDADE_MAX 10 

class Turma {
private:
	string nome;
	string id;
	Aluno* alunos[CAPACIDADE_MAX];
	int matriculados = 0;
public:
	string getNome();
	void setNome(string nome);
	string getId();
	void setId(string id);
	void addAluno(Aluno* novo);
	void remAluno(string nome);
};

#endif