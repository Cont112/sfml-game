#include "../../../include/Entidades/Personagens/Jogador.h"
#include "../../../include/Gerenciadores/Gerenciador_Colisoes.h"
#define WIDTH 1280
#define HEIGHT 720

//MUDAR MOVIMENTO PARA SETAR VELOCIDADES 

namespace Entidades{ 
    namespace Personagens{ 
        Jogador::Jogador(const sf::Vector2f pos, const sf::Vector2f tam, const IDs ID): Personagem(pos,tam, VELOCIDADE_JOGADOR, ID), isJumping(false), invulneravel(false), dtAux(0.0f)
        {
            init();
        }

        Jogador::~Jogador()
        {
        }

        void Jogador::init()
        {
            pGrafico->createTexture(PATH_JOGADOR);
            setTextura(pGrafico->textureMap.at(PATH_JOGADOR));
            shape.setOrigin(sf::Vector2f(tam.x/2.0f,0.0f));
        }

        void Jogador::pular()
        {
            if(!isJumping){
                vel.y = -sqrt(2.0f * GRAVIDADE * TAMANHO_PULO);
                isJumping = true;
            }
        }

        void Jogador::podePular()
        {
            isJumping = false;
        }

        void Jogador::atualizar()
        {
            if(vida <= 0)
            {
                ativo = false;
            }

            if(ativo)
            {
                
                imprimir_se();
                atualizarPosicao();
            }

            if(invulneravel)
            {
                dtAux += dt;
                if(dtAux > 1.f)
                {
                    shape.setFillColor(sf::Color(0xFFFFFFFF));
                    invulneravel = false;
                    dtAux = 0.0f;
                }
            }



        }

        void Jogador::receberDano(int dano)
        {
            dtAux += dt;
            if(!invulneravel)
            {
                vida -= dano;
                shape.setFillColor(sf::Color(0xFF0000FF));
                invulneravel = true;
            }
        }

        void Jogador::colisao(Entidade* other, sf::Vector2f ds)
        {
            switch (other->getID())
            {
            case (IDs::esqueleto):
                receberDano(25);
                break;
            
            case (IDs::caixa):

                break;
            }
        }

    }
}
