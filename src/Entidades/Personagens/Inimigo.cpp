#include "../../../include/Entidades/Personagens/Inimigo.h"
namespace Entidades { 
    namespace Personagens{ 

        Inimigo::Inimigo(): atira(0)
        {
            init();
        }
        Inimigo::~Inimigo()
        {

        }
        void Inimigo::init()
        {
            vel = sf::Vector2f(0.1f,0.1f);
            shape.setOrigin(0.0f,0.0f);
            shape.setSize(sf::Vector2f(100.0f,100.0f));

        }
        void Inimigo::movimentar()
        {
            shape.move(vel.x, 0.f);

        }
        void Inimigo::executar()
        {
            imprimir_se();
            movimentar();
        }
    }
}