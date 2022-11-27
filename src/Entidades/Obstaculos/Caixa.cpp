#include "../../../include/Entidades/Obstaculos/Caixa.h"

namespace Entidades{
    namespace Obstaculos{
        
        Caixa::Caixa(sf::Vector2f pos): Obstaculo(pos, sf::Vector2f(TAMANHO_CAIXA_X,TAMANHO_CAIXA_Y), PATH_CAIXA, IDs::caixa, 0)
        {
        }

        Caixa::~Caixa()
        {
        }

        void Caixa::atualizar()
        {
            float dt = pGrafico->getDt();
            sf::Vector2f ds(0.0f, 0.0f);

            //sofre o efeito da gravidade
            vel.y += GRAVIDADE * dt;
            ds.y = vel.y * GRAVIDADE;
            if(vel.y >15.f)
            {
                vel.y = 15.f;
            }

            //atualiza posição
            setPosicao(sf::Vector2f(posicao.x, posicao.y + ds.y));

            //desenha na janela
            imprimir_se();
            
        }

        void Caixa::colisao(Entidade* other, sf::Vector2f ds)
        {
            if(other->getID() == IDs::jogador || other->getID() == IDs::esqueleto || other->getID() == IDs::mago || other->getID() == IDs::cavaleiro){ 
                colisaoObstaculo(ds, static_cast<Personagens::Personagem*>(other));    
            }
            else if(other->getID() == IDs::plataforma || other->getID() == IDs::caixa){
                posicao.y = other->getPosicao().y - tam.y;
                vel.y = 0.0f;
            }

        }
    }
}