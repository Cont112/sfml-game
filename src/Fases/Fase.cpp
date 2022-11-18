#include "../../include/Fases/Fase.h"

namespace Fases{

    Fase::Fase(): Ente(), fundo(),listaPersonagens(), listaObstaculos(), pColisao(new Gerenciadores::Gerenciador_Colisoes(&listaObstaculos, &listaPersonagens))
    {
        if (pColisao == NULL)
        {
            std::cout << "Fase: Nao foi possivel criar o gerenciador de colisoes" << std::endl;
            exit(1);
        }
    }

    Fase::~Fase() 
    {
        if(pColisao){
            delete(pColisao);
            pColisao = nullptr;
        }

        listaObstaculos.limparLista();
        listaPersonagens.limparLista();
    }

    void Fase::criarPlataforma(const sf::Vector2f pos)
    {
        
    }
    void Fase::gerenciar_colisoes() {}
}
