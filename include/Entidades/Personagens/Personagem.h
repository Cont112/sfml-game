#pragma once
#include "../Entidade.h"
#define GRAVIDADE 1.0f

namespace Entidades{ 
    namespace Personagens { 

    class Personagem: public Entidade{
    protected:
        int vida;
        int dano;
        const float velMax;
        bool podeAndarEsquerda;
        bool podeAndarDireita;
        bool esquerda;
        bool vivo;
        float dtAux;
        
    public:
        Personagem (const sf::Vector2f pos, const sf::Vector2f tam, const float vel, const IDs ID);
        ~Personagem();

        int getVida() const;
        int getDano() const;
        bool getVivo() const; 
        void setVivo(bool v);
        void setDano(int d);
        void setVida(int v);

        void setVel(sf::Vector2f v);
        sf::Vector2f getVel() const;
        void movimentar(const bool esquerda);

        void parar();
        void pararEsquerda();
        void pararDireita();

        void atualizarPosicao();
        virtual void atualizar() = 0;
        virtual void colisao(Entidade* other, sf::Vector2f ds =  sf::Vector2f(0.0f,0.0f)) = 0;
        void colisaoPersonagem(sf::Vector2f ds, Entidades::Entidade* pPersonagem);
};


}}