#include "../../../include/Entidades/Personagens/Personagem.h"

namespace Entidades{
    namespace Personagens{

        Personagem::Personagem(const sf::Vector2f pos, const sf::Vector2f tam, const float vel, const IDs ID): 
        Entidade(pos,tam, sf::Vector2f(vel,0.0f),ID), podeAndarEsquerda(0),podeAndarDireita(0), esquerda(0), dtAux(0.0f),
        velMax(vel),vida(100), dano(10), vivo(1)
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

        void Personagem::setVivo(bool v) {
            vivo = v;
        }

        bool Personagem::getVivo() const {
            return vivo;
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
            float dt = pGrafico->getDt();
            sf::Vector2f ds(0.0f, 0.0f);

            //move na horizontal
            if(podeAndarDireita){
                shape.setScale(1.f,1.f);
                ds.x = vel.x * dt;
            } else if(podeAndarEsquerda){
                shape.setScale(-1.f,1.f);
                 ds.x = -1*vel.x * dt;
            }
            

            //sofre o efeito da gravidade
            vel.y += GRAVIDADE * dt;
            ds.y = vel.y * GRAVIDADE;

            //atualiza posição
            setPosicao(sf::Vector2f(posicao.x + ds.x, posicao.y + ds.y));

            //atualiza velocidade na horizontal
            vel.x = velMax;

            if(posicao.y >= 720)
            {
                setPosicao(sf::Vector2f(posicao.x, 700));
            }
            //desenha na janela
            imprimir_se();
}
   
        void Personagem::colisaoPersonagem(sf::Vector2f ds, Entidades::Entidade* pPersonagem)
        {
            sf::Vector2f posOutro = pPersonagem->getPosicao();
            sf::Vector2f tamOutro = pPersonagem->getTam();
            sf::Vector2f vel = pPersonagem->getVel();
            sf::Vector2f velPersonagem = getVel();

            if(ds.x < 0.0f && ds.y < 0.0f){ //houve colisao
            if(ds.x > ds.y){
                if(posOutro.x < posicao.x){ //colisão em x
                    posOutro.x += ds.x;
                } 
                else {
                    posOutro.x -= ds.x;
                }
                vel.x = 0.0f;
                pararDireita();
                pararEsquerda();
            } 
            else {
                if(posOutro.y < posicao.y){ //colisão em y
                    posOutro.y += ds.y;
                    
                } 
                else {
                    posOutro.y -= ds.y;
                    if (ID == IDs::jogador && pPersonagem->getID()!=IDs::jogador){

                        pPersonagem->setAtividade(false);
                    }
                }
                vel.y = 0.0f;
                
                

                
            }
            pPersonagem->setPosicao(posOutro);
            pPersonagem->setVel(vel);
            }
        }
   
   
    }
}


