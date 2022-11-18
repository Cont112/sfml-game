#pragma once

#include "Gerenciador_Grafico.h"
#include "../Entidades/Personagens/Jogador.h"

namespace Gerenciadores {
    
    class Gerenciador_Eventos
    {
        private:
        Gerenciadores::Gerenciador_Grafico* pGrafico;
        Entidades::Personagens::Jogador* pJogador;

        //Padroes de projeto singleton
        static Gerenciador_Eventos* instance;
    };
}