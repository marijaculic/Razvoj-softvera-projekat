#include "Headers/jellyfish.h"
#include <cstdlib>

Jellyfish::Jellyfish(qreal playerWidth)
{
    qreal width = playerWidth * 0.5;
    qreal height = width;

    this->generator = new QRandomGenerator();
    int x = generator->bounded(2);

    if (x == 0)
        setPixmap(QPixmap(":/images/jellyfish.png").scaled(width, height));
    else
        setPixmap(QPixmap(":/images/jellyfish_blue.png").scaled(width, height));
}

void Jellyfish::move()
{
    stepForward();
    changeDirectionIfNeeded();
}

void Jellyfish::stepForward()
{
    setPos(x(), y() - move_y);
    steps++;
}

void Jellyfish::changeDirectionIfNeeded()
{
    if(steps == max_steps) {
        steps = 0;
        move_y = -move_y;
    }
}
Jellyfish::~Jellyfish(){

}

