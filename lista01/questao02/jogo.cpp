#include "jogo.hpp"

Jogo::Jogo():total_jogadores(0), rodadas(0){}

Jogo::~Jogo(){}

void 
Jogo::novaRodada(){
	this->rodadas++;
	std::cout << "------------------------------------" << std::endl;
	std::cout << "RODADA #" << this->rodadas << std::endl;
	std::cout << "------------------------------------" << std::endl;
	for (int i = 0; i < this->total_jogadores; ++i)
	{
		// Caso seja o unico jogador no jogo, ja o declara vencedor
		if (this->jogadores[i]->getStatus()!=EXCLUIDO 
				&& totalEmJogo()==1){
			this->vencedor = this->jogadores[i];
			break;
		}
		if (this->jogadores[i]->podeJogar()){
			int jogada = this->jogadores[i]->Jogar(this->dado1, this->dado2);
			if (this->jogadores[i]->getStatus()==EXCLUIDO) {
				std::cout << this->jogadores[i]->getNome() << " pontuou: " << jogada 
						<< " e estourou os pontos (" << this->jogadores[i]->getPontos() << ") e foi EXCLUIDO." 
						<< std::endl;
			} else {
				std::cout << this->jogadores[i]->getNome() << " pontuou: " << jogada 
						<< " | total: " << this->jogadores[i]->getPontos() << std::endl;
			}
			
			// Caso o jogado tenha alcancado o alvo, ja o declara vencedor
			if (this->jogadores[i]->getPontos()==Jogador::getAlvo()){
				this->vencedor = this->jogadores[i];
				break;
			}
		}
	}
	std::cout << "------------------------------------" << std::endl;
}
	
void 
Jogo::run(){
	while (this->vencedor==nullptr 
			&& totalEmJogo()>1 
			&& getAtivos()>0){
		novaRodada();
	}
	// Caso exista mais de um jogador em jogo, mas todos decidiram parar na mesma rodada
	int maior=0;
	if (this->vencedor==nullptr){
		for (int i = 0; i < this->total_jogadores; ++i){
			if (this->jogadores[i]->getStatus()!=EXCLUIDO 
					&& this->jogadores[i]->getPontos()>maior){
				this->vencedor = this->jogadores[i];
				maior = this->jogadores[i]->getPontos();
			}
		}
	}
	mostrarResultado();
}

void 
Jogo::addJogador(Jogador * novo){
	if (this->total_jogadores<MAX_JOGADORES){
		this->jogadores[this->total_jogadores++]=novo;
	}
}

int 
Jogo::getAtivos(){
	int ativos=0;
	for (int i = 0; i < this->total_jogadores; ++i)
	{
		if (this->jogadores[i]->getStatus()==ATIVO){
			ativos++;
		}
	}
	return ativos;
}

int 
Jogo::totalEmJogo(){
	int emjogo=0;
	for (int i = 0; i < this->total_jogadores; ++i)
	{
		if (this->jogadores[i]->getStatus()==ATIVO || 
			this->jogadores[i]->getStatus()==PARADO){
			emjogo++;
		}
	}
	return emjogo;
}

void
Jogo::mostrarResultado(){
	std::cout << "====================================" << std::endl;
	std::cout << "          RESULTADO DO JOGO " << std::endl;
	std::cout << "------------------------------------" << std::endl;
	for (int i = 0; i < this->total_jogadores; ++i)
	{
		std::cout << this->jogadores[i]->getNome() << " --- " 
			<< this->jogadores[i]->getPontos() << " pontos.";
		if (this->jogadores[i]==this->vencedor){
			std::cout << " ** VENCEDOR ** ";
		}
		if (this->jogadores[i]->getStatus()==EXCLUIDO){
			std::cout << " >> EXCLUIDO << ";	
		}
		std::cout << std::endl;		
	}
	std::cout << "------------------------------------" << std::endl;
}
