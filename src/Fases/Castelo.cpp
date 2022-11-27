#include "../../include/Fases/Castelo.h"

Fases::Castelo::Castelo():Fase(IDs::castelo)
{
    setTextura(PATH_CASTELO);
    criarMapa();
}

Fases::Castelo::~Castelo()
{

}

void Fases::Castelo::criarMapa()
{
    std::ifstream arquivo;
    std::string linha;

    int nLavas = (rand()%3)+3;
    int nCaixas = (rand()%9)+3;
    int nEsqueletos = (rand()%4)+3;
    int nCavaleiros = (rand()%4)+3;

    for (int i=0; i<nCaixas;i++)//criando caixas aleatorias 
    {
        criarEntidade('c', sf::Vector2f( (rand()%23)+2 ,0));
    }

    for (int i=0; i<nLavas;i++)//criando caixas aleatorias 
    {
        criarEntidade('l', sf::Vector2f( (rand()%23)+2 ,0));
    }


    //criando mapa 
    
    arquivo.open("src/Fases/Mapa_Castelo.txt");
    try
    {
        if (!arquivo.is_open())
        {
            std::cout<<"erro ao abrir o arquivo da fase castelo"<<std::endl;
            throw 1;
        }

    }
    catch(const int erro)
    {
        std::cout<<"erro:"<<erro<<std::endl;
    }
    int j = 0;
    while(std::getline(arquivo, linha)){
        for(int i = 0; i < linha.size(); i++){
            if(linha[i] != ' '){
                criarEntidade(linha[i], sf::Vector2f(i, j));
            }
        }
        j++;
    }
    arquivo.close();

    for (int i=0; i<nEsqueletos;i++)//criando magos aleatorios
    {
        criarEntidade('e', sf::Vector2f( (rand()%20)+5 ,0));
    } 

    for (int i=0; i<nCavaleiros;i++)//criando esqueleto aleatorios
    {
        criarEntidade('k', sf::Vector2f( (rand()%20)+5 ,0));
    }  
}

void Fases::Castelo::resetar()
{
    listaObstaculos.limparLista();
    listaPersonagens.limparLista();

    if(player2)
    {
        setJogador2(pEventos->getJogador(false));
        j2->resetar();
    }
    setJogador1(pEventos->getJogador(true));
    j1->resetar();
    criarMapa();
}
