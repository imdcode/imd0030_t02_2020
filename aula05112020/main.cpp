#include "agencia.hpp"

#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
	Agencia ag1("Banco do Brasil","Agencia Central","3400-9");

	ag1.criarConta();
	ag1.listarContas();

	ContaCorrente c1("1234-5","12345-6",0.00,tcNormal,400.00);

	cout << c1 << endl;

	Movimentacao* m1 = new Movimentacao("Pagamento de condomínio.",480.00,tmDebito);
	if (!c1.processarMovimentacao(m1))  {
		cout << "Operação inválida!" << endl;
	}
	cout << (*m1) << endl;
	cout << c1 << endl;

	Movimentacao* m2 = new Movimentacao("Recebimento de bolsa.",600.00,tmCredito);
	if (!c1.processarMovimentacao(m2))  {
		cout << "Operação inválida!" << endl;
	}
	cout << (*m2) << endl;
	cout << c1 << endl;

	Movimentacao* m3 = new Movimentacao("Pagamento de boleto.",780.00,tmDebito);
	if (!c1.processarMovimentacao(m3))  {
		cout << "Operação inválida!" << endl;
	}
	cout << (*m3) << endl;
	cout << c1 << endl;

	return 0;
}