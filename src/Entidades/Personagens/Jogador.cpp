#include "../../../include/Entidades/Personagens/Jogador.h"
#include "../../../include/Gerenciadores/Gerenciador_Colisoes.h"
#define WIDTH 1280
#define HEIGHT 720

namespace Entidades{ 
    namespace Personagens{ 
        Jogador::Jogador()
        {
            init();

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
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && shape.getPosition().x != 0)
            {
                shape.move(-vel.x, 0.0f);

            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)&& shape.getPosition().x != WIDTH)
            {
                shape.move(vel.x, 0.0f);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)&& shape.getPosition().y != 0)
            {   
                shape.move(0.0f, -vel.y);   
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)&& shape.getPosition().y != (HEIGHT-shape.getSize().y))
            {
                shape.move(0.0f, vel.y);
            }
            
            posicao = shape.getPosition();
        }

        void Jogador::executar()
        {
            imprimir_se();
            movimentar();
        }

    }
}
