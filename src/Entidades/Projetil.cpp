#include "../../include/Entidades/Projetil.h"

namespace Entidades{

    Projetil::Projetil(const sf::Vector2f pos, const sf::Vector2f tam, const char* path, const IDs id, sf::Vector2f vel):
              Entidade(pos, tam, sf::Vector2f(VEL_X_PROJETIL, 0), IDs::projetil, DANO_PROJETIL)
    {
        setTextura(PATH_PROJETIL);
        setAtividade(true);
    }
    
    Projetil::~Projetil()
    {

    }
    
    void Projetil:: atualizar()
    {
       
        if (ativo){
            float dt = pGrafico->getDt();
            sf::Vector2f ds(0.0f, 0.0f);
            
            //desenha na janela
            imprimir_se();
            

            //sofre o efeito da gravidade
            vel.y += GRAVIDADE * dt;
            ds.y = vel.y * GRAVIDADE;

            float efeitoMagnus = ds.y;

            //atualiza posição
            setPosicao(sf::Vector2f(posicao.x + vel.x*dt, posicao.y + ds.y - efeitoMagnus));

        }

        
            

        
          
    }
    
    void Projetil::colisao(Entidade* other, sf::Vector2f ds)
    {
        if (ativo)
        {

            switch (other->getID())
            {
            case (IDs::caixa):
                setAtividade(false);
                break;
            case (IDs::jogador):
            {
                setAtividade(false);
                Entidades::Personagens::Jogador * j = static_cast<Personagens::Jogador*>(other);
                j->receberDano(getDano());
            }
                break;
            case (IDs::esqueleto):
                //setAtividade(false);
                break;
            case (IDs::lava):
                setAtividade(false);
                break;
                setAtividade(false);
            case (IDs::plataforma):
            {
                setAtividade(false);
                std::cout<<"colidiu plataforma"<<std::endl;
            }
                break;
            default:
                break;
            }
            
            
            colisaoProjetil(ds, other);
        }
    }
    
    void Projetil::colisaoProjetil(sf::Vector2f ds, Entidades::Entidade* pPersonagem)
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
                   
                } 
                else {
                    if(posOutro.y < posicao.y){ //colisão em y
                        posOutro.y += ds.y;
                    }
                    
                    else {
                        posOutro.y -= ds.y;
                    }
                    
                    vel.y = 0.0f;

                    
                    

                    
                }
            pPersonagem->setPosicao(posOutro);
            pPersonagem->setVel(vel);

            
        }    
    
    
    }  

}
