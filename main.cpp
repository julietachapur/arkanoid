#include<stdlib.h>
#include<time.h>
#include "BaseScene.h"
#include "Game.h"
#include "PlayScene.h"

int main ( int argc, char** argv ){


    BaseScene *scene = new PlayScene();
    Game &g = Game::create(sf::VideoMode(400, 500), scene, "ARKANOID");

    g.run();

    return 0;

}
