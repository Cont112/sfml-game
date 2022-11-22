#pragma once

#include "../Listas/Lista_Entidades.h"
#include "../Gerenciadores/Gerenciador_Colisoes.h"
#include "../Entidades/Obstaculos/Obstaculo.h"
#include "../Entidades/Obstaculos/Plataforma.h"
#include "../Gerenciadores/Gerenciador_Eventos.h"
#include "../Entidades/Personagens/Inimigos/Mago.h"
#include "../Entidades/Personagens/Inimigos/Esqueleto.h"
#include "../Entidades/Personagens/Inimigos/Inimigo.h"
#include "../Entidades/Obstaculos/Caixa.h"

//Adaptado do monitor Geovane

namespace Fases{
    class Fase : public Ente{

    protected:
        Listas::Lista_Entidades listaPersonagens;
        Listas::Lista_Entidades listaObstaculos;
        Gerenciadores::Gerenciador_Colisoes* pColisao;
        static Gerenciadores::Gerenciador_Grafico* pGrafico;
        static Gerenciadores::Gerenciador_Eventos* pEventos;

        sf::RectangleShape fundo;

    public:
        Fase();
        ~Fase();
        void criarMago(const sf::Vector2f pos);
        void criarEsqueleto(const sf::Vector2f pos);
        void criarJogador(const sf::Vector2f pos);
        void criarPlataforma(const sf::Vector2f pos);
        void criarCaixa(const sf::Vector2f pos);
        virtual void criarFundo() = 0;
        virtual void criarMapa() = 0;
        void criarEntidade(char letra ,const sf::Vector2f pos);
        void executar();
        void atualizar();

   };
}