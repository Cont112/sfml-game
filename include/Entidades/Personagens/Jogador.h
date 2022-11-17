#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../../Gerenciadores/Gerenciador_Grafico.h"
#include "../../Entidades/Colisao.h"
#include "../../Ente.h"
#include "../Entidade.h"

class Gerenciador_Colisoes;

namespace Entidades { 
    namespace Personagens{ 

        class Jogador:public Entidade
        {
            private:
                void init();
                bool isJumping;
            public:
                Jogador();
                ~Jogador();
                void movimentar();
                void executar();
                

        };
    }
}