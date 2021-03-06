#include "Menu.h"
#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cstdlib>
#include <iostream>
#include "Game.h"
#include "PlayScene.h"

using namespace std;
Menu::Menu(int highScore){
    _highScore = highScore;
    // LOAD BACKGROUND IMAGE
    texBackground.loadFromFile("assets/images/menu.png");
    spBackground.setTexture(texBackground);
    spBackground.setScale(0.5, 0.5);

    // LOAD SPACESHIP
    texSpace.loadFromFile("assets/images/space1.png");
    spSpace.setTexture(texSpace);
    spSpace.setPosition(95,140);
    spSpace.setScale(0.23, 0.23);

    // LOAD ASTRONAUT
    texAstronaut.loadFromFile("assets/images/astronaut.png");
    spAstronaut.setTexture(texAstronaut);
    spAstronaut.setPosition(2, 20);
    spAstronaut.setScale(0.5, 0.5);

    // LOAD FONT
    if(!textFont.loadFromFile("assets/fonts/menu-font.ttf")){
        cout << "Error loading font" << endl;
    };
    // GAME TITLE
    titleText.setFont(textFont);
    titleText.setColor(sf::Color::Black);
    titleText.setString("Arkaoix");
    titleText.setCharacterSize(48);
    titleText.setPosition(sf::Vector2f((400-titleText.getGlobalBounds().width)/2.0, 200));

    // PLAY
    playText.setFont(textFont);
    playText.setColor(sf::Color::Cyan);
    playText.setString("Press TAB to start");
    playText.setCharacterSize(16);
    playText.setPosition(sf::Vector2f((400-playText.getGlobalBounds().width)/2.0, 400));

    // EXIT OPTION
    exitText.setFont(textFont);
    exitText.setColor(sf::Color::Yellow);
    exitText.setString("[backspace] - Exit");
    exitText.setCharacterSize(10);
    exitText.setPosition(230, 480);

    ///Musica
    music.openFromFile("assets/music/menu.ogg");
    music.setLoop(true);
    music.play();
}

void Menu::update(){

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)){
        music.stop();
        Game::getInstance().switchScene(new PlayScene(_highScore));
    }
}

void Menu::draw(sf::RenderWindow &w){
    //w.clear(sf::Color::Black); //limpia la pantalla
    w.draw(spBackground);
    w.draw(spSpace);
    w.draw(spAstronaut);
    w.draw(titleText);
    w.draw(playText);
    /*if (Global::getHighScore!= 0) {
        w.draw(highScoreText);
        w.draw(highScoreValue);
    }*/
    w.draw(exitText);
    //w.display();
}
