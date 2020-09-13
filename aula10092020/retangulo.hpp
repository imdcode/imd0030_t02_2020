#ifndef _RETANGULO_
#define _RETANGULO_

class Retangulo {
public:
	// Atributos
	int largura;
	int altura;

	// Metodos de acesso
	int getLargura();
	void setLargura(int largura_);
	int getAltura();
	void setAltura(int altura_);
	// Metodos Gerais
	int area();
	int perimetro();
};

#endif