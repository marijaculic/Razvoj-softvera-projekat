#include "score.h"
#include<iostream>

Score::Score()
{
    scores.resize(6, 0);
    level_time.resize(6, 0);
    current_score = 0;
    lives = 3;
}

void Score::increase()
{
    current_score += value;
    std::cout << current_score << std::endl;
}

void Score::decrease()
{
    current_score -= value;
}

void Score::addLife()
{
    this->lives++;
    std::cout << this->lives << std::endl;
}

void Score::takeLife()
{
    this->lives--;
    if(lives == 0)
        std::cout << "nema vise zivota, kraj igrice" << std::endl;
}

std::vector<int> Score::getScores(){
    return this->scores;
}

int Score::getLives(){
    return this->lives;
}

void Score::saveCurrentScore(int levelId){
    this->scores[levelId - 1] = this->current_score;
    current_score = 0;
}

void Score::saveCurrentTime(int levelId, int time){
    this->level_time[levelId - 1] = time;
}

int Score::getLevelTime(int levelId) {
    return this->level_time[levelId - 1];
}
