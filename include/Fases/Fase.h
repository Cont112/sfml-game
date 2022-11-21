#pragma once

#include "../Listas/Lista_Entidades.h"
#include "../Gerenciadores/Gerenciador_Colisoes.h"
#include "../Entidades/Obstaculos/Obstaculo.h"
#include "../Entidades/Obstaculos/Plataforma.h"

//Adaptado do monitor Geovane

namespace Fases{
    class Fase : public Ente{

    protected:
        Listas::Lista_Entidades* listaPersonagens;
        Listas::Lista_Entidades* listaObstaculos;
        Gerenciadores::Gerenciador_Colisoes* pColisao;
        Gerenciadores::Gerenciador_Grafico* pGrafico;
        sf::Sprite fundo;

    public:
        Fase();
        ~Fase();

        void criarInimigo(const sf::Vector2f pos);
        void criarJogador(const sf::Vector2f pos);
        void criarPlataforma(const sf::Vector2f pos);
        void criarCaixa(const sf::Vector2f pos);
        virtual void criarFundo() = 0;
        virtual void criarMapa() = 0;
        void criarEntidade(char letra ,const sf::Vector2f pos);
        Entidades::Personagens::Jogador* getJogador();
        void gerenciar_colisoes();
        void executar();
        void desenhar();

   };
}