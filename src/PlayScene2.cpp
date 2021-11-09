#include "PlayScene2.h"

#include "Game.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cstdlib>
#include <iostream>
#include "../include/Ball.h"
#include "../include/Player.h"
#include"../include/Enemy.h"
#include"../include/LimiteGameOver.h"
using namespace std;

PlayScene2::PlayScene2()
{
    init();
}

void PlayScene2::init(){//inicializacion
    vidas=3;
    player = new Player(sf::Vector2f(210,390));
    BaseScene::add(player);
    ball = new Ball();
    BaseScene::add(ball);


    n=0;
    for(int i=1;i<=5;i++){
        for(int j=0;j<=5;j++){
            enemy[n]=new Enemy(i,j,2);
            BaseScene::add(enemy[n]);
            n++;
        }
    }

    limit= new LimiteGameOver();
    BaseScene::add(limit);

    texBackground.loadFromFile("assets/images/bckground.png");
    spBackground.setTexture(texBackground);

    font.loadFromFile("assets/fonts/font.ttf");

    ///Texto para vidas

    vida.setFont(font);
    vida.setString("Vidas "+ to_string(vidas));
    vida.setFillColor(sf::Color::White);
    vida.setPosition(330,420);
    vida.setScale(0.5,0.5);

    ///Texto para score

    txt.setFont(font);
    txt.setString("Score "+ to_string(score));
    txt.setFillColor(sf::Color::White);
    txt.setPosition(30,420);
    txt.setScale(0.5,0.5);

    ///Musica
    /*music.openFromFile("assets/music/music.ogg");
    music.setLoop(true);
    music.play();*/


}
void PlayScene2::aumentarScore()
{
    score +=1;
    txt.setString("Score "+ to_string(score));
}

void PlayScene2::update(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::P)){
        if(pause == true){
            pause = false;
        }
        else{pause = true;}
        }



    if(!pause) BaseScene::update();
    colisiones_ball();
    colisiones_enemy();
    if(vidas==0){
       Game::getInstance().switchScene(new EndGame());
    }
    vida.setString("vidas " + to_string(vidas));
}

void PlayScene2::draw(sf::RenderWindow &w)
{
    w.draw(spBackground);
    BaseScene::draw(w);
    w.draw(vida);
    w.draw(txt);
}

void PlayScene2::colisiones_ball(){
   sf::Vector2f pos=ball->getVelocity();

    if(ball->isCollision(*player)){
        ball->moveBall(*player);
        ball->dirChange();
    }

    if(ball->isCollision(*limit)){
        if(ball->velBall.y>0){
            vidas--;
            ball->reset();
        }
    }
}

void PlayScene2::colisiones_limit(){
if(limit->isCollision(*ball)){
    w.close();
}
}

void PlayScene2::colisiones_enemy(){

   for(int i=0;i<n;i++){
        if(enemy[i]->isCollision(*ball)){
        if(enemy[i]->getVidas()==0){
            enemy[i]->disapear();
            ball->dirChangeE();
            aumentarScore();
        }
        else{
        ball->dirChangeE();
        enemy[i]->disminuir();
        enemy[i]->changeColour();
        aumentarScore();
        }

    }
   }


}
