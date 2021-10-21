#ifndef ENDGAME_H
#define ENDGAME_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <string>
#include "./BaseScene.h"
#include "./Global.h"

using namespace std;

class EndGame: public BaseScene, public Global{
    private:
        sf::Texture texBackground;//fondo
        sf::Sprite spBackground;
        //sf::Music music;

        sf::Font textFont;
        sf::Text titleText;
        sf::Text highScore;
        sf::Text highScoreValue;
        sf::Text newText;
        sf::Text newHighScore;
        sf::Text newHighScoreValue;
        sf::Text scoreText;
        sf::Text scoreValue;
        sf::Text backMenu;
        sf::Text replay;
        sf::Text exit;

        Global *global;

    public:
        EndGame();
        void update();
        void draw(sf::RenderWindow &w);
};

#endif // ENDGAME_H
