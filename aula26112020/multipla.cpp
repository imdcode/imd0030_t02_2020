#include <iostream>
#include <vector>
#include <memory>

using namespace std;
enum tpAnimal
{
	anfibioExotico,
	anfibioNativo,
	mamiferoExotico,
	mamiferoNativo //...
};

class animal
{
public:
	animal(int attrA, tpAnimal tipo):
		attrA(attrA), tipo(tipo) {};
	virtual ~animal(){};
	int getAttrA() { return this->attrA; }
	void setAttrA(int attrA) { this->attrA = attrA; }
	tpAnimal getTipo() { return this->tipo; }
protected:
	int attrA;
	tpAnimal tipo;
};

class anfibio: public animal
{
public:
	anfibio(int attrA, tpAnimal tipo, int attrB):
		animal(attrA, tipo),attrB(attrB){};
	virtual ~anfibio(){};
	int getAttrB() { return this->attrB; }
	void setAttrB(int attrB) { this->attrB = attrB; }
protected:
	int attrB;	
};

class exotico
{
public:
	exotico(int attrC):
		attrC(attrC){};
	virtual ~exotico(){};
	int getAttrC() { return this->attrC; }
	void setAttrC(int attrC) { this->attrC = attrC; }
protected:
	int attrC;
};

class anfibioexotico: public anfibio, public exotico
{
public:
	anfibioexotico(int attrA,int attrB, int attrC, int attrD):
		anfibio(attrA, anfibioExotico, attrB),
		exotico(attrC),
		attrD(attrD){};
	virtual ~anfibioexotico(){};
	int getAttrD() { return this->attrD; }
	void setAttrD(int attrD) { this->attrD = attrD; }
protected:
	int attrD;
};

int main(int argc, char const *argv[])
{
	// Declara um vetor de animais
	vector<shared_ptr<animal>> animais;
	// Upcast: insere um anfibioexotico no vetor de animais
	animais.push_back(make_shared<anfibioexotico>(1,2,3,4)); 
	// Downcast usando pronteiros inteligentes
	// Uso do casting dinâmico de ponteiros inteligentes!!! 
	shared_ptr<anfibioexotico> aexZero =
		dynamic_pointer_cast<anfibioexotico>(animais[0]);
	// Agora é possível alterar dados das classes derivadas
	aexZero->setAttrB(9);
	aexZero->setAttrD(8);
	// Percorre a lista de animais
	for (auto& bicho : animais)
	{
		if (bicho->getTipo()==anfibioExotico) {
			// Faz o downcast
			shared_ptr<anfibioexotico> aex = 
				dynamic_pointer_cast<anfibioexotico>(bicho);
			// Imprime os dados gerais de um anfibioexotico
			string tipoStr = "";
			if (bicho->getTipo()==anfibioExotico) {
				tipoStr = "Anfibio exótico";
			}
			cout << "Esse animal é um " << tipoStr << " : "
				<< aex->getAttrA()
				<< " - " << aex->getAttrB()
				<< " - " << aex->getAttrC()
				<< " - " << aex->getAttrD() << endl;
		}
		
	}

	return 0;
}