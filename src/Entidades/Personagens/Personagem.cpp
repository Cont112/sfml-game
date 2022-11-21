#include "../../../include/Entidades/Personagens/Personagem.h"

namespace Entidades{
    namespace Personagens{

        Personagem::Personagem(const sf::Vector2f pos, const sf::Vector2f tam, const float vel, const IDs ID): 
        Entidade(pos,tam, ID), podeAndarEsquerda(0),podeAndarDireita(0), esquerda(0),relogio(), dt(0.0f),
        vel(sf::Vector2f(vel,0.0f)), velMax(vel),vida(100), dano(10)
        {
        }

        Personagem::~Personagem()
        {
        }

        int Personagem::getDano() const{
            return dano;
        }

        int Personagem::getVida() const {
            return vida;
        }

        void Personagem::setDano(int d){
            dano = d;
        }

        void Personagem::setVida(int v){
            vida = v;
        }

        void Personagem::setVel(sf::Vector2f v)
        {
            this->vel = v;
        }

        sf::Vector2f Personagem::getVel() const
        {
            return vel;
        }
   
        
        void Personagem::movimentar(const bool esquerda)
        {
            if(esquerda)
            {
                podeAndarEsquerda = true;
                podeAndarDireita = false;
            }
            else{
                podeAndarDireita = true;
                podeAndarEsquerda = false;
            }
            this->esquerda = esquerda;
        }

        void Personagem::parar()
        {
            podeAndarEsquerda = false;
            podeAndarDireita = false;
        }
        void Personagem::pararEsquerda()
        {
            podeAndarEsquerda = false;
        }

        void Personagem::pararDireita()
        {
            podeAndarDireita = false;
        }

        void Personagem::atualizarPosicao()
        {
            dt = relogio.getElapsedTime().asSeconds();
            relogio.restart();
            sf::Vector2f ds(0.0f, 0.0f);

            //move na horizontal
            if(podeAndarDireita){
                ds.x = vel.x * dt;
            } else if (podeAndarEsquerda) {
                ds.x = -1 * vel.x*dt;
            }

            //sofre o efeito da gravidade
            vel.y += GRAVIDADE * dt;
            ds.y = vel.y * GRAVIDADE;

            //atualiza posição
            setPosicao(sf::Vector2f(posicao.x + ds.x, posicao.y + ds.y));

            //atualiza velocidade na horizontal
            vel.x = velMax;

            //desenha na janela
            imprimir_se();
}
   
   
   
   
    }
}


