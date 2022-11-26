#include "../../include/Entidades/Projetil.h"

namespace Entidades{

    Projetil::Projetil(const sf::Vector2f pos, const sf::Vector2f tam, const char* path, const IDs id, sf::Vector2f vel):
              Entidade(pos, tam, vel, id, DANO_PROJETIL)
    {
        pGrafico->createTexture(PATH_PROJETIL);
        setTextura(pGrafico->textureMap.at(PATH_PROJETIL));
        setAtividade(false);
    }
    
    Projetil::~Projetil()
    {

    }
    
    void Projetil:: atualizar()
    {
       
            
            float dt = relogio.getElapsedTime().asSeconds();
            relogio.restart();
            sf::Vector2f ds(0.0f, 0.0f);
            
            //desenha na janela
            imprimir_se();

            //sofre o efeito da gravidade
            vel.y += GRAVIDADE * dt;
            ds.y = vel.y * GRAVIDADE;

            //atualiza posição
            setPosicao(sf::Vector2f(posicao.x + VEL_X_PROJETIL, posicao.y + ds.y));

        
          
    }
    
    void Projetil::colisao(Entidade* other, sf::Vector2f ds)
    {
        std::cout<<"colidiu projetil"<<std::endl;
        colisaoProjetil(ds, static_cast<Personagens::Personagem*>(other));
    }
    
    void Projetil::colisaoProjetil(sf::Vector2f ds, Entidades::Personagens::Personagem* pPersonagem)
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
                    ativo = 0;
                } 
                else {
                    if(posOutro.y < posicao.y){ //colisão em y
                        posOutro.y += ds.y;
                    }
                    
                    else {
                        posOutro.y -= ds.y;
                    }
                    
                    vel.y = 0.0f;
                    ativo = 0;

                    
                }
            pPersonagem->setPosicao(posOutro);
            pPersonagem->setVel(vel);

            
        }    
    
    
    }  

}
