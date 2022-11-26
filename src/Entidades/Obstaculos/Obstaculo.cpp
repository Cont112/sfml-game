#include "../../../include/Entidades/Obstaculos/Obstaculo.h"

namespace Entidades{
    namespace Obstaculos{
        Obstaculo::Obstaculo(const sf::Vector2f pos, const sf::Vector2f tam, const char* path, const IDs ID): Entidade(pos,tam, sf::Vector2f(0.0f,0.0f),ID),danoso(false),dano()
        {
            setTextura(path);
        }
       
        Obstaculo::~Obstaculo()
        {
            
        }
       
        void Obstaculo::setDanoso(bool d)
        {
            danoso = d;
            
        }

        void Obstaculo::setDano(int d)
        {
            dano = d;
        }

        int Obstaculo::getDano()
        {
            return dano;
        }

        void Obstaculo::colisaoObstaculo(sf::Vector2f ds, Personagens::Personagem* pPersonagem)
        {
            sf::Vector2f posOutro = pPersonagem->getPosicao();
            sf::Vector2f tamOutro = pPersonagem->getTam();
            sf::Vector2f vel = pPersonagem->getVel();

            if(ds.x < 0.0f && ds.y < 0.0f){ //houve colisao
            if(ds.x > ds.y){
                if(posOutro.x < posicao.x){ //colisão em x
                    posOutro.x += ds.x;
                } else {
                    posOutro.x -= ds.x;
                }
                vel.x = 0.0f;
            } else {
                if(posOutro.y < posicao.y){ //colisão em y
                    posOutro.y += ds.y;
                    if(pPersonagem->getID() == IDs::jogador){
                        Personagens::Jogador* pJogador = static_cast<Personagens::Jogador*>(pPersonagem);
                        pJogador->podePular();
                        if(danoso)
                        {
                            pJogador->receberDano(getDano());
                        }
                    }
                } else {
                    posOutro.y -= ds.y;
                }
                vel.y = 0.0f;

                
            }
            pPersonagem->setPosicao(posOutro);
            pPersonagem->setVel(vel);
        }


    }
}}