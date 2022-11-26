#pragma once

#include "Inimigo.h"
#include "../../Projetil.h"
#include "../../../Listas/Lista_Entidades.h"

#define PATH_MAGO "assets/Wizard.png"
#define TAM_MAGO_X 48.f
#define TAM_MAGO_Y 48.f
#define VELOCIDADE_MAGO 120.f
namespace Entidades {
    namespace Personagens{
        namespace Inimigos{
            class Mago: public Inimigo{
            private:
                float range;
                Projetil *projetil;
                Listas::Lista_Entidades *listaObst;

                
            public:
                Mago(sf::Vector2f pos, Jogador* jogador,Listas::Lista_Entidades *listaObst);
                ~Mago();
                void atacar();
                
            };
        }
    }
}