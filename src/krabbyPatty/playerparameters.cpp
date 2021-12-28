#include "playerparameters.h"

PlayerParameters::PlayerParameters()
{
    QScreen *screen = QApplication::screens().at(0);
    qreal screenHeight = screen->availableSize().height();

    _height = screenHeight * 0.2;
    _width = _height * 0.7;
    _stepY = _height * 0.13;
    _gravity = 0.05 *_stepY;
    _posY = screenHeight * 0.65;
}

void PlayerParameters::setSpeed(Speed speed){
    _stepX = int(speed);
}

Speed PlayerParameters::getSpeed(){
    return Speed(_stepX);
}
