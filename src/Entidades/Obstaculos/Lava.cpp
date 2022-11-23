#include "../../../include/Entidades/Obstaculos/Lava.h"

namespace Entidades{
    namespace Obstaculos{
        Lava::Lava(sf::Vector2f pos): 
        Obstaculo(pos, sf::Vector2f(TAMANHO_LAVA_X, TAMANHO_LAVA_Y), PATH_LAVA, IDs::lava), 
        dano(50)
        {
            pGrafico->createTexture(PATH_LAVA);
            setTextura(pGrafico->textureMap.at(PATH_LAVA));
            setDanoso(true);
        }

        Lava::~Lava()
        {
        }
        void Lava::atualizar()
        {
            float dt = relogio.getElapsedTime().asSeconds();
            relogio.restart();
            sf::Vector2f ds(0.0f, 0.0f);

            //sofre o efeito da gravidade
            vely += GRAVIDADE * dt;
            ds.y = vely * GRAVIDADE;

            //atualiza posição
            setPosicao(sf::Vector2f(posicao.x, posicao.y + ds.y));

            //desenha na janela
            imprimir_se();
        }

        void Lava::colisao(Entidade* other, sf::Vector2f ds)
        {

            if(other->getID() == IDs::jogador || other->getID() == IDs::esqueleto || other->getID() == IDs::mago){ 
                colisaoObstaculo(ds, static_cast<Personagens::Personagem*>(other));
            }
            else if(other->getID() == IDs::plataforma || other->getID() == IDs::caixa){
                posicao.y = other->getPosicao().y - tam.y;
                vely = 0.0f;
            }
        }

    }
}