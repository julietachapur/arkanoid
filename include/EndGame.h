#ifndef ENDGAME_H
#define ENDGAME_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <string>
#include "./BaseScene.h"
#include "GlobalScore.h"

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

        sf::Text high;
        sf::Text highValue;


        GlobalScore sc;
       int _highScore;
       int _lastScore;

    public:
        EndGame();
        int mayor();
        void update();
        void draw(sf::RenderWindow &w);
};

#endif // ENDGAME_H
