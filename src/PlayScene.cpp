#include "../include/PlayScene.h"
#include "Game.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cstdlib>
#include <iostream>
#include "../include/Ball.h"
#include "../include/Player.h"
#include"../include/Limite_inf.h"
using namespace std;

PlayScene::PlayScene()
{
    init();
}

void PlayScene::init(){//inicializacion
    vidas=3;
    player = new Player(sf::Vector2f(210,390));
    BaseScene::add(player);
    ball = new Ball();
    BaseScene::add(ball);
    //limit=new Limite_inf(sf::Vector2f(50,50));
    //BaseScene::add(limit);
    texBackground.loadFromFile("assets/images/bckground.png");
    spBackground.setTexture(texBackground);

    font.loadFromFile("assets/fonts/font.ttf");

    ///Texto para vidas

    vida.setFont(font);
    vida.setString("Vidas "+ to_string(vidas));
    vida.setFillColor(sf::Color::White);
    vida.setPosition(330,420);
    vida.setScale(0.5,0.5);
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
    w.draw(vida);
}

void PlayScene::colisiones_ball(){
   sf::Vector2f pos=ball->getVelocity();

    if(ball->isCollision(*player)){
        ball->moveBall(*player);
        ball->dirChange();
    }

    if(pos.y==400){
        vidas--;
        if(vidas==0){
            w.close();
        }
        vida.setString("Vidas "+to_string(vidas));
        ball->dirChange();
    }


}
