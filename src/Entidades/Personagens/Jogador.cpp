#include "../../../include/Entidades/Personagens/Jogador.h"
#include "../../../include/Gerenciadores/Gerenciador_Colisoes.h"
#define WIDTH 1280
#define HEIGHT 720

namespace Entidades{ 
    namespace Personagens{ 
        Jogador::Jogador()
        {
            init();
            isJumping = false;

        }

        Jogador::~Jogador()
        {
        }

        void Jogador::init()
        {
            vel = sf::Vector2f(1.f,1.f);
            shape.setOrigin(0.0f,0.0f);
            shape.setSize(sf::Vector2f(100.0f,100.0f));
        }

        void Jogador::movimentar()
        {
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
                isJumping = true;
                jumpCooldown = true;
                if(isJumping)
                {
                    shape.move(0.0f, -200);
                    g = 0;
                }
            }
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
        }

        void Jogador::executar()
        {
            imprimir_se();
            movimentar();
        }

    }
}
