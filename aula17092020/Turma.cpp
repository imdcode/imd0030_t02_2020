#include "turma.hpp"

#include<iostream>

using namespace std;

Turma::Turma (){
	this->nome = "A definir";
	this->id = "IMD????";
}
Turma::Turma (string nome, string id):nome(nome),id(id){}
Turma::~Turma(){
	for (int i = 0; i < this->matriculados; ++i)
	{
		delete this->alunos[i];
	}
}
string 
Turma::getNome(){
	return this->nome;
}
void 
Turma::setNome(string nome){
	this->nome = nome;
}
string 
Turma::getId(){
	return this->id;
}
void 
Turma::setId(string id){
	this->id = id;
}
int 
Turma::getMatriculados(){
	return this->matriculados;
}
void 
Turma::listarAlunos(){
	for (int i = 0; i < this->matriculados; ++i)
	{
		cout << this->alunos[i]->getNome() << endl;
	}
}
void 
Turma::addAluno(Aluno* novo){
	if (this->matriculados < CAPACIDADE_MAX) {
		this->alunos[this->matriculados++] = novo;
	}
}
void 
Turma::remAluno(string nome){
	bool encontrou = false;
	for (int i = 0; i < this->matriculados; ++i)
	{
		if (alunos[i]->getNome() == nome) {
			Aluno* tmp = alunos[i];
			alunos[i] = alunos[i+1];
			alunos[i+1] = tmp;
			encontrou = true;
		}
	}
	if (encontrou) {
		delete alunos[this->matriculados--];
	}
}