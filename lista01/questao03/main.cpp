#include <iostream>
#include "fruta.hpp"
#include "bebida.hpp"
#include "roupa.hpp"

using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
	Produto* lista[20]; //upcasting
	// Bebidas
	lista[0] = new Bebida("002002003-01","Whisky Natu Nobles",32.50,18);
	lista[1] = new Bebida("002002003-02","Cerv Rinikin pek c/6",17.50,5);
	lista[2] = new Bebida("002002003-03","Verdarula",22.00,12);
	lista[3] = new Bebida("002002003-05","Vodi K",37.00,22);
	// Frutas
	lista[4] = new Fruta("001002003-45","Maca verde",8.70,"01/10/2017","01/02/2018");
	lista[5] = new Fruta("001002004-44","Laranja",4.75,"23/09/2017","23/11/2017");
	lista[6] = new Fruta("001002005-11","Limao verde",2.30,"01/10/2017","01/01/2018");
	lista[7] = new Fruta("001002006-11","Melancia",2.30,"01/10/2017","01/11/2017");
	lista[8] = new Fruta("001002007-11","Melao",2.30,"10/10/2017","10/11/2017");
	lista[9] = new Fruta("001002003-21","Mamao Papaia",2.30,"03/01/2017","23/01/2017");
	lista[10] = new Fruta("001002003-21","Mamao Normal",1.98,"21/11/2016","11/12/2016");
	lista[11] = new Fruta("001002000-03","Morango",9.35,"06/09/2017","26/09/2017");
	//Roupas
	lista[12] = new Roupa("003002005-10","Camisa Nique Futebol",39.00,"Naique",FEMININO,P);
	lista[13] = new Roupa("003002005-11","Camisa Nique Futebol",39.00,"Naique",MASCULINO,M);
	lista[14] = new Roupa("003002005-21","Camisa Nique Futebol",39.00,"Naique",MASCULINO,G);
	lista[15] = new Roupa("003002005-22","Camisa Nique Futebol",39.00,"Naique",MASCULINO,GG);
	lista[16] = new Roupa("003002005-10","Jaketa Xulapa",42.30,"Xulapitas",FEMININO,M);
	lista[17] = new Roupa("003002005-30","Calca Jins",144.50,"Rangler",FEMININO,M);

	for (int i = 0; i < 18; ++i)
	{
		cout << *lista[i] << endl;
	}

	cout << "Valor total: " << (*lista[16] + *lista[15]) << endl;
	cout << "Camisa: " << *lista[15] + 50.55 << endl;

	// Range-based for loop - C++11
	double total = 0;
	for (auto& prod: lista)
	{
		if (prod){
			total = *prod + total;		
		}
	}
	cout << "Total: " << total << endl;
	return 0;
}