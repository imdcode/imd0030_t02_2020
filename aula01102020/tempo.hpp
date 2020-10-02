#ifndef _TEMPO_
#define _TEMPO_

class Tempo { 
private:
	short horas; 
	short minutos; 
	short segundos;
public:
	Tempo(short h, short m, short s);
	short getHoras();
	short getMinutos();
	short getSegundos();
	Tempo somar(Tempo &t);
};

#endif