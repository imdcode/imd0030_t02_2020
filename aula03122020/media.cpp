#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using std::stringstream;
using std::ifstream;
using std::ofstream;
using std::string;
using std::cout;
using std::endl;
using std::ios;
using std::vector;
using std::fixed;
using std::setprecision;
using std::ostream;
using std::istream;

class Aluno
{
public:
	Aluno(string nome, double nota1, double nota2, double nota3):
		nome(nome), nota1(nota1), nota2(nota2), nota3(nota3) {}
	Aluno() {}
	~Aluno() {}
	string getNome() const {
		return this->nome;
	}
	double getNota1() const {
		return this->nota1;
	}
	double getNota2() const {
		return this->nota2;
	}
	double getNota3() const {
		return this->nota3;
	}
	double getMedia() const {
		return (this->nota1+this->nota2+this->nota3)/3;
	}
	string getStatus() const {
		double media = this->getMedia();
		if (media >= 7.0) {
			return "Aprovado";
		}
		return "Reprovado";
	}
	friend ostream& operator<< (ostream &o, Aluno const aluno) {
		o << aluno.nome << " " << fixed << setprecision(1) << aluno.getMedia() << " " << aluno.getStatus();
		return o;
	}
	friend istream& operator>> (istream &i, Aluno aluno) {
		i >> aluno.nome >> aluno.nota1 >> aluno.nota2 >> aluno.nota3;
		return i;
	}
private:
	string nome;
	double nota1;
	double nota2;
	double nota3;
};

int main(int argc, char const *argv[])
{
	ifstream arqDados("media.dat");
	ofstream arqMediasFinais("medias_finais.dat");
	string linha;
	string palavra;

	while(getline(arqDados,linha)) {
		//cout << linha;
		// linha = "Antonio Silva;10.0;9.0;8.0"
		// quebrando a linha 
        stringstream s(linha);
        vector <string> tokens; 
        while (getline(s, palavra, ';')) {
        	tokens.push_back(palavra); 
        	// tokens = ["Antonio Silva" "10.0" "9.0" "8.0"]
        }
        if (tokens.size() == 4) { // tokens.at(0) == tokens[0]
        	Aluno lido(tokens.at(0), stod(tokens.at(1)), 
        		stod(tokens.at(2)), stod(tokens.at(3)));
        	cout << lido << endl;
        	arqMediasFinais << lido << endl;
        }
	}
	return 0;
}