#include "../../../include/Entidades/Personagens/Jogador.h"
#include "../../../include/Gerenciadores/Gerenciador_Colisoes.h"
#define WIDTH 1280
#define HEIGHT 720

//MUDAR MOVIMENTO PARA SETAR VELOCIDADES 

namespace Entidades{ 
    namespace Personagens{ 
        Jogador::Jogador(const sf::Vector2f pos, const sf::Vector2f tam): Personagem(pos,tam, VELOCIDADE_JOGADOR), isJumping(false)
        {
            init();
        }

        Jogador::Jogador(): Personagem(VELOCIDADE_JOGADOR), isJumping(false)
        {
            init();
        }

        Jogador::~Jogador()
        {
        }

        void Jogador::init()
        {
            shape.setOrigin(sf::Vector2f(0.0f,0.0f));
            shape.setSize(sf::Vector2f(100.0f,100.0f));
        }

        void Jogador::pular()
        {
<<<<<<< HEAD
            if(!isJumping){
                vel.y = -2;
=======
            float g = 1.0f;
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                shape.move(-vel.x, 0.0f);

            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                shape.move(vel.x, 0.0f);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)&& !isJumping && !jumpCooldown)
            {   
>>>>>>> Ian
                isJumping = true;
            }
<<<<<<< HEAD
=======
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                shape.move(0.0f, vel.y);
            }
            if(shape.getPosition().y >= (HEIGHT-shape.getSize().y))
            {
                isJumping = false;
                shape.setPosition(sf::Vector2f(shape.getPosition().x, HEIGHT-shape.getSize().y));
                jumpCooldown = false;
            }
            
            shape.move(0.0f,g);
            
            posicao = shape.getPosition();
>>>>>>> Ian
        }

        void Jogador::atualizar()
        {
            if(ativo)
            {
                imprimir_se();
                atualizarPosicao();
            }

        }

    }
}
