#include "../../include/Fases/Bosque.h"

Fases::Bosque::Bosque():Fase()
{

}

Fases::Bosque::~Bosque()
{

}

void Fases::Bosque::criarMapa()
{
    std::ifstream arquivo;
    std::string linha;
    arquivo.open("Mapa_Fase.txt");
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

}

void Fases::Bosque::criarFundo()
{
    


}