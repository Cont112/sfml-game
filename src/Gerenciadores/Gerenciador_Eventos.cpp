 #include "../../include/Gerenciadores/Gerenciador_Eventos.h"
 #include "../../include/Jogo.h"

namespace Gerenciadores
{
    Gerenciador_Eventos* Gerenciador_Eventos::instance = NULL;

    Gerenciadores::Gerenciador_Grafico* Gerenciador_Eventos::pGrafico = Gerenciadores::Gerenciador_Grafico::getInstance();

    Gerenciador_Eventos* Gerenciador_Eventos::getInstance()
    {
        if(instance == NULL)
        {
            instance = new Gerenciador_Eventos();
        }

        return instance;
    }

    Gerenciador_Eventos::Gerenciador_Eventos()
    {
        pJogador1 = nullptr;
        pJogador2 = nullptr;
        pJogo = nullptr;
        ultimoClick = false;
        mouseClick = false;
        player2 = false;
    }

    Gerenciador_Eventos::~Gerenciador_Eventos()
    {
        std::cout << "Gerenciador de Eventos foi destruido!" << std::endl;
    }

    void Gerenciador_Eventos::setJogador(Entidades::Personagens::Jogador* pJogador1)
    {
        this->pJogador1 = pJogador1;
    }

    void Gerenciador_Eventos::setJogador2(Entidades::Personagens::Jogador* pJogador2)
    {
        this->pJogador2 = pJogador2;
        player2 = true;
    }


    void Gerenciador_Eventos::verificaTeclaPressionada(sf::Keyboard::Key tecla)
    {
        if(pJogador1){ 
        if (tecla == sf::Keyboard::A){
            pJogador1->movimentar(true);
        } else if (tecla == sf::Keyboard::D){
            pJogador1->movimentar(false);
        } else if (tecla == sf::Keyboard::W){
            pJogador1->pular();
        } }
        if (tecla == sf::Keyboard::Escape){
            switch (pJogo->getGameState())
            {
            case 0:
                pGrafico->closeWindow();
                break;
            case 1:
                pJogo->setGameState(0);
                break;
            case 2:
                pJogo->setGameState(1);
                break;
            case 3:
                pJogo->setGameState(0);
                break;
            case 4:
                pJogo->setGameState(3);
                break;  
            case 5:
                pJogo->setGameState(3);
                break;

            }
        } else if (tecla == sf::Keyboard::R){
            pJogo->getFase(IDs::bosque)->resetar();
            pJogo->getFase(IDs::castelo)->resetar();
        }

        if (player2)
        {
            if (tecla == sf::Keyboard::Left){
                pJogador2->movimentar(true);
            } else if (tecla == sf::Keyboard::Right){
                pJogador2->movimentar(false);
            } else if (tecla == sf::Keyboard::Up){
                pJogador2->pular();
            }
        }

    }

    void Gerenciador_Eventos::verificaTeclaSolta(sf::Keyboard::Key tecla)
    {
        if (player2)
        {

            if(tecla == sf::Keyboard::Left){
                pJogador2->pararEsquerda();
            } 
            else if (tecla == sf::Keyboard::Key::Right){
                pJogador2->pararDireita();
            }

        }

        if(tecla == sf::Keyboard::A){
            pJogador1->pararEsquerda();
        } 
        else if (tecla == sf::Keyboard::Key::D){
            pJogador1->pararDireita();
        }

        
    }

    void Gerenciador_Eventos::verificaMousePressionado(sf::Mouse::Button click)
    {
        if(click == sf::Mouse::Button::Left)
        {
            if (!ultimoClick)
            {
                mouseClick = true;
                ultimoClick = true;
            }
        }

    }
    void Gerenciador_Eventos::verificaMouseSolto (sf::Mouse::Button click)
    {
        if(click == sf::Mouse::Button::Left)
        {
            mouseClick = false;
            ultimoClick = false;
        }
    }

    void Gerenciador_Eventos::executar()
    { 
        {
            sf::Event evento;
            while(pGrafico->getWindow()->pollEvent(evento))
            {
                if(evento.type == sf::Event::KeyPressed){
                    verificaTeclaPressionada(evento.key.code);
                } else if (evento.type == sf::Event::KeyReleased){
                    verificaTeclaSolta(evento.key.code);
                } else if (evento.type == sf::Event::Closed){
                    pGrafico->closeWindow();
                } else if (evento.type == sf::Event::MouseButtonPressed){
                    verificaMousePressionado(evento.mouseButton.button);
                } else if (evento.type == sf::Event::MouseButtonReleased){
                    verificaMouseSolto(evento.mouseButton.button);
                }
            }
        } 
    }

    void Gerenciador_Eventos::deletarInstance()
    {
        if(instance){
            delete instance;
        } else {
            std::cout << "Gerenciador_Eventos: nao foi possivel deletar instancia, nao existe!" << std::endl;
        }       
    }

    Entidades::Personagens::Jogador* Gerenciador_Eventos:: getJogador(bool j)
    {
        if(j){
           return pJogador1;
        }
            
        return pJogador2;
    }

    bool Gerenciador_Eventos:: getJogadorAtividade(bool j)
    {
        if(j)
        {
            return pJogador1->getAtividade();
        }

        return pJogador2->getAtividade();
    }

    sf::Vector2f Gerenciador_Eventos::getMousePosition()
    {
        return (sf::Vector2f)sf::Mouse::getPosition(*pGrafico->getWindow());
    }

    bool Gerenciador_Eventos::getMouseClick()
    {
        return mouseClick;
    }

    void Gerenciador_Eventos::setJogo(Jogo* jogo)
    {
        pJogo = jogo;
    }
}