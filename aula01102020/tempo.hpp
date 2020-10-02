#ifndef _TEMPO_
#define _TEMPO_

#include<iostream>

using namespace std;

class Tempo { 
private:
	short horas; 
	short minutos; 
	short segundos;
public:
	Tempo();
	Tempo(short h, short m, short s);
	short getHoras() const; 
	short getMinutos() const;
	short getSegundos() const;
	Tempo somar(Tempo &t);
	Tempo operator+(Tempo &t);
	friend ostream& operator<< (ostream &o, Tempo const t);
	friend istream& operator>> (istream &i, Tempo &t);
};

#endif




