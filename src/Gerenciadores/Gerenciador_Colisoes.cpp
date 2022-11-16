#include "../../include/Gerenciadores/Gerenciador_Colisoes.h"

namespace Gerenciadores{
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
    void Gerenciador_Colisoes::setListas(Listas::Lista_Entidades *lm,Listas::Lista_Entidades *lf )
    {
        listaMoveis = lm;
        listaFixos = lf;
    }
    
    void Gerenciador_Colisoes::executar()
    {
        //colisao entre moveis
        int i =0;
        Entidades::Entidade *entidade1;
        Entidades::Entidade *entidade2;

        for (i=0; i<listaMoveis->getTamanho()-1; i++)
        {
            entidade1 = listaMoveis->operator[](i);
            sf::Vector2f tam1 = listaMoveis->operator[](i)->getShape().getSize();
            for (int j = i+1; j<listaMoveis->getTamanho(); j++)
            {
                entidade2 = listaMoveis->operator[](j);
                sf::Vector2f tam2 = listaMoveis->operator[](j)->getShape().getSize();
                sf::Vector2f ds = calculaDistancia(entidade1, entidade2);

                if (ds.x==(tam1.x+tam2.x) && ds.y<=(tam1.y+tam2.y))//colisao frontal 
                {
                    entidade1->getColisao().setColisor(entidade2);
                    entidade1->getColisao().SetColisao(1, true);
                }
                else if (ds.y==(tam1.y+tam2.y) && ds.x<=(tam1.x+tam2.x))//colisao superior 
                {
                    entidade1->getColisao().setColisor(entidade2);
                    entidade1->getColisao().SetColisao(2, true);
                }       
            }
        }
    }
}