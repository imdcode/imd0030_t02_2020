#ifndef _TURMA_
#define _TURMA_

#include "aluno.hpp"

#define CAPACIDADE_MAX 10 

class Turma {
private:
	string nome;
	string id;
	Aluno* alunos[CAPACIDADE_MAX];
	int matriculados = 0;
public:
	Turma ();
	Turma (string nome, string id);
	~Turma();
	string getNome();
	void setNome(string nome);
	string getId();
	void setId(string id);
	int getMatriculados();
	void addAluno(Aluno* novo);
	void remAluno(string nome);
	void listarAlunos();
};

#endif