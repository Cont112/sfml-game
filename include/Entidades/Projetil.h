#pragma once

#include "Entidade.h"
#include "Personagens/Personagem.h"
#include "Personagens/Jogador.h"
#include "Personagens/Inimigos/Esqueleto.h"



#define PATH_PROJETIL "assets/fogo.png"
#define DANO_PROJETIL 25
#define TAM_X_PROJETIL 20.f
#define TAM_Y_PROJETIL 20.f
#define VEL_X_PROJETIL 0.1f

namespace Entidades{
    class Projetil: public Entidade{
    private:
        int dano;
    public:
        Projetil(const sf::Vector2f pos, const sf::Vector2f tam, const char* path, const IDs id, sf::Vector2f vel);
        ~Projetil();
        void atualizar();   
        void colisao(Entidade* other, sf::Vector2f ds);
        void colisaoProjetil(sf::Vector2f ds, Entidades::Entidade* pPersonagem);     
    };
}