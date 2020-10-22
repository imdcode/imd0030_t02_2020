#include "agencia.hpp"

#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{

	Agencia ag("2304-1","Agência Central","Banco Quebrado S/A");

	ContaCorrente* conta1 = new ContaCorrente("2304-1", "8900765-7", 600.00,contaNormal, 400.00);
	ag.adicionaConta(conta1);
	
	Movimentacao credito("Mais uma parcela.",600.00,tipoCredito);
	Movimentacao energia("Pagamento da conta de energia 10/2020.",135.90,tipoDebito);
	Movimentacao agua("Pagamento da conta de agua 10/2020.",67.50,tipoDebito);
	Movimentacao agua_atrasada("Pagamento da conta de agua 9/2020.",55.43,tipoDebito);
	
	conta1->processaMovimentacao(credito);
	conta1->processaMovimentacao(energia);
	conta1->processaMovimentacao(agua);
	conta1->processaMovimentacao(agua_atrasada);


	cout << conta1->getSaldo() << endl;

	ag.criarConta();
	ag.listaContas();

	return 0;
}