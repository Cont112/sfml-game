#pragma once

#include "Inimigo.h"
#include "../../Projetil.h"
#include "../../../Listas/Lista_Entidades.h"
#include <math.h>


#define PATH_MAGO "assets/Inimigos/mago.png"
#define TAM_MAGO_X 48.f
#define TAM_MAGO_Y 48.f
#define VELOCIDADE_MAGO 120.f
#define RANGE_MAGO_X 400.f
#define RANGE_MAGO_Y 50.f

namespace Entidades {
    namespace Personagens{
        namespace Inimigos{
            class Mago: public Inimigo{
            private:
                float range;
                Projetil *projetil;
                Listas::Lista_Entidades *listaObst;
                bool projetilCriado;
                
                

                
            public:
                Mago(sf::Vector2f pos, Jogador* jogador,Listas::Lista_Entidades *listaObst);
                ~Mago();
                void criarProjetil();
                void atacar();
                
            };
        }
    }
}