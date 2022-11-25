#include "../../include/Entidades/Projetil.h"

namespace Entidades{

    Projetil::Projetil(const sf::Vector2f pos, const sf::Vector2f tam, const char* path, const IDs id, int dano, Entidades::Entidade* dono, sf::Vector2f vel):
              Entidade(pos, tam, vel, id,dano)
    {
        pGrafico->createTexture(PATH_PROJETIL);
        setTextura(pGrafico->textureMap.at(PATH_PROJETIL));
    }
    
    Projetil::~Projetil()
    {

    }
    
    void Projetil:: atualizar()
    {
        float dt = relogio.getElapsedTime().asSeconds();
        relogio.restart();
        sf::Vector2f ds(0.0f, 0.0f);

        //sofre o efeito da gravidade
        vel.y += GRAVIDADE * dt;
        ds.y = vel.y * GRAVIDADE;

        //atualiza posição
        setPosicao(sf::Vector2f(posicao.x + vel.x, posicao.y + ds.y));

        //desenha na janela
        imprimir_se();
    }
    
    
    
    
    

}
