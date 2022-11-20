#include "../../include/Gerenciadores/Gerenciador_Colisoes.h"

namespace Gerenciadores{
    Gerenciador_Colisoes::Gerenciador_Colisoes()
    {
        listaFixos = new Listas::Lista_Entidades();
        listaMoveis = new Listas::Lista_Entidades();

    }

    Gerenciador_Colisoes::Gerenciador_Colisoes(Listas::Lista_Entidades* l1, Listas::Lista_Entidades* l2)
    {
        setListas(l1,l2);
    }

    Gerenciador_Colisoes::~Gerenciador_Colisoes()
    {
        if(listaFixos)
        {
            delete (listaFixos);
            listaFixos = nullptr;
        }
        if(listaMoveis)
        {
            delete (listaMoveis);
            listaMoveis = nullptr;
        }
            
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
        if(listaMoveis || listaFixos)
        {
            listaMoveis = lm;
            listaFixos = lf;
        }

    }
    
    void Gerenciador_Colisoes::executar()
    {
        //colisao entre moveis

        for (int i=0; i<listaMoveis->getTamanho()-1; i++)//gerencai colisao moveis com moveis
        {
            Entidades::Entidade *entidade1 = listaMoveis->operator[](i);
            sf::Vector2f tam1 = listaMoveis->operator[](i)->getShape().getSize();
            for (int j = i+1; j<listaMoveis->getTamanho(); j++)
            {
                Entidades::Entidade *entidade2 = listaMoveis->operator[](j);
                sf::Vector2f tam2 = listaMoveis->operator[](j)->getShape().getSize();
                sf::Vector2f ds = calculaDistancia(entidade1, entidade2);

                sf::Vector2f instersecao;
                instersecao.x = fabs(ds.x) - (tam1.x / 2.f + tam2.x / 2.f);
				instersecao.y = fabs(ds.y) - (tam1.y / 2.f + tam2.y / 2.f);

                //verifica a colisao
                if (instersecao.x < 0.f && instersecao.y < 0.f ) 
                {
                    entidade1->Colisao(instersecao, entidade2);                       
                    //std::cout<<"colidiu"<<std::endl;
                }
                entidade1 = nullptr;
                entidade2 = nullptr;
            }   
        }
        for (int i=0; i<listaMoveis->getTamanho(); i++)//gerencia colisao moveis com fixos
        {
            Entidades::Entidade *entidade1 = listaMoveis->operator[](i);
            sf::Vector2f tam1 = listaMoveis->operator[](i)->getShape().getSize();
            for (int j = 0; j<listaFixos->getTamanho(); j++)
            {
                Entidades::Entidade *entidade2 = listaFixos->operator[](j);
                sf::Vector2f tam2 = listaFixos->operator[](j)->getShape().getSize();
                sf::Vector2f ds = calculaDistancia(entidade1, entidade2);

                sf::Vector2f instersecao;
                instersecao.x = fabs(ds.x) - (tam1.x / 2.f + tam2.x / 2.f);
				instersecao.y = fabs(ds.y) - (tam1.y / 2.f + tam2.y / 2.f);

                //verifica a colisao
                if (instersecao.x < 0.f && instersecao.y < 0.f ) 
                {
                    entidade1->Colisao(instersecao, entidade2);                       
                    //std::cout<<"colidiu"<<std::endl;
                }
                entidade1 = nullptr;
                entidade2 = nullptr;
            }   
        }

        
    }
}