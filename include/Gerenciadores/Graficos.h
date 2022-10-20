#pragma once
#include "../Fisica/CoordTL.h"
#include <SFML/Graphics.hpp>
#include <map>

namespace Gerenciadores {

    class Graficos{
    private:
        sf::RenderWindow* window;   
        sf::View view;
        sf::Clock clock;
        static float dt;

        //singleton
        static Gerenciadores::Graficos* instance; 
        Graficos();
    public:
        ~Graficos();
        
        static Graficos* getInstance();

        void render(sf::RectangleShape* shape);
        void render(sf::Text* text);

        void display();

        void clear();

        bool isWindowOpen() const;

        void closeWindow();

        void updateDeltaTime();
    };
}