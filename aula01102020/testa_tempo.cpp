#include "tempo.hpp"

#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	Tempo r(12, 30, 11); // 12h 30min 0s 
	Tempo t(1, 5, 20); // 1h 20min 0s

	cout << "Tempo r: " << r << endl;
	cout << "Tempo t: " << t << endl;

	//Tempo s = r + t; // Instanciar s como sendo a soma dos tempos r e t
	//Tempo s = r.somar(t);

	/*cout << s.getHoras() << ":"
		<< s.getMinutos() << ":"
		<< s.getSegundos() << endl;
	*/
	cout << (r+t) << endl;

	Tempo final; 

	cout << "Tempo final: ";
	cin >> final;
	cout << final << endl; 


	return 0;
}



