#include <iostream>

#include "Aluno.hpp"

using namespace std;

Aluno::Aluno(){
	this->nome = "Indigente";
}
/*
Aluno::Aluno(string nome, int idade, double altura, 
		string matricula, string telefone){
	this->nome = nome;
	this->idade = idade;
	this->altura = altura;
	this->matricula = matricula;
	this->telefone = telefone;
}
*/
Aluno::Aluno(string nome, int idade, double altura, 
		string matricula, string telefone):nome(nome),
		idade(idade),altura(altura), matricula(matricula),
		telefone(telefone){}
Aluno::~Aluno(){
	cout << this->nome << " está deixando essa existencia." << endl;
}
string 
Aluno::getNome(){
	return this->nome;
}
void 
Aluno::setNome(string nome){
	this->nome = nome;
}
int 
Aluno::getIdade(){
	return this->idade;
}
void 
Aluno::setIdade(int idade){
	this->idade = idade;
}
double 
Aluno::getAltura(){
	return this->altura;
}
void 
Aluno::setAltura(double altura){
	this->altura = altura;
}
string 
Aluno::getMatricula(){
	return this->matricula;
}
void 
Aluno::setMatricula(string matricula){
	this->matricula = matricula;
}
string 
Aluno::getTelefone(){
	return this->telefone;
}
void 
Aluno::setTelefone(string telefone){
	this->telefone = telefone;
}