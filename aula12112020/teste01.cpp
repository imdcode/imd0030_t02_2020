#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
	double a, *p, *q;
	a= 3.14;
	cout << a << endl;
	p = &a;
	*p = 2.718;
	cout << a << endl;
	a = 5;
	cout << *p << endl;
	p = nullptr;
	p = new double;
	*p = 20;
	q = p;
	cout << *p << endl;
	cout << a << endl;
	delete p;
	p = nullptr;
	cout << *p << endl;
	return 0;
}