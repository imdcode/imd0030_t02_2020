#include "jogo.hpp"

#include <iostream>

using std::cout;
using std::endl;

int Jogador::alvo = 50;

int main(int argc, char const *argv[])
{
	Jogo game;
	cout << "Grande jogo da Carreta Furacão" << endl;
	game.addJogador(new Jogador("Capitão América"));
	game.addJogador(new Jogador("Fofão"));
	game.addJogador(new Jogador("Mickey"));
	game.addJogador(new Jogador("Popeye"));
	game.run();
	return 0;
}