#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
	double a, *p, *q;
	a= 3.14;
	cout << a << endl; // 3.14
	p = &a; // p --> a
	*p = 2.718;
	cout << a << endl; // 2.718
	a = 5; 
	cout << *p << endl; // p--> a
	p = nullptr; // p --> nullptr
	p = new double; 
	// p --> uma nova posição to tipo double
	*p = 20;
	q = p; // q --> x <--p
	cout << *p << endl; // 20
	cout << a << endl; // 5
	delete p; // q --> x p
	p = nullptr;
	cout << *p << endl;
	return 0;
}