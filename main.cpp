#include<stdlib.h>
#include<time.h>
#include "BaseScene.h"
#include "Menu.h"
#include "Game.h"
#include "PlayScene.h"

int main ( int argc, char** argv ){

    int highScore=0;
    int score =20;
    BaseScene *scene = new EndGame(score,highScore);;
    Game &g = Game::create(sf::VideoMode(400, 500), scene, "ARKANOID");
    g.run();

    return 0;

}
