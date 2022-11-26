#include "../../include/Gerenciadores/Gerenciador_Colisoes.h"

namespace Gerenciadores { 
    Gerenciador_Colisoes::Gerenciador_Colisoes(Listas::Lista_Entidades* l1, Listas::Lista_Entidades* l2):
        listaPersonagem(l1), listaObstaculo(l2)
    {

    }

    Gerenciador_Colisoes::~Gerenciador_Colisoes(){
        if(listaPersonagem){
            delete(listaPersonagem);
        }
        if(listaObstaculo){
            delete(listaObstaculo);
        }
    }
   
    sf::Vector2f Gerenciador_Colisoes::calculaDistancia(Entidades::Entidade* ent1, Entidades::Entidade* ent2)
    {
        sf::Vector2f pos1 = ent1->getPosicao();
        sf::Vector2f pos2 = ent2->getPosicao();

        sf::Vector2f tam1 = ent1->getTam();
        sf::Vector2f tam2 = ent2->getTam();
        
        sf::Vector2f distanciaEntreCentros(
            fabs((pos1.x) - (pos2.x)), // pos1.x + tam.x/2.0f pq agr o centro ja esta no meio
            fabs((pos1.y + tam1.y/2.0f) - (pos2.y + tam2.y/2.0f))
        );
        sf::Vector2f somaMetadeRectangulo(tam1.x/2.0f + tam2.x/2.0f, tam1.y/2.0f + tam2.y/2.0f);
        return sf::Vector2f(distanciaEntreCentros.x - somaMetadeRectangulo.x, distanciaEntreCentros.y - somaMetadeRectangulo.y);
    }

    void Gerenciador_Colisoes::executar(){

    //COLISAO PERSONAGEM X PERSONAGEM
    for(int i = 0; i < listaPersonagem->getTamanho() - 1; i++){
        Entidades::Entidade* ent1 = listaPersonagem->operator[](i);
        for(int j = i + 1; j < listaPersonagem->getTamanho(); j++){
            Entidades::Entidade* ent2 = listaPersonagem->operator[](j);
            sf::Vector2f ds = calculaDistancia(ent1, ent2);
            if(ds.x < 0.0f && ds.y < 0.0f){
                ent1->colisao(ent2, ds);
                ent2->colisao(ent1, ds);
            }
            }
        }
    

    //COLISAO PERSONAGEM X OBSTACULO
    for(int i = 0; i < listaPersonagem->getTamanho(); i++){
        Entidades::Entidade* ent1 = listaPersonagem->operator[](i);
        for(int j = 0; j < listaObstaculo->getTamanho(); j++){
            Entidades::Entidade* ent2 = listaObstaculo->operator[](j);
            sf::Vector2f ds = calculaDistancia(ent1, ent2);
            if(ds.x < 0.0f && ds.y < 0.0f){
                if(ent2->getID() == IDs::plataforma || ent2->getID() == IDs::caixa || ent2->getID() == IDs::lava ){
                    ent2->colisao(ent1, ds);
                } 
                else {
                    // outro obstáculo 
                }
            }
        }
    }

    //COLISAO OBSTACULO X OBSTACULO
    for(int i = 0; i < listaObstaculo->getTamanho() - 1; i++){
        Entidades::Entidade* ent1 = listaObstaculo->operator[](i);
        for(int j = i + 1; j < listaObstaculo->getTamanho(); j++){
            Entidades::Entidade* ent2 = listaObstaculo->operator[](j);
            sf::Vector2f ds = calculaDistancia(ent1, ent2);
            if(ds.x < 0.0f && ds.y < 0.0f){
                ent1->colisao(ent2,ds);
            }
        }
    }
}

    void Gerenciador_Colisoes::setListas(Listas::Lista_Entidades *lm,Listas::Lista_Entidades *lf ){
    listaPersonagem = lm;
    listaObstaculo = lf;
}

}
