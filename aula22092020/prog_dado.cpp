#include <iostream> 
#include <cstdlib>

#include "dado.hpp"

int main(int argc, char const *argv[])
{
	if (argc == 2) {
		Dado meu_dado;
		for (int i=0;i<atoi(argv[1]);++i) {
			std::cout << meu_dado.jogar() << std::endl;
		} 	
	}
	return 0; 
}