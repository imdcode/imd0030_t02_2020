#include "tempo.hpp"

#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	Tempo r(12, 30, 0); // 12h 30min 0s 
	Tempo t(1, 20, 0); // 1h 20min 0s

	//Tempo s = r + t;
	Tempo s = r.somar(t);
	
	cout << s.getHoras() << ":"
		<< s.getMinutos() << ":"
		<< s.getSegundos() << endl;

	return 0;
}