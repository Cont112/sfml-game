#include "../../../include/Entidades/Obstaculos/Plataforma.h"

namespace Entidades{
    namespace Obstaculos{
        Plataforma::Plataforma(sf::Vector2f pos): 
        Obstaculo(pos, sf::Vector2f(TAMANHO_PLATAFORMA_X, TAMANHO_PLATAFORMA_Y), PATH_PLATAFORMA, IDs::plataforma, 0), 
        flutuando(false)
        {
        }

        Plataforma::~Plataforma()
        {
        }
        void Plataforma::atualizar()
        {
            float dt = pGrafico->getDt();
            sf::Vector2f ds(0.0f, 0.0f);

            //sofre o efeito da gravidade
            vel.y += GRAVIDADE * dt;
            ds.y = vel.y * GRAVIDADE;

            float flutuabilidade = ds.y;
            if(flutuando)
                flutuabilidade = 0.0f;

            //atualiza posição
            setPosicao(sf::Vector2f(posicao.x, posicao.y + ds.y - flutuabilidade));

            //desenha na janela
            imprimir_se();
        }

        void Plataforma::colisao(Entidade* other, sf::Vector2f ds)
        {

            if(other->getID() == IDs::jogador || other->getID() == IDs::esqueleto || other->getID() == IDs::mago)
            {
                colisaoObstaculo(ds, static_cast<Personagens::Personagem*>(other));
            }
        }

    }
}