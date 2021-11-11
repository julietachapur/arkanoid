#include "EndGame.h"
#include <iostream>
#include "Game.h"
#include "PlayScene.h"

EndGame::EndGame(){
    // LOAD BACKGROUND IMAGE
    texBackground.loadFromFile("assets/images/gameover.png");
    spBackground.setTexture(texBackground);
    spBackground.setScale(0.5, 0.5);

    // LOAD ASTRONAUT
    texAstronaut.loadFromFile("assets/images/astro.png");
    spAstronaut.setTexture(texAstronaut);
    spAstronaut.setPosition(20,50);
    spAstronaut.setScale(0.2, 0.2);
    // LOAD FONT
    if(!textFont.loadFromFile("assets/fonts/menu-font.ttf")){
        cout << "Error loading font" << endl;
    };

    // GAME OVER TITLE
    titleText.setFont(textFont);
    titleText.setColor(sf::Color::Blue);
    titleText.setString("Game Over");
    titleText.setCharacterSize(48);
    titleText.setPosition(sf::Vector2f((400-titleText.getGlobalBounds().width)/2.0, 50));

    // BACK TO MENU
    exit.setFont(textFont);
    exit.setColor(sf::Color::Yellow);
    exit.setString("[ESC] - Exit");
    exit.setCharacterSize(10);
    exit.setPosition(250, 480);

    //MUSIC
    music.openFromFile("assets/music/menu.ogg");
    music.setLoop(true);
    music.play();
}

void EndGame::update(){

    // Replay button
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)){
        Game::getInstance().switchScene(new PlayScene());
    }
}

void EndGame::draw(sf::RenderWindow &w){
    w.draw(spBackground);
    w.draw(spAstronaut);
    w.draw(titleText);
    w.draw(exit);
}
