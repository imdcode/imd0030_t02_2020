#include <iostream>
#include <memory>
#include <string>
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::shared_ptr;
using std::unique_ptr;
using std::weak_ptr;
using std::make_shared;
using std::make_unique;
using std::vector;

class Teste
{
public:
	Teste(string nome):nome(nome){ 
		cout << "Objeto " << this->nome
			<<" CRIADO no endereço " 
			<< this << "." << endl; 
	}
	Teste(Teste& copia){ 
		this->nome = copia.nome + "_cpy";
		cout << "Objeto " << this->nome 
			<< " COPIADO no endereço " 
			<< this << "." << endl; 
	}
	~Teste(){ 
		cout << "Objeto " << this->nome
			<< " REMOVIDO do endereço " 
			<< this << "." << endl;
	};
	string getNome() const { return this->nome; };
private:
	string nome;
};

void nadaAFazer(Teste) {}

void nadaAFazer2(Teste&) {}

void nadaAFazer3(Teste*) {}

void nadaAFazer4(shared_ptr<Teste> x) {
	cout << "nadaAFazer4: " << (*x).getNome() << endl;
}

void TesteVector()
{
    vector<unique_ptr<Teste>> conjunto;

    conjunto.push_back(make_unique<Teste>("U1"));
    conjunto.push_back(make_unique<Teste>("U2"));
    conjunto.push_back(make_unique<Teste>("U3"));
    conjunto.push_back(make_unique<Teste>("U4"));

    // Passe por referência, sempre que possível,
    // para evitar cópias.
    cout << "Percorrendo o vetor..." << endl;
    for (const auto& teste : conjunto)
    {
        cout << teste->getNome() << " utilizado." << endl; 
    }    
}

shared_ptr<Teste> TesteVector2()
{
    vector<shared_ptr<Teste>> conjunto;

    conjunto.push_back(make_shared<Teste>("S1"));
    conjunto.push_back(make_shared<Teste>("S2"));
    conjunto.push_back(make_shared<Teste>("S3"));
    conjunto.push_back(make_shared<Teste>("S4"));

    // Passe por referência, sempre que possível,
    // para evitar cópias.
    cout << "Percorrendo o vetor..." << endl;
    for (const auto& teste : conjunto)
    {
        cout << teste->getNome() << " utilizado." << endl;
        if (teste->getNome()=="S3") {
        	return teste;
        } 
    }   
    return nullptr; 
}

int main(int argc, char const *argv[])
{
	TesteVector();
	shared_ptr<Teste> c = TesteVector2();
	Teste* a = new Teste("a");
	shared_ptr<Teste> b = make_shared<Teste>("b");
	cout << "Chamando nadaAFazer..." << endl;
	nadaAFazer(*a);
	cout << "Chamando nadaAFazer2..." << endl;
	nadaAFazer2(*a);
	cout << "Chamando nadaAFazer3..." << endl;
	nadaAFazer3(a);
	cout << "Chamando nadaAFazer4..." << endl;
	nadaAFazer4(b);
	cout << "Chamando delete..." << endl;
	delete a;
	return 0;
}