#ifndef ENDGAME_H
#define ENDGAME_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <string>
#include "./BaseScene.h"

using namespace std;

class EndGame: public BaseScene{
    private:
        sf::Texture texBackground;//fondo
        sf::Sprite spBackground;
        sf::Texture texAstronaut;//fondo
        sf::Sprite spAstronaut;
        sf::Music music;

        sf::Font textFont;
        sf::Text titleText;
        sf::Text exit;


    public:
        EndGame();
        void update();
        void draw(sf::RenderWindow &w);
};

#endif // ENDGAME_H
