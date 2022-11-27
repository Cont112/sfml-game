#pragma once

#include "../Listas/Lista_Entidades.h"
#include "../Gerenciadores/Gerenciador_Colisoes.h"
#include "../Entidades/Obstaculos/Obstaculo.h"
#include "../Entidades/Obstaculos/Plataforma.h"
#include "../Gerenciadores/Gerenciador_Eventos.h"
#include "../Entidades/Personagens/Inimigos/Mago.h"
#include "../Entidades/Personagens/Inimigos/Esqueleto.h"
#include "../Entidades/Personagens/Inimigos/Cavaleiro.h"
#include "../Entidades/Personagens/Inimigos/Inimigo.h"
#include "../Entidades/Obstaculos/Caixa.h"
#include "../Entidades/Obstaculos/Lava.h"

//Adaptado do monitor Geovane

namespace Fases{
    class Fase : public Ente{

    protected:
        Listas::Lista_Entidades listaPersonagens;
        Listas::Lista_Entidades listaObstaculos;
        Gerenciadores::Gerenciador_Colisoes* pColisao;
        static Gerenciadores::Gerenciador_Grafico* pGrafico;
        static Gerenciadores::Gerenciador_Eventos* pEventos;
        Entidades::Personagens::Jogador* j1;
        Entidades::Personagens::Jogador* j2;


        bool player2;
        bool ativo;
    public:
        Fase(const IDs ID);
        ~Fase();
        void criarMago(const sf::Vector2f pos);
        void criarEsqueleto(const sf::Vector2f pos);
        void criarCavaleiro(const sf::Vector2f pos);
        void setJogador1(Entidades::Personagens::Jogador* j);
        void setJogador2(Entidades::Personagens::Jogador* j);
        void criarPlataforma(const sf::Vector2f pos, bool f,bool v);
        void criarCaixa(const sf::Vector2f pos);
        void criarLava(const sf::Vector2f pos);
        void criarEntidade(char letra ,const sf::Vector2f pos);
        void executar();
        void atualizar();
        void doisJogadores(bool j);
        bool getDoisJogadores();
        bool getAtividadeInimigos();
        virtual void resetar() = 0;
        virtual void criarMapa() = 0;
   };
}