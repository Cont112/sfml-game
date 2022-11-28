#include "../../../include/Entidades/Personagens/Jogador.h"
#include "../../../include/Gerenciadores/Gerenciador_Colisoes.h"


namespace Entidades{ 
    namespace Personagens{ 
        Jogador::Jogador(const bool multiplayer): Personagem(sf::Vector2f(50.f,600.f),sf::Vector2f(48.f, 48.f), VELOCIDADE_JOGADOR, IDs::jogador, 0), isJumping(false),invulneravel(false), textoVida()
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
            textoVida.setFont(*pGrafico->loadFont());
            textoVida.setString(std::to_string(vida));
            textoVida.setCharacterSize(18);
            textoVida.setFillColor(sf::Color::Red);
            textoVida.setOrigin(sf::Vector2f(0.0f,0.0f));

            if(multiplayer)
                textoVida.setPosition(sf::Vector2f(1030.f, 50.f));
            else
                textoVida.setPosition(sf::Vector2f(150.f, 50.f));

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
            pGrafico->render(textoVida);
            textoVida.setString(std::to_string(vida));
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

        void Jogador::resetar()
        {
            setAtividade(true);
            setVida(100);
            shape.setFillColor(sf::Color(0xFFFFFFFF));
            setPosicao(sf::Vector2f(50.f,600.f));
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
                break;

            case (IDs::esqueleto):
                if (other->getAtividade())
                {
                    colisaoPersonagem(ds, other);
                    if (ds.y < ds.x)
                    {
                        receberDano(other->getDano());
                    }
                }
                break;
            case (IDs::cavaleiro):
                if(other->getAtividade())
                {
                    colisaoPersonagem(ds,other);
                    if (ds.y < ds.x)
                    {
                        receberDano(other->getDano());
                    }
                }
                break;

            case(IDs::lava):
                colisaoPersonagem(ds, other);
                break;

            case (IDs::mago):
                if (other->getAtividade())
                {
                    colisaoPersonagem(ds, other);
                }
                break;
            case(IDs::projetil):
                receberDano(other->getDano());
                break;
            
            
            }
        }

    }
}
