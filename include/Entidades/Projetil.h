#pragma once

#include "Entidade.h"
#include "Personagens/Personagem.h"
#include "Personagens/Jogador.h"
#include "Personagens/Inimigos/Esqueleto.h"
#include "Personagens/Inimigos/Mago.h"

#define VEL_PROJETIL
#define PATH_PROJETIL "assets/fogo.png"

namespace Entidades{
    class Projetil: public Entidade{
    private:
        int dano;
        Entidades::Entidade * donoProjetil;
    public:
        Projetil(const sf::Vector2f pos, const sf::Vector2f tam, const char* path, const IDs id, int dano, Entidades::Entidade* dono, sf::Vector2f vel);
        ~Projetil();
        void atualizar();        
    };
}