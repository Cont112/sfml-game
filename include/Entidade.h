#include "Ente.h"
class Entidade:public Ente{

    protected:
        sf::Vector2f posicao;       
        bool ativo;
        sf::Vector2f vel; 
    
    public:
        Entidade();
        ~Entidade();
        sf::Vector2f getPosicao();
        void setPosicao(sf::Vector2f p);
        sf::Vector2f getVelocidade();
        void setVelocidade(sf::Vector2f v);
        


};