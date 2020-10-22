#include <iostream>

#include "jogador.hpp"

Jogador::Jogador():nome("None"),pontos(0),status(ATIVO){}
	
Jogador::Jogador(string nome):nome(nome),pontos(0),status(ATIVO){}

Jogador::~Jogador(){}

int  
Jogador::Jogar(Dado &d1, Dado &d2){
	int jogada = d1.jogar()+d2.jogar();
	this->pontos+=jogada;
	if (this->pontos> alvo){
		this->status=EXCLUIDO;	
	}
	return jogada;
}

int 
Jogador::getPontos() const{
	return this->pontos;
}

string 
Jogador::getNome() const{
	return this->nome;
}

StatusJogador 
Jogador::getStatus() const{
	return this->status;
}

bool 
Jogador::podeJogar(){
	if (this->status==EXCLUIDO){
		return false;
	}
	char opcao;
	do{
		std::cout << this->nome << "(" << this->pontos << ")" 
				<< ", deseja jogar nesta rodada? (S/N): ";
		std::cin >> opcao;
		std::cin.ignore();
	} while (opcao!='S' && opcao!='s' && opcao!='N' && opcao!='n');
	if (opcao=='S' || opcao=='s'){
		this->status=ATIVO;
		return true;
	}
	this->status=PARADO;
	return false;
}

int 
Jogador::getAlvo(){
	return alvo;
}
