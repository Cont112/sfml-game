#pragma once 
#include "../Personagem.h"
#include "../Jogador.h"

#include <cmath>

#define RAIO_X 200.0f


namespace Entidades { 
    namespace Personagens{ 
            namespace Inimigos{ 
            class Inimigo : public Personagem{

                protected:
                    bool atira;
                    Jogador *jogador1;
                    int moveAleatorio;

                    void moveInimigo();
                    void atualizarMovimentoAleatorio();
                public:
                    Inimigo(const sf::Vector2f pos, const sf::Vector2f tam, const float vel,Jogador* jogador,const IDs ID, int dano);
                    ~Inimigo();

                    virtual void atualizar();
                    virtual void atacar();
                    void colisao(Entidade* other, sf::Vector2f ds =  sf::Vector2f(0.0f,0.0f));

                    
            };
}
}
}