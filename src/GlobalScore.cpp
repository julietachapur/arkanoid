#inluce <iostream>
using namespace std;


#include "GlobalScore.h"

GlobalScore::GlobalScore()
{
}

void GlobalScore::setCer(){
    highScore = 0;
    lastScore = 0;
    cout<<highScore;
    cout<<lastScore;
}

void GlobalScore::getHighScore(){
return highScore;
}

void GlobalScore::getLastScore(){
return lastScore;
}

void GlobalScore::setHighScore(int n){
highScore=n;
}

void GlobalScore::setHighScore(int n){
lastScore=n;
}
