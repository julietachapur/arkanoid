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
        sf::Texture texHighScore;
        sf::Sprite spHighScore;
        sf::Texture texBackground;//fondo
        sf::Sprite spBackground;
        sf::Texture texAstronaut;//fondo
        sf::Sprite spAstronaut;
        sf::Music music;
        sf::Font textFont;
        sf::Text titleText;
        sf::Text exit;
<<<<<<< HEAD
        sf::Text txt;
        int _highScore;
        int _score;

    public:
        EndGame(int score, int highScore);
=======

        sf::Text high;
        sf::Text highValue;


        GlobalScore sc;
       int _highScore;
       int _lastScore;

    public:
        EndGame();
        int mayor();
>>>>>>> d9849e24ce24f97f2c5aa6c548bb178c90619b18
        void update();
        void draw(sf::RenderWindow &w);
};

#endif // ENDGAME_H
