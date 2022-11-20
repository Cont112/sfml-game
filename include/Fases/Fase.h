#pragma once

#include "../Listas/Lista_Entidades.h"
#include "../Gerenciadores/Gerenciador_Colisoes.h"
#include "../Entidades/Obstaculos/Obstaculo.h"

//Adaptado do monitor Geovane

namespace Fases{
    class Fase : public Ente{

    protected:
        Listas::Lista_Entidades listaPersonagens;
        Listas::Lista_Entidades listaObstaculos;
        Gerenciadores::Gerenciador_Colisoes* pColisao;
        Gerenciadores::Gerenciador_Grafico* pGrafico;
        sf::RectangleShape fundoTela;

        
    public:
        Fase();
        ~Fase();

        void criarInimigo(const sf::Vector2f pos);
        void criarJogador(const sf::Vector2f pos);
        void criarPlataforma(const sf::Vector2f pos);
        void criarCaixa(const sf::Vector2f pos);
        void criarEntidade(const sf::Vector2f pos);
        virtual void criarMapa() = 0;
        virtual void criarFundo() = 0;
        void gerenciar_colisoes();
        void executar();
        void desenhar();
        void setPColisao(Gerenciadores::Gerenciador_Colisoes* g);
        Listas::Lista_Entidades* getListaPersonagens();
        Listas::Lista_Entidades* getListaObstaculos();

   };
}