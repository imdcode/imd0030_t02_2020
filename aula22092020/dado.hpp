#ifndef _DADO_H_ 
#define _DADO_H_

#include <random>

class Dado { 
private:
	int valor;
	std::random_device rd; 
	std::default_random_engine gen; 
	std::uniform_int_distribution<> dis;
public:
	Dado();
	int jogar();
	int getValor();
}; 

#endif