#include "../../../include/Entidades/Obstaculos/Obstaculo.h"

namespace Entidades{
    namespace Obstaculos{
        Obstaculo::Obstaculo(const sf::Vector2f pos, const sf::Vector2f tam, const char* path, const IDs ID): Entidade(pos,tam, ID)
        {
            pGrafico->createTexture(path);
        }
        Obstaculo::~Obstaculo()
        {
            
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