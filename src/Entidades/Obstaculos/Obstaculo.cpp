#include "../../../include/Entidades/Obstaculos/Obstaculo.h"

namespace Entidades{
    namespace Obstaculos{
        Obstaculo::Obstaculo():tamanho(sf::Vector2f(0.f, 0.f)), danoso(false)
        {

        }
        Obstaculo::~Obstaculo()
        {

        }
        void Obstaculo::setTamanho(sf::Vector2f t)
        {
            shape.setSize(t);
        }
        void Obstaculo::setDanoso(bool d)
        {
            danoso = d;
            
        }
        void Obstaculo::executar()
        {
            imprimir_se();
        }


    }
}