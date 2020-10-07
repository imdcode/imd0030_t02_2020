#include "veiculo.hpp"

Veiculo::Veiculo(){
	cout << "Veiculo " << this->modelo << " construído." << endl;
}
Veiculo::Veiculo (string cor, string modelo, string ano,
			string placa, string proprietario):
			cor(cor),modelo(modelo),ano(ano),
			placa(placa),proprietario(proprietario){
	cout << "Veiculo " << this->modelo << " construído." << endl;
}
Veiculo::~Veiculo(){
	cout << "Veiculo " << this->modelo << " destruido." << endl;
}
string 
Veiculo::getCor(){
	return this->cor;
}
string 
Veiculo::getModelo(){
	return this->modelo;
}
string 
Veiculo::getAno(){
	return this->ano;
}
string 
Veiculo::getPlaca(){
	return this->placa;
}
string 
Veiculo::getProprietario(){
	return this->proprietario;
}
void 
Veiculo::setCor(string cor){
	this->cor = cor;
}
void 
Veiculo::setModelo(string modelo){
	this->modelo = modelo;
}
void 
Veiculo::setAno(string ano){
	this->ano = ano;
}
void 
Veiculo::setPlaca(string placa){
	this->placa = placa;
}
void 
Veiculo::setProprietario(string proprietario){
	this->proprietario = proprietario;
}
void 
Veiculo::ligar(){
	cout << "O veículo foi ligado." << endl;
}
void 
Veiculo::andar(){
	cout << "O veículo andou." << endl;
}
void 
Veiculo::parar(){
	cout << "O veículo parou." << endl;
}
