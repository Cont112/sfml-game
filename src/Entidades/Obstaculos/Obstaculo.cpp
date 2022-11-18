#include "../../../include/Entidades/Obstaculos/Obstaculo.h"

namespace Entidades{
    namespace Obstaculos{
        Obstaculo::Obstaculo(): Entidade(), tamanho(sf::Vector2f(0.f, 0.f)), danoso(false)
        {

        }
        Obstaculo::Obstaculo(const sf::Vector2f pos, const sf::Vector2f tam, const char* path): Entidade(pos,tam)
        {
            pGrafico->createTexture(path);
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
        void Obstaculo::atualizar()
        {
            imprimir_se();
        }


    }
}