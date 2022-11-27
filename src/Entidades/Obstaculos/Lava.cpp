#include "../../../include/Entidades/Obstaculos/Lava.h"

namespace Entidades{
    namespace Obstaculos{
        Lava::Lava(sf::Vector2f pos): 
        Obstaculo(pos, sf::Vector2f(TAMANHO_LAVA_X, TAMANHO_LAVA_Y), PATH_LAVA, IDs::lava, DANO_LAVA)
        {
            setDano(DANO_LAVA);
            setDanoso(true);
        }

        Lava::~Lava()
        {
        }
        void Lava::atualizar()
        {
            if (ativo){ 
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
        }

        void Lava::colisao(Entidade* other, sf::Vector2f ds)
        {

            if(other->getID() == IDs::jogador || other->getID() == IDs::esqueleto || other->getID() == IDs::mago || other->getID() == IDs::cavaleiro){ 
                colisaoObstaculo(ds, static_cast<Personagens::Personagem*>(other));
            }
            else if(other->getID() == IDs::plataforma || other->getID() == IDs::caixa ){
                posicao.y = other->getPosicao().y - tam.y;
                vel.y = 0.0f;
            }
        }

    }
}