#include "empresa.hpp"

#include <vector>
#include <string>

using std::vector;

class Questao01 {
public:
	Questao01();
	~Questao01();
	void listarEmpresas();
	bool adicionaEmpresa(Empresa* nova);
	bool removeEmpresa(string nome);
	void aumento();
	void addEmpresa();
	void remEmpresa();
	void listarFuncionariosEmExperiencia();
	void listarMediaDeFuncionariosPorEmpresa();
	void testar();
private:
	vector<Empresa*> empresas;
};



