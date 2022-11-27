#include "../../../include/Entidades/Personagens/Jogador.h"
#include "../../../include/Gerenciadores/Gerenciador_Colisoes.h"
#define WIDTH 1280
#define HEIGHT 720

//MUDAR MOVIMENTO PARA SETAR VELOCIDADES 

namespace Entidades{ 
    namespace Personagens{ 
        Jogador::Jogador(const sf::Vector2f pos, const sf::Vector2f tam, const bool multiplayer,const IDs ID): Personagem(pos,tam, VELOCIDADE_JOGADOR, ID, 0), isJumping(false),invulneravel(false)
        {
            init(multiplayer);
            
        }

        Jogador::~Jogador()
        {
        }

        void Jogador::init(const bool multiplayer)
        {
            setAtividade(false);
            if(!multiplayer){ 
                setTextura(PATH_JOGADOR_1);
            }else {
                setTextura(PATH_JOGADOR_2);
            }
            shape.setOrigin(sf::Vector2f(tam.x/2.0f,0.0f));
        }

        void Jogador::pular()
        {
            if(!isJumping){
                vel.y = -sqrt(2.0f * GRAVIDADE * TAMANHO_PULO);
                isJumping = true;
            }
        }

        void Jogador::podePular()
        {
            isJumping = false;
        }

        void Jogador::atualizar()
        {
            if(vida <= 0)
            {
                ativo = false;
            }
            if(ativo){ 
            
            isJumping = true;
            imprimir_se();
            atualizarPosicao();
            

            if(invulneravel)
            {
                dtAux += pGrafico->getDt();
                if(dtAux > 1.f)
                {
                    shape.setFillColor(sf::Color(0xFFFFFFFF));
                    invulneravel = false;
                    dtAux = 0.0f;
                }
            }
            }
        }

        void Jogador::receberDano(int dano)
        {
            this->dtAux += pGrafico->getDt();
            if(!this->invulneravel)
            {
                this->vida -= dano;
                this->shape.setFillColor(sf::Color(0xFF0000FF));
                this->invulneravel = true;
            }
        }

        void Jogador::colisao(Entidade* other, sf::Vector2f ds)
        {
            switch (other->getID())
            {
            case(IDs::jogador):
            {
            }
            break;

            case (IDs::esqueleto):
            {
                if (other->getAtividade())
                {
                    colisaoPersonagem(ds, other);
                    if (ds.y < ds.x)
                    {
                        receberDano(25);
                    }
                }
            }
                break;

            case(IDs::lava):
            {
                colisaoPersonagem(ds, other);
            }
                break;

            case (IDs::mago):
            {
                if (other->getAtividade())
                {
                    colisaoPersonagem(ds, other);
                }
            }
                break;
            case(IDs::projetil):
            {
                receberDano(other->getDano());
                std::cout<<"colidiu"<<std::endl;
            }
                break;
            
            
            }
        }

    }
}
