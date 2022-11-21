#pragma once

#include "Gerenciador_Grafico.h"
#include "../Entidades/Personagens/Jogador.h"

namespace Gerenciadores {
    
    class Gerenciador_Eventos
    {
    private:
        static Gerenciadores::Gerenciador_Grafico* pGrafico;
        Entidades::Personagens::Jogador* pJogador1;

        //padrao de projeto singleton
        static Gerenciador_Eventos* instance;
        Gerenciador_Eventos();

    public:
        ~Gerenciador_Eventos();

        static Gerenciador_Eventos* getInstance();
        void deletarInstance();

        void setJogador(Entidades::Personagens::Jogador* pJogador);
        void verificaTeclaPressionada(sf::Keyboard::Key tecla);
        void verificaTeclaSolta(sf::Keyboard::Key tecla);
        Entidades::Personagens::Jogador* getJogador();
        void executar();
    };
}