 #include "../../include/Gerenciadores/Gerenciador_Eventos.h"

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
    {}

    Gerenciador_Eventos::~Gerenciador_Eventos()
    {
        std::cout << "Gerenciador de Eventos foi destruido!" << std::endl;
    }

    void Gerenciador_Eventos::setJogador(Entidades::Personagens::Jogador* pJogador1)
    {
        this->pJogador1 = pJogador1;
    }


    void Gerenciador_Eventos::verificaTeclaPressionada(sf::Keyboard::Key tecla)
    {
        if (tecla == sf::Keyboard::A){
            pJogador1->movimentar(true);
        } else if (tecla == sf::Keyboard::D){
            pJogador1->movimentar(false);
        } else if (tecla == sf::Keyboard::W){
            pJogador1->pular();
        }  else if (tecla == sf::Keyboard::Escape){
            pGrafico->closeWindow();
        }

    }

    void Gerenciador_Eventos::verificaTeclaSolta(sf::Keyboard::Key tecla)
    {
        if(tecla == sf::Keyboard::A){
            pJogador1->pararEsquerda();
        } else if (tecla == sf::Keyboard::Key::D){
            pJogador1->pararDireita();
        }
    }

    void Gerenciador_Eventos::executar()
    {
        if(pJogador1){
            sf::Event evento;
            while(pGrafico->getWindow()->pollEvent(evento))
            {
                if(evento.type == sf::Event::KeyPressed){
                    verificaTeclaPressionada(evento.key.code);
                } else if (evento.type == sf::Event::KeyReleased){
                    verificaTeclaSolta(evento.key.code);
                } else if (evento.type == sf::Event::Closed){
                    pGrafico->closeWindow();
                }
            }
        } else
        {
            std::cout << "Evento: ponteiro para jogador!" << std::endl;
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
}