#pragma once

#include "Gerenciador_Grafico.h"
#include "../Entidades/Personagens/Jogador.h"

class Jogo;

namespace Gerenciadores {
    
    class Gerenciador_Eventos
    {
    private:
        static Gerenciadores::Gerenciador_Grafico* pGrafico;
        Entidades::Personagens::Jogador* pJogador1;
        Entidades::Personagens::Jogador* pJogador2;
        Jogo* pJogo;
        bool player2;
        bool mouseClick;
        bool ultimoClick;

        //padrao de projeto singleton
        static Gerenciador_Eventos* instance;
        Gerenciador_Eventos();

    public:
        ~Gerenciador_Eventos();

        static Gerenciador_Eventos* getInstance();
        void deletarInstance();

        void setJogador(Entidades::Personagens::Jogador* pJogador);
        void setJogador2(Entidades::Personagens::Jogador* pJogador2);
        void setJogo(Jogo* jogo);
        void verificaTeclaPressionada(sf::Keyboard::Key tecla);
        void verificaTeclaSolta(sf::Keyboard::Key tecla);
        void verificaMousePressionado(sf::Mouse::Button click);
        void verificaMouseSolto (sf::Mouse::Button click);
        sf::Vector2f getMousePosition();
        bool getJogadorAtividade(bool j);
        bool getMouseClick();
        Entidades::Personagens::Jogador* getJogador(bool j);
        void executar();
    };
}