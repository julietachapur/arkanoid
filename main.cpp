#include<stdlib.h>
#include<time.h>
#include "BaseScene.h"
#include "Menu.h"
#include "Game.h"
#include "PlayScene.h"

int main ( int argc, char** argv ){

    int highScore=0;
    BaseScene *scene = new Menu(highScore);;
    Game &g = Game::create(sf::VideoMode(400, 500), scene, "ARKANOID");
    g.run();

    return 0;

}
