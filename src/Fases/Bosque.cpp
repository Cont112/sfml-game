#include "../../include/Fases/Bosque.h"

Fases::Bosque::Bosque():Fase()
{
    setTextura(PATH_BOSQUE);
    criarMapa();
}

Fases::Bosque::~Bosque()
{
    
}

void Fases::Bosque::criarMapa()
{
    std::ifstream arquivo;
    std::string linha;

    int nCaixas = (rand()%9)+3;
    int nMagos = (rand()%4)+3;
    int nCaveiras = (rand()%4)+3;

    for (int i=0; i<nCaixas;i++)//criando caixas aleatorias 
    {
        criarEntidade('c', sf::Vector2f( (rand()%25)+2 ,0));
    }

    //criando mapa
    arquivo.open("src/Fases/Mapa_Fase.txt");
    if(!arquivo.is_open()){
        std::cout << "Não foi possivel abrir o arquivo da fase Bosque" << std::endl;
        exit(1);
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

    for (int i=0; i<nMagos;i++)//criando magos aleatorios
    {
        criarEntidade('m', sf::Vector2f( (rand()%25)+5 ,0));
    }    

    for (int i=0; i<nMagos;i++)//criando esqueleto aleatorios
    {
        criarEntidade('e', sf::Vector2f( (rand()%25)+5 ,0));
    }  
}

void Fases::Bosque::resetar()
{
    listaObstaculos.limparLista();
    listaPersonagens.limparLista();

    criarMapa();
}

