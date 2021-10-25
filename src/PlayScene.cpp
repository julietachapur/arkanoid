#include "../include/PlayScene.h"
#include "Game.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cstdlib>
#include <iostream>
#include "../include/Ball.h"
#include "../include/Player.h"
using namespace std;

PlayScene::PlayScene()
{
    init();
}

void PlayScene::init(){//inicializacion
    player = new Player(sf::Vector2f(210,390));
    BaseScene::add(player);
    ball = new Ball();
    BaseScene::add(ball);
}


void PlayScene::update(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::P)){
        if(pause == true){
            pause = false;
        }
        else{pause = true;}
        }



    if(!pause) BaseScene::update();
    colisiones_ball();
}

void PlayScene::draw(sf::RenderWindow &w)
{
    w.draw(spBackground);
    BaseScene::draw(w);
}

void PlayScene::colisiones_ball(){
    if(ball->isCollision(*player)){
        ball->moveBall(*player);
        ball->dirChange();
    }


}
