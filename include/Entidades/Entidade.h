#pragma once
#include "../Ente.h"
#include "../Gerenciadores/Colisao.h"

namespace Entidades{ 
class Entidade:public Ente{

    protected:
        sf::Vector2f posicao;       
        bool ativo;
        sf::Vector2f vel; 
        Gerenciadores::GColisao::Colisao c;
    
    public:
        Entidade();
        ~Entidade();
        sf::Vector2f getPosicao();
        void setPosicao(sf::Vector2f p);
        sf::Vector2f getVelocidade();
        void setVelocidade(sf::Vector2f v);
        Gerenciadores::GColisao::Colisao getColisao();
        void executar();
        


};
}