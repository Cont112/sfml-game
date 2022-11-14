#include "../../include/Gerenciadores/Gerenciador_Colisoes.h"

Gerenciador_Colisoes::Gerenciador_Colisoes()
{

}

Gerenciador_Colisoes::~Gerenciador_Colisoes()
{

}

sf::Vector2f Gerenciador_Colisoes::calculaDistancia(Entidades::Entidade *ente1,Entidades::Entidade *ente2 )
{
    //calculado distancia entre objetos moveis
    int i = 0;
    sf::Vector2f ds;

    ds.x = fabs((ente1->getPosicao().x + ente1->getShape().getSize().x/2)-((ente2->getPosicao().x + ente2->getShape().getSize().x/2)));
    ds.y = fabs((ente1->getPosicao().y + ente1->getShape().getSize().y/2)-((ente2->getPosicao().y + ente2->getShape().getSize().y/2)));  

    return ds;
}