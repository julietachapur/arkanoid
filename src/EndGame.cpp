#include "EndGame.h"
#include <iostream>
#include "Game.h"
#include "PlayScene.h"

int EndGame::mayor(){
int aux=0;
int pos=0;
while(sc.leerDeDisco(pos)){
    if(sc.getLastScore()>aux){
        aux=sc.getLastScore();
    }
    pos++;
}
return aux;
}
EndGame::EndGame(){

    _highScore=mayor();
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


    //HighScore
    high.setFont(textFont);
    high.setColor(sf::Color::Magenta);
    high.setString("Highscore");
    high.setCharacterSize(29);
    high.setPosition(sf::Vector2f((400-high.getGlobalBounds().width)/2.0, 230));

    //highScore Value

    highValue.setFont(textFont);
    highValue.setColor(sf::Color::Magenta);
    highValue.setString(to_string(_highScore));
    highValue.setCharacterSize(29);
    highValue.setPosition(sf::Vector2f((400-high.getGlobalBounds().width)/2.0, 280));

    //MUSIC
    music.openFromFile("assets/music/menu.ogg");
    music.setLoop(true);
    music.play();
}

void EndGame::update(){

    // Replay button
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)){
        music.stop();
        Game::getInstance().switchScene(new PlayScene());
    }
}

void EndGame::draw(sf::RenderWindow &w){
    w.draw(spBackground);
    w.draw(spAstronaut);
    w.draw(high);
    w.draw(highValue);
    w.draw(titleText);
    w.draw(exit);
}
