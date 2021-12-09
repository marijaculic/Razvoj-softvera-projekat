#include "player.h"
#include <thread>
#include <QKeyEvent>
#include<iostream>
#include "level.h"
#include "ingredient.h"
#include "life.h"
#include "slowingbarrier.h"
#include "deadlybarrier.h"

#include<QApplication>

extern Level *level;

Player::Player()
{
    calculateDimension();
    setPixmap(QPixmap(":images/player.png").scaled(_width, _height));
    setPos(100, 275);

}

void Player::keyPressEvent(QKeyEvent *event){

    if(event->key() == Qt::Key_Right){
        setPixmap(QPixmap(":images/playerRight.png").scaled(_width, _height));
        m_velocityX = stepX;
    }if(event->key() == Qt::Key_Left){
        setPixmap(QPixmap(":images/playerLeft.png").scaled(_width, _height));
        m_velocityX = -stepX;
    }if(event->key() == Qt::Key_Up && m_isOnGround){
        m_velocityY = -stepY;
        setPos(x(), y() + m_velocityY);
        m_isOnGround = false;
    }


}
void Player::keyReleaseEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Right){
        m_velocityX = 0;
        setPixmap(QPixmap(":images/player.png").scaled(_width, _height));
    }
    if(event->key() == Qt::Key_Left){
        m_velocityX = 0;
        setPixmap(QPixmap(":images/player.png").scaled(_width, _height));
    }
}


void Player::advance(int phase)
{

    if(!phase){
        return;
    }
    QGraphicsItem::advance(phase);
    if(m_canMove)
    {
        walk();
    }
    jump();
    detectCollision();


    level->view->centerOn(this);
}

void Player::jump()
{

    if(!m_isOnGround)
    {

        if(m_velocityY < 10)
            m_velocityY += m_gravity;

         setPos(x(), y() + m_velocityY);
    }
    if(isOnGround(this))
        m_isOnGround = true;
}


bool Player::isOnGround(Player *p){
    if(p->y() >=275)
        return true;

    return false;
}

void Player::walk()
{
    setPos(x() + m_velocityX, y());
}


void Player::detectCollision() {

    QList<QGraphicsItem *> colliding_items = collidingItems();

    if(colliding_items.size())
    {
        for (auto &colliding_item : colliding_items)
        {
            if (typeid(*(colliding_item)) == typeid(Ingredient))
            {
                scene()->removeItem(colliding_item);
                emit ingredientPicked();
            }
            if (typeid(*(colliding_item)) == typeid(Life))
            {
                scene()->removeItem(colliding_item);
                emit lifePicked();
            }
            if (typeid(*(colliding_item)) == typeid(SlowingBarrier))
            {
                //scene()->removeItem(colliding_item);
                emit slowingBarrier();
            }
            if (typeid(*(colliding_item)) == typeid(DeadlyBarrier))
            {
                //scene()->removeItem(colliding_item);
                emit deadlyBarrier();
            }
        }
    }

}

void Player::calculateDimension(){
    QScreen *screen = QApplication::screens().at(0);
    qreal screenHeight = screen->availableSize().height();


    _height = screenHeight * 0.2;
    _width = _height * 0.7;
    stepY = _height * 0.12;
    m_gravity = 0.05 * stepY;
}
