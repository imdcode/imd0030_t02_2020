#include <iostream>

#include "Aluno.hpp"

using namespace std;

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